#ifndef APIGEN_SDL_H
#define APIGEN_SDL_H

#include "SDL.h"

#include <dlfcn.h>

namespace sym{
    typedef void * ( *SDL_revcpy_handle )( void * dst, const void * src, size_t len );
    static auto SDL_revcpy = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_revcpy" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_revcpy" );
        }
        return ( SDL_revcpy_handle )( dlsym_ptr );
    } ();
}

void * SDL_revcpy ( void * dst, const void * src, size_t len );

namespace sym{
    typedef size_t ( *SDL_strlcpy_handle )( char * dst, const char * src, size_t maxlen );
    static auto SDL_strlcpy = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_strlcpy" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_strlcpy" );
        }
        return ( SDL_strlcpy_handle )( dlsym_ptr );
    } ();
}

size_t SDL_strlcpy ( char * dst, const char * src, size_t maxlen );

namespace sym{
    typedef size_t ( *SDL_strlcat_handle )( char * dst, const char * src, size_t maxlen );
    static auto SDL_strlcat = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_strlcat" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_strlcat" );
        }
        return ( SDL_strlcat_handle )( dlsym_ptr );
    } ();
}

size_t SDL_strlcat ( char * dst, const char * src, size_t maxlen );

namespace sym{
    typedef char * ( *SDL_strrev_handle )( char * string );
    static auto SDL_strrev = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_strrev" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_strrev" );
        }
        return ( SDL_strrev_handle )( dlsym_ptr );
    } ();
}

char * SDL_strrev ( char * string );

namespace sym{
    typedef char * ( *SDL_strupr_handle )( char * string );
    static auto SDL_strupr = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_strupr" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_strupr" );
        }
        return ( SDL_strupr_handle )( dlsym_ptr );
    } ();
}

char * SDL_strupr ( char * string );

namespace sym{
    typedef char * ( *SDL_strlwr_handle )( char * string );
    static auto SDL_strlwr = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_strlwr" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_strlwr" );
        }
        return ( SDL_strlwr_handle )( dlsym_ptr );
    } ();
}

char * SDL_strlwr ( char * string );

namespace sym{
    typedef char * ( *SDL_ltoa_handle )( long value, char * string, int radix );
    static auto SDL_ltoa = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_ltoa" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_ltoa" );
        }
        return ( SDL_ltoa_handle )( dlsym_ptr );
    } ();
}

char * SDL_ltoa ( long value, char * string, int radix );

namespace sym{
    typedef char * ( *SDL_ultoa_handle )( unsigned long value, char * string, int radix );
    static auto SDL_ultoa = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_ultoa" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_ultoa" );
        }
        return ( SDL_ultoa_handle )( dlsym_ptr );
    } ();
}

char * SDL_ultoa ( unsigned long value, char * string, int radix );

namespace sym{
    typedef char * ( *SDL_lltoa_handle )( Sint64 value, char * string, int radix );
    static auto SDL_lltoa = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_lltoa" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_lltoa" );
        }
        return ( SDL_lltoa_handle )( dlsym_ptr );
    } ();
}

char * SDL_lltoa ( Sint64 value, char * string, int radix );

namespace sym{
    typedef char * ( *SDL_ulltoa_handle )( Uint64 value, char * string, int radix );
    static auto SDL_ulltoa = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_ulltoa" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_ulltoa" );
        }
        return ( SDL_ulltoa_handle )( dlsym_ptr );
    } ();
}

char * SDL_ulltoa ( Uint64 value, char * string, int radix );

namespace sym{
    typedef size_t ( *SDL_iconv_handle )( iconv_t cd, const char ** inbuf, size_t * inbytesleft, char ** outbuf, size_t * outbytesleft );
    static auto SDL_iconv = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_iconv" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_iconv" );
        }
        return ( SDL_iconv_handle )( dlsym_ptr );
    } ();
}

size_t SDL_iconv ( iconv_t cd, const char ** inbuf, size_t * inbytesleft, char ** outbuf, size_t * outbytesleft );

namespace sym{
    typedef char * ( *SDL_iconv_string_handle )( const char * tocode, const char * fromcode, const char * inbuf, size_t inbytesleft );
    static auto SDL_iconv_string = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_iconv_string" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_iconv_string" );
        }
        return ( SDL_iconv_string_handle )( dlsym_ptr );
    } ();
}

char * SDL_iconv_string ( const char * tocode, const char * fromcode, const char * inbuf, size_t inbytesleft );

namespace sym{
    typedef void ( *SDL_SetError_handle )( const char * fmt );
    static auto SDL_SetError = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_SetError" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_SetError" );
        }
        return ( SDL_SetError_handle )( dlsym_ptr );
    } ();
}

void SDL_SetError ( const char * fmt );

namespace sym{
    typedef char * ( *SDL_GetError_handle )(  );
    static auto SDL_GetError = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetError" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetError" );
        }
        return ( SDL_GetError_handle )( dlsym_ptr );
    } ();
}

char * SDL_GetError (  );

namespace sym{
    typedef void ( *SDL_ClearError_handle )(  );
    static auto SDL_ClearError = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_ClearError" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_ClearError" );
        }
        return ( SDL_ClearError_handle )( dlsym_ptr );
    } ();
}

void SDL_ClearError (  );

namespace sym{
    typedef void ( *SDL_Error_handle )( SDL_errorcode code );
    static auto SDL_Error = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_Error" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_Error" );
        }
        return ( SDL_Error_handle )( dlsym_ptr );
    } ();
}

void SDL_Error ( SDL_errorcode code );

namespace sym{
    typedef SDL_mutex * ( *SDL_CreateMutex_handle )(  );
    static auto SDL_CreateMutex = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_CreateMutex" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_CreateMutex" );
        }
        return ( SDL_CreateMutex_handle )( dlsym_ptr );
    } ();
}

SDL_mutex * SDL_CreateMutex (  );

namespace sym{
    typedef int ( *SDL_mutexP_handle )( SDL_mutex * mutex );
    static auto SDL_mutexP = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_mutexP" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_mutexP" );
        }
        return ( SDL_mutexP_handle )( dlsym_ptr );
    } ();
}

int SDL_mutexP ( SDL_mutex * mutex );

namespace sym{
    typedef int ( *SDL_mutexV_handle )( SDL_mutex * mutex );
    static auto SDL_mutexV = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_mutexV" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_mutexV" );
        }
        return ( SDL_mutexV_handle )( dlsym_ptr );
    } ();
}

int SDL_mutexV ( SDL_mutex * mutex );

namespace sym{
    typedef void ( *SDL_DestroyMutex_handle )( SDL_mutex * mutex );
    static auto SDL_DestroyMutex = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_DestroyMutex" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_DestroyMutex" );
        }
        return ( SDL_DestroyMutex_handle )( dlsym_ptr );
    } ();
}

void SDL_DestroyMutex ( SDL_mutex * mutex );

namespace sym{
    typedef SDL_sem * ( *SDL_CreateSemaphore_handle )( Uint32 initial_value );
    static auto SDL_CreateSemaphore = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_CreateSemaphore" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_CreateSemaphore" );
        }
        return ( SDL_CreateSemaphore_handle )( dlsym_ptr );
    } ();
}

SDL_sem * SDL_CreateSemaphore ( Uint32 initial_value );

namespace sym{
    typedef void ( *SDL_DestroySemaphore_handle )( SDL_sem * sem );
    static auto SDL_DestroySemaphore = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_DestroySemaphore" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_DestroySemaphore" );
        }
        return ( SDL_DestroySemaphore_handle )( dlsym_ptr );
    } ();
}

void SDL_DestroySemaphore ( SDL_sem * sem );

namespace sym{
    typedef int ( *SDL_SemWait_handle )( SDL_sem * sem );
    static auto SDL_SemWait = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_SemWait" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_SemWait" );
        }
        return ( SDL_SemWait_handle )( dlsym_ptr );
    } ();
}

int SDL_SemWait ( SDL_sem * sem );

namespace sym{
    typedef int ( *SDL_SemTryWait_handle )( SDL_sem * sem );
    static auto SDL_SemTryWait = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_SemTryWait" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_SemTryWait" );
        }
        return ( SDL_SemTryWait_handle )( dlsym_ptr );
    } ();
}

int SDL_SemTryWait ( SDL_sem * sem );

namespace sym{
    typedef int ( *SDL_SemWaitTimeout_handle )( SDL_sem * sem, Uint32 ms );
    static auto SDL_SemWaitTimeout = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_SemWaitTimeout" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_SemWaitTimeout" );
        }
        return ( SDL_SemWaitTimeout_handle )( dlsym_ptr );
    } ();
}

int SDL_SemWaitTimeout ( SDL_sem * sem, Uint32 ms );

namespace sym{
    typedef int ( *SDL_SemPost_handle )( SDL_sem * sem );
    static auto SDL_SemPost = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_SemPost" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_SemPost" );
        }
        return ( SDL_SemPost_handle )( dlsym_ptr );
    } ();
}

int SDL_SemPost ( SDL_sem * sem );

namespace sym{
    typedef Uint32 ( *SDL_SemValue_handle )( SDL_sem * sem );
    static auto SDL_SemValue = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_SemValue" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_SemValue" );
        }
        return ( SDL_SemValue_handle )( dlsym_ptr );
    } ();
}

Uint32 SDL_SemValue ( SDL_sem * sem );

