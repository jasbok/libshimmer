#ifndef SHIMMER_EXCHANGE_H
#define SHIMMER_EXCHANGE_H

#include "receiver.h"

#include "signal/Signal.h"

#include <algorithm>
#include <functional>
#include <vector>

namespace shimmer
{
/**
 * @brief Creates a slot used to signal events to a defined receiver.
 */
template<typename S, typename E>
struct slot
{
public:
    typedef S                              SIGNATURE;
    typedef E                              EVENT;
    typedef receiver<EVENT>                RECEIVER;
    typedef Gallant::Signal1<const EVENT&> SIGNAL;

    SIGNATURE signature;
    SIGNAL    signal;

    slot(const SIGNATURE& signature,
         RECEIVER&        receiver)
        : signature (signature),
          _receiver (&receiver),
          signal()
    {
        signal.Connect (_receiver,&RECEIVER::send);
    }

    virtual ~slot() {
        // signal.Disconnect (receiver,&RECEIVER::send);
    }

    bool operator==(const slot<SIGNATURE,RECEIVER>& comp) const {
        return signature == comp.signature && _receiver == comp._receiver;
    }

private:
    RECEIVER* _receiver;
};

/**
 * @brief Sends events E with signatures S to connected receivers. The matching
 * function MATCHER is used to determine whether an event should be sent to
 * a receiver, based on the signature of the receiver slot and the sent event.
 */
template<typename S,typename E,bool ( * MATCHER )( const S&,const E& )>
class exchange : public receiver<E>
{
public:
    typedef S                     SIGNATURE;
    typedef E                     EVENT;
    typedef slot<SIGNATURE,EVENT> SLOT;
    typedef receiver<EVENT>       RECEIVER;

    virtual ~exchange() = default;

    /**
     * @brief Connects a receiver to the specified signature.
     * @param signature The signature to which the receiver should connect.
     * @param receiver The component that should receive events.
     * @return this
     */
    exchange& connect (const SIGNATURE& signature,
                       RECEIVER&        receiver) {
        _slots.push_back ({ signature,receiver });

        return *this;
    }

    /**
     * @brief send
     * @param event
     */
    virtual void send (const EVENT& event) {
        for ( auto& slot : _slots ) {
            if ( MATCHER (slot.signature,event)) {
                slot.signal (event);
            }
        }
    }

private:
    std::vector<SLOT> _slots;
};
}

#endif // ifndef SHIMMER_EXCHANGE_H
