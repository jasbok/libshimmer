#include "SDL2_apigen.h"
#include <chrono>
#include <fstream>
#include <iomanip>
#include <iostream>

#define TRACE()                                                           \
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
    if ( _FIRST_CALL ) {                                                 \
        std::cout << "[[ " << __FUNCTION__ << " ]]" << std::endl;         \
        _FIRST_CALL = false;                                              \
    }                                                                    \
    else if ( _DURATION.count() > _INTERVAL ) {                          \
        std::cout << _COUNTER << "x " << __FUNCTION__                     \
                  << "[" << std::setprecision ( 2 )                       \
                  <<  _COUNTER / _DURATION.count()                        \
                  << "/sec]" << std::endl;                                \
                                                                          \
                                                                          \
        _COUNTER   = 0;                                                   \
        _INTERVAL *= 2;                                                   \
        _START     = steady_clock::now();                                 \
    }


const char * SDL_GetPlatform (  ) {
            TRACE();
            return sym::SDL_GetPlatform (  );
        }

void * SDL_malloc ( size_t size ) {
            TRACE();
            return sym::SDL_malloc ( size );
        }

void * SDL_calloc ( size_t nmemb, size_t size ) {
            TRACE();
            return sym::SDL_calloc ( nmemb, size );
        }

void * SDL_realloc ( void * mem, size_t size ) {
            TRACE();
            return sym::SDL_realloc ( mem, size );
        }

void SDL_free ( void * mem ) {
            TRACE();
            return sym::SDL_free ( mem );
        }

void SDL_GetMemoryFunctions ( SDL_malloc_func * malloc_func, SDL_calloc_func * calloc_func, SDL_realloc_func * realloc_func, SDL_free_func * free_func ) {
            TRACE();
            return sym::SDL_GetMemoryFunctions ( malloc_func, calloc_func, realloc_func, free_func );
        }

int SDL_SetMemoryFunctions ( SDL_malloc_func malloc_func, SDL_calloc_func calloc_func, SDL_realloc_func realloc_func, SDL_free_func free_func ) {
            TRACE();
            return sym::SDL_SetMemoryFunctions ( malloc_func, calloc_func, realloc_func, free_func );
        }

int SDL_GetNumAllocations (  ) {
            TRACE();
            return sym::SDL_GetNumAllocations (  );
        }

char * SDL_getenv ( const char * name ) {
            TRACE();
            return sym::SDL_getenv ( name );
        }

int SDL_setenv ( const char * name, const char * value, int overwrite ) {
            TRACE();
            return sym::SDL_setenv ( name, value, overwrite );
        }

void SDL_qsort ( void * base, size_t nmemb, size_t size, int (*compare)(const void *, const void *) ) {
            TRACE();
            return sym::SDL_qsort ( base, nmemb, size, compare );
        }

int SDL_abs ( int x ) {
            TRACE();
            return sym::SDL_abs ( x );
        }

int SDL_isdigit ( int x ) {
            TRACE();
            return sym::SDL_isdigit ( x );
        }

int SDL_isspace ( int x ) {
            TRACE();
            return sym::SDL_isspace ( x );
        }

int SDL_toupper ( int x ) {
            TRACE();
            return sym::SDL_toupper ( x );
        }

int SDL_tolower ( int x ) {
            TRACE();
            return sym::SDL_tolower ( x );
        }

void * SDL_memset ( void * dst, int c, size_t len ) {
            TRACE();
            return sym::SDL_memset ( dst, c, len );
        }

void * SDL_memcpy ( void * dst, const void * src, size_t len ) {
            TRACE();
            return sym::SDL_memcpy ( dst, src, len );
        }

void * SDL_memmove ( void * dst, const void * src, size_t len ) {
            TRACE();
            return sym::SDL_memmove ( dst, src, len );
        }

int SDL_memcmp ( const void * s1, const void * s2, size_t len ) {
            TRACE();
            return sym::SDL_memcmp ( s1, s2, len );
        }

size_t SDL_wcslen ( const wchar_t * wstr ) {
            TRACE();
            return sym::SDL_wcslen ( wstr );
        }

size_t SDL_wcslcpy ( wchar_t * dst, const wchar_t * src, size_t maxlen ) {
            TRACE();
            return sym::SDL_wcslcpy ( dst, src, maxlen );
        }

size_t SDL_wcslcat ( wchar_t * dst, const wchar_t * src, size_t maxlen ) {
            TRACE();
            return sym::SDL_wcslcat ( dst, src, maxlen );
        }

int SDL_wcscmp ( const wchar_t * str1, const wchar_t * str2 ) {
            TRACE();
            return sym::SDL_wcscmp ( str1, str2 );
        }

size_t SDL_strlen ( const char * str ) {
            TRACE();
            return sym::SDL_strlen ( str );
        }

size_t SDL_strlcpy ( char * dst, const char * src, size_t maxlen ) {
            TRACE();
            return sym::SDL_strlcpy ( dst, src, maxlen );
        }

size_t SDL_utf8strlcpy ( char * dst, const char * src, size_t dst_bytes ) {
            TRACE();
            return sym::SDL_utf8strlcpy ( dst, src, dst_bytes );
        }

size_t SDL_strlcat ( char * dst, const char * src, size_t maxlen ) {
            TRACE();
            return sym::SDL_strlcat ( dst, src, maxlen );
        }

char * SDL_strdup ( const char * str ) {
            TRACE();
            return sym::SDL_strdup ( str );
        }

char * SDL_strrev ( char * str ) {
            TRACE();
            return sym::SDL_strrev ( str );
        }

char * SDL_strupr ( char * str ) {
            TRACE();
            return sym::SDL_strupr ( str );
        }

char * SDL_strlwr ( char * str ) {
            TRACE();
            return sym::SDL_strlwr ( str );
        }

char * SDL_strchr ( const char * str, int c ) {
            TRACE();
            return sym::SDL_strchr ( str, c );
        }

char * SDL_strrchr ( const char * str, int c ) {
            TRACE();
            return sym::SDL_strrchr ( str, c );
        }

char * SDL_strstr ( const char * haystack, const char * needle ) {
            TRACE();
            return sym::SDL_strstr ( haystack, needle );
        }

size_t SDL_utf8strlen ( const char * str ) {
            TRACE();
            return sym::SDL_utf8strlen ( str );
        }

char * SDL_itoa ( int value, char * str, int radix ) {
            TRACE();
            return sym::SDL_itoa ( value, str, radix );
        }

char * SDL_uitoa ( unsigned int value, char * str, int radix ) {
            TRACE();
            return sym::SDL_uitoa ( value, str, radix );
        }

char * SDL_ltoa ( long value, char * str, int radix ) {
            TRACE();
            return sym::SDL_ltoa ( value, str, radix );
        }

char * SDL_ultoa ( unsigned long value, char * str, int radix ) {
            TRACE();
            return sym::SDL_ultoa ( value, str, radix );
        }

char * SDL_lltoa ( Sint64 value, char * str, int radix ) {
            TRACE();
            return sym::SDL_lltoa ( value, str, radix );
        }

char * SDL_ulltoa ( Uint64 value, char * str, int radix ) {
            TRACE();
            return sym::SDL_ulltoa ( value, str, radix );
        }

int SDL_atoi ( const char * str ) {
            TRACE();
            return sym::SDL_atoi ( str );
        }

double SDL_atof ( const char * str ) {
            TRACE();
            return sym::SDL_atof ( str );
        }

long SDL_strtol ( const char * str, char ** endp, int base ) {
            TRACE();
            return sym::SDL_strtol ( str, endp, base );
        }

unsigned long SDL_strtoul ( const char * str, char ** endp, int base ) {
            TRACE();
            return sym::SDL_strtoul ( str, endp, base );
        }

Sint64 SDL_strtoll ( const char * str, char ** endp, int base ) {
            TRACE();
            return sym::SDL_strtoll ( str, endp, base );
        }

Uint64 SDL_strtoull ( const char * str, char ** endp, int base ) {
            TRACE();
            return sym::SDL_strtoull ( str, endp, base );
        }

double SDL_strtod ( const char * str, char ** endp ) {
            TRACE();
            return sym::SDL_strtod ( str, endp );
        }

int SDL_strcmp ( const char * str1, const char * str2 ) {
            TRACE();
            return sym::SDL_strcmp ( str1, str2 );
        }

int SDL_strncmp ( const char * str1, const char * str2, size_t maxlen ) {
            TRACE();
            return sym::SDL_strncmp ( str1, str2, maxlen );
        }

int SDL_strcasecmp ( const char * str1, const char * str2 ) {
            TRACE();
            return sym::SDL_strcasecmp ( str1, str2 );
        }

int SDL_strncasecmp ( const char * str1, const char * str2, size_t len ) {
            TRACE();
            return sym::SDL_strncasecmp ( str1, str2, len );
        }

int SDL_sscanf ( const char * text, const char * fmt ) {
            TRACE();
            return sym::SDL_sscanf ( text, fmt );
        }

int SDL_vsscanf ( const char * text, const char * fmt, va_list ap ) {
            TRACE();
            return sym::SDL_vsscanf ( text, fmt, ap );
        }

int SDL_snprintf ( char * text, size_t maxlen, const char * fmt ) {
            TRACE();
            return sym::SDL_snprintf ( text, maxlen, fmt );
        }

int SDL_vsnprintf ( char * text, size_t maxlen, const char * fmt, va_list ap ) {
            TRACE();
            return sym::SDL_vsnprintf ( text, maxlen, fmt, ap );
        }

double SDL_acos ( double x ) {
            TRACE();
            return sym::SDL_acos ( x );
        }

float SDL_acosf ( float x ) {
            TRACE();
            return sym::SDL_acosf ( x );
        }

double SDL_asin ( double x ) {
            TRACE();
            return sym::SDL_asin ( x );
        }

float SDL_asinf ( float x ) {
            TRACE();
            return sym::SDL_asinf ( x );
        }

double SDL_atan ( double x ) {
            TRACE();
            return sym::SDL_atan ( x );
        }

float SDL_atanf ( float x ) {
            TRACE();
            return sym::SDL_atanf ( x );
        }

double SDL_atan2 ( double x, double y ) {
            TRACE();
            return sym::SDL_atan2 ( x, y );
        }

float SDL_atan2f ( float x, float y ) {
            TRACE();
            return sym::SDL_atan2f ( x, y );
        }

double SDL_ceil ( double x ) {
            TRACE();
            return sym::SDL_ceil ( x );
        }

float SDL_ceilf ( float x ) {
            TRACE();
            return sym::SDL_ceilf ( x );
        }

double SDL_copysign ( double x, double y ) {
            TRACE();
            return sym::SDL_copysign ( x, y );
        }

float SDL_copysignf ( float x, float y ) {
            TRACE();
            return sym::SDL_copysignf ( x, y );
        }

double SDL_cos ( double x ) {
            TRACE();
            return sym::SDL_cos ( x );
        }

float SDL_cosf ( float x ) {
            TRACE();
            return sym::SDL_cosf ( x );
        }

double SDL_fabs ( double x ) {
            TRACE();
            return sym::SDL_fabs ( x );
        }

float SDL_fabsf ( float x ) {
            TRACE();
            return sym::SDL_fabsf ( x );
        }

double SDL_floor ( double x ) {
            TRACE();
            return sym::SDL_floor ( x );
        }

float SDL_floorf ( float x ) {
            TRACE();
            return sym::SDL_floorf ( x );
        }

double SDL_fmod ( double x, double y ) {
            TRACE();
            return sym::SDL_fmod ( x, y );
        }

float SDL_fmodf ( float x, float y ) {
            TRACE();
            return sym::SDL_fmodf ( x, y );
        }

double SDL_log ( double x ) {
            TRACE();
            return sym::SDL_log ( x );
        }

float SDL_logf ( float x ) {
            TRACE();
            return sym::SDL_logf ( x );
        }

double SDL_log10 ( double x ) {
            TRACE();
            return sym::SDL_log10 ( x );
        }

float SDL_log10f ( float x ) {
            TRACE();
            return sym::SDL_log10f ( x );
        }

double SDL_pow ( double x, double y ) {
            TRACE();
            return sym::SDL_pow ( x, y );
        }

float SDL_powf ( float x, float y ) {
            TRACE();
            return sym::SDL_powf ( x, y );
        }

double SDL_scalbn ( double x, int n ) {
            TRACE();
            return sym::SDL_scalbn ( x, n );
        }

float SDL_scalbnf ( float x, int n ) {
            TRACE();
            return sym::SDL_scalbnf ( x, n );
        }

double SDL_sin ( double x ) {
            TRACE();
            return sym::SDL_sin ( x );
        }

float SDL_sinf ( float x ) {
            TRACE();
            return sym::SDL_sinf ( x );
        }

double SDL_sqrt ( double x ) {
            TRACE();
            return sym::SDL_sqrt ( x );
        }

float SDL_sqrtf ( float x ) {
            TRACE();
            return sym::SDL_sqrtf ( x );
        }

double SDL_tan ( double x ) {
            TRACE();
            return sym::SDL_tan ( x );
        }

float SDL_tanf ( float x ) {
            TRACE();
            return sym::SDL_tanf ( x );
        }

