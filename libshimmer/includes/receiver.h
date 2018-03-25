#ifndef SHIMMER_RECEIVER_H
#define SHIMMER_RECEIVER_H

namespace shimmer
{
/**
 * @brief Receives an event of type T.
 */
template<typename T>
class receiver
{
public:
    virtual ~receiver() {}

    /**
     * @brief Send an event to this component.
     * @param event The event to send to the component.
     * @return True if the event was received, false otherwise.
     */
    virtual void send ( const T& event ) = 0;
};
}

#endif // ifndef SHIMMER_RECEIVER_H