namespace sym{
    typedef SDL_cond * ( *SDL_CreateCond_handle )(  );
    static auto SDL_CreateCond = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_CreateCond" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_CreateCond" );
        }
        return ( SDL_CreateCond_handle )( dlsym_ptr );
    } ();
}

SDL_cond * SDL_CreateCond (  );

namespace sym{
    typedef void ( *SDL_DestroyCond_handle )( SDL_cond * cond );
    static auto SDL_DestroyCond = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_DestroyCond" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_DestroyCond" );
        }
        return ( SDL_DestroyCond_handle )( dlsym_ptr );
    } ();
}

void SDL_DestroyCond ( SDL_cond * cond );

namespace sym{
    typedef int ( *SDL_CondSignal_handle )( SDL_cond * cond );
    static auto SDL_CondSignal = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_CondSignal" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_CondSignal" );
        }
        return ( SDL_CondSignal_handle )( dlsym_ptr );
    } ();
}

int SDL_CondSignal ( SDL_cond * cond );

namespace sym{
    typedef int ( *SDL_CondBroadcast_handle )( SDL_cond * cond );
    static auto SDL_CondBroadcast = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_CondBroadcast" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_CondBroadcast" );
        }
        return ( SDL_CondBroadcast_handle )( dlsym_ptr );
    } ();
}

int SDL_CondBroadcast ( SDL_cond * cond );

namespace sym{
    typedef int ( *SDL_CondWait_handle )( SDL_cond * cond, SDL_mutex * mut );
    static auto SDL_CondWait = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_CondWait" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_CondWait" );
        }
        return ( SDL_CondWait_handle )( dlsym_ptr );
    } ();
}

int SDL_CondWait ( SDL_cond * cond, SDL_mutex * mut );

namespace sym{
    typedef int ( *SDL_CondWaitTimeout_handle )( SDL_cond * cond, SDL_mutex * mutex, Uint32 ms );
    static auto SDL_CondWaitTimeout = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_CondWaitTimeout" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_CondWaitTimeout" );
        }
        return ( SDL_CondWaitTimeout_handle )( dlsym_ptr );
    } ();
}

int SDL_CondWaitTimeout ( SDL_cond * cond, SDL_mutex * mutex, Uint32 ms );

namespace sym{
    typedef SDL_Thread * ( *SDL_CreateThread_handle )( int (*fn)(void *), void * data );
    static auto SDL_CreateThread = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_CreateThread" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_CreateThread" );
        }
        return ( SDL_CreateThread_handle )( dlsym_ptr );
    } ();
}

SDL_Thread * SDL_CreateThread ( int (*fn)(void *), void * data );

namespace sym{
    typedef Uint32 ( *SDL_ThreadID_handle )(  );
    static auto SDL_ThreadID = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_ThreadID" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_ThreadID" );
        }
        return ( SDL_ThreadID_handle )( dlsym_ptr );
    } ();
}

Uint32 SDL_ThreadID (  );

namespace sym{
    typedef Uint32 ( *SDL_GetThreadID_handle )( SDL_Thread * thread );
    static auto SDL_GetThreadID = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetThreadID" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetThreadID" );
        }
        return ( SDL_GetThreadID_handle )( dlsym_ptr );
    } ();
}

Uint32 SDL_GetThreadID ( SDL_Thread * thread );

namespace sym{
    typedef void ( *SDL_WaitThread_handle )( SDL_Thread * thread, int * status );
    static auto SDL_WaitThread = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_WaitThread" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_WaitThread" );
        }
        return ( SDL_WaitThread_handle )( dlsym_ptr );
    } ();
}

void SDL_WaitThread ( SDL_Thread * thread, int * status );

namespace sym{
    typedef void ( *SDL_KillThread_handle )( SDL_Thread * thread );
    static auto SDL_KillThread = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_KillThread" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_KillThread" );
        }
        return ( SDL_KillThread_handle )( dlsym_ptr );
    } ();
}

void SDL_KillThread ( SDL_Thread * thread );

namespace sym{
    typedef SDL_RWops * ( *SDL_RWFromFile_handle )( const char * file, const char * mode );
    static auto SDL_RWFromFile = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_RWFromFile" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_RWFromFile" );
        }
        return ( SDL_RWFromFile_handle )( dlsym_ptr );
    } ();
}

SDL_RWops * SDL_RWFromFile ( const char * file, const char * mode );

namespace sym{
    typedef SDL_RWops * ( *SDL_RWFromFP_handle )( FILE * fp, int autoclose );
    static auto SDL_RWFromFP = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_RWFromFP" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_RWFromFP" );
        }
        return ( SDL_RWFromFP_handle )( dlsym_ptr );
    } ();
}

SDL_RWops * SDL_RWFromFP ( FILE * fp, int autoclose );

namespace sym{
    typedef SDL_RWops * ( *SDL_RWFromMem_handle )( void * mem, int size );
    static auto SDL_RWFromMem = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_RWFromMem" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_RWFromMem" );
        }
        return ( SDL_RWFromMem_handle )( dlsym_ptr );
    } ();
}

SDL_RWops * SDL_RWFromMem ( void * mem, int size );

namespace sym{
    typedef SDL_RWops * ( *SDL_RWFromConstMem_handle )( const void * mem, int size );
    static auto SDL_RWFromConstMem = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_RWFromConstMem" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_RWFromConstMem" );
        }
        return ( SDL_RWFromConstMem_handle )( dlsym_ptr );
    } ();
}

SDL_RWops * SDL_RWFromConstMem ( const void * mem, int size );

namespace sym{
    typedef SDL_RWops * ( *SDL_AllocRW_handle )(  );
    static auto SDL_AllocRW = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_AllocRW" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_AllocRW" );
        }
        return ( SDL_AllocRW_handle )( dlsym_ptr );
    } ();
}

SDL_RWops * SDL_AllocRW (  );

namespace sym{
    typedef void ( *SDL_FreeRW_handle )( SDL_RWops * area );
    static auto SDL_FreeRW = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_FreeRW" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_FreeRW" );
        }
        return ( SDL_FreeRW_handle )( dlsym_ptr );
    } ();
}

void SDL_FreeRW ( SDL_RWops * area );

namespace sym{
    typedef Uint16 ( *SDL_ReadLE16_handle )( SDL_RWops * src );
    static auto SDL_ReadLE16 = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_ReadLE16" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_ReadLE16" );
        }
        return ( SDL_ReadLE16_handle )( dlsym_ptr );
    } ();
}

Uint16 SDL_ReadLE16 ( SDL_RWops * src );

namespace sym{
    typedef Uint16 ( *SDL_ReadBE16_handle )( SDL_RWops * src );
    static auto SDL_ReadBE16 = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_ReadBE16" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_ReadBE16" );
        }
        return ( SDL_ReadBE16_handle )( dlsym_ptr );
    } ();
}

Uint16 SDL_ReadBE16 ( SDL_RWops * src );

namespace sym{
    typedef Uint32 ( *SDL_ReadLE32_handle )( SDL_RWops * src );
    static auto SDL_ReadLE32 = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_ReadLE32" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_ReadLE32" );
        }
        return ( SDL_ReadLE32_handle )( dlsym_ptr );
    } ();
}

Uint32 SDL_ReadLE32 ( SDL_RWops * src );

namespace sym{
    typedef Uint32 ( *SDL_ReadBE32_handle )( SDL_RWops * src );
    static auto SDL_ReadBE32 = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_ReadBE32" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_ReadBE32" );
        }
        return ( SDL_ReadBE32_handle )( dlsym_ptr );
    } ();
}

Uint32 SDL_ReadBE32 ( SDL_RWops * src );

namespace sym{
    typedef Uint64 ( *SDL_ReadLE64_handle )( SDL_RWops * src );
    static auto SDL_ReadLE64 = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_ReadLE64" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_ReadLE64" );
        }
        return ( SDL_ReadLE64_handle )( dlsym_ptr );
    } ();
}

Uint64 SDL_ReadLE64 ( SDL_RWops * src );

namespace sym{
    typedef Uint64 ( *SDL_ReadBE64_handle )( SDL_RWops * src );
    static auto SDL_ReadBE64 = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_ReadBE64" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_ReadBE64" );
        }
        return ( SDL_ReadBE64_handle )( dlsym_ptr );
    } ();
}

Uint64 SDL_ReadBE64 ( SDL_RWops * src );

namespace sym{
    typedef int ( *SDL_WriteLE16_handle )( SDL_RWops * dst, Uint16 value );
    static auto SDL_WriteLE16 = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_WriteLE16" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_WriteLE16" );
        }
        return ( SDL_WriteLE16_handle )( dlsym_ptr );
    } ();
}

int SDL_WriteLE16 ( SDL_RWops * dst, Uint16 value );

namespace sym{
    typedef int ( *SDL_WriteBE16_handle )( SDL_RWops * dst, Uint16 value );
    static auto SDL_WriteBE16 = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_WriteBE16" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_WriteBE16" );
        }
        return ( SDL_WriteBE16_handle )( dlsym_ptr );
    } ();
}

int SDL_WriteBE16 ( SDL_RWops * dst, Uint16 value );

namespace sym{
    typedef int ( *SDL_WriteLE32_handle )( SDL_RWops * dst, Uint32 value );
    static auto SDL_WriteLE32 = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_WriteLE32" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_WriteLE32" );
        }
        return ( SDL_WriteLE32_handle )( dlsym_ptr );
    } ();
}

int SDL_WriteLE32 ( SDL_RWops * dst, Uint32 value );