SDL_iconv_t SDL_iconv_open ( const char * tocode, const char * fromcode ) {
            TRACE();
            return sym::SDL_iconv_open ( tocode, fromcode );
        }

int SDL_iconv_close ( SDL_iconv_t cd ) {
            TRACE();
            return sym::SDL_iconv_close ( cd );
        }

size_t SDL_iconv ( SDL_iconv_t cd, const char ** inbuf, size_t * inbytesleft, char ** outbuf, size_t * outbytesleft ) {
            TRACE();
            return sym::SDL_iconv ( cd, inbuf, inbytesleft, outbuf, outbytesleft );
        }

char * SDL_iconv_string ( const char * tocode, const char * fromcode, const char * inbuf, size_t inbytesleft ) {
            TRACE();
            return sym::SDL_iconv_string ( tocode, fromcode, inbuf, inbytesleft );
        }

void SDL_SetMainReady (  ) {
            TRACE();
            return sym::SDL_SetMainReady (  );
        }

SDL_AssertState SDL_ReportAssertion ( SDL_AssertData * parm_0, const char * parm_1, const char * parm_2, int parm_3 ) {
            TRACE();
            return sym::SDL_ReportAssertion ( parm_0, parm_1, parm_2, parm_3 );
        }

void SDL_SetAssertionHandler ( SDL_AssertionHandler handler, void * userdata ) {
            TRACE();
            return sym::SDL_SetAssertionHandler ( handler, userdata );
        }

SDL_AssertionHandler SDL_GetDefaultAssertionHandler (  ) {
            TRACE();
            return sym::SDL_GetDefaultAssertionHandler (  );
        }

SDL_AssertionHandler SDL_GetAssertionHandler ( void ** puserdata ) {
            TRACE();
            return sym::SDL_GetAssertionHandler ( puserdata );
        }

const SDL_AssertData * SDL_GetAssertionReport (  ) {
            TRACE();
            return sym::SDL_GetAssertionReport (  );
        }

void SDL_ResetAssertionReport (  ) {
            TRACE();
            return sym::SDL_ResetAssertionReport (  );
        }

SDL_bool SDL_AtomicTryLock ( SDL_SpinLock * lock ) {
            TRACE();
            return sym::SDL_AtomicTryLock ( lock );
        }

void SDL_AtomicLock ( SDL_SpinLock * lock ) {
            TRACE();
            return sym::SDL_AtomicLock ( lock );
        }

void SDL_AtomicUnlock ( SDL_SpinLock * lock ) {
            TRACE();
            return sym::SDL_AtomicUnlock ( lock );
        }

void SDL_MemoryBarrierReleaseFunction (  ) {
            TRACE();
            return sym::SDL_MemoryBarrierReleaseFunction (  );
        }

void SDL_MemoryBarrierAcquireFunction (  ) {
            TRACE();
            return sym::SDL_MemoryBarrierAcquireFunction (  );
        }

SDL_bool SDL_AtomicCAS ( SDL_atomic_t * a, int oldval, int newval ) {
            TRACE();
            return sym::SDL_AtomicCAS ( a, oldval, newval );
        }

int SDL_AtomicSet ( SDL_atomic_t * a, int v ) {
            TRACE();
            return sym::SDL_AtomicSet ( a, v );
        }

int SDL_AtomicGet ( SDL_atomic_t * a ) {
            TRACE();
            return sym::SDL_AtomicGet ( a );
        }

int SDL_AtomicAdd ( SDL_atomic_t * a, int v ) {
            TRACE();
            return sym::SDL_AtomicAdd ( a, v );
        }

SDL_bool SDL_AtomicCASPtr ( void ** a, void * oldval, void * newval ) {
            TRACE();
            return sym::SDL_AtomicCASPtr ( a, oldval, newval );
        }

void * SDL_AtomicSetPtr ( void ** a, void * v ) {
            TRACE();
            return sym::SDL_AtomicSetPtr ( a, v );
        }

void * SDL_AtomicGetPtr ( void ** a ) {
            TRACE();
            return sym::SDL_AtomicGetPtr ( a );
        }

int SDL_SetError ( const char * fmt ) {
            TRACE();
            return sym::SDL_SetError ( fmt );
        }

const char * SDL_GetError (  ) {
            TRACE();
            return sym::SDL_GetError (  );
        }

void SDL_ClearError (  ) {
            TRACE();
            return sym::SDL_ClearError (  );
        }

int SDL_Error ( SDL_errorcode code ) {
            TRACE();
            return sym::SDL_Error ( code );
        }

SDL_mutex * SDL_CreateMutex (  ) {
            TRACE();
            return sym::SDL_CreateMutex (  );
        }

int SDL_LockMutex ( SDL_mutex * mutex ) {
            TRACE();
            return sym::SDL_LockMutex ( mutex );
        }

int SDL_TryLockMutex ( SDL_mutex * mutex ) {
            TRACE();
            return sym::SDL_TryLockMutex ( mutex );
        }

int SDL_UnlockMutex ( SDL_mutex * mutex ) {
            TRACE();
            return sym::SDL_UnlockMutex ( mutex );
        }

void SDL_DestroyMutex ( SDL_mutex * mutex ) {
            TRACE();
            return sym::SDL_DestroyMutex ( mutex );
        }

SDL_sem * SDL_CreateSemaphore ( Uint32 initial_value ) {
            TRACE();
            return sym::SDL_CreateSemaphore ( initial_value );
        }

void SDL_DestroySemaphore ( SDL_sem * sem ) {
            TRACE();
            return sym::SDL_DestroySemaphore ( sem );
        }

int SDL_SemWait ( SDL_sem * sem ) {
            TRACE();
            return sym::SDL_SemWait ( sem );
        }

int SDL_SemTryWait ( SDL_sem * sem ) {
            TRACE();
            return sym::SDL_SemTryWait ( sem );
        }

int SDL_SemWaitTimeout ( SDL_sem * sem, Uint32 ms ) {
            TRACE();
            return sym::SDL_SemWaitTimeout ( sem, ms );
        }

int SDL_SemPost ( SDL_sem * sem ) {
            TRACE();
            return sym::SDL_SemPost ( sem );
        }

Uint32 SDL_SemValue ( SDL_sem * sem ) {
            TRACE();
            return sym::SDL_SemValue ( sem );
        }

SDL_cond * SDL_CreateCond (  ) {
            TRACE();
            return sym::SDL_CreateCond (  );
        }

void SDL_DestroyCond ( SDL_cond * cond ) {
            TRACE();
            return sym::SDL_DestroyCond ( cond );
        }

int SDL_CondSignal ( SDL_cond * cond ) {
            TRACE();
            return sym::SDL_CondSignal ( cond );
        }

int SDL_CondBroadcast ( SDL_cond * cond ) {
            TRACE();
            return sym::SDL_CondBroadcast ( cond );
        }

int SDL_CondWait ( SDL_cond * cond, SDL_mutex * mutex ) {
            TRACE();
            return sym::SDL_CondWait ( cond, mutex );
        }

int SDL_CondWaitTimeout ( SDL_cond * cond, SDL_mutex * mutex, Uint32 ms ) {
            TRACE();
            return sym::SDL_CondWaitTimeout ( cond, mutex, ms );
        }

SDL_Thread * SDL_CreateThread ( SDL_ThreadFunction fn, const char * name, void * data ) {
            TRACE();
            return sym::SDL_CreateThread ( fn, name, data );
        }

const char * SDL_GetThreadName ( SDL_Thread * thread ) {
            TRACE();
            return sym::SDL_GetThreadName ( thread );
        }

SDL_threadID SDL_ThreadID (  ) {
            TRACE();
            return sym::SDL_ThreadID (  );
        }

SDL_threadID SDL_GetThreadID ( SDL_Thread * thread ) {
            TRACE();
            return sym::SDL_GetThreadID ( thread );
        }

int SDL_SetThreadPriority ( SDL_ThreadPriority priority ) {
            TRACE();
            return sym::SDL_SetThreadPriority ( priority );
        }

void SDL_WaitThread ( SDL_Thread * thread, int * status ) {
            TRACE();
            return sym::SDL_WaitThread ( thread, status );
        }

void SDL_DetachThread ( SDL_Thread * thread ) {
            TRACE();
            return sym::SDL_DetachThread ( thread );
        }

SDL_TLSID SDL_TLSCreate (  ) {
            TRACE();
            return sym::SDL_TLSCreate (  );
        }

void * SDL_TLSGet ( SDL_TLSID id ) {
            TRACE();
            return sym::SDL_TLSGet ( id );
        }

int SDL_TLSSet ( SDL_TLSID id, const void * value, void (*destructor)(void *) ) {
            TRACE();
            return sym::SDL_TLSSet ( id, value, destructor );
        }

SDL_RWops * SDL_RWFromFile ( const char * file, const char * mode ) {
            TRACE();
            return sym::SDL_RWFromFile ( file, mode );
        }

SDL_RWops * SDL_RWFromFP ( FILE * fp, SDL_bool autoclose ) {
            TRACE();
            return sym::SDL_RWFromFP ( fp, autoclose );
        }

SDL_RWops * SDL_RWFromMem ( void * mem, int size ) {
            TRACE();
            return sym::SDL_RWFromMem ( mem, size );
        }

SDL_RWops * SDL_RWFromConstMem ( const void * mem, int size ) {
            TRACE();
            return sym::SDL_RWFromConstMem ( mem, size );
        }

SDL_RWops * SDL_AllocRW (  ) {
            TRACE();
            return sym::SDL_AllocRW (  );
        }

void SDL_FreeRW ( SDL_RWops * area ) {
            TRACE();
            return sym::SDL_FreeRW ( area );
        }

void * SDL_LoadFile_RW ( SDL_RWops * src, size_t * datasize, int freesrc ) {
            TRACE();
            return sym::SDL_LoadFile_RW ( src, datasize, freesrc );
        }

Uint8 SDL_ReadU8 ( SDL_RWops * src ) {
            TRACE();
            return sym::SDL_ReadU8 ( src );
        }

Uint16 SDL_ReadLE16 ( SDL_RWops * src ) {
            TRACE();
            return sym::SDL_ReadLE16 ( src );
        }

Uint16 SDL_ReadBE16 ( SDL_RWops * src ) {
            TRACE();
            return sym::SDL_ReadBE16 ( src );
        }

Uint32 SDL_ReadLE32 ( SDL_RWops * src ) {
            TRACE();
            return sym::SDL_ReadLE32 ( src );
        }

Uint32 SDL_ReadBE32 ( SDL_RWops * src ) {
            TRACE();
            return sym::SDL_ReadBE32 ( src );
        }

Uint64 SDL_ReadLE64 ( SDL_RWops * src ) {
            TRACE();
            return sym::SDL_ReadLE64 ( src );
        }

Uint64 SDL_ReadBE64 ( SDL_RWops * src ) {
            TRACE();
            return sym::SDL_ReadBE64 ( src );
        }

size_t SDL_WriteU8 ( SDL_RWops * dst, Uint8 value ) {
            TRACE();
            return sym::SDL_WriteU8 ( dst, value );
        }

size_t SDL_WriteLE16 ( SDL_RWops * dst, Uint16 value ) {
            TRACE();
            return sym::SDL_WriteLE16 ( dst, value );
        }

size_t SDL_WriteBE16 ( SDL_RWops * dst, Uint16 value ) {
            TRACE();
            return sym::SDL_WriteBE16 ( dst, value );
        }

size_t SDL_WriteLE32 ( SDL_RWops * dst, Uint32 value ) {
            TRACE();
            return sym::SDL_WriteLE32 ( dst, value );
        }

size_t SDL_WriteBE32 ( SDL_RWops * dst, Uint32 value ) {
            TRACE();
            return sym::SDL_WriteBE32 ( dst, value );
        }

size_t SDL_WriteLE64 ( SDL_RWops * dst, Uint64 value ) {
            TRACE();
            return sym::SDL_WriteLE64 ( dst, value );
        }

size_t SDL_WriteBE64 ( SDL_RWops * dst, Uint64 value ) {
            TRACE();
            return sym::SDL_WriteBE64 ( dst, value );
        }

int SDL_GetNumAudioDrivers (  ) {
            TRACE();
            return sym::SDL_GetNumAudioDrivers (  );
        }

const char * SDL_GetAudioDriver ( int index ) {
            TRACE();
            return sym::SDL_GetAudioDriver ( index );
        }

int SDL_AudioInit ( const char * driver_name ) {
            TRACE();
            return sym::SDL_AudioInit ( driver_name );
        }

void SDL_AudioQuit (  ) {
            TRACE();
            return sym::SDL_AudioQuit (  );
        }

const char * SDL_GetCurrentAudioDriver (  ) {
            TRACE();
            return sym::SDL_GetCurrentAudioDriver (  );
        }

int SDL_OpenAudio ( SDL_AudioSpec * desired, SDL_AudioSpec * obtained ) {
            TRACE();
            return sym::SDL_OpenAudio ( desired, obtained );
        }

int SDL_GetNumAudioDevices ( int iscapture ) {
            TRACE();
            return sym::SDL_GetNumAudioDevices ( iscapture );
        }

const char * SDL_GetAudioDeviceName ( int index, int iscapture ) {
            TRACE();
            return sym::SDL_GetAudioDeviceName ( index, iscapture );
        }

