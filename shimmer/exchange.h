#ifndef SHIMMER_EXCHANGE_H
#define SHIMMER_EXCHANGE_H

#include "connector.h"

#include "external/signal/Signal.h"

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
          signal(),
          _receiver (&receiver)
    {}

    /**
     * @brief connect Connects the current slot to the receiver.
     */
    void connect() {
        signal.Connect (_receiver,&RECEIVER::send);
    }

    /**
     * @brief connect Disconnects the current slot from the receiver.
     */
    void disconnect() {
        signal.Disconnect (_receiver,&RECEIVER::send);
    }

    virtual ~slot() {
        // signal.Disconnect (receiver,&RECEIVER::send);
    }

    bool operator==(const slot<S,E>& comp) const {
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
template<typename S,typename E,bool (* MATCHER)( const S&,const E& )>
class exchange : public connector<S,E>
{
public:
    typedef typename connector<S,E>::SIGNATURE SIGNATURE;
    typedef typename connector<S,E>::EVENT     EVENT;
    typedef typename connector<S,E>::RECEIVER  RECEIVER;
    typedef slot<SIGNATURE,EVENT>              SLOT;

    virtual ~exchange() = default;

    /**
     * @brief Connects a receiver to the specified signature.
     * @param signature The signature to which the receiver should connect.
     * @param receiver The component that should receive events.
     * @return this
     */
    virtual void connect (const SIGNATURE& signature,
                          RECEIVER&        receiver) {
        auto slot = SLOT{ signature,receiver };

        slot.connect();
        _slots.push_back (slot);
    }

    /**
     * @brief Disconnects a specific signature of a receiver from the exchange.
     * @param signature The signature to disconnect.
     * @param receiver The receiver that should have its corresponding signature
     * disconnected.
     * @return this
     */
    virtual void disconnect (const SIGNATURE& signature,
                             RECEIVER&        receiver) {
        auto slot = SLOT{ signature,receiver };

        _slots.erase (std::remove (_slots.begin(),_slots.end(),slot));
    }

    /**
     * @brief send Sends the event to slot receivers with matching signatures.
     * @param event The event to send.
     */
    virtual void send (const EVENT& event) {
        for ( auto& slot : _slots ) {
            if ( MATCHER (slot.signature,event) ) slot.signal (event);
        }
    }

private:
    std::vector<SLOT> _slots;
};
}

#endif // ifndef SHIMMER_EXCHANGE_H
