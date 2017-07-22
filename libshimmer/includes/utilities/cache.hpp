#ifndef LIBSHIMMER_UTILITIES_CACHE_HPP
#define LIBSHIMMER_UTILITIES_CACHE_HPP

namespace shimmer
{
template<typename K,  typename V>
class cache
{
public:
    virtual ~cache() {}

    virtual bool exists(const K& key) = 0;
    virtual V get(const K& key) = 0;
    virtual void set(const K& key, const V& value) = 0;
};
}

#endif
