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
                        ARGS ... ) typedef RET ( *FUNC ## _Handle )( ARGS )

#define SHIM( RET, FUNC, ARGS ... )     \
    HANDLE_TYPEDEF ( RET, FUNC, ARGS ); \
    DLSYM ( FUNC );                     \
    RET FUNC ( ARGS )

#ifdef DEBUG

# define SHIM_LOG( MAX )                                                   \
    static unsigned int _SHIM_LOG_COUNT = 0;                               \
    if ( _SHIM_LOG_COUNT++ < MAX )                                         \
        printf ( "=> Handle: %s (%u/%u)\n", __FUNCTION__, _SHIM_LOG_COUNT, \
                 MAX )

#else // ifdef DEBUG
# define SHIM_LOG( MAX )
#endif // ifdef DEBUG


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
