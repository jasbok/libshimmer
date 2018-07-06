#ifndef COMMON_SERIES_H
#define COMMON_SERIES_H

#include <cassert>
#include <vector>

namespace common::series
{
/**
 * @brief sequential Generates a sequential series of values based on t
 * he given parameters, such that series => [start, end) with increments of
 * step.
 * @param start The start of the series.
 * @param end The end of the series (non-inclusive).
 * @param step The step between sequential values.
 * @return The series [start, end) with increments of step.
 */
template<typename T>
std::vector<T> sequential ( T start, T end, T step ) {
    assert ( ( start < end && step > 0 ) || start >= end );

    std::size_t size = ( end - start ) / step;
    std::vector<T> series;
    series.reserve ( size );

    for ( T i = start; i < end; i += step ) {
        series.push_back ( i );
    }

    return series;
}

/**
 * @brief transform Transforms the given series using a scale factor and
 * translation value.
 * @param series The series which will be transformed.
 * @param translation The translation value.
 * @param scale The scale factor.
 * @return The new transformed series.
 */
template<typename I, typename T, typename S>
std::vector<I> transform ( const std::vector<I>& series,
                           const T&              translation,
                           const S&              scale ) {
    std::vector<I> results;

    results.reserve ( series.size() );

    for ( const I& item : series ) {
        results.push_back ( item * scale + translation );
    }

    return results;
}

template<typename I>

/**
 * @brief blend Blends the two series using the given blend factor. Each item
 * is blended using the equation f(factor) = a * (1.0f - factor) + b * factor.
 * @param series_a The first series.
 * @param series_b The second series.
 * @param factor The blend factor.
 * @return The blended series.
 */
std::vector<I> blend ( const std::vector<I>& series_a,
                       const std::vector<I>& series_b,
                       float                 factor ) {
    assert ( series_a.size() == series_b.size() );

    float factor_a = 1.0f - factor;
    std::vector<I> blended;
    blended.reserve ( series_a.size() );


    for ( std::size_t i = 0; i < series_a.size(); i++ ) {
        blended.push_back ( series_a[i] * factor_a + series_b[i] * factor );
    }

    return blended;
}
}

#endif // ifndef COMMON_SERIES_H