namespace sym{
    typedef int ( *SDL_WriteBE32_handle )( SDL_RWops * dst, Uint32 value );
    static auto SDL_WriteBE32 = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_WriteBE32" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_WriteBE32" );
        }
        return ( SDL_WriteBE32_handle )( dlsym_ptr );
    } ();
}

int SDL_WriteBE32 ( SDL_RWops * dst, Uint32 value );

namespace sym{
    typedef int ( *SDL_WriteLE64_handle )( SDL_RWops * dst, Uint64 value );
    static auto SDL_WriteLE64 = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_WriteLE64" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_WriteLE64" );
        }
        return ( SDL_WriteLE64_handle )( dlsym_ptr );
    } ();
}

int SDL_WriteLE64 ( SDL_RWops * dst, Uint64 value );

namespace sym{
    typedef int ( *SDL_WriteBE64_handle )( SDL_RWops * dst, Uint64 value );
    static auto SDL_WriteBE64 = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_WriteBE64" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_WriteBE64" );
        }
        return ( SDL_WriteBE64_handle )( dlsym_ptr );
    } ();
}

int SDL_WriteBE64 ( SDL_RWops * dst, Uint64 value );

namespace sym{
    typedef int ( *SDL_AudioInit_handle )( const char * driver_name );
    static auto SDL_AudioInit = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_AudioInit" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_AudioInit" );
        }
        return ( SDL_AudioInit_handle )( dlsym_ptr );
    } ();
}

int SDL_AudioInit ( const char * driver_name );

namespace sym{
    typedef void ( *SDL_AudioQuit_handle )(  );
    static auto SDL_AudioQuit = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_AudioQuit" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_AudioQuit" );
        }
        return ( SDL_AudioQuit_handle )( dlsym_ptr );
    } ();
}

void SDL_AudioQuit (  );

namespace sym{
    typedef char * ( *SDL_AudioDriverName_handle )( char * namebuf, int maxlen );
    static auto SDL_AudioDriverName = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_AudioDriverName" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_AudioDriverName" );
        }
        return ( SDL_AudioDriverName_handle )( dlsym_ptr );
    } ();
}

char * SDL_AudioDriverName ( char * namebuf, int maxlen );

namespace sym{
    typedef int ( *SDL_OpenAudio_handle )( SDL_AudioSpec * desired, SDL_AudioSpec * obtained );
    static auto SDL_OpenAudio = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_OpenAudio" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_OpenAudio" );
        }
        return ( SDL_OpenAudio_handle )( dlsym_ptr );
    } ();
}

int SDL_OpenAudio ( SDL_AudioSpec * desired, SDL_AudioSpec * obtained );

namespace sym{
    typedef SDL_audiostatus ( *SDL_GetAudioStatus_handle )(  );
    static auto SDL_GetAudioStatus = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetAudioStatus" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetAudioStatus" );
        }
        return ( SDL_GetAudioStatus_handle )( dlsym_ptr );
    } ();
}

SDL_audiostatus SDL_GetAudioStatus (  );

namespace sym{
    typedef void ( *SDL_PauseAudio_handle )( int pause_on );
    static auto SDL_PauseAudio = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_PauseAudio" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_PauseAudio" );
        }
        return ( SDL_PauseAudio_handle )( dlsym_ptr );
    } ();
}

void SDL_PauseAudio ( int pause_on );

namespace sym{
    typedef SDL_AudioSpec * ( *SDL_LoadWAV_RW_handle )( SDL_RWops * src, int freesrc, SDL_AudioSpec * spec, Uint8 ** audio_buf, Uint32 * audio_len );
    static auto SDL_LoadWAV_RW = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_LoadWAV_RW" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_LoadWAV_RW" );
        }
        return ( SDL_LoadWAV_RW_handle )( dlsym_ptr );
    } ();
}

SDL_AudioSpec * SDL_LoadWAV_RW ( SDL_RWops * src, int freesrc, SDL_AudioSpec * spec, Uint8 ** audio_buf, Uint32 * audio_len );

namespace sym{
    typedef void ( *SDL_FreeWAV_handle )( Uint8 * audio_buf );
    static auto SDL_FreeWAV = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_FreeWAV" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_FreeWAV" );
        }
        return ( SDL_FreeWAV_handle )( dlsym_ptr );
    } ();
}

void SDL_FreeWAV ( Uint8 * audio_buf );

namespace sym{
    typedef int ( *SDL_BuildAudioCVT_handle )( SDL_AudioCVT * cvt, Uint16 src_format, Uint8 src_channels, int src_rate, Uint16 dst_format, Uint8 dst_channels, int dst_rate );
    static auto SDL_BuildAudioCVT = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_BuildAudioCVT" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_BuildAudioCVT" );
        }
        return ( SDL_BuildAudioCVT_handle )( dlsym_ptr );
    } ();
}

int SDL_BuildAudioCVT ( SDL_AudioCVT * cvt, Uint16 src_format, Uint8 src_channels, int src_rate, Uint16 dst_format, Uint8 dst_channels, int dst_rate );

namespace sym{
    typedef int ( *SDL_ConvertAudio_handle )( SDL_AudioCVT * cvt );
    static auto SDL_ConvertAudio = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_ConvertAudio" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_ConvertAudio" );
        }
        return ( SDL_ConvertAudio_handle )( dlsym_ptr );
    } ();
}

int SDL_ConvertAudio ( SDL_AudioCVT * cvt );

namespace sym{
    typedef void ( *SDL_MixAudio_handle )( Uint8 * dst, const Uint8 * src, Uint32 len, int volume );
    static auto SDL_MixAudio = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_MixAudio" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_MixAudio" );
        }
        return ( SDL_MixAudio_handle )( dlsym_ptr );
    } ();
}

void SDL_MixAudio ( Uint8 * dst, const Uint8 * src, Uint32 len, int volume );

namespace sym{
    typedef void ( *SDL_LockAudio_handle )(  );
    static auto SDL_LockAudio = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_LockAudio" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_LockAudio" );
        }
        return ( SDL_LockAudio_handle )( dlsym_ptr );
    } ();
}

void SDL_LockAudio (  );

namespace sym{
    typedef void ( *SDL_UnlockAudio_handle )(  );
    static auto SDL_UnlockAudio = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_UnlockAudio" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_UnlockAudio" );
        }
        return ( SDL_UnlockAudio_handle )( dlsym_ptr );
    } ();
}

void SDL_UnlockAudio (  );

namespace sym{
    typedef void ( *SDL_CloseAudio_handle )(  );
    static auto SDL_CloseAudio = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_CloseAudio" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_CloseAudio" );
        }
        return ( SDL_CloseAudio_handle )( dlsym_ptr );
    } ();
}

void SDL_CloseAudio (  );

namespace sym{
    typedef int ( *SDL_CDNumDrives_handle )(  );
    static auto SDL_CDNumDrives = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_CDNumDrives" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_CDNumDrives" );
        }
        return ( SDL_CDNumDrives_handle )( dlsym_ptr );
    } ();
}

int SDL_CDNumDrives (  );

namespace sym{
    typedef const char * ( *SDL_CDName_handle )( int drive );
    static auto SDL_CDName = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_CDName" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_CDName" );
        }
        return ( SDL_CDName_handle )( dlsym_ptr );
    } ();
}

const char * SDL_CDName ( int drive );

namespace sym{
    typedef SDL_CD * ( *SDL_CDOpen_handle )( int drive );
    static auto SDL_CDOpen = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_CDOpen" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_CDOpen" );
        }
        return ( SDL_CDOpen_handle )( dlsym_ptr );
    } ();
}

SDL_CD * SDL_CDOpen ( int drive );

namespace sym{
    typedef CDstatus ( *SDL_CDStatus_handle )( SDL_CD * cdrom );
    static auto SDL_CDStatus = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_CDStatus" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_CDStatus" );
        }
        return ( SDL_CDStatus_handle )( dlsym_ptr );
    } ();
}

CDstatus SDL_CDStatus ( SDL_CD * cdrom );

namespace sym{
    typedef int ( *SDL_CDPlayTracks_handle )( SDL_CD * cdrom, int start_track, int start_frame, int ntracks, int nframes );
    static auto SDL_CDPlayTracks = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_CDPlayTracks" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_CDPlayTracks" );
        }
        return ( SDL_CDPlayTracks_handle )( dlsym_ptr );
    } ();
}

int SDL_CDPlayTracks ( SDL_CD * cdrom, int start_track, int start_frame, int ntracks, int nframes );

namespace sym{
    typedef int ( *SDL_CDPlay_handle )( SDL_CD * cdrom, int start, int length );
    static auto SDL_CDPlay = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_CDPlay" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_CDPlay" );
        }
        return ( SDL_CDPlay_handle )( dlsym_ptr );
    } ();
}

int SDL_CDPlay ( SDL_CD * cdrom, int start, int length );

namespace sym{
    typedef int ( *SDL_CDPause_handle )( SDL_CD * cdrom );
    static auto SDL_CDPause = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_CDPause" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_CDPause" );
        }
        return ( SDL_CDPause_handle )( dlsym_ptr );
    } ();
}

int SDL_CDPause ( SDL_CD * cdrom );

namespace sym{
    typedef int ( *SDL_CDResume_handle )( SDL_CD * cdrom );
    static auto SDL_CDResume = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_CDResume" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_CDResume" );
        }
        return ( SDL_CDResume_handle )( dlsym_ptr );
    } ();
}

int SDL_CDResume ( SDL_CD * cdrom );