SDL_AudioDeviceID SDL_OpenAudioDevice ( const char * device, int iscapture, const SDL_AudioSpec * desired, SDL_AudioSpec * obtained, int allowed_changes ) {
            TRACE();
            return sym::SDL_OpenAudioDevice ( device, iscapture, desired, obtained, allowed_changes );
        }

SDL_AudioStatus SDL_GetAudioStatus (  ) {
            TRACE();
            return sym::SDL_GetAudioStatus (  );
        }

SDL_AudioStatus SDL_GetAudioDeviceStatus ( SDL_AudioDeviceID dev ) {
            TRACE();
            return sym::SDL_GetAudioDeviceStatus ( dev );
        }

void SDL_PauseAudio ( int pause_on ) {
            TRACE();
            return sym::SDL_PauseAudio ( pause_on );
        }

void SDL_PauseAudioDevice ( SDL_AudioDeviceID dev, int pause_on ) {
            TRACE();
            return sym::SDL_PauseAudioDevice ( dev, pause_on );
        }

SDL_AudioSpec * SDL_LoadWAV_RW ( SDL_RWops * src, int freesrc, SDL_AudioSpec * spec, Uint8 ** audio_buf, Uint32 * audio_len ) {
            TRACE();
            return sym::SDL_LoadWAV_RW ( src, freesrc, spec, audio_buf, audio_len );
        }

void SDL_FreeWAV ( Uint8 * audio_buf ) {
            TRACE();
            return sym::SDL_FreeWAV ( audio_buf );
        }

int SDL_BuildAudioCVT ( SDL_AudioCVT * cvt, SDL_AudioFormat src_format, Uint8 src_channels, int src_rate, SDL_AudioFormat dst_format, Uint8 dst_channels, int dst_rate ) {
            TRACE();
            return sym::SDL_BuildAudioCVT ( cvt, src_format, src_channels, src_rate, dst_format, dst_channels, dst_rate );
        }

int SDL_ConvertAudio ( SDL_AudioCVT * cvt ) {
            TRACE();
            return sym::SDL_ConvertAudio ( cvt );
        }

SDL_AudioStream * SDL_NewAudioStream ( const SDL_AudioFormat src_format, const Uint8 src_channels, const int src_rate, const SDL_AudioFormat dst_format, const Uint8 dst_channels, const int dst_rate ) {
            TRACE();
            return sym::SDL_NewAudioStream ( src_format, src_channels, src_rate, dst_format, dst_channels, dst_rate );
        }

int SDL_AudioStreamPut ( SDL_AudioStream * stream, const void * buf, int len ) {
            TRACE();
            return sym::SDL_AudioStreamPut ( stream, buf, len );
        }

int SDL_AudioStreamGet ( SDL_AudioStream * stream, void * buf, int len ) {
            TRACE();
            return sym::SDL_AudioStreamGet ( stream, buf, len );
        }

int SDL_AudioStreamAvailable ( SDL_AudioStream * stream ) {
            TRACE();
            return sym::SDL_AudioStreamAvailable ( stream );
        }

int SDL_AudioStreamFlush ( SDL_AudioStream * stream ) {
            TRACE();
            return sym::SDL_AudioStreamFlush ( stream );
        }

void SDL_AudioStreamClear ( SDL_AudioStream * stream ) {
            TRACE();
            return sym::SDL_AudioStreamClear ( stream );
        }

void SDL_FreeAudioStream ( SDL_AudioStream * stream ) {
            TRACE();
            return sym::SDL_FreeAudioStream ( stream );
        }

void SDL_MixAudio ( Uint8 * dst, const Uint8 * src, Uint32 len, int volume ) {
            TRACE();
            return sym::SDL_MixAudio ( dst, src, len, volume );
        }

void SDL_MixAudioFormat ( Uint8 * dst, const Uint8 * src, SDL_AudioFormat format, Uint32 len, int volume ) {
            TRACE();
            return sym::SDL_MixAudioFormat ( dst, src, format, len, volume );
        }

int SDL_QueueAudio ( SDL_AudioDeviceID dev, const void * data, Uint32 len ) {
            TRACE();
            return sym::SDL_QueueAudio ( dev, data, len );
        }

Uint32 SDL_DequeueAudio ( SDL_AudioDeviceID dev, void * data, Uint32 len ) {
            TRACE();
            return sym::SDL_DequeueAudio ( dev, data, len );
        }

Uint32 SDL_GetQueuedAudioSize ( SDL_AudioDeviceID dev ) {
            TRACE();
            return sym::SDL_GetQueuedAudioSize ( dev );
        }

void SDL_ClearQueuedAudio ( SDL_AudioDeviceID dev ) {
            TRACE();
            return sym::SDL_ClearQueuedAudio ( dev );
        }

void SDL_LockAudio (  ) {
            TRACE();
            return sym::SDL_LockAudio (  );
        }

void SDL_LockAudioDevice ( SDL_AudioDeviceID dev ) {
            TRACE();
            return sym::SDL_LockAudioDevice ( dev );
        }

void SDL_UnlockAudio (  ) {
            TRACE();
            return sym::SDL_UnlockAudio (  );
        }

void SDL_UnlockAudioDevice ( SDL_AudioDeviceID dev ) {
            TRACE();
            return sym::SDL_UnlockAudioDevice ( dev );
        }

void SDL_CloseAudio (  ) {
            TRACE();
            return sym::SDL_CloseAudio (  );
        }

void SDL_CloseAudioDevice ( SDL_AudioDeviceID dev ) {
            TRACE();
            return sym::SDL_CloseAudioDevice ( dev );
        }

int SDL_SetClipboardText ( const char * text ) {
            TRACE();
            return sym::SDL_SetClipboardText ( text );
        }

char * SDL_GetClipboardText (  ) {
            TRACE();
            return sym::SDL_GetClipboardText (  );
        }

SDL_bool SDL_HasClipboardText (  ) {
            TRACE();
            return sym::SDL_HasClipboardText (  );
        }

int SDL_GetCPUCount (  ) {
            TRACE();
            return sym::SDL_GetCPUCount (  );
        }

int SDL_GetCPUCacheLineSize (  ) {
            TRACE();
            return sym::SDL_GetCPUCacheLineSize (  );
        }

SDL_bool SDL_HasRDTSC (  ) {
            TRACE();
            return sym::SDL_HasRDTSC (  );
        }

SDL_bool SDL_HasAltiVec (  ) {
            TRACE();
            return sym::SDL_HasAltiVec (  );
        }

SDL_bool SDL_HasMMX (  ) {
            TRACE();
            return sym::SDL_HasMMX (  );
        }

SDL_bool SDL_Has3DNow (  ) {
            TRACE();
            return sym::SDL_Has3DNow (  );
        }

SDL_bool SDL_HasSSE (  ) {
            TRACE();
            return sym::SDL_HasSSE (  );
        }

SDL_bool SDL_HasSSE2 (  ) {
            TRACE();
            return sym::SDL_HasSSE2 (  );
        }

SDL_bool SDL_HasSSE3 (  ) {
            TRACE();
            return sym::SDL_HasSSE3 (  );
        }

SDL_bool SDL_HasSSE41 (  ) {
            TRACE();
            return sym::SDL_HasSSE41 (  );
        }

SDL_bool SDL_HasSSE42 (  ) {
            TRACE();
            return sym::SDL_HasSSE42 (  );
        }

SDL_bool SDL_HasAVX (  ) {
            TRACE();
            return sym::SDL_HasAVX (  );
        }

SDL_bool SDL_HasAVX2 (  ) {
            TRACE();
            return sym::SDL_HasAVX2 (  );
        }

SDL_bool SDL_HasNEON (  ) {
            TRACE();
            return sym::SDL_HasNEON (  );
        }

int SDL_GetSystemRAM (  ) {
            TRACE();
            return sym::SDL_GetSystemRAM (  );
        }

const char * SDL_GetPixelFormatName ( Uint32 format ) {
            TRACE();
            return sym::SDL_GetPixelFormatName ( format );
        }

SDL_bool SDL_PixelFormatEnumToMasks ( Uint32 format, int * bpp, Uint32 * Rmask, Uint32 * Gmask, Uint32 * Bmask, Uint32 * Amask ) {
            TRACE();
            return sym::SDL_PixelFormatEnumToMasks ( format, bpp, Rmask, Gmask, Bmask, Amask );
        }

Uint32 SDL_MasksToPixelFormatEnum ( int bpp, Uint32 Rmask, Uint32 Gmask, Uint32 Bmask, Uint32 Amask ) {
            TRACE();
            return sym::SDL_MasksToPixelFormatEnum ( bpp, Rmask, Gmask, Bmask, Amask );
        }

SDL_PixelFormat * SDL_AllocFormat ( Uint32 pixel_format ) {
            TRACE();
            return sym::SDL_AllocFormat ( pixel_format );
        }

void SDL_FreeFormat ( SDL_PixelFormat * format ) {
            TRACE();
            return sym::SDL_FreeFormat ( format );
        }

SDL_Palette * SDL_AllocPalette ( int ncolors ) {
            TRACE();
            return sym::SDL_AllocPalette ( ncolors );
        }

int SDL_SetPixelFormatPalette ( SDL_PixelFormat * format, SDL_Palette * palette ) {
            TRACE();
            return sym::SDL_SetPixelFormatPalette ( format, palette );
        }

int SDL_SetPaletteColors ( SDL_Palette * palette, const SDL_Color * colors, int firstcolor, int ncolors ) {
            TRACE();
            return sym::SDL_SetPaletteColors ( palette, colors, firstcolor, ncolors );
        }

void SDL_FreePalette ( SDL_Palette * palette ) {
            TRACE();
            return sym::SDL_FreePalette ( palette );
        }

Uint32 SDL_MapRGB ( const SDL_PixelFormat * format, Uint8 r, Uint8 g, Uint8 b ) {
            TRACE();
            return sym::SDL_MapRGB ( format, r, g, b );
        }

Uint32 SDL_MapRGBA ( const SDL_PixelFormat * format, Uint8 r, Uint8 g, Uint8 b, Uint8 a ) {
            TRACE();
            return sym::SDL_MapRGBA ( format, r, g, b, a );
        }

void SDL_GetRGB ( Uint32 pixel, const SDL_PixelFormat * format, Uint8 * r, Uint8 * g, Uint8 * b ) {
            TRACE();
            return sym::SDL_GetRGB ( pixel, format, r, g, b );
        }

void SDL_GetRGBA ( Uint32 pixel, const SDL_PixelFormat * format, Uint8 * r, Uint8 * g, Uint8 * b, Uint8 * a ) {
            TRACE();
            return sym::SDL_GetRGBA ( pixel, format, r, g, b, a );
        }

void SDL_CalculateGammaRamp ( float gamma, Uint16 * ramp ) {
            TRACE();
            return sym::SDL_CalculateGammaRamp ( gamma, ramp );
        }

SDL_bool SDL_HasIntersection ( const SDL_Rect * A, const SDL_Rect * B ) {
            TRACE();
            return sym::SDL_HasIntersection ( A, B );
        }

SDL_bool SDL_IntersectRect ( const SDL_Rect * A, const SDL_Rect * B, SDL_Rect * result ) {
            TRACE();
            return sym::SDL_IntersectRect ( A, B, result );
        }

void SDL_UnionRect ( const SDL_Rect * A, const SDL_Rect * B, SDL_Rect * result ) {
            TRACE();
            return sym::SDL_UnionRect ( A, B, result );
        }

SDL_bool SDL_EnclosePoints ( const SDL_Point * points, int count, const SDL_Rect * clip, SDL_Rect * result ) {
            TRACE();
            return sym::SDL_EnclosePoints ( points, count, clip, result );
        }

SDL_bool SDL_IntersectRectAndLine ( const SDL_Rect * rect, int * X1, int * Y1, int * X2, int * Y2 ) {
            TRACE();
            return sym::SDL_IntersectRectAndLine ( rect, X1, Y1, X2, Y2 );
        }

SDL_BlendMode SDL_ComposeCustomBlendMode ( SDL_BlendFactor srcColorFactor, SDL_BlendFactor dstColorFactor, SDL_BlendOperation colorOperation, SDL_BlendFactor srcAlphaFactor, SDL_BlendFactor dstAlphaFactor, SDL_BlendOperation alphaOperation ) {
            TRACE();
            return sym::SDL_ComposeCustomBlendMode ( srcColorFactor, dstColorFactor, colorOperation, srcAlphaFactor, dstAlphaFactor, alphaOperation );
        }

SDL_Surface * SDL_CreateRGBSurface ( Uint32 flags, int width, int height, int depth, Uint32 Rmask, Uint32 Gmask, Uint32 Bmask, Uint32 Amask ) {
            TRACE();
            return sym::SDL_CreateRGBSurface ( flags, width, height, depth, Rmask, Gmask, Bmask, Amask );
        }

SDL_Surface * SDL_CreateRGBSurfaceWithFormat ( Uint32 flags, int width, int height, int depth, Uint32 format ) {
            TRACE();
            return sym::SDL_CreateRGBSurfaceWithFormat ( flags, width, height, depth, format );
        }

