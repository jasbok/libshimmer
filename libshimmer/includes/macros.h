#ifndef SHIMMER_MACROS_H
#define SHIMMER_MACROS_H

#include <dlfcn.h>

#define DLSYM( FUNC ) namespace sym                                      \
    {                                                                    \
    static auto FUNC = [] () {                                           \
                           auto dlsym_ptr = dlsym ( RTLD_NEXT, # FUNC ); \
                           if ( !dlsym_ptr ) {                           \
                               printf ( "Unable to find function: %s\n", \
                                        # FUNC );                        \
                               abort();                                  \
                           }                                             \
                           return ( FUNC ## _Handle )( dlsym_ptr );      \
                       } ( );                                            \
    }

#define HANDLE_TYPEDEF( RET, FUNC, \
                        ... ) typedef RET ( *FUNC ## _Handle )( ... )

#define SHIM( RET, FUNC, ... )         \
    HANDLE_TYPEDEF ( RET, FUNC, ... ); \
    DLSYM ( FUNC );                    \
    RET FUNC ( ... )

#ifdef DEBUG
# include <chrono>
# include <fstream>

static std::ofstream _SHIMMER_LOG_FILE ( "/tmp/shimmer.log" );

# define SHIM_LOG()                                                       \
    using namespace std::chrono;                                          \
    static unsigned int _COUNTER           = 0;                           \
    static steady_clock::time_point _START = steady_clock::now();         \
    static bool  _FIRST_CALL               = true;                        \
    static float _INTERVAL                 = 1.0f;                        \
                                                                          \
    auto _DURATION = duration_cast<duration<float>>(                      \
        steady_clock::now() - _START );                                   \
                                                                          \
    _COUNTER++;                                                           \
                                                                          \
    if ( _FIRST_CALL ) {                                                  \
        std::cout << "[[ " << __FUNCTION__ << " ]]" << std::endl;         \
        _SHIMMER_LOG_FILE << "[[ " << __FUNCTION__ << " ]]" << std::endl; \
        _FIRST_CALL = false;                                              \
    }                                                                     \
    else if ( _DURATION.count() > _INTERVAL ) {                           \
        std::cout << _COUNTER << "x " << __FUNCTION__                     \
                  << "(" << std::setprecision ( 2 )                       \
                  <<  _COUNTER / _DURATION.count()                        \
                  << "/sec)" << std::endl;                                \
                                                                          \
        _SHIMMER_LOG_FILE << _COUNTER << "x " << __FUNCTION__             \
                          << "(" << std::setprecision ( 2 )               \
                          <<  _COUNTER / _DURATION.count()                \
                          << "/sec)" << std::endl;                        \
                                                                          \
        _COUNTER   = 0;                                                   \
        _INTERVAL *= 2;                                                   \
        _START     = steady_clock::now();                                 \
    }

#else // ifdef DEBUG
# define SHIM_LOG()
#endif  // ifdef DEBUG


        #define FLUENT( CLASS, TYPE, NAME )    \
public:                                        \
    virtual CLASS& NAME ( const TYPE &NAME ) { \
        _ ## NAME = NAME; return *this;        \
    }                                          \
    virtual CLASS& NAME ( TYPE && NAME ) {     \
        _ ## NAME = NAME; return *this;        \
    }                                          \
    virtual const TYPE NAME() const {          \
        return _ ## NAME;                      \
    }                                          \
    virtual TYPE NAME() {                      \
        return _ ## NAME;                      \
    }                                          \
private:                                       \
    TYPE _ ## NAME

#define GETTER( TYPE, NAME )           \
public:                                \
    virtual const TYPE &NAME() const { \
        return _ ## NAME;              \
    }                                  \
    virtual TYPE NAME() {              \
        return _ ## NAME;              \
    }                                  \
private:                               \
    TYPE _ ## NAME

#define GETTER_OVERRIDE( TYPE, NAME ) \
public:                               \
    virtual TYPE NAME() override {    \
        return _ ## NAME;             \
    }                                 \
private:                              \
    TYPE _ ## NAME

#endif // ifndef SHIMMER_MACROS_H