namespace sym{
    typedef int ( *SDL_CDStop_handle )( SDL_CD * cdrom );
    static auto SDL_CDStop = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_CDStop" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_CDStop" );
        }
        return ( SDL_CDStop_handle )( dlsym_ptr );
    } ();
}

int SDL_CDStop ( SDL_CD * cdrom );

namespace sym{
    typedef int ( *SDL_CDEject_handle )( SDL_CD * cdrom );
    static auto SDL_CDEject = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_CDEject" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_CDEject" );
        }
        return ( SDL_CDEject_handle )( dlsym_ptr );
    } ();
}

int SDL_CDEject ( SDL_CD * cdrom );

namespace sym{
    typedef void ( *SDL_CDClose_handle )( SDL_CD * cdrom );
    static auto SDL_CDClose = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_CDClose" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_CDClose" );
        }
        return ( SDL_CDClose_handle )( dlsym_ptr );
    } ();
}

void SDL_CDClose ( SDL_CD * cdrom );

namespace sym{
    typedef SDL_bool ( *SDL_HasRDTSC_handle )(  );
    static auto SDL_HasRDTSC = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_HasRDTSC" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_HasRDTSC" );
        }
        return ( SDL_HasRDTSC_handle )( dlsym_ptr );
    } ();
}

SDL_bool SDL_HasRDTSC (  );

namespace sym{
    typedef SDL_bool ( *SDL_HasMMX_handle )(  );
    static auto SDL_HasMMX = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_HasMMX" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_HasMMX" );
        }
        return ( SDL_HasMMX_handle )( dlsym_ptr );
    } ();
}

SDL_bool SDL_HasMMX (  );

namespace sym{
    typedef SDL_bool ( *SDL_HasMMXExt_handle )(  );
    static auto SDL_HasMMXExt = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_HasMMXExt" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_HasMMXExt" );
        }
        return ( SDL_HasMMXExt_handle )( dlsym_ptr );
    } ();
}

SDL_bool SDL_HasMMXExt (  );

namespace sym{
    typedef SDL_bool ( *SDL_Has3DNow_handle )(  );
    static auto SDL_Has3DNow = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_Has3DNow" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_Has3DNow" );
        }
        return ( SDL_Has3DNow_handle )( dlsym_ptr );
    } ();
}

SDL_bool SDL_Has3DNow (  );

namespace sym{
    typedef SDL_bool ( *SDL_Has3DNowExt_handle )(  );
    static auto SDL_Has3DNowExt = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_Has3DNowExt" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_Has3DNowExt" );
        }
        return ( SDL_Has3DNowExt_handle )( dlsym_ptr );
    } ();
}

SDL_bool SDL_Has3DNowExt (  );

namespace sym{
    typedef SDL_bool ( *SDL_HasSSE_handle )(  );
    static auto SDL_HasSSE = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_HasSSE" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_HasSSE" );
        }
        return ( SDL_HasSSE_handle )( dlsym_ptr );
    } ();
}

SDL_bool SDL_HasSSE (  );

namespace sym{
    typedef SDL_bool ( *SDL_HasSSE2_handle )(  );
    static auto SDL_HasSSE2 = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_HasSSE2" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_HasSSE2" );
        }
        return ( SDL_HasSSE2_handle )( dlsym_ptr );
    } ();
}

SDL_bool SDL_HasSSE2 (  );

namespace sym{
    typedef SDL_bool ( *SDL_HasAltiVec_handle )(  );
    static auto SDL_HasAltiVec = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_HasAltiVec" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_HasAltiVec" );
        }
        return ( SDL_HasAltiVec_handle )( dlsym_ptr );
    } ();
}

SDL_bool SDL_HasAltiVec (  );

namespace sym{
    typedef Uint8 ( *SDL_GetAppState_handle )(  );
    static auto SDL_GetAppState = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetAppState" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetAppState" );
        }
        return ( SDL_GetAppState_handle )( dlsym_ptr );
    } ();
}

Uint8 SDL_GetAppState (  );

namespace sym{
    typedef int ( *SDL_EnableUNICODE_handle )( int enable );
    static auto SDL_EnableUNICODE = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_EnableUNICODE" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_EnableUNICODE" );
        }
        return ( SDL_EnableUNICODE_handle )( dlsym_ptr );
    } ();
}

int SDL_EnableUNICODE ( int enable );

namespace sym{
    typedef int ( *SDL_EnableKeyRepeat_handle )( int delay, int interval );
    static auto SDL_EnableKeyRepeat = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_EnableKeyRepeat" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_EnableKeyRepeat" );
        }
        return ( SDL_EnableKeyRepeat_handle )( dlsym_ptr );
    } ();
}

int SDL_EnableKeyRepeat ( int delay, int interval );

namespace sym{
    typedef void ( *SDL_GetKeyRepeat_handle )( int * delay, int * interval );
    static auto SDL_GetKeyRepeat = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetKeyRepeat" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetKeyRepeat" );
        }
        return ( SDL_GetKeyRepeat_handle )( dlsym_ptr );
    } ();
}

void SDL_GetKeyRepeat ( int * delay, int * interval );

namespace sym{
    typedef Uint8 * ( *SDL_GetKeyState_handle )( int * numkeys );
    static auto SDL_GetKeyState = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetKeyState" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetKeyState" );
        }
        return ( SDL_GetKeyState_handle )( dlsym_ptr );
    } ();
}

Uint8 * SDL_GetKeyState ( int * numkeys );

namespace sym{
    typedef SDLMod ( *SDL_GetModState_handle )(  );
    static auto SDL_GetModState = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetModState" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetModState" );
        }
        return ( SDL_GetModState_handle )( dlsym_ptr );
    } ();
}

SDLMod SDL_GetModState (  );

namespace sym{
    typedef void ( *SDL_SetModState_handle )( SDLMod modstate );
    static auto SDL_SetModState = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_SetModState" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_SetModState" );
        }
        return ( SDL_SetModState_handle )( dlsym_ptr );
    } ();
}

void SDL_SetModState ( SDLMod modstate );

namespace sym{
    typedef char * ( *SDL_GetKeyName_handle )( SDLKey key );
    static auto SDL_GetKeyName = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetKeyName" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetKeyName" );
        }
        return ( SDL_GetKeyName_handle )( dlsym_ptr );
    } ();
}

char * SDL_GetKeyName ( SDLKey key );

namespace sym{
    typedef int ( *SDL_VideoInit_handle )( const char * driver_name, Uint32 flags );
    static auto SDL_VideoInit = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_VideoInit" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_VideoInit" );
        }
        return ( SDL_VideoInit_handle )( dlsym_ptr );
    } ();
}

int SDL_VideoInit ( const char * driver_name, Uint32 flags );

namespace sym{
    typedef void ( *SDL_VideoQuit_handle )(  );
    static auto SDL_VideoQuit = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_VideoQuit" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_VideoQuit" );
        }
        return ( SDL_VideoQuit_handle )( dlsym_ptr );
    } ();
}

void SDL_VideoQuit (  );

namespace sym{
    typedef char * ( *SDL_VideoDriverName_handle )( char * namebuf, int maxlen );
    static auto SDL_VideoDriverName = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_VideoDriverName" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_VideoDriverName" );
        }
        return ( SDL_VideoDriverName_handle )( dlsym_ptr );
    } ();
}

char * SDL_VideoDriverName ( char * namebuf, int maxlen );

namespace sym{
    typedef SDL_Surface * ( *SDL_GetVideoSurface_handle )(  );
    static auto SDL_GetVideoSurface = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetVideoSurface" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetVideoSurface" );
        }
        return ( SDL_GetVideoSurface_handle )( dlsym_ptr );
    } ();
}

SDL_Surface * SDL_GetVideoSurface (  );

namespace sym{
    typedef const SDL_VideoInfo * ( *SDL_GetVideoInfo_handle )(  );
    static auto SDL_GetVideoInfo = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetVideoInfo" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetVideoInfo" );
        }
        return ( SDL_GetVideoInfo_handle )( dlsym_ptr );
    } ();
}

const SDL_VideoInfo * SDL_GetVideoInfo (  );

namespace sym{
    typedef int ( *SDL_VideoModeOK_handle )( int width, int height, int bpp, Uint32 flags );
    static auto SDL_VideoModeOK = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_VideoModeOK" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_VideoModeOK" );
        }
        return ( SDL_VideoModeOK_handle )( dlsym_ptr );
    } ();
}

int SDL_VideoModeOK ( int width, int height, int bpp, Uint32 flags );

namespace sym{
    typedef SDL_Rect ** ( *SDL_ListModes_handle )( SDL_PixelFormat * format, Uint32 flags );
    static auto SDL_ListModes = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_ListModes" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_ListModes" );
        }
        return ( SDL_ListModes_handle )( dlsym_ptr );
    } ();
}

SDL_Rect ** SDL_ListModes ( SDL_PixelFormat * format, Uint32 flags );

namespace sym{
    typedef SDL_Surface * ( *SDL_SetVideoMode_handle )( int width, int height, int bpp, Uint32 flags );
    static auto SDL_SetVideoMode = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_SetVideoMode" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_SetVideoMode" );
        }
        return ( SDL_SetVideoMode_handle )( dlsym_ptr );
    } ();
}

SDL_Surface * SDL_SetVideoMode ( int width, int height, int bpp, Uint32 flags );

namespace sym{
    typedef void ( *SDL_UpdateRects_handle )( SDL_Surface * screen, int numrects, SDL_Rect * rects );
    static auto SDL_UpdateRects = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_UpdateRects" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_UpdateRects" );
        }
        return ( SDL_UpdateRects_handle )( dlsym_ptr );
    } ();
}