SDL_Surface * SDL_CreateRGBSurfaceFrom ( void * pixels, int width, int height, int depth, int pitch, Uint32 Rmask, Uint32 Gmask, Uint32 Bmask, Uint32 Amask ) {
            TRACE();
            return sym::SDL_CreateRGBSurfaceFrom ( pixels, width, height, depth, pitch, Rmask, Gmask, Bmask, Amask );
        }

SDL_Surface * SDL_CreateRGBSurfaceWithFormatFrom ( void * pixels, int width, int height, int depth, int pitch, Uint32 format ) {
            TRACE();
            return sym::SDL_CreateRGBSurfaceWithFormatFrom ( pixels, width, height, depth, pitch, format );
        }

void SDL_FreeSurface ( SDL_Surface * surface ) {
            TRACE();
            return sym::SDL_FreeSurface ( surface );
        }

int SDL_SetSurfacePalette ( SDL_Surface * surface, SDL_Palette * palette ) {
            TRACE();
            return sym::SDL_SetSurfacePalette ( surface, palette );
        }

int SDL_LockSurface ( SDL_Surface * surface ) {
            TRACE();
            return sym::SDL_LockSurface ( surface );
        }

void SDL_UnlockSurface ( SDL_Surface * surface ) {
            TRACE();
            return sym::SDL_UnlockSurface ( surface );
        }

SDL_Surface * SDL_LoadBMP_RW ( SDL_RWops * src, int freesrc ) {
            TRACE();
            return sym::SDL_LoadBMP_RW ( src, freesrc );
        }

int SDL_SaveBMP_RW ( SDL_Surface * surface, SDL_RWops * dst, int freedst ) {
            TRACE();
            return sym::SDL_SaveBMP_RW ( surface, dst, freedst );
        }

int SDL_SetSurfaceRLE ( SDL_Surface * surface, int flag ) {
            TRACE();
            return sym::SDL_SetSurfaceRLE ( surface, flag );
        }

int SDL_SetColorKey ( SDL_Surface * surface, int flag, Uint32 key ) {
            TRACE();
            return sym::SDL_SetColorKey ( surface, flag, key );
        }

int SDL_GetColorKey ( SDL_Surface * surface, Uint32 * key ) {
            TRACE();
            return sym::SDL_GetColorKey ( surface, key );
        }

int SDL_SetSurfaceColorMod ( SDL_Surface * surface, Uint8 r, Uint8 g, Uint8 b ) {
            TRACE();
            return sym::SDL_SetSurfaceColorMod ( surface, r, g, b );
        }

int SDL_GetSurfaceColorMod ( SDL_Surface * surface, Uint8 * r, Uint8 * g, Uint8 * b ) {
            TRACE();
            return sym::SDL_GetSurfaceColorMod ( surface, r, g, b );
        }

int SDL_SetSurfaceAlphaMod ( SDL_Surface * surface, Uint8 alpha ) {
            TRACE();
            return sym::SDL_SetSurfaceAlphaMod ( surface, alpha );
        }

int SDL_GetSurfaceAlphaMod ( SDL_Surface * surface, Uint8 * alpha ) {
            TRACE();
            return sym::SDL_GetSurfaceAlphaMod ( surface, alpha );
        }

int SDL_SetSurfaceBlendMode ( SDL_Surface * surface, SDL_BlendMode blendMode ) {
            TRACE();
            return sym::SDL_SetSurfaceBlendMode ( surface, blendMode );
        }

int SDL_GetSurfaceBlendMode ( SDL_Surface * surface, SDL_BlendMode * blendMode ) {
            TRACE();
            return sym::SDL_GetSurfaceBlendMode ( surface, blendMode );
        }

SDL_bool SDL_SetClipRect ( SDL_Surface * surface, const SDL_Rect * rect ) {
            TRACE();
            return sym::SDL_SetClipRect ( surface, rect );
        }

void SDL_GetClipRect ( SDL_Surface * surface, SDL_Rect * rect ) {
            TRACE();
            return sym::SDL_GetClipRect ( surface, rect );
        }

SDL_Surface * SDL_DuplicateSurface ( SDL_Surface * surface ) {
            TRACE();
            return sym::SDL_DuplicateSurface ( surface );
        }

SDL_Surface * SDL_ConvertSurface ( SDL_Surface * src, const SDL_PixelFormat * fmt, Uint32 flags ) {
            TRACE();
            return sym::SDL_ConvertSurface ( src, fmt, flags );
        }

SDL_Surface * SDL_ConvertSurfaceFormat ( SDL_Surface * src, Uint32 pixel_format, Uint32 flags ) {
            TRACE();
            return sym::SDL_ConvertSurfaceFormat ( src, pixel_format, flags );
        }

int SDL_ConvertPixels ( int width, int height, Uint32 src_format, const void * src, int src_pitch, Uint32 dst_format, void * dst, int dst_pitch ) {
            TRACE();
            return sym::SDL_ConvertPixels ( width, height, src_format, src, src_pitch, dst_format, dst, dst_pitch );
        }

int SDL_FillRect ( SDL_Surface * dst, const SDL_Rect * rect, Uint32 color ) {
            TRACE();
            return sym::SDL_FillRect ( dst, rect, color );
        }

int SDL_FillRects ( SDL_Surface * dst, const SDL_Rect * rects, int count, Uint32 color ) {
            TRACE();
            return sym::SDL_FillRects ( dst, rects, count, color );
        }

int SDL_UpperBlit ( SDL_Surface * src, const SDL_Rect * srcrect, SDL_Surface * dst, SDL_Rect * dstrect ) {
            TRACE();
            return sym::SDL_UpperBlit ( src, srcrect, dst, dstrect );
        }

int SDL_LowerBlit ( SDL_Surface * src, SDL_Rect * srcrect, SDL_Surface * dst, SDL_Rect * dstrect ) {
            TRACE();
            return sym::SDL_LowerBlit ( src, srcrect, dst, dstrect );
        }

int SDL_SoftStretch ( SDL_Surface * src, const SDL_Rect * srcrect, SDL_Surface * dst, const SDL_Rect * dstrect ) {
            TRACE();
            return sym::SDL_SoftStretch ( src, srcrect, dst, dstrect );
        }

int SDL_UpperBlitScaled ( SDL_Surface * src, const SDL_Rect * srcrect, SDL_Surface * dst, SDL_Rect * dstrect ) {
            TRACE();
            return sym::SDL_UpperBlitScaled ( src, srcrect, dst, dstrect );
        }

int SDL_LowerBlitScaled ( SDL_Surface * src, SDL_Rect * srcrect, SDL_Surface * dst, SDL_Rect * dstrect ) {
            TRACE();
            return sym::SDL_LowerBlitScaled ( src, srcrect, dst, dstrect );
        }

void SDL_SetYUVConversionMode ( SDL_YUV_CONVERSION_MODE mode ) {
            TRACE();
            return sym::SDL_SetYUVConversionMode ( mode );
        }

SDL_YUV_CONVERSION_MODE SDL_GetYUVConversionMode (  ) {
            TRACE();
            return sym::SDL_GetYUVConversionMode (  );
        }

SDL_YUV_CONVERSION_MODE SDL_GetYUVConversionModeForResolution ( int width, int height ) {
            TRACE();
            return sym::SDL_GetYUVConversionModeForResolution ( width, height );
        }

int SDL_GetNumVideoDrivers (  ) {
            TRACE();
            return sym::SDL_GetNumVideoDrivers (  );
        }

const char * SDL_GetVideoDriver ( int index ) {
            TRACE();
            return sym::SDL_GetVideoDriver ( index );
        }

int SDL_VideoInit ( const char * driver_name ) {
            TRACE();
            return sym::SDL_VideoInit ( driver_name );
        }

void SDL_VideoQuit (  ) {
            TRACE();
            return sym::SDL_VideoQuit (  );
        }

const char * SDL_GetCurrentVideoDriver (  ) {
            TRACE();
            return sym::SDL_GetCurrentVideoDriver (  );
        }

int SDL_GetNumVideoDisplays (  ) {
            TRACE();
            return sym::SDL_GetNumVideoDisplays (  );
        }

const char * SDL_GetDisplayName ( int displayIndex ) {
            TRACE();
            return sym::SDL_GetDisplayName ( displayIndex );
        }

int SDL_GetDisplayBounds ( int displayIndex, SDL_Rect * rect ) {
            TRACE();
            return sym::SDL_GetDisplayBounds ( displayIndex, rect );
        }

int SDL_GetDisplayDPI ( int displayIndex, float * ddpi, float * hdpi, float * vdpi ) {
            TRACE();
            return sym::SDL_GetDisplayDPI ( displayIndex, ddpi, hdpi, vdpi );
        }

int SDL_GetDisplayUsableBounds ( int displayIndex, SDL_Rect * rect ) {
            TRACE();
            return sym::SDL_GetDisplayUsableBounds ( displayIndex, rect );
        }

int SDL_GetNumDisplayModes ( int displayIndex ) {
            TRACE();
            return sym::SDL_GetNumDisplayModes ( displayIndex );
        }

int SDL_GetDisplayMode ( int displayIndex, int modeIndex, SDL_DisplayMode * mode ) {
            TRACE();
            return sym::SDL_GetDisplayMode ( displayIndex, modeIndex, mode );
        }

int SDL_GetDesktopDisplayMode ( int displayIndex, SDL_DisplayMode * mode ) {
            TRACE();
            return sym::SDL_GetDesktopDisplayMode ( displayIndex, mode );
        }

int SDL_GetCurrentDisplayMode ( int displayIndex, SDL_DisplayMode * mode ) {
            TRACE();
            return sym::SDL_GetCurrentDisplayMode ( displayIndex, mode );
        }

SDL_DisplayMode * SDL_GetClosestDisplayMode ( int displayIndex, const SDL_DisplayMode * mode, SDL_DisplayMode * closest ) {
            TRACE();
            return sym::SDL_GetClosestDisplayMode ( displayIndex, mode, closest );
        }

int SDL_GetWindowDisplayIndex ( SDL_Window * window ) {
            TRACE();
            return sym::SDL_GetWindowDisplayIndex ( window );
        }

int SDL_SetWindowDisplayMode ( SDL_Window * window, const SDL_DisplayMode * mode ) {
            TRACE();
            return sym::SDL_SetWindowDisplayMode ( window, mode );
        }

int SDL_GetWindowDisplayMode ( SDL_Window * window, SDL_DisplayMode * mode ) {
            TRACE();
            return sym::SDL_GetWindowDisplayMode ( window, mode );
        }

Uint32 SDL_GetWindowPixelFormat ( SDL_Window * window ) {
            TRACE();
            return sym::SDL_GetWindowPixelFormat ( window );
        }

SDL_Window * SDL_CreateWindow ( const char * title, int x, int y, int w, int h, Uint32 flags ) {
            TRACE();
            return sym::SDL_CreateWindow ( title, x, y, w, h, flags );
        }

SDL_Window * SDL_CreateWindowFrom ( const void * data ) {
            TRACE();
            return sym::SDL_CreateWindowFrom ( data );
        }

Uint32 SDL_GetWindowID ( SDL_Window * window ) {
            TRACE();
            return sym::SDL_GetWindowID ( window );
        }

SDL_Window * SDL_GetWindowFromID ( Uint32 id ) {
            TRACE();
            return sym::SDL_GetWindowFromID ( id );
        }

Uint32 SDL_GetWindowFlags ( SDL_Window * window ) {
            TRACE();
            return sym::SDL_GetWindowFlags ( window );
        }

void SDL_SetWindowTitle ( SDL_Window * window, const char * title ) {
            TRACE();
            return sym::SDL_SetWindowTitle ( window, title );
        }

const char * SDL_GetWindowTitle ( SDL_Window * window ) {
            TRACE();
            return sym::SDL_GetWindowTitle ( window );
        }

void SDL_SetWindowIcon ( SDL_Window * window, SDL_Surface * icon ) {
            TRACE();
            return sym::SDL_SetWindowIcon ( window, icon );
        }

void * SDL_SetWindowData ( SDL_Window * window, const char * name, void * userdata ) {
            TRACE();
            return sym::SDL_SetWindowData ( window, name, userdata );
        }

void * SDL_GetWindowData ( SDL_Window * window, const char * name ) {
            TRACE();
            return sym::SDL_GetWindowData ( window, name );
        }

void SDL_SetWindowPosition ( SDL_Window * window, int x, int y ) {
            TRACE();
            return sym::SDL_SetWindowPosition ( window, x, y );
        }

void SDL_GetWindowPosition ( SDL_Window * window, int * x, int * y ) {
            TRACE();
            return sym::SDL_GetWindowPosition ( window, x, y );
        }

void SDL_SetWindowSize ( SDL_Window * window, int w, int h ) {
            TRACE();
            return sym::SDL_SetWindowSize ( window, w, h );
        }

void SDL_GetWindowSize ( SDL_Window * window, int * w, int * h ) {
            TRACE();
            return sym::SDL_GetWindowSize ( window, w, h );
        }

int SDL_GetWindowBordersSize ( SDL_Window * window, int * top, int * left, int * bottom, int * right ) {
            TRACE();
            return sym::SDL_GetWindowBordersSize ( window, top, left, bottom, right );
        }

void SDL_SetWindowMinimumSize ( SDL_Window * window, int min_w, int min_h ) {
            TRACE();
            return sym::SDL_SetWindowMinimumSize ( window, min_w, min_h );
        }

