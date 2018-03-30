#ifndef SHIMMER_CONNECTOR_H
#define SHIMMER_CONNECTOR_H

#include "receiver.h"

namespace shimmer
{
template<typename S, typename E>
class connector
{
public:
    typedef S               SIGNATURE;
    typedef E               EVENT;
    typedef receiver<EVENT> RECEIVER;

    virtual ~connector() = default;

    /**
     * @brief Connects a receiver to the specified signature.
     * @param signature The signature to which the receiver should connect.
     * @param receiver The component that should receive events.
     */
    virtual void connect ( const SIGNATURE& signature,
                           RECEIVER&        receiver ) = 0;

    /**
     * @brief Disconnects a specific signature of a receiver from the exchange.
     * @param signature The signature to disconnect.
     * @param receiver The receiver that should have its corresponding signature
     * disconnected.
     * @return this
     */
    virtual void disconnect ( const SIGNATURE& signature,
                              RECEIVER&        receiver ) = 0;
};
}

#endif // ifndef SHIMMER_CONNECTOR_H
