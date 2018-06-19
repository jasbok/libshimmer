#ifndef COMMON_LIMITER_H
#define COMMON_LIMITER_H

#include <chrono>

namespace common {
class limiter
{
public:
    limiter() = default;

    virtual ~limiter() = default;

    bool  check();

    void  limit ( float limit );

    float limit() const;

    void  samples ( float samples );

    float samples() const;

private:
    std::chrono::steady_clock::time_point _t1;

    float _limit;

    float _r_limit;

    float _samples;

    float _r_samples;

    float _average;
};
}

#endif