void SDL_GetWindowMinimumSize ( SDL_Window * window, int * w, int * h ) {
            TRACE();
            return sym::SDL_GetWindowMinimumSize ( window, w, h );
        }

void SDL_SetWindowMaximumSize ( SDL_Window * window, int max_w, int max_h ) {
            TRACE();
            return sym::SDL_SetWindowMaximumSize ( window, max_w, max_h );
        }

void SDL_GetWindowMaximumSize ( SDL_Window * window, int * w, int * h ) {
            TRACE();
            return sym::SDL_GetWindowMaximumSize ( window, w, h );
        }

void SDL_SetWindowBordered ( SDL_Window * window, SDL_bool bordered ) {
            TRACE();
            return sym::SDL_SetWindowBordered ( window, bordered );
        }

void SDL_SetWindowResizable ( SDL_Window * window, SDL_bool resizable ) {
            TRACE();
            return sym::SDL_SetWindowResizable ( window, resizable );
        }

void SDL_ShowWindow ( SDL_Window * window ) {
            TRACE();
            return sym::SDL_ShowWindow ( window );
        }

void SDL_HideWindow ( SDL_Window * window ) {
            TRACE();
            return sym::SDL_HideWindow ( window );
        }

void SDL_RaiseWindow ( SDL_Window * window ) {
            TRACE();
            return sym::SDL_RaiseWindow ( window );
        }

void SDL_MaximizeWindow ( SDL_Window * window ) {
            TRACE();
            return sym::SDL_MaximizeWindow ( window );
        }

void SDL_MinimizeWindow ( SDL_Window * window ) {
            TRACE();
            return sym::SDL_MinimizeWindow ( window );
        }

void SDL_RestoreWindow ( SDL_Window * window ) {
            TRACE();
            return sym::SDL_RestoreWindow ( window );
        }

int SDL_SetWindowFullscreen ( SDL_Window * window, Uint32 flags ) {
            TRACE();
            return sym::SDL_SetWindowFullscreen ( window, flags );
        }

SDL_Surface * SDL_GetWindowSurface ( SDL_Window * window ) {
            TRACE();
            return sym::SDL_GetWindowSurface ( window );
        }

int SDL_UpdateWindowSurface ( SDL_Window * window ) {
            TRACE();
            return sym::SDL_UpdateWindowSurface ( window );
        }

int SDL_UpdateWindowSurfaceRects ( SDL_Window * window, const SDL_Rect * rects, int numrects ) {
            TRACE();
            return sym::SDL_UpdateWindowSurfaceRects ( window, rects, numrects );
        }

void SDL_SetWindowGrab ( SDL_Window * window, SDL_bool grabbed ) {
            TRACE();
            return sym::SDL_SetWindowGrab ( window, grabbed );
        }

SDL_bool SDL_GetWindowGrab ( SDL_Window * window ) {
            TRACE();
            return sym::SDL_GetWindowGrab ( window );
        }

SDL_Window * SDL_GetGrabbedWindow (  ) {
            TRACE();
            return sym::SDL_GetGrabbedWindow (  );
        }

int SDL_SetWindowBrightness ( SDL_Window * window, float brightness ) {
            TRACE();
            return sym::SDL_SetWindowBrightness ( window, brightness );
        }

float SDL_GetWindowBrightness ( SDL_Window * window ) {
            TRACE();
            return sym::SDL_GetWindowBrightness ( window );
        }

int SDL_SetWindowOpacity ( SDL_Window * window, float opacity ) {
            TRACE();
            return sym::SDL_SetWindowOpacity ( window, opacity );
        }

int SDL_GetWindowOpacity ( SDL_Window * window, float * out_opacity ) {
            TRACE();
            return sym::SDL_GetWindowOpacity ( window, out_opacity );
        }

int SDL_SetWindowModalFor ( SDL_Window * modal_window, SDL_Window * parent_window ) {
            TRACE();
            return sym::SDL_SetWindowModalFor ( modal_window, parent_window );
        }

int SDL_SetWindowInputFocus ( SDL_Window * window ) {
            TRACE();
            return sym::SDL_SetWindowInputFocus ( window );
        }

int SDL_SetWindowGammaRamp ( SDL_Window * window, const Uint16 * red, const Uint16 * green, const Uint16 * blue ) {
            TRACE();
            return sym::SDL_SetWindowGammaRamp ( window, red, green, blue );
        }

int SDL_GetWindowGammaRamp ( SDL_Window * window, Uint16 * red, Uint16 * green, Uint16 * blue ) {
            TRACE();
            return sym::SDL_GetWindowGammaRamp ( window, red, green, blue );
        }

int SDL_SetWindowHitTest ( SDL_Window * window, SDL_HitTest callback, void * callback_data ) {
            TRACE();
            return sym::SDL_SetWindowHitTest ( window, callback, callback_data );
        }

void SDL_DestroyWindow ( SDL_Window * window ) {
            TRACE();
            return sym::SDL_DestroyWindow ( window );
        }

SDL_bool SDL_IsScreenSaverEnabled (  ) {
            TRACE();
            return sym::SDL_IsScreenSaverEnabled (  );
        }

void SDL_EnableScreenSaver (  ) {
            TRACE();
            return sym::SDL_EnableScreenSaver (  );
        }

void SDL_DisableScreenSaver (  ) {
            TRACE();
            return sym::SDL_DisableScreenSaver (  );
        }

int SDL_GL_LoadLibrary ( const char * path ) {
            TRACE();
            return sym::SDL_GL_LoadLibrary ( path );
        }

void * SDL_GL_GetProcAddress ( const char * proc ) {
            TRACE();
            return sym::SDL_GL_GetProcAddress ( proc );
        }

void SDL_GL_UnloadLibrary (  ) {
            TRACE();
            return sym::SDL_GL_UnloadLibrary (  );
        }

SDL_bool SDL_GL_ExtensionSupported ( const char * extension ) {
            TRACE();
            return sym::SDL_GL_ExtensionSupported ( extension );
        }

void SDL_GL_ResetAttributes (  ) {
            TRACE();
            return sym::SDL_GL_ResetAttributes (  );
        }

int SDL_GL_SetAttribute ( SDL_GLattr attr, int value ) {
            TRACE();
            return sym::SDL_GL_SetAttribute ( attr, value );
        }

int SDL_GL_GetAttribute ( SDL_GLattr attr, int * value ) {
            TRACE();
            return sym::SDL_GL_GetAttribute ( attr, value );
        }

SDL_GLContext SDL_GL_CreateContext ( SDL_Window * window ) {
            TRACE();
            return sym::SDL_GL_CreateContext ( window );
        }

int SDL_GL_MakeCurrent ( SDL_Window * window, SDL_GLContext context ) {
            TRACE();
            return sym::SDL_GL_MakeCurrent ( window, context );
        }

SDL_Window * SDL_GL_GetCurrentWindow (  ) {
            TRACE();
            return sym::SDL_GL_GetCurrentWindow (  );
        }

SDL_GLContext SDL_GL_GetCurrentContext (  ) {
            TRACE();
            return sym::SDL_GL_GetCurrentContext (  );
        }

void SDL_GL_GetDrawableSize ( SDL_Window * window, int * w, int * h ) {
            TRACE();
            return sym::SDL_GL_GetDrawableSize ( window, w, h );
        }

int SDL_GL_SetSwapInterval ( int interval ) {
            TRACE();
            return sym::SDL_GL_SetSwapInterval ( interval );
        }

int SDL_GL_GetSwapInterval (  ) {
            TRACE();
            return sym::SDL_GL_GetSwapInterval (  );
        }

void SDL_GL_SwapWindow ( SDL_Window * window ) {
            TRACE();
            return sym::SDL_GL_SwapWindow ( window );
        }

void SDL_GL_DeleteContext ( SDL_GLContext context ) {
            TRACE();
            return sym::SDL_GL_DeleteContext ( context );
        }

SDL_Window * SDL_GetKeyboardFocus (  ) {
            TRACE();
            return sym::SDL_GetKeyboardFocus (  );
        }

const Uint8 * SDL_GetKeyboardState ( int * numkeys ) {
            TRACE();
            return sym::SDL_GetKeyboardState ( numkeys );
        }

SDL_Keymod SDL_GetModState (  ) {
            TRACE();
            return sym::SDL_GetModState (  );
        }

void SDL_SetModState ( SDL_Keymod modstate ) {
            TRACE();
            return sym::SDL_SetModState ( modstate );
        }

SDL_Keycode SDL_GetKeyFromScancode ( SDL_Scancode scancode ) {
            TRACE();
            return sym::SDL_GetKeyFromScancode ( scancode );
        }

SDL_Scancode SDL_GetScancodeFromKey ( SDL_Keycode key ) {
            TRACE();
            return sym::SDL_GetScancodeFromKey ( key );
        }

const char * SDL_GetScancodeName ( SDL_Scancode scancode ) {
            TRACE();
            return sym::SDL_GetScancodeName ( scancode );
        }

SDL_Scancode SDL_GetScancodeFromName ( const char * name ) {
            TRACE();
            return sym::SDL_GetScancodeFromName ( name );
        }

const char * SDL_GetKeyName ( SDL_Keycode key ) {
            TRACE();
            return sym::SDL_GetKeyName ( key );
        }

SDL_Keycode SDL_GetKeyFromName ( const char * name ) {
            TRACE();
            return sym::SDL_GetKeyFromName ( name );
        }

void SDL_StartTextInput (  ) {
            TRACE();
            return sym::SDL_StartTextInput (  );
        }

SDL_bool SDL_IsTextInputActive (  ) {
            TRACE();
            return sym::SDL_IsTextInputActive (  );
        }

void SDL_StopTextInput (  ) {
            TRACE();
            return sym::SDL_StopTextInput (  );
        }

void SDL_SetTextInputRect ( SDL_Rect * rect ) {
            TRACE();
            return sym::SDL_SetTextInputRect ( rect );
        }

SDL_bool SDL_HasScreenKeyboardSupport (  ) {
            TRACE();
            return sym::SDL_HasScreenKeyboardSupport (  );
        }

SDL_bool SDL_IsScreenKeyboardShown ( SDL_Window * window ) {
            TRACE();
            return sym::SDL_IsScreenKeyboardShown ( window );
        }

SDL_Window * SDL_GetMouseFocus (  ) {
            TRACE();
            return sym::SDL_GetMouseFocus (  );
        }

Uint32 SDL_GetMouseState ( int * x, int * y ) {
            TRACE();
            return sym::SDL_GetMouseState ( x, y );
        }

Uint32 SDL_GetGlobalMouseState ( int * x, int * y ) {
            TRACE();
            return sym::SDL_GetGlobalMouseState ( x, y );
        }

Uint32 SDL_GetRelativeMouseState ( int * x, int * y ) {
            TRACE();
            return sym::SDL_GetRelativeMouseState ( x, y );
        }

void SDL_WarpMouseInWindow ( SDL_Window * window, int x, int y ) {
            TRACE();
            return sym::SDL_WarpMouseInWindow ( window, x, y );
        }

int SDL_WarpMouseGlobal ( int x, int y ) {
            TRACE();
            return sym::SDL_WarpMouseGlobal ( x, y );
        }

int SDL_SetRelativeMouseMode ( SDL_bool enabled ) {
            TRACE();
            return sym::SDL_SetRelativeMouseMode ( enabled );
        }

int SDL_CaptureMouse ( SDL_bool enabled ) {
            TRACE();
            return sym::SDL_CaptureMouse ( enabled );
        }

SDL_bool SDL_GetRelativeMouseMode (  ) {
            TRACE();
            return sym::SDL_GetRelativeMouseMode (  );
        }

SDL_Cursor * SDL_CreateCursor ( const Uint8 * data, const Uint8 * mask, int w, int h, int hot_x, int hot_y ) {
            TRACE();
            return sym::SDL_CreateCursor ( data, mask, w, h, hot_x, hot_y );
        }

SDL_Cursor * SDL_CreateColorCursor ( SDL_Surface * surface, int hot_x, int hot_y ) {
            TRACE();
            return sym::SDL_CreateColorCursor ( surface, hot_x, hot_y );
        }

SDL_Cursor * SDL_CreateSystemCursor ( SDL_SystemCursor id ) {
            TRACE();
            return sym::SDL_CreateSystemCursor ( id );
        }

void SDL_SetCursor ( SDL_Cursor * cursor ) {
            TRACE();
            return sym::SDL_SetCursor ( cursor );
        }

SDL_Cursor * SDL_GetCursor (  ) {
            TRACE();
            return sym::SDL_GetCursor (  );
        }

SDL_Cursor * SDL_GetDefaultCursor (  ) {
            TRACE();
            return sym::SDL_GetDefaultCursor (  );
        }

void SDL_FreeCursor ( SDL_Cursor * cursor ) {
            TRACE();
            return sym::SDL_FreeCursor ( cursor );
        }

int SDL_ShowCursor ( int toggle ) {
            TRACE();
            return sym::SDL_ShowCursor ( toggle );
        }

void SDL_LockJoysticks (  ) {
            TRACE();
            return sym::SDL_LockJoysticks (  );
        }

void SDL_UnlockJoysticks (  ) {
            TRACE();
            return sym::SDL_UnlockJoysticks (  );
        }