void SDL_UpdateRects ( SDL_Surface * screen, int numrects, SDL_Rect * rects );

namespace sym{
    typedef void ( *SDL_UpdateRect_handle )( SDL_Surface * screen, Sint32 x, Sint32 y, Uint32 w, Uint32 h );
    static auto SDL_UpdateRect = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_UpdateRect" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_UpdateRect" );
        }
        return ( SDL_UpdateRect_handle )( dlsym_ptr );
    } ();
}

void SDL_UpdateRect ( SDL_Surface * screen, Sint32 x, Sint32 y, Uint32 w, Uint32 h );

namespace sym{
    typedef int ( *SDL_Flip_handle )( SDL_Surface * screen );
    static auto SDL_Flip = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_Flip" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_Flip" );
        }
        return ( SDL_Flip_handle )( dlsym_ptr );
    } ();
}

int SDL_Flip ( SDL_Surface * screen );

namespace sym{
    typedef int ( *SDL_SetGamma_handle )( float red, float green, float blue );
    static auto SDL_SetGamma = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_SetGamma" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_SetGamma" );
        }
        return ( SDL_SetGamma_handle )( dlsym_ptr );
    } ();
}

int SDL_SetGamma ( float red, float green, float blue );

namespace sym{
    typedef int ( *SDL_SetGammaRamp_handle )( const Uint16 * red, const Uint16 * green, const Uint16 * blue );
    static auto SDL_SetGammaRamp = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_SetGammaRamp" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_SetGammaRamp" );
        }
        return ( SDL_SetGammaRamp_handle )( dlsym_ptr );
    } ();
}

int SDL_SetGammaRamp ( const Uint16 * red, const Uint16 * green, const Uint16 * blue );

namespace sym{
    typedef int ( *SDL_GetGammaRamp_handle )( Uint16 * red, Uint16 * green, Uint16 * blue );
    static auto SDL_GetGammaRamp = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetGammaRamp" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetGammaRamp" );
        }
        return ( SDL_GetGammaRamp_handle )( dlsym_ptr );
    } ();
}

int SDL_GetGammaRamp ( Uint16 * red, Uint16 * green, Uint16 * blue );

namespace sym{
    typedef int ( *SDL_SetColors_handle )( SDL_Surface * surface, SDL_Color * colors, int firstcolor, int ncolors );
    static auto SDL_SetColors = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_SetColors" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_SetColors" );
        }
        return ( SDL_SetColors_handle )( dlsym_ptr );
    } ();
}

int SDL_SetColors ( SDL_Surface * surface, SDL_Color * colors, int firstcolor, int ncolors );

namespace sym{
    typedef int ( *SDL_SetPalette_handle )( SDL_Surface * surface, int flags, SDL_Color * colors, int firstcolor, int ncolors );
    static auto SDL_SetPalette = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_SetPalette" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_SetPalette" );
        }
        return ( SDL_SetPalette_handle )( dlsym_ptr );
    } ();
}

int SDL_SetPalette ( SDL_Surface * surface, int flags, SDL_Color * colors, int firstcolor, int ncolors );

namespace sym{
    typedef Uint32 ( *SDL_MapRGB_handle )( const SDL_PixelFormat *const format, const Uint8 r, const Uint8 g, const Uint8 b );
    static auto SDL_MapRGB = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_MapRGB" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_MapRGB" );
        }
        return ( SDL_MapRGB_handle )( dlsym_ptr );
    } ();
}

Uint32 SDL_MapRGB ( const SDL_PixelFormat *const format, const Uint8 r, const Uint8 g, const Uint8 b );

namespace sym{
    typedef Uint32 ( *SDL_MapRGBA_handle )( const SDL_PixelFormat *const format, const Uint8 r, const Uint8 g, const Uint8 b, const Uint8 a );
    static auto SDL_MapRGBA = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_MapRGBA" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_MapRGBA" );
        }
        return ( SDL_MapRGBA_handle )( dlsym_ptr );
    } ();
}

Uint32 SDL_MapRGBA ( const SDL_PixelFormat *const format, const Uint8 r, const Uint8 g, const Uint8 b, const Uint8 a );

namespace sym{
    typedef void ( *SDL_GetRGB_handle )( Uint32 pixel, const SDL_PixelFormat *const fmt, Uint8 * r, Uint8 * g, Uint8 * b );
    static auto SDL_GetRGB = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetRGB" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetRGB" );
        }
        return ( SDL_GetRGB_handle )( dlsym_ptr );
    } ();
}

void SDL_GetRGB ( Uint32 pixel, const SDL_PixelFormat *const fmt, Uint8 * r, Uint8 * g, Uint8 * b );

namespace sym{
    typedef void ( *SDL_GetRGBA_handle )( Uint32 pixel, const SDL_PixelFormat *const fmt, Uint8 * r, Uint8 * g, Uint8 * b, Uint8 * a );
    static auto SDL_GetRGBA = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetRGBA" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetRGBA" );
        }
        return ( SDL_GetRGBA_handle )( dlsym_ptr );
    } ();
}

void SDL_GetRGBA ( Uint32 pixel, const SDL_PixelFormat *const fmt, Uint8 * r, Uint8 * g, Uint8 * b, Uint8 * a );

namespace sym{
    typedef SDL_Surface * ( *SDL_CreateRGBSurface_handle )( Uint32 flags, int width, int height, int depth, Uint32 Rmask, Uint32 Gmask, Uint32 Bmask, Uint32 Amask );
    static auto SDL_CreateRGBSurface = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_CreateRGBSurface" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_CreateRGBSurface" );
        }
        return ( SDL_CreateRGBSurface_handle )( dlsym_ptr );
    } ();
}

SDL_Surface * SDL_CreateRGBSurface ( Uint32 flags, int width, int height, int depth, Uint32 Rmask, Uint32 Gmask, Uint32 Bmask, Uint32 Amask );

namespace sym{
    typedef SDL_Surface * ( *SDL_CreateRGBSurfaceFrom_handle )( void * pixels, int width, int height, int depth, int pitch, Uint32 Rmask, Uint32 Gmask, Uint32 Bmask, Uint32 Amask );
    static auto SDL_CreateRGBSurfaceFrom = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_CreateRGBSurfaceFrom" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_CreateRGBSurfaceFrom" );
        }
        return ( SDL_CreateRGBSurfaceFrom_handle )( dlsym_ptr );
    } ();
}

SDL_Surface * SDL_CreateRGBSurfaceFrom ( void * pixels, int width, int height, int depth, int pitch, Uint32 Rmask, Uint32 Gmask, Uint32 Bmask, Uint32 Amask );

namespace sym{
    typedef void ( *SDL_FreeSurface_handle )( SDL_Surface * surface );
    static auto SDL_FreeSurface = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_FreeSurface" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_FreeSurface" );
        }
        return ( SDL_FreeSurface_handle )( dlsym_ptr );
    } ();
}

void SDL_FreeSurface ( SDL_Surface * surface );

namespace sym{
    typedef int ( *SDL_LockSurface_handle )( SDL_Surface * surface );
    static auto SDL_LockSurface = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_LockSurface" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_LockSurface" );
        }
        return ( SDL_LockSurface_handle )( dlsym_ptr );
    } ();
}

int SDL_LockSurface ( SDL_Surface * surface );

namespace sym{
    typedef void ( *SDL_UnlockSurface_handle )( SDL_Surface * surface );
    static auto SDL_UnlockSurface = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_UnlockSurface" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_UnlockSurface" );
        }
        return ( SDL_UnlockSurface_handle )( dlsym_ptr );
    } ();
}

void SDL_UnlockSurface ( SDL_Surface * surface );

namespace sym{
    typedef SDL_Surface * ( *SDL_LoadBMP_RW_handle )( SDL_RWops * src, int freesrc );
    static auto SDL_LoadBMP_RW = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_LoadBMP_RW" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_LoadBMP_RW" );
        }
        return ( SDL_LoadBMP_RW_handle )( dlsym_ptr );
    } ();
}

SDL_Surface * SDL_LoadBMP_RW ( SDL_RWops * src, int freesrc );

namespace sym{
    typedef int ( *SDL_SaveBMP_RW_handle )( SDL_Surface * surface, SDL_RWops * dst, int freedst );
    static auto SDL_SaveBMP_RW = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_SaveBMP_RW" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_SaveBMP_RW" );
        }
        return ( SDL_SaveBMP_RW_handle )( dlsym_ptr );
    } ();
}

int SDL_SaveBMP_RW ( SDL_Surface * surface, SDL_RWops * dst, int freedst );

namespace sym{
    typedef int ( *SDL_SetColorKey_handle )( SDL_Surface * surface, Uint32 flag, Uint32 key );
    static auto SDL_SetColorKey = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_SetColorKey" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_SetColorKey" );
        }
        return ( SDL_SetColorKey_handle )( dlsym_ptr );
    } ();
}

int SDL_SetColorKey ( SDL_Surface * surface, Uint32 flag, Uint32 key );

namespace sym{
    typedef int ( *SDL_SetAlpha_handle )( SDL_Surface * surface, Uint32 flag, Uint8 alpha );
    static auto SDL_SetAlpha = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_SetAlpha" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_SetAlpha" );
        }
        return ( SDL_SetAlpha_handle )( dlsym_ptr );
    } ();
}

