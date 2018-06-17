#ifndef SHIMMER_LIMITER_H
#define SHIMMER_LIMITER_H

#include "external/json/json.hpp"

#include <chrono>
#include <string>

namespace shimmer
{
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

std::string to_json ( const limiter& limiter );

void        to_json ( nlohmann::json& json,
                      const limiter&  obj );

void from_json ( const nlohmann::json& json,
                 limiter&              obj );
}

#endif // ifndef SHIMMER_LIMITER_H