int SDL_NumJoysticks (  ) {
            TRACE();
            return sym::SDL_NumJoysticks (  );
        }

const char * SDL_JoystickNameForIndex ( int device_index ) {
            TRACE();
            return sym::SDL_JoystickNameForIndex ( device_index );
        }

SDL_JoystickGUID SDL_JoystickGetDeviceGUID ( int device_index ) {
            TRACE();
            return sym::SDL_JoystickGetDeviceGUID ( device_index );
        }

Uint16 SDL_JoystickGetDeviceVendor ( int device_index ) {
            TRACE();
            return sym::SDL_JoystickGetDeviceVendor ( device_index );
        }

Uint16 SDL_JoystickGetDeviceProduct ( int device_index ) {
            TRACE();
            return sym::SDL_JoystickGetDeviceProduct ( device_index );
        }

Uint16 SDL_JoystickGetDeviceProductVersion ( int device_index ) {
            TRACE();
            return sym::SDL_JoystickGetDeviceProductVersion ( device_index );
        }

SDL_JoystickType SDL_JoystickGetDeviceType ( int device_index ) {
            TRACE();
            return sym::SDL_JoystickGetDeviceType ( device_index );
        }

SDL_JoystickID SDL_JoystickGetDeviceInstanceID ( int device_index ) {
            TRACE();
            return sym::SDL_JoystickGetDeviceInstanceID ( device_index );
        }

SDL_Joystick * SDL_JoystickOpen ( int device_index ) {
            TRACE();
            return sym::SDL_JoystickOpen ( device_index );
        }

SDL_Joystick * SDL_JoystickFromInstanceID ( SDL_JoystickID joyid ) {
            TRACE();
            return sym::SDL_JoystickFromInstanceID ( joyid );
        }

const char * SDL_JoystickName ( SDL_Joystick * joystick ) {
            TRACE();
            return sym::SDL_JoystickName ( joystick );
        }

SDL_JoystickGUID SDL_JoystickGetGUID ( SDL_Joystick * joystick ) {
            TRACE();
            return sym::SDL_JoystickGetGUID ( joystick );
        }

Uint16 SDL_JoystickGetVendor ( SDL_Joystick * joystick ) {
            TRACE();
            return sym::SDL_JoystickGetVendor ( joystick );
        }

Uint16 SDL_JoystickGetProduct ( SDL_Joystick * joystick ) {
            TRACE();
            return sym::SDL_JoystickGetProduct ( joystick );
        }

Uint16 SDL_JoystickGetProductVersion ( SDL_Joystick * joystick ) {
            TRACE();
            return sym::SDL_JoystickGetProductVersion ( joystick );
        }

SDL_JoystickType SDL_JoystickGetType ( SDL_Joystick * joystick ) {
            TRACE();
            return sym::SDL_JoystickGetType ( joystick );
        }

void SDL_JoystickGetGUIDString ( SDL_JoystickGUID guid, char * pszGUID, int cbGUID ) {
            TRACE();
            return sym::SDL_JoystickGetGUIDString ( guid, pszGUID, cbGUID );
        }

SDL_JoystickGUID SDL_JoystickGetGUIDFromString ( const char * pchGUID ) {
            TRACE();
            return sym::SDL_JoystickGetGUIDFromString ( pchGUID );
        }

SDL_bool SDL_JoystickGetAttached ( SDL_Joystick * joystick ) {
            TRACE();
            return sym::SDL_JoystickGetAttached ( joystick );
        }

SDL_JoystickID SDL_JoystickInstanceID ( SDL_Joystick * joystick ) {
            TRACE();
            return sym::SDL_JoystickInstanceID ( joystick );
        }

int SDL_JoystickNumAxes ( SDL_Joystick * joystick ) {
            TRACE();
            return sym::SDL_JoystickNumAxes ( joystick );
        }

int SDL_JoystickNumBalls ( SDL_Joystick * joystick ) {
            TRACE();
            return sym::SDL_JoystickNumBalls ( joystick );
        }

int SDL_JoystickNumHats ( SDL_Joystick * joystick ) {
            TRACE();
            return sym::SDL_JoystickNumHats ( joystick );
        }

int SDL_JoystickNumButtons ( SDL_Joystick * joystick ) {
            TRACE();
            return sym::SDL_JoystickNumButtons ( joystick );
        }

void SDL_JoystickUpdate (  ) {
            TRACE();
            return sym::SDL_JoystickUpdate (  );
        }

int SDL_JoystickEventState ( int state ) {
            TRACE();
            return sym::SDL_JoystickEventState ( state );
        }

Sint16 SDL_JoystickGetAxis ( SDL_Joystick * joystick, int axis ) {
            TRACE();
            return sym::SDL_JoystickGetAxis ( joystick, axis );
        }

SDL_bool SDL_JoystickGetAxisInitialState ( SDL_Joystick * joystick, int axis, Sint16 * state ) {
            TRACE();
            return sym::SDL_JoystickGetAxisInitialState ( joystick, axis, state );
        }

Uint8 SDL_JoystickGetHat ( SDL_Joystick * joystick, int hat ) {
            TRACE();
            return sym::SDL_JoystickGetHat ( joystick, hat );
        }

int SDL_JoystickGetBall ( SDL_Joystick * joystick, int ball, int * dx, int * dy ) {
            TRACE();
            return sym::SDL_JoystickGetBall ( joystick, ball, dx, dy );
        }

Uint8 SDL_JoystickGetButton ( SDL_Joystick * joystick, int button ) {
            TRACE();
            return sym::SDL_JoystickGetButton ( joystick, button );
        }

void SDL_JoystickClose ( SDL_Joystick * joystick ) {
            TRACE();
            return sym::SDL_JoystickClose ( joystick );
        }

SDL_JoystickPowerLevel SDL_JoystickCurrentPowerLevel ( SDL_Joystick * joystick ) {
            TRACE();
            return sym::SDL_JoystickCurrentPowerLevel ( joystick );
        }

int SDL_GameControllerAddMappingsFromRW ( SDL_RWops * rw, int freerw ) {
            TRACE();
            return sym::SDL_GameControllerAddMappingsFromRW ( rw, freerw );
        }

int SDL_GameControllerAddMapping ( const char * mappingString ) {
            TRACE();
            return sym::SDL_GameControllerAddMapping ( mappingString );
        }

int SDL_GameControllerNumMappings (  ) {
            TRACE();
            return sym::SDL_GameControllerNumMappings (  );
        }

char * SDL_GameControllerMappingForIndex ( int mapping_index ) {
            TRACE();
            return sym::SDL_GameControllerMappingForIndex ( mapping_index );
        }

char * SDL_GameControllerMappingForGUID ( SDL_JoystickGUID guid ) {
            TRACE();
            return sym::SDL_GameControllerMappingForGUID ( guid );
        }

char * SDL_GameControllerMapping ( SDL_GameController * gamecontroller ) {
            TRACE();
            return sym::SDL_GameControllerMapping ( gamecontroller );
        }

SDL_bool SDL_IsGameController ( int joystick_index ) {
            TRACE();
            return sym::SDL_IsGameController ( joystick_index );
        }

const char * SDL_GameControllerNameForIndex ( int joystick_index ) {
            TRACE();
            return sym::SDL_GameControllerNameForIndex ( joystick_index );
        }

SDL_GameController * SDL_GameControllerOpen ( int joystick_index ) {
            TRACE();
            return sym::SDL_GameControllerOpen ( joystick_index );
        }

SDL_GameController * SDL_GameControllerFromInstanceID ( SDL_JoystickID joyid ) {
            TRACE();
            return sym::SDL_GameControllerFromInstanceID ( joyid );
        }

const char * SDL_GameControllerName ( SDL_GameController * gamecontroller ) {
            TRACE();
            return sym::SDL_GameControllerName ( gamecontroller );
        }

Uint16 SDL_GameControllerGetVendor ( SDL_GameController * gamecontroller ) {
            TRACE();
            return sym::SDL_GameControllerGetVendor ( gamecontroller );
        }

Uint16 SDL_GameControllerGetProduct ( SDL_GameController * gamecontroller ) {
            TRACE();
            return sym::SDL_GameControllerGetProduct ( gamecontroller );
        }

Uint16 SDL_GameControllerGetProductVersion ( SDL_GameController * gamecontroller ) {
            TRACE();
            return sym::SDL_GameControllerGetProductVersion ( gamecontroller );
        }

SDL_bool SDL_GameControllerGetAttached ( SDL_GameController * gamecontroller ) {
            TRACE();
            return sym::SDL_GameControllerGetAttached ( gamecontroller );
        }

SDL_Joystick * SDL_GameControllerGetJoystick ( SDL_GameController * gamecontroller ) {
            TRACE();
            return sym::SDL_GameControllerGetJoystick ( gamecontroller );
        }

int SDL_GameControllerEventState ( int state ) {
            TRACE();
            return sym::SDL_GameControllerEventState ( state );
        }

void SDL_GameControllerUpdate (  ) {
            TRACE();
            return sym::SDL_GameControllerUpdate (  );
        }

SDL_GameControllerAxis SDL_GameControllerGetAxisFromString ( const char * pchString ) {
            TRACE();
            return sym::SDL_GameControllerGetAxisFromString ( pchString );
        }

const char * SDL_GameControllerGetStringForAxis ( SDL_GameControllerAxis axis ) {
            TRACE();
            return sym::SDL_GameControllerGetStringForAxis ( axis );
        }

SDL_GameControllerButtonBind SDL_GameControllerGetBindForAxis ( SDL_GameController * gamecontroller, SDL_GameControllerAxis axis ) {
            TRACE();
            return sym::SDL_GameControllerGetBindForAxis ( gamecontroller, axis );
        }

Sint16 SDL_GameControllerGetAxis ( SDL_GameController * gamecontroller, SDL_GameControllerAxis axis ) {
            TRACE();
            return sym::SDL_GameControllerGetAxis ( gamecontroller, axis );
        }

SDL_GameControllerButton SDL_GameControllerGetButtonFromString ( const char * pchString ) {
            TRACE();
            return sym::SDL_GameControllerGetButtonFromString ( pchString );
        }

const char * SDL_GameControllerGetStringForButton ( SDL_GameControllerButton button ) {
            TRACE();
            return sym::SDL_GameControllerGetStringForButton ( button );
        }

SDL_GameControllerButtonBind SDL_GameControllerGetBindForButton ( SDL_GameController * gamecontroller, SDL_GameControllerButton button ) {
            TRACE();
            return sym::SDL_GameControllerGetBindForButton ( gamecontroller, button );
        }

Uint8 SDL_GameControllerGetButton ( SDL_GameController * gamecontroller, SDL_GameControllerButton button ) {
            TRACE();
            return sym::SDL_GameControllerGetButton ( gamecontroller, button );
        }

void SDL_GameControllerClose ( SDL_GameController * gamecontroller ) {
            TRACE();
            return sym::SDL_GameControllerClose ( gamecontroller );
        }

int SDL_GetNumTouchDevices (  ) {
            TRACE();
            return sym::SDL_GetNumTouchDevices (  );
        }

SDL_TouchID SDL_GetTouchDevice ( int index ) {
            TRACE();
            return sym::SDL_GetTouchDevice ( index );
        }

int SDL_GetNumTouchFingers ( SDL_TouchID touchID ) {
            TRACE();
            return sym::SDL_GetNumTouchFingers ( touchID );
        }

SDL_Finger * SDL_GetTouchFinger ( SDL_TouchID touchID, int index ) {
            TRACE();
            return sym::SDL_GetTouchFinger ( touchID, index );
        }

int SDL_RecordGesture ( SDL_TouchID touchId ) {
            TRACE();
            return sym::SDL_RecordGesture ( touchId );
        }

int SDL_SaveAllDollarTemplates ( SDL_RWops * dst ) {
            TRACE();
            return sym::SDL_SaveAllDollarTemplates ( dst );
        }

int SDL_SaveDollarTemplate ( SDL_GestureID gestureId, SDL_RWops * dst ) {
            TRACE();
            return sym::SDL_SaveDollarTemplate ( gestureId, dst );
        }

int SDL_LoadDollarTemplates ( SDL_TouchID touchId, SDL_RWops * src ) {
            TRACE();
            return sym::SDL_LoadDollarTemplates ( touchId, src );
        }

void SDL_PumpEvents (  ) {
            TRACE();
            return sym::SDL_PumpEvents (  );
        }

int SDL_PeepEvents ( SDL_Event * events, int numevents, SDL_eventaction action, Uint32 minType, Uint32 maxType ) {
            TRACE();
            return sym::SDL_PeepEvents ( events, numevents, action, minType, maxType );
        }

SDL_bool SDL_HasEvent ( Uint32 type ) {
            TRACE();
            return sym::SDL_HasEvent ( type );
        }

SDL_bool SDL_HasEvents ( Uint32 minType, Uint32 maxType ) {
            TRACE();
            return sym::SDL_HasEvents ( minType, maxType );
        }

void SDL_FlushEvent ( Uint32 type ) {
            TRACE();
            return sym::SDL_FlushEvent ( type );
        }

void SDL_FlushEvents ( Uint32 minType, Uint32 maxType ) {
            TRACE();
            return sym::SDL_FlushEvents ( minType, maxType );
        }