int SDL_SetAlpha ( SDL_Surface * surface, Uint32 flag, Uint8 alpha );

namespace sym{
    typedef SDL_bool ( *SDL_SetClipRect_handle )( SDL_Surface * surface, const SDL_Rect * rect );
    static auto SDL_SetClipRect = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_SetClipRect" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_SetClipRect" );
        }
        return ( SDL_SetClipRect_handle )( dlsym_ptr );
    } ();
}

SDL_bool SDL_SetClipRect ( SDL_Surface * surface, const SDL_Rect * rect );

namespace sym{
    typedef void ( *SDL_GetClipRect_handle )( SDL_Surface * surface, SDL_Rect * rect );
    static auto SDL_GetClipRect = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetClipRect" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetClipRect" );
        }
        return ( SDL_GetClipRect_handle )( dlsym_ptr );
    } ();
}

void SDL_GetClipRect ( SDL_Surface * surface, SDL_Rect * rect );

namespace sym{
    typedef SDL_Surface * ( *SDL_ConvertSurface_handle )( SDL_Surface * src, SDL_PixelFormat * fmt, Uint32 flags );
    static auto SDL_ConvertSurface = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_ConvertSurface" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_ConvertSurface" );
        }
        return ( SDL_ConvertSurface_handle )( dlsym_ptr );
    } ();
}

SDL_Surface * SDL_ConvertSurface ( SDL_Surface * src, SDL_PixelFormat * fmt, Uint32 flags );

namespace sym{
    typedef int ( *SDL_UpperBlit_handle )( SDL_Surface * src, SDL_Rect * srcrect, SDL_Surface * dst, SDL_Rect * dstrect );
    static auto SDL_UpperBlit = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_UpperBlit" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_UpperBlit" );
        }
        return ( SDL_UpperBlit_handle )( dlsym_ptr );
    } ();
}

int SDL_UpperBlit ( SDL_Surface * src, SDL_Rect * srcrect, SDL_Surface * dst, SDL_Rect * dstrect );

namespace sym{
    typedef int ( *SDL_LowerBlit_handle )( SDL_Surface * src, SDL_Rect * srcrect, SDL_Surface * dst, SDL_Rect * dstrect );
    static auto SDL_LowerBlit = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_LowerBlit" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_LowerBlit" );
        }
        return ( SDL_LowerBlit_handle )( dlsym_ptr );
    } ();
}

int SDL_LowerBlit ( SDL_Surface * src, SDL_Rect * srcrect, SDL_Surface * dst, SDL_Rect * dstrect );

namespace sym{
    typedef int ( *SDL_FillRect_handle )( SDL_Surface * dst, SDL_Rect * dstrect, Uint32 color );
    static auto SDL_FillRect = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_FillRect" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_FillRect" );
        }
        return ( SDL_FillRect_handle )( dlsym_ptr );
    } ();
}

int SDL_FillRect ( SDL_Surface * dst, SDL_Rect * dstrect, Uint32 color );

namespace sym{
    typedef SDL_Surface * ( *SDL_DisplayFormat_handle )( SDL_Surface * surface );
    static auto SDL_DisplayFormat = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_DisplayFormat" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_DisplayFormat" );
        }
        return ( SDL_DisplayFormat_handle )( dlsym_ptr );
    } ();
}

SDL_Surface * SDL_DisplayFormat ( SDL_Surface * surface );

namespace sym{
    typedef SDL_Surface * ( *SDL_DisplayFormatAlpha_handle )( SDL_Surface * surface );
    static auto SDL_DisplayFormatAlpha = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_DisplayFormatAlpha" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_DisplayFormatAlpha" );
        }
        return ( SDL_DisplayFormatAlpha_handle )( dlsym_ptr );
    } ();
}

SDL_Surface * SDL_DisplayFormatAlpha ( SDL_Surface * surface );

namespace sym{
    typedef SDL_Overlay * ( *SDL_CreateYUVOverlay_handle )( int width, int height, Uint32 format, SDL_Surface * display );
    static auto SDL_CreateYUVOverlay = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_CreateYUVOverlay" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_CreateYUVOverlay" );
        }
        return ( SDL_CreateYUVOverlay_handle )( dlsym_ptr );
    } ();
}

SDL_Overlay * SDL_CreateYUVOverlay ( int width, int height, Uint32 format, SDL_Surface * display );

namespace sym{
    typedef int ( *SDL_LockYUVOverlay_handle )( SDL_Overlay * overlay );
    static auto SDL_LockYUVOverlay = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_LockYUVOverlay" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_LockYUVOverlay" );
        }
        return ( SDL_LockYUVOverlay_handle )( dlsym_ptr );
    } ();
}

int SDL_LockYUVOverlay ( SDL_Overlay * overlay );

namespace sym{
    typedef void ( *SDL_UnlockYUVOverlay_handle )( SDL_Overlay * overlay );
    static auto SDL_UnlockYUVOverlay = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_UnlockYUVOverlay" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_UnlockYUVOverlay" );
        }
        return ( SDL_UnlockYUVOverlay_handle )( dlsym_ptr );
    } ();
}

void SDL_UnlockYUVOverlay ( SDL_Overlay * overlay );

namespace sym{
    typedef int ( *SDL_DisplayYUVOverlay_handle )( SDL_Overlay * overlay, SDL_Rect * dstrect );
    static auto SDL_DisplayYUVOverlay = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_DisplayYUVOverlay" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_DisplayYUVOverlay" );
        }
        return ( SDL_DisplayYUVOverlay_handle )( dlsym_ptr );
    } ();
}

int SDL_DisplayYUVOverlay ( SDL_Overlay * overlay, SDL_Rect * dstrect );

namespace sym{
    typedef void ( *SDL_FreeYUVOverlay_handle )( SDL_Overlay * overlay );
    static auto SDL_FreeYUVOverlay = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_FreeYUVOverlay" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_FreeYUVOverlay" );
        }
        return ( SDL_FreeYUVOverlay_handle )( dlsym_ptr );
    } ();
}

void SDL_FreeYUVOverlay ( SDL_Overlay * overlay );

namespace sym{
    typedef int ( *SDL_GL_LoadLibrary_handle )( const char * path );
    static auto SDL_GL_LoadLibrary = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GL_LoadLibrary" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GL_LoadLibrary" );
        }
        return ( SDL_GL_LoadLibrary_handle )( dlsym_ptr );
    } ();
}

int SDL_GL_LoadLibrary ( const char * path );

namespace sym{
    typedef void * ( *SDL_GL_GetProcAddress_handle )( const char * proc );
    static auto SDL_GL_GetProcAddress = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GL_GetProcAddress" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GL_GetProcAddress" );
        }
        return ( SDL_GL_GetProcAddress_handle )( dlsym_ptr );
    } ();
}

void * SDL_GL_GetProcAddress ( const char * proc );

namespace sym{
    typedef int ( *SDL_GL_SetAttribute_handle )( SDL_GLattr attr, int value );
    static auto SDL_GL_SetAttribute = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GL_SetAttribute" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GL_SetAttribute" );
        }
        return ( SDL_GL_SetAttribute_handle )( dlsym_ptr );
    } ();
}

int SDL_GL_SetAttribute ( SDL_GLattr attr, int value );

namespace sym{
    typedef int ( *SDL_GL_GetAttribute_handle )( SDL_GLattr attr, int * value );
    static auto SDL_GL_GetAttribute = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GL_GetAttribute" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GL_GetAttribute" );
        }
        return ( SDL_GL_GetAttribute_handle )( dlsym_ptr );
    } ();
}

int SDL_GL_GetAttribute ( SDL_GLattr attr, int * value );

namespace sym{
    typedef void ( *SDL_GL_SwapBuffers_handle )(  );
    static auto SDL_GL_SwapBuffers = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GL_SwapBuffers" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GL_SwapBuffers" );
        }
        return ( SDL_GL_SwapBuffers_handle )( dlsym_ptr );
    } ();
}

void SDL_GL_SwapBuffers (  );

namespace sym{
    typedef void ( *SDL_GL_UpdateRects_handle )( int numrects, SDL_Rect * rects );
    static auto SDL_GL_UpdateRects = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GL_UpdateRects" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GL_UpdateRects" );
        }
        return ( SDL_GL_UpdateRects_handle )( dlsym_ptr );
    } ();
}

void SDL_GL_UpdateRects ( int numrects, SDL_Rect * rects );

namespace sym{
    typedef void ( *SDL_GL_Lock_handle )(  );
    static auto SDL_GL_Lock = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GL_Lock" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GL_Lock" );
        }
        return ( SDL_GL_Lock_handle )( dlsym_ptr );
    } ();
}

void SDL_GL_Lock (  );

namespace sym{
    typedef void ( *SDL_GL_Unlock_handle )(  );
    static auto SDL_GL_Unlock = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GL_Unlock" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GL_Unlock" );
        }
        return ( SDL_GL_Unlock_handle )( dlsym_ptr );
    } ();
}

void SDL_GL_Unlock (  );

namespace sym{
    typedef void ( *SDL_WM_SetCaption_handle )( const char * title, const char * icon );
    static auto SDL_WM_SetCaption = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_WM_SetCaption" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_WM_SetCaption" );
        }
        return ( SDL_WM_SetCaption_handle )( dlsym_ptr );
    } ();
}

void SDL_WM_SetCaption ( const char * title, const char * icon );

