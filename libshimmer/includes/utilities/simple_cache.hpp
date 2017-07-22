#ifndef LIBSHIMMER_UTILITIES_SIMPLE_CACHE_HPP
#define LIBSHIMMER_UTILITIES_SIMPLE_CACHE_HPP

#include "cache.hpp"
#include "spdlog.h"
#include <string>
#include <unordered_map>

namespace shimmer
{
template<typename K,  typename V>
class simple_cache: public cache<K, V>
{
public:
    simple_cache ( const std::string name, const V& default_value = V() )
        :  _default_value ( default_value ),
           _logger ( spdlog::stdout_color_mt ( "simple_cache::" + name ) )
    {}

    virtual ~simple_cache() {}

    bool exists ( const K& key ) override
    {
        return _cache.find ( key ) != _cache.end();
    }

    V get ( const K& key ) override
    {
        if ( !exists ( key ) ) {
            _logger->warn ( "Unable to find {} in cache.", key );
            return _default_value;
        }

        return _cache.at ( key );
    }

    void set ( const K& key, const V& value ) override
    {
        _cache[key] = value;
    }

private:
    std::unordered_map<K, V> _cache;
    V _default_value;
    std::shared_ptr<spdlog::logger> _logger;
};
}

#endif