int SDL_PollEvent ( SDL_Event * event ) {
            TRACE();
            return sym::SDL_PollEvent ( event );
        }

int SDL_WaitEvent ( SDL_Event * event ) {
            TRACE();
            return sym::SDL_WaitEvent ( event );
        }

int SDL_WaitEventTimeout ( SDL_Event * event, int timeout ) {
            TRACE();
            return sym::SDL_WaitEventTimeout ( event, timeout );
        }

int SDL_PushEvent ( SDL_Event * event ) {
            TRACE();
            return sym::SDL_PushEvent ( event );
        }

void SDL_SetEventFilter ( SDL_EventFilter filter, void * userdata ) {
            TRACE();
            return sym::SDL_SetEventFilter ( filter, userdata );
        }

SDL_bool SDL_GetEventFilter ( SDL_EventFilter * filter, void ** userdata ) {
            TRACE();
            return sym::SDL_GetEventFilter ( filter, userdata );
        }

void SDL_AddEventWatch ( SDL_EventFilter filter, void * userdata ) {
            TRACE();
            return sym::SDL_AddEventWatch ( filter, userdata );
        }

void SDL_DelEventWatch ( SDL_EventFilter filter, void * userdata ) {
            TRACE();
            return sym::SDL_DelEventWatch ( filter, userdata );
        }

void SDL_FilterEvents ( SDL_EventFilter filter, void * userdata ) {
            TRACE();
            return sym::SDL_FilterEvents ( filter, userdata );
        }

Uint8 SDL_EventState ( Uint32 type, int state ) {
            TRACE();
            return sym::SDL_EventState ( type, state );
        }

Uint32 SDL_RegisterEvents ( int numevents ) {
            TRACE();
            return sym::SDL_RegisterEvents ( numevents );
        }

char * SDL_GetBasePath (  ) {
            TRACE();
            return sym::SDL_GetBasePath (  );
        }

char * SDL_GetPrefPath ( const char * org, const char * app ) {
            TRACE();
            return sym::SDL_GetPrefPath ( org, app );
        }

int SDL_NumHaptics (  ) {
            TRACE();
            return sym::SDL_NumHaptics (  );
        }

const char * SDL_HapticName ( int device_index ) {
            TRACE();
            return sym::SDL_HapticName ( device_index );
        }

SDL_Haptic * SDL_HapticOpen ( int device_index ) {
            TRACE();
            return sym::SDL_HapticOpen ( device_index );
        }

int SDL_HapticOpened ( int device_index ) {
            TRACE();
            return sym::SDL_HapticOpened ( device_index );
        }

int SDL_HapticIndex ( SDL_Haptic * haptic ) {
            TRACE();
            return sym::SDL_HapticIndex ( haptic );
        }

int SDL_MouseIsHaptic (  ) {
            TRACE();
            return sym::SDL_MouseIsHaptic (  );
        }

SDL_Haptic * SDL_HapticOpenFromMouse (  ) {
            TRACE();
            return sym::SDL_HapticOpenFromMouse (  );
        }

int SDL_JoystickIsHaptic ( SDL_Joystick * joystick ) {
            TRACE();
            return sym::SDL_JoystickIsHaptic ( joystick );
        }

SDL_Haptic * SDL_HapticOpenFromJoystick ( SDL_Joystick * joystick ) {
            TRACE();
            return sym::SDL_HapticOpenFromJoystick ( joystick );
        }

void SDL_HapticClose ( SDL_Haptic * haptic ) {
            TRACE();
            return sym::SDL_HapticClose ( haptic );
        }

int SDL_HapticNumEffects ( SDL_Haptic * haptic ) {
            TRACE();
            return sym::SDL_HapticNumEffects ( haptic );
        }

int SDL_HapticNumEffectsPlaying ( SDL_Haptic * haptic ) {
            TRACE();
            return sym::SDL_HapticNumEffectsPlaying ( haptic );
        }

unsigned int SDL_HapticQuery ( SDL_Haptic * haptic ) {
            TRACE();
            return sym::SDL_HapticQuery ( haptic );
        }

int SDL_HapticNumAxes ( SDL_Haptic * haptic ) {
            TRACE();
            return sym::SDL_HapticNumAxes ( haptic );
        }

int SDL_HapticEffectSupported ( SDL_Haptic * haptic, SDL_HapticEffect * effect ) {
            TRACE();
            return sym::SDL_HapticEffectSupported ( haptic, effect );
        }

int SDL_HapticNewEffect ( SDL_Haptic * haptic, SDL_HapticEffect * effect ) {
            TRACE();
            return sym::SDL_HapticNewEffect ( haptic, effect );
        }

int SDL_HapticUpdateEffect ( SDL_Haptic * haptic, int effect, SDL_HapticEffect * data ) {
            TRACE();
            return sym::SDL_HapticUpdateEffect ( haptic, effect, data );
        }

int SDL_HapticRunEffect ( SDL_Haptic * haptic, int effect, Uint32 iterations ) {
            TRACE();
            return sym::SDL_HapticRunEffect ( haptic, effect, iterations );
        }

int SDL_HapticStopEffect ( SDL_Haptic * haptic, int effect ) {
            TRACE();
            return sym::SDL_HapticStopEffect ( haptic, effect );
        }

void SDL_HapticDestroyEffect ( SDL_Haptic * haptic, int effect ) {
            TRACE();
            return sym::SDL_HapticDestroyEffect ( haptic, effect );
        }

int SDL_HapticGetEffectStatus ( SDL_Haptic * haptic, int effect ) {
            TRACE();
            return sym::SDL_HapticGetEffectStatus ( haptic, effect );
        }

int SDL_HapticSetGain ( SDL_Haptic * haptic, int gain ) {
            TRACE();
            return sym::SDL_HapticSetGain ( haptic, gain );
        }

int SDL_HapticSetAutocenter ( SDL_Haptic * haptic, int autocenter ) {
            TRACE();
            return sym::SDL_HapticSetAutocenter ( haptic, autocenter );
        }

int SDL_HapticPause ( SDL_Haptic * haptic ) {
            TRACE();
            return sym::SDL_HapticPause ( haptic );
        }

int SDL_HapticUnpause ( SDL_Haptic * haptic ) {
            TRACE();
            return sym::SDL_HapticUnpause ( haptic );
        }

int SDL_HapticStopAll ( SDL_Haptic * haptic ) {
            TRACE();
            return sym::SDL_HapticStopAll ( haptic );
        }

int SDL_HapticRumbleSupported ( SDL_Haptic * haptic ) {
            TRACE();
            return sym::SDL_HapticRumbleSupported ( haptic );
        }

int SDL_HapticRumbleInit ( SDL_Haptic * haptic ) {
            TRACE();
            return sym::SDL_HapticRumbleInit ( haptic );
        }

int SDL_HapticRumblePlay ( SDL_Haptic * haptic, float strength, Uint32 length ) {
            TRACE();
            return sym::SDL_HapticRumblePlay ( haptic, strength, length );
        }

int SDL_HapticRumbleStop ( SDL_Haptic * haptic ) {
            TRACE();
            return sym::SDL_HapticRumbleStop ( haptic );
        }

SDL_bool SDL_SetHintWithPriority ( const char * name, const char * value, SDL_HintPriority priority ) {
            TRACE();
            return sym::SDL_SetHintWithPriority ( name, value, priority );
        }

SDL_bool SDL_SetHint ( const char * name, const char * value ) {
            TRACE();
            return sym::SDL_SetHint ( name, value );
        }

const char * SDL_GetHint ( const char * name ) {
            TRACE();
            return sym::SDL_GetHint ( name );
        }

SDL_bool SDL_GetHintBoolean ( const char * name, SDL_bool default_value ) {
            TRACE();
            return sym::SDL_GetHintBoolean ( name, default_value );
        }

void SDL_AddHintCallback ( const char * name, SDL_HintCallback callback, void * userdata ) {
            TRACE();
            return sym::SDL_AddHintCallback ( name, callback, userdata );
        }

void SDL_DelHintCallback ( const char * name, SDL_HintCallback callback, void * userdata ) {
            TRACE();
            return sym::SDL_DelHintCallback ( name, callback, userdata );
        }

void SDL_ClearHints (  ) {
            TRACE();
            return sym::SDL_ClearHints (  );
        }

void * SDL_LoadObject ( const char * sofile ) {
            TRACE();
            return sym::SDL_LoadObject ( sofile );
        }

void * SDL_LoadFunction ( void * handle, const char * name ) {
            TRACE();
            return sym::SDL_LoadFunction ( handle, name );
        }

void SDL_UnloadObject ( void * handle ) {
            TRACE();
            return sym::SDL_UnloadObject ( handle );
        }

void SDL_LogSetAllPriority ( SDL_LogPriority priority ) {
            TRACE();
            return sym::SDL_LogSetAllPriority ( priority );
        }

void SDL_LogSetPriority ( int category, SDL_LogPriority priority ) {
            TRACE();
            return sym::SDL_LogSetPriority ( category, priority );
        }

SDL_LogPriority SDL_LogGetPriority ( int category ) {
            TRACE();
            return sym::SDL_LogGetPriority ( category );
        }

void SDL_LogResetPriorities (  ) {
            TRACE();
            return sym::SDL_LogResetPriorities (  );
        }

void SDL_Log ( const char * fmt ) {
            TRACE();
            return sym::SDL_Log ( fmt );
        }

void SDL_LogVerbose ( int category, const char * fmt ) {
            TRACE();
            return sym::SDL_LogVerbose ( category, fmt );
        }

void SDL_LogDebug ( int category, const char * fmt ) {
            TRACE();
            return sym::SDL_LogDebug ( category, fmt );
        }

void SDL_LogInfo ( int category, const char * fmt ) {
            TRACE();
            return sym::SDL_LogInfo ( category, fmt );
        }

void SDL_LogWarn ( int category, const char * fmt ) {
            TRACE();
            return sym::SDL_LogWarn ( category, fmt );
        }

void SDL_LogError ( int category, const char * fmt ) {
            TRACE();
            return sym::SDL_LogError ( category, fmt );
        }

void SDL_LogCritical ( int category, const char * fmt ) {
            TRACE();
            return sym::SDL_LogCritical ( category, fmt );
        }

void SDL_LogMessage ( int category, SDL_LogPriority priority, const char * fmt ) {
            TRACE();
            return sym::SDL_LogMessage ( category, priority, fmt );
        }

void SDL_LogMessageV ( int category, SDL_LogPriority priority, const char * fmt, va_list ap ) {
            TRACE();
            return sym::SDL_LogMessageV ( category, priority, fmt, ap );
        }

void SDL_LogGetOutputFunction ( SDL_LogOutputFunction * callback, void ** userdata ) {
            TRACE();
            return sym::SDL_LogGetOutputFunction ( callback, userdata );
        }

void SDL_LogSetOutputFunction ( SDL_LogOutputFunction callback, void * userdata ) {
            TRACE();
            return sym::SDL_LogSetOutputFunction ( callback, userdata );
        }

int SDL_ShowMessageBox ( const SDL_MessageBoxData * messageboxdata, int * buttonid ) {
            TRACE();
            return sym::SDL_ShowMessageBox ( messageboxdata, buttonid );
        }

int SDL_ShowSimpleMessageBox ( Uint32 flags, const char * title, const char * message, SDL_Window * window ) {
            TRACE();
            return sym::SDL_ShowSimpleMessageBox ( flags, title, message, window );
        }

SDL_PowerState SDL_GetPowerInfo ( int * secs, int * pct ) {
            TRACE();
            return sym::SDL_GetPowerInfo ( secs, pct );
        }

int SDL_GetNumRenderDrivers (  ) {
            TRACE();
            return sym::SDL_GetNumRenderDrivers (  );
        }

int SDL_GetRenderDriverInfo ( int index, SDL_RendererInfo * info ) {
            TRACE();
            return sym::SDL_GetRenderDriverInfo ( index, info );
        }

int SDL_CreateWindowAndRenderer ( int width, int height, Uint32 window_flags, SDL_Window ** window, SDL_Renderer ** renderer ) {
            TRACE();
            return sym::SDL_CreateWindowAndRenderer ( width, height, window_flags, window, renderer );
        }

SDL_Renderer * SDL_CreateRenderer ( SDL_Window * window, int index, Uint32 flags ) {
            TRACE();
            return sym::SDL_CreateRenderer ( window, index, flags );
        }

SDL_Renderer * SDL_CreateSoftwareRenderer ( SDL_Surface * surface ) {
            TRACE();
            return sym::SDL_CreateSoftwareRenderer ( surface );
        }

SDL_Renderer * SDL_GetRenderer ( SDL_Window * window ) {
            TRACE();
            return sym::SDL_GetRenderer ( window );
        }

int SDL_GetRendererInfo ( SDL_Renderer * renderer, SDL_RendererInfo * info ) {
            TRACE();
            return sym::SDL_GetRendererInfo ( renderer, info );
        }

int SDL_GetRendererOutputSize ( SDL_Renderer * renderer, int * w, int * h ) {
            TRACE();
            return sym::SDL_GetRendererOutputSize ( renderer, w, h );
        }

SDL_Texture * SDL_CreateTexture ( SDL_Renderer * renderer, Uint32 format, int access, int w, int h ) {
            TRACE();
            return sym::SDL_CreateTexture ( renderer, format, access, w, h );
        }