namespace sym{
    typedef void ( *SDL_WM_GetCaption_handle )( char ** title, char ** icon );
    static auto SDL_WM_GetCaption = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_WM_GetCaption" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_WM_GetCaption" );
        }
        return ( SDL_WM_GetCaption_handle )( dlsym_ptr );
    } ();
}

void SDL_WM_GetCaption ( char ** title, char ** icon );

namespace sym{
    typedef void ( *SDL_WM_SetIcon_handle )( SDL_Surface * icon, Uint8 * mask );
    static auto SDL_WM_SetIcon = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_WM_SetIcon" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_WM_SetIcon" );
        }
        return ( SDL_WM_SetIcon_handle )( dlsym_ptr );
    } ();
}

void SDL_WM_SetIcon ( SDL_Surface * icon, Uint8 * mask );

namespace sym{
    typedef int ( *SDL_WM_IconifyWindow_handle )(  );
    static auto SDL_WM_IconifyWindow = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_WM_IconifyWindow" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_WM_IconifyWindow" );
        }
        return ( SDL_WM_IconifyWindow_handle )( dlsym_ptr );
    } ();
}

int SDL_WM_IconifyWindow (  );

namespace sym{
    typedef int ( *SDL_WM_ToggleFullScreen_handle )( SDL_Surface * surface );
    static auto SDL_WM_ToggleFullScreen = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_WM_ToggleFullScreen" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_WM_ToggleFullScreen" );
        }
        return ( SDL_WM_ToggleFullScreen_handle )( dlsym_ptr );
    } ();
}

int SDL_WM_ToggleFullScreen ( SDL_Surface * surface );

namespace sym{
    typedef SDL_GrabMode ( *SDL_WM_GrabInput_handle )( SDL_GrabMode mode );
    static auto SDL_WM_GrabInput = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_WM_GrabInput" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_WM_GrabInput" );
        }
        return ( SDL_WM_GrabInput_handle )( dlsym_ptr );
    } ();
}

SDL_GrabMode SDL_WM_GrabInput ( SDL_GrabMode mode );

namespace sym{
    typedef int ( *SDL_SoftStretch_handle )( SDL_Surface * src, SDL_Rect * srcrect, SDL_Surface * dst, SDL_Rect * dstrect );
    static auto SDL_SoftStretch = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_SoftStretch" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_SoftStretch" );
        }
        return ( SDL_SoftStretch_handle )( dlsym_ptr );
    } ();
}

int SDL_SoftStretch ( SDL_Surface * src, SDL_Rect * srcrect, SDL_Surface * dst, SDL_Rect * dstrect );

namespace sym{
    typedef Uint8 ( *SDL_GetMouseState_handle )( int * x, int * y );
    static auto SDL_GetMouseState = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetMouseState" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetMouseState" );
        }
        return ( SDL_GetMouseState_handle )( dlsym_ptr );
    } ();
}

Uint8 SDL_GetMouseState ( int * x, int * y );

namespace sym{
    typedef Uint8 ( *SDL_GetRelativeMouseState_handle )( int * x, int * y );
    static auto SDL_GetRelativeMouseState = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetRelativeMouseState" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetRelativeMouseState" );
        }
        return ( SDL_GetRelativeMouseState_handle )( dlsym_ptr );
    } ();
}

Uint8 SDL_GetRelativeMouseState ( int * x, int * y );

namespace sym{
    typedef void ( *SDL_WarpMouse_handle )( Uint16 x, Uint16 y );
    static auto SDL_WarpMouse = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_WarpMouse" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_WarpMouse" );
        }
        return ( SDL_WarpMouse_handle )( dlsym_ptr );
    } ();
}

void SDL_WarpMouse ( Uint16 x, Uint16 y );

namespace sym{
    typedef SDL_Cursor * ( *SDL_CreateCursor_handle )( Uint8 * data, Uint8 * mask, int w, int h, int hot_x, int hot_y );
    static auto SDL_CreateCursor = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_CreateCursor" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_CreateCursor" );
        }
        return ( SDL_CreateCursor_handle )( dlsym_ptr );
    } ();
}

SDL_Cursor * SDL_CreateCursor ( Uint8 * data, Uint8 * mask, int w, int h, int hot_x, int hot_y );

namespace sym{
    typedef void ( *SDL_SetCursor_handle )( SDL_Cursor * cursor );
    static auto SDL_SetCursor = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_SetCursor" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_SetCursor" );
        }
        return ( SDL_SetCursor_handle )( dlsym_ptr );
    } ();
}

void SDL_SetCursor ( SDL_Cursor * cursor );

namespace sym{
    typedef SDL_Cursor * ( *SDL_GetCursor_handle )(  );
    static auto SDL_GetCursor = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetCursor" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetCursor" );
        }
        return ( SDL_GetCursor_handle )( dlsym_ptr );
    } ();
}

SDL_Cursor * SDL_GetCursor (  );

namespace sym{
    typedef void ( *SDL_FreeCursor_handle )( SDL_Cursor * cursor );
    static auto SDL_FreeCursor = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_FreeCursor" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_FreeCursor" );
        }
        return ( SDL_FreeCursor_handle )( dlsym_ptr );
    } ();
}

void SDL_FreeCursor ( SDL_Cursor * cursor );

namespace sym{
    typedef int ( *SDL_ShowCursor_handle )( int toggle );
    static auto SDL_ShowCursor = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_ShowCursor" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_ShowCursor" );
        }
        return ( SDL_ShowCursor_handle )( dlsym_ptr );
    } ();
}

int SDL_ShowCursor ( int toggle );

namespace sym{
    typedef int ( *SDL_NumJoysticks_handle )(  );
    static auto SDL_NumJoysticks = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_NumJoysticks" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_NumJoysticks" );
        }
        return ( SDL_NumJoysticks_handle )( dlsym_ptr );
    } ();
}

int SDL_NumJoysticks (  );

namespace sym{
    typedef const char * ( *SDL_JoystickName_handle )( int device_index );
    static auto SDL_JoystickName = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_JoystickName" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_JoystickName" );
        }
        return ( SDL_JoystickName_handle )( dlsym_ptr );
    } ();
}

const char * SDL_JoystickName ( int device_index );

namespace sym{
    typedef SDL_Joystick * ( *SDL_JoystickOpen_handle )( int device_index );
    static auto SDL_JoystickOpen = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_JoystickOpen" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_JoystickOpen" );
        }
        return ( SDL_JoystickOpen_handle )( dlsym_ptr );
    } ();
}

SDL_Joystick * SDL_JoystickOpen ( int device_index );

namespace sym{
    typedef int ( *SDL_JoystickOpened_handle )( int device_index );
    static auto SDL_JoystickOpened = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_JoystickOpened" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_JoystickOpened" );
        }
        return ( SDL_JoystickOpened_handle )( dlsym_ptr );
    } ();
}

int SDL_JoystickOpened ( int device_index );

namespace sym{
    typedef int ( *SDL_JoystickIndex_handle )( SDL_Joystick * joystick );
    static auto SDL_JoystickIndex = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_JoystickIndex" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_JoystickIndex" );
        }
        return ( SDL_JoystickIndex_handle )( dlsym_ptr );
    } ();
}

int SDL_JoystickIndex ( SDL_Joystick * joystick );

namespace sym{
    typedef int ( *SDL_JoystickNumAxes_handle )( SDL_Joystick * joystick );
    static auto SDL_JoystickNumAxes = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_JoystickNumAxes" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_JoystickNumAxes" );
        }
        return ( SDL_JoystickNumAxes_handle )( dlsym_ptr );
    } ();
}

int SDL_JoystickNumAxes ( SDL_Joystick * joystick );

namespace sym{
    typedef int ( *SDL_JoystickNumBalls_handle )( SDL_Joystick * joystick );
    static auto SDL_JoystickNumBalls = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_JoystickNumBalls" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_JoystickNumBalls" );
        }
        return ( SDL_JoystickNumBalls_handle )( dlsym_ptr );
    } ();
}

int SDL_JoystickNumBalls ( SDL_Joystick * joystick );

namespace sym{
    typedef int ( *SDL_JoystickNumHats_handle )( SDL_Joystick * joystick );
    static auto SDL_JoystickNumHats = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_JoystickNumHats" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_JoystickNumHats" );
        }
        return ( SDL_JoystickNumHats_handle )( dlsym_ptr );
    } ();
}

int SDL_JoystickNumHats ( SDL_Joystick * joystick );

namespace sym{
    typedef int ( *SDL_JoystickNumButtons_handle )( SDL_Joystick * joystick );
    static auto SDL_JoystickNumButtons = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_JoystickNumButtons" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_JoystickNumButtons" );
        }
        return ( SDL_JoystickNumButtons_handle )( dlsym_ptr );
    } ();
}

int SDL_JoystickNumButtons ( SDL_Joystick * joystick );

namespace sym{
    typedef void ( *SDL_JoystickUpdate_handle )(  );
    static auto SDL_JoystickUpdate = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_JoystickUpdate" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_JoystickUpdate" );
        }
        return ( SDL_JoystickUpdate_handle )( dlsym_ptr );
    } ();
}

void SDL_JoystickUpdate (  );

namespace sym{
    typedef int ( *SDL_JoystickEventState_handle )( int state );
    static auto SDL_JoystickEventState = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_JoystickEventState" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_JoystickEventState" );
        }
        return ( SDL_JoystickEventState_handle )( dlsym_ptr );
    } ();
}

int SDL_JoystickEventState ( int state );

