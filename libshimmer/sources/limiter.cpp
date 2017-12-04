#include "limiter.h"

using namespace shimmer;
using namespace std;

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
    _limit = limit;

    if ( _limit > 0 ) _r_limit = 1.0f / _limit;
}

float limiter::limit() const {
    return _limit;
}

void limiter::samples ( float samples ) {
    _samples = samples;

    if ( _samples > 0 ) _r_samples = 1.0f / _samples;
}

float limiter::samples() const {
    return _samples;
}