SDL_Texture * SDL_CreateTextureFromSurface ( SDL_Renderer * renderer, SDL_Surface * surface ) {
            TRACE();
            return sym::SDL_CreateTextureFromSurface ( renderer, surface );
        }

int SDL_QueryTexture ( SDL_Texture * texture, Uint32 * format, int * access, int * w, int * h ) {
            TRACE();
            return sym::SDL_QueryTexture ( texture, format, access, w, h );
        }

int SDL_SetTextureColorMod ( SDL_Texture * texture, Uint8 r, Uint8 g, Uint8 b ) {
            TRACE();
            return sym::SDL_SetTextureColorMod ( texture, r, g, b );
        }

int SDL_GetTextureColorMod ( SDL_Texture * texture, Uint8 * r, Uint8 * g, Uint8 * b ) {
            TRACE();
            return sym::SDL_GetTextureColorMod ( texture, r, g, b );
        }

int SDL_SetTextureAlphaMod ( SDL_Texture * texture, Uint8 alpha ) {
            TRACE();
            return sym::SDL_SetTextureAlphaMod ( texture, alpha );
        }

int SDL_GetTextureAlphaMod ( SDL_Texture * texture, Uint8 * alpha ) {
            TRACE();
            return sym::SDL_GetTextureAlphaMod ( texture, alpha );
        }

int SDL_SetTextureBlendMode ( SDL_Texture * texture, SDL_BlendMode blendMode ) {
            TRACE();
            return sym::SDL_SetTextureBlendMode ( texture, blendMode );
        }

int SDL_GetTextureBlendMode ( SDL_Texture * texture, SDL_BlendMode * blendMode ) {
            TRACE();
            return sym::SDL_GetTextureBlendMode ( texture, blendMode );
        }

int SDL_UpdateTexture ( SDL_Texture * texture, const SDL_Rect * rect, const void * pixels, int pitch ) {
            TRACE();
            return sym::SDL_UpdateTexture ( texture, rect, pixels, pitch );
        }

int SDL_UpdateYUVTexture ( SDL_Texture * texture, const SDL_Rect * rect, const Uint8 * Yplane, int Ypitch, const Uint8 * Uplane, int Upitch, const Uint8 * Vplane, int Vpitch ) {
            TRACE();
            return sym::SDL_UpdateYUVTexture ( texture, rect, Yplane, Ypitch, Uplane, Upitch, Vplane, Vpitch );
        }

int SDL_LockTexture ( SDL_Texture * texture, const SDL_Rect * rect, void ** pixels, int * pitch ) {
            TRACE();
            return sym::SDL_LockTexture ( texture, rect, pixels, pitch );
        }

void SDL_UnlockTexture ( SDL_Texture * texture ) {
            TRACE();
            return sym::SDL_UnlockTexture ( texture );
        }

SDL_bool SDL_RenderTargetSupported ( SDL_Renderer * renderer ) {
            TRACE();
            return sym::SDL_RenderTargetSupported ( renderer );
        }

int SDL_SetRenderTarget ( SDL_Renderer * renderer, SDL_Texture * texture ) {
            TRACE();
            return sym::SDL_SetRenderTarget ( renderer, texture );
        }

SDL_Texture * SDL_GetRenderTarget ( SDL_Renderer * renderer ) {
            TRACE();
            return sym::SDL_GetRenderTarget ( renderer );
        }

int SDL_RenderSetLogicalSize ( SDL_Renderer * renderer, int w, int h ) {
            TRACE();
            return sym::SDL_RenderSetLogicalSize ( renderer, w, h );
        }

void SDL_RenderGetLogicalSize ( SDL_Renderer * renderer, int * w, int * h ) {
            TRACE();
            return sym::SDL_RenderGetLogicalSize ( renderer, w, h );
        }

int SDL_RenderSetIntegerScale ( SDL_Renderer * renderer, SDL_bool enable ) {
            TRACE();
            return sym::SDL_RenderSetIntegerScale ( renderer, enable );
        }

SDL_bool SDL_RenderGetIntegerScale ( SDL_Renderer * renderer ) {
            TRACE();
            return sym::SDL_RenderGetIntegerScale ( renderer );
        }

int SDL_RenderSetViewport ( SDL_Renderer * renderer, const SDL_Rect * rect ) {
            TRACE();
            return sym::SDL_RenderSetViewport ( renderer, rect );
        }

void SDL_RenderGetViewport ( SDL_Renderer * renderer, SDL_Rect * rect ) {
            TRACE();
            return sym::SDL_RenderGetViewport ( renderer, rect );
        }

int SDL_RenderSetClipRect ( SDL_Renderer * renderer, const SDL_Rect * rect ) {
            TRACE();
            return sym::SDL_RenderSetClipRect ( renderer, rect );
        }

void SDL_RenderGetClipRect ( SDL_Renderer * renderer, SDL_Rect * rect ) {
            TRACE();
            return sym::SDL_RenderGetClipRect ( renderer, rect );
        }

SDL_bool SDL_RenderIsClipEnabled ( SDL_Renderer * renderer ) {
            TRACE();
            return sym::SDL_RenderIsClipEnabled ( renderer );
        }

int SDL_RenderSetScale ( SDL_Renderer * renderer, float scaleX, float scaleY ) {
            TRACE();
            return sym::SDL_RenderSetScale ( renderer, scaleX, scaleY );
        }

void SDL_RenderGetScale ( SDL_Renderer * renderer, float * scaleX, float * scaleY ) {
            TRACE();
            return sym::SDL_RenderGetScale ( renderer, scaleX, scaleY );
        }

int SDL_SetRenderDrawColor ( SDL_Renderer * renderer, Uint8 r, Uint8 g, Uint8 b, Uint8 a ) {
            TRACE();
            return sym::SDL_SetRenderDrawColor ( renderer, r, g, b, a );
        }

int SDL_GetRenderDrawColor ( SDL_Renderer * renderer, Uint8 * r, Uint8 * g, Uint8 * b, Uint8 * a ) {
            TRACE();
            return sym::SDL_GetRenderDrawColor ( renderer, r, g, b, a );
        }

int SDL_SetRenderDrawBlendMode ( SDL_Renderer * renderer, SDL_BlendMode blendMode ) {
            TRACE();
            return sym::SDL_SetRenderDrawBlendMode ( renderer, blendMode );
        }

int SDL_GetRenderDrawBlendMode ( SDL_Renderer * renderer, SDL_BlendMode * blendMode ) {
            TRACE();
            return sym::SDL_GetRenderDrawBlendMode ( renderer, blendMode );
        }

int SDL_RenderClear ( SDL_Renderer * renderer ) {
            TRACE();
            return sym::SDL_RenderClear ( renderer );
        }

int SDL_RenderDrawPoint ( SDL_Renderer * renderer, int x, int y ) {
            TRACE();
            return sym::SDL_RenderDrawPoint ( renderer, x, y );
        }

int SDL_RenderDrawPoints ( SDL_Renderer * renderer, const SDL_Point * points, int count ) {
            TRACE();
            return sym::SDL_RenderDrawPoints ( renderer, points, count );
        }

int SDL_RenderDrawLine ( SDL_Renderer * renderer, int x1, int y1, int x2, int y2 ) {
            TRACE();
            return sym::SDL_RenderDrawLine ( renderer, x1, y1, x2, y2 );
        }

int SDL_RenderDrawLines ( SDL_Renderer * renderer, const SDL_Point * points, int count ) {
            TRACE();
            return sym::SDL_RenderDrawLines ( renderer, points, count );
        }

int SDL_RenderDrawRect ( SDL_Renderer * renderer, const SDL_Rect * rect ) {
            TRACE();
            return sym::SDL_RenderDrawRect ( renderer, rect );
        }

int SDL_RenderDrawRects ( SDL_Renderer * renderer, const SDL_Rect * rects, int count ) {
            TRACE();
            return sym::SDL_RenderDrawRects ( renderer, rects, count );
        }

int SDL_RenderFillRect ( SDL_Renderer * renderer, const SDL_Rect * rect ) {
            TRACE();
            return sym::SDL_RenderFillRect ( renderer, rect );
        }

int SDL_RenderFillRects ( SDL_Renderer * renderer, const SDL_Rect * rects, int count ) {
            TRACE();
            return sym::SDL_RenderFillRects ( renderer, rects, count );
        }

int SDL_RenderCopy ( SDL_Renderer * renderer, SDL_Texture * texture, const SDL_Rect * srcrect, const SDL_Rect * dstrect ) {
            TRACE();
            return sym::SDL_RenderCopy ( renderer, texture, srcrect, dstrect );
        }

int SDL_RenderCopyEx ( SDL_Renderer * renderer, SDL_Texture * texture, const SDL_Rect * srcrect, const SDL_Rect * dstrect, const double angle, const SDL_Point * center, const SDL_RendererFlip flip ) {
            TRACE();
            return sym::SDL_RenderCopyEx ( renderer, texture, srcrect, dstrect, angle, center, flip );
        }

int SDL_RenderReadPixels ( SDL_Renderer * renderer, const SDL_Rect * rect, Uint32 format, void * pixels, int pitch ) {
            TRACE();
            return sym::SDL_RenderReadPixels ( renderer, rect, format, pixels, pitch );
        }

void SDL_RenderPresent ( SDL_Renderer * renderer ) {
            TRACE();
            return sym::SDL_RenderPresent ( renderer );
        }

void SDL_DestroyTexture ( SDL_Texture * texture ) {
            TRACE();
            return sym::SDL_DestroyTexture ( texture );
        }

void SDL_DestroyRenderer ( SDL_Renderer * renderer ) {
            TRACE();
            return sym::SDL_DestroyRenderer ( renderer );
        }

int SDL_GL_BindTexture ( SDL_Texture * texture, float * texw, float * texh ) {
            TRACE();
            return sym::SDL_GL_BindTexture ( texture, texw, texh );
        }

int SDL_GL_UnbindTexture ( SDL_Texture * texture ) {
            TRACE();
            return sym::SDL_GL_UnbindTexture ( texture );
        }

void * SDL_RenderGetMetalLayer ( SDL_Renderer * renderer ) {
            TRACE();
            return sym::SDL_RenderGetMetalLayer ( renderer );
        }

void * SDL_RenderGetMetalCommandEncoder ( SDL_Renderer * renderer ) {
            TRACE();
            return sym::SDL_RenderGetMetalCommandEncoder ( renderer );
        }

SDL_Window * SDL_CreateShapedWindow ( const char * title, unsigned int x, unsigned int y, unsigned int w, unsigned int h, Uint32 flags ) {
            TRACE();
            return sym::SDL_CreateShapedWindow ( title, x, y, w, h, flags );
        }

SDL_bool SDL_IsShapedWindow ( const SDL_Window * window ) {
            TRACE();
            return sym::SDL_IsShapedWindow ( window );
        }

int SDL_SetWindowShape ( SDL_Window * window, SDL_Surface * shape, SDL_WindowShapeMode * shape_mode ) {
            TRACE();
            return sym::SDL_SetWindowShape ( window, shape, shape_mode );
        }

int SDL_GetShapedWindowMode ( SDL_Window * window, SDL_WindowShapeMode * shape_mode ) {
            TRACE();
            return sym::SDL_GetShapedWindowMode ( window, shape_mode );
        }

Uint32 SDL_GetTicks (  ) {
            TRACE();
            return sym::SDL_GetTicks (  );
        }

Uint64 SDL_GetPerformanceCounter (  ) {
            TRACE();
            return sym::SDL_GetPerformanceCounter (  );
        }

Uint64 SDL_GetPerformanceFrequency (  ) {
            TRACE();
            return sym::SDL_GetPerformanceFrequency (  );
        }

void SDL_Delay ( Uint32 ms ) {
            TRACE();
            return sym::SDL_Delay ( ms );
        }

SDL_TimerID SDL_AddTimer ( Uint32 interval, SDL_TimerCallback callback, void * param ) {
            TRACE();
            return sym::SDL_AddTimer ( interval, callback, param );
        }

SDL_bool SDL_RemoveTimer ( SDL_TimerID id ) {
            TRACE();
            return sym::SDL_RemoveTimer ( id );
        }

void SDL_GetVersion ( SDL_version * ver ) {
            TRACE();
            return sym::SDL_GetVersion ( ver );
        }

const char * SDL_GetRevision (  ) {
            TRACE();
            return sym::SDL_GetRevision (  );
        }

int SDL_GetRevisionNumber (  ) {
            TRACE();
            return sym::SDL_GetRevisionNumber (  );
        }

int SDL_Init ( Uint32 flags ) {
            TRACE();
            return sym::SDL_Init ( flags );
        }

int SDL_InitSubSystem ( Uint32 flags ) {
            TRACE();
            return sym::SDL_InitSubSystem ( flags );
        }

void SDL_QuitSubSystem ( Uint32 flags ) {
            TRACE();
            return sym::SDL_QuitSubSystem ( flags );
        }

Uint32 SDL_WasInit ( Uint32 flags ) {
            TRACE();
            return sym::SDL_WasInit ( flags );
        }

void SDL_Quit (  ) {
            TRACE();
            return sym::SDL_Quit (  );
        }