namespace sym{
    typedef Sint16 ( *SDL_JoystickGetAxis_handle )( SDL_Joystick * joystick, int axis );
    static auto SDL_JoystickGetAxis = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_JoystickGetAxis" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_JoystickGetAxis" );
        }
        return ( SDL_JoystickGetAxis_handle )( dlsym_ptr );
    } ();
}

Sint16 SDL_JoystickGetAxis ( SDL_Joystick * joystick, int axis );

namespace sym{
    typedef Uint8 ( *SDL_JoystickGetHat_handle )( SDL_Joystick * joystick, int hat );
    static auto SDL_JoystickGetHat = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_JoystickGetHat" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_JoystickGetHat" );
        }
        return ( SDL_JoystickGetHat_handle )( dlsym_ptr );
    } ();
}

Uint8 SDL_JoystickGetHat ( SDL_Joystick * joystick, int hat );

namespace sym{
    typedef int ( *SDL_JoystickGetBall_handle )( SDL_Joystick * joystick, int ball, int * dx, int * dy );
    static auto SDL_JoystickGetBall = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_JoystickGetBall" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_JoystickGetBall" );
        }
        return ( SDL_JoystickGetBall_handle )( dlsym_ptr );
    } ();
}

int SDL_JoystickGetBall ( SDL_Joystick * joystick, int ball, int * dx, int * dy );

namespace sym{
    typedef Uint8 ( *SDL_JoystickGetButton_handle )( SDL_Joystick * joystick, int button );
    static auto SDL_JoystickGetButton = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_JoystickGetButton" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_JoystickGetButton" );
        }
        return ( SDL_JoystickGetButton_handle )( dlsym_ptr );
    } ();
}

Uint8 SDL_JoystickGetButton ( SDL_Joystick * joystick, int button );

namespace sym{
    typedef void ( *SDL_JoystickClose_handle )( SDL_Joystick * joystick );
    static auto SDL_JoystickClose = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_JoystickClose" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_JoystickClose" );
        }
        return ( SDL_JoystickClose_handle )( dlsym_ptr );
    } ();
}

void SDL_JoystickClose ( SDL_Joystick * joystick );

namespace sym{
    typedef void ( *SDL_PumpEvents_handle )(  );
    static auto SDL_PumpEvents = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_PumpEvents" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_PumpEvents" );
        }
        return ( SDL_PumpEvents_handle )( dlsym_ptr );
    } ();
}

void SDL_PumpEvents (  );

namespace sym{
    typedef int ( *SDL_PeepEvents_handle )( SDL_Event * events, int numevents, SDL_eventaction action, Uint32 mask );
    static auto SDL_PeepEvents = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_PeepEvents" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_PeepEvents" );
        }
        return ( SDL_PeepEvents_handle )( dlsym_ptr );
    } ();
}

int SDL_PeepEvents ( SDL_Event * events, int numevents, SDL_eventaction action, Uint32 mask );

namespace sym{
    typedef int ( *SDL_PollEvent_handle )( SDL_Event * event );
    static auto SDL_PollEvent = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_PollEvent" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_PollEvent" );
        }
        return ( SDL_PollEvent_handle )( dlsym_ptr );
    } ();
}

int SDL_PollEvent ( SDL_Event * event );

namespace sym{
    typedef int ( *SDL_WaitEvent_handle )( SDL_Event * event );
    static auto SDL_WaitEvent = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_WaitEvent" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_WaitEvent" );
        }
        return ( SDL_WaitEvent_handle )( dlsym_ptr );
    } ();
}

int SDL_WaitEvent ( SDL_Event * event );

namespace sym{
    typedef int ( *SDL_PushEvent_handle )( SDL_Event * event );
    static auto SDL_PushEvent = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_PushEvent" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_PushEvent" );
        }
        return ( SDL_PushEvent_handle )( dlsym_ptr );
    } ();
}

int SDL_PushEvent ( SDL_Event * event );

namespace sym{
    typedef void ( *SDL_SetEventFilter_handle )( SDL_EventFilter filter );
    static auto SDL_SetEventFilter = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_SetEventFilter" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_SetEventFilter" );
        }
        return ( SDL_SetEventFilter_handle )( dlsym_ptr );
    } ();
}

void SDL_SetEventFilter ( SDL_EventFilter filter );

namespace sym{
    typedef SDL_EventFilter ( *SDL_GetEventFilter_handle )(  );
    static auto SDL_GetEventFilter = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetEventFilter" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetEventFilter" );
        }
        return ( SDL_GetEventFilter_handle )( dlsym_ptr );
    } ();
}

SDL_EventFilter SDL_GetEventFilter (  );

namespace sym{
    typedef Uint8 ( *SDL_EventState_handle )( Uint8 type, int state );
    static auto SDL_EventState = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_EventState" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_EventState" );
        }
        return ( SDL_EventState_handle )( dlsym_ptr );
    } ();
}

Uint8 SDL_EventState ( Uint8 type, int state );

namespace sym{
    typedef void * ( *SDL_LoadObject_handle )( const char * sofile );
    static auto SDL_LoadObject = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_LoadObject" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_LoadObject" );
        }
        return ( SDL_LoadObject_handle )( dlsym_ptr );
    } ();
}

void * SDL_LoadObject ( const char * sofile );

namespace sym{
    typedef void * ( *SDL_LoadFunction_handle )( void * handle, const char * name );
    static auto SDL_LoadFunction = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_LoadFunction" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_LoadFunction" );
        }
        return ( SDL_LoadFunction_handle )( dlsym_ptr );
    } ();
}

void * SDL_LoadFunction ( void * handle, const char * name );

namespace sym{
    typedef void ( *SDL_UnloadObject_handle )( void * handle );
    static auto SDL_UnloadObject = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_UnloadObject" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_UnloadObject" );
        }
        return ( SDL_UnloadObject_handle )( dlsym_ptr );
    } ();
}

void SDL_UnloadObject ( void * handle );

namespace sym{
    typedef Uint32 ( *SDL_GetTicks_handle )(  );
    static auto SDL_GetTicks = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetTicks" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetTicks" );
        }
        return ( SDL_GetTicks_handle )( dlsym_ptr );
    } ();
}

Uint32 SDL_GetTicks (  );

namespace sym{
    typedef void ( *SDL_Delay_handle )( Uint32 ms );
    static auto SDL_Delay = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_Delay" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_Delay" );
        }
        return ( SDL_Delay_handle )( dlsym_ptr );
    } ();
}

void SDL_Delay ( Uint32 ms );

namespace sym{
    typedef int ( *SDL_SetTimer_handle )( Uint32 interval, SDL_TimerCallback callback );
    static auto SDL_SetTimer = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_SetTimer" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_SetTimer" );
        }
        return ( SDL_SetTimer_handle )( dlsym_ptr );
    } ();
}

int SDL_SetTimer ( Uint32 interval, SDL_TimerCallback callback );

namespace sym{
    typedef SDL_TimerID ( *SDL_AddTimer_handle )( Uint32 interval, SDL_NewTimerCallback callback, void * param );
    static auto SDL_AddTimer = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_AddTimer" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_AddTimer" );
        }
        return ( SDL_AddTimer_handle )( dlsym_ptr );
    } ();
}

SDL_TimerID SDL_AddTimer ( Uint32 interval, SDL_NewTimerCallback callback, void * param );

namespace sym{
    typedef SDL_bool ( *SDL_RemoveTimer_handle )( SDL_TimerID t );
    static auto SDL_RemoveTimer = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_RemoveTimer" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_RemoveTimer" );
        }
        return ( SDL_RemoveTimer_handle )( dlsym_ptr );
    } ();
}

SDL_bool SDL_RemoveTimer ( SDL_TimerID t );

namespace sym{
    typedef const SDL_version * ( *SDL_Linked_Version_handle )(  );
    static auto SDL_Linked_Version = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_Linked_Version" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_Linked_Version" );
        }
        return ( SDL_Linked_Version_handle )( dlsym_ptr );
    } ();
}

const SDL_version * SDL_Linked_Version (  );

namespace sym{
    typedef int ( *SDL_Init_handle )( Uint32 flags );
    static auto SDL_Init = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_Init" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_Init" );
        }
        return ( SDL_Init_handle )( dlsym_ptr );
    } ();
}

int SDL_Init ( Uint32 flags );

namespace sym{
    typedef int ( *SDL_InitSubSystem_handle )( Uint32 flags );
    static auto SDL_InitSubSystem = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_InitSubSystem" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_InitSubSystem" );
        }
        return ( SDL_InitSubSystem_handle )( dlsym_ptr );
    } ();
}

int SDL_InitSubSystem ( Uint32 flags );

namespace sym{
    typedef void ( *SDL_QuitSubSystem_handle )( Uint32 flags );
    static auto SDL_QuitSubSystem = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_QuitSubSystem" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_QuitSubSystem" );
        }
        return ( SDL_QuitSubSystem_handle )( dlsym_ptr );
    } ();
}

void SDL_QuitSubSystem ( Uint32 flags );

namespace sym{
    typedef Uint32 ( *SDL_WasInit_handle )( Uint32 flags );
    static auto SDL_WasInit = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_WasInit" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_WasInit" );
        }
        return ( SDL_WasInit_handle )( dlsym_ptr );
    } ();
}

Uint32 SDL_WasInit ( Uint32 flags );

namespace sym{
    typedef void ( *SDL_Quit_handle )(  );
    static auto SDL_Quit = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_Quit" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_Quit" );
        }
        return ( SDL_Quit_handle )( dlsym_ptr );
    } ();
}

void SDL_Quit (  );
#endif
