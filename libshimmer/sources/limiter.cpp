#include "limiter.h"
#include "logger.h"

using namespace std;

namespace shimmer
{
bool limiter::check() {
    using namespace std::chrono;

    if ( _limit <= 0.0f ) return false;

    auto t2 = steady_clock::now();

    _average -= _average * _r_samples;
    _average += duration_cast<duration<float>>( t2 - _t1 ).count() *
                _r_samples;

    if ( _average < _r_limit ) return true;

    _t1 = t2;

    return false;
}

void limiter::limit ( float limit ) {
    LOGD << "limit set to: " << limit;
    _limit = limit;

    if ( _limit > 0 ) _r_limit = 1.0f / _limit;
}

float limiter::limit() const {
    return _limit;
}

void limiter::samples ( float samples ) {
    LOGD << "samples set to: " << samples;
    _samples = samples;

    if ( _samples > 0 ) _r_samples = 1.0f / _samples;
}

float limiter::samples() const {
    return _samples;
}

std::string to_json ( const limiter& limiter )
{
    return nlohmann::json ( limiter ).dump();
}

void to_json ( nlohmann::json& json, const limiter& obj )
{
    json["limit"]   = obj.limit();
    json["samples"] = obj.samples();
}

void from_json ( const nlohmann::json& json, limiter& obj )
{
    obj.limit ( json.at ( "limit" ) );
    obj.samples ( json.at ( "samples" ) );
}
}
