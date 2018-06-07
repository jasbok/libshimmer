#ifndef APIGEN_SDL_H
#define APIGEN_SDL_H

#include "SDL.h"

#include <dlfcn.h>

namespace sym{
    typedef const char * ( *SDL_GetPlatform_handle )(  );
    static auto SDL_GetPlatform = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetPlatform" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetPlatform" );
        }
        return ( SDL_GetPlatform_handle )( dlsym_ptr );
    } ();
}

const char * SDL_GetPlatform (  );

namespace sym{
    typedef void * ( *SDL_malloc_handle )( size_t size );
    static auto SDL_malloc = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_malloc" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_malloc" );
        }
        return ( SDL_malloc_handle )( dlsym_ptr );
    } ();
}

void * SDL_malloc ( size_t size );

namespace sym{
    typedef void * ( *SDL_calloc_handle )( size_t nmemb, size_t size );
    static auto SDL_calloc = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_calloc" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_calloc" );
        }
        return ( SDL_calloc_handle )( dlsym_ptr );
    } ();
}

void * SDL_calloc ( size_t nmemb, size_t size );

namespace sym{
    typedef void * ( *SDL_realloc_handle )( void * mem, size_t size );
    static auto SDL_realloc = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_realloc" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_realloc" );
        }
        return ( SDL_realloc_handle )( dlsym_ptr );
    } ();
}

void * SDL_realloc ( void * mem, size_t size );

namespace sym{
    typedef void ( *SDL_free_handle )( void * mem );
    static auto SDL_free = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_free" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_free" );
        }
        return ( SDL_free_handle )( dlsym_ptr );
    } ();
}

void SDL_free ( void * mem );

namespace sym{
    typedef void ( *SDL_GetMemoryFunctions_handle )( SDL_malloc_func * malloc_func, SDL_calloc_func * calloc_func, SDL_realloc_func * realloc_func, SDL_free_func * free_func );
    static auto SDL_GetMemoryFunctions = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetMemoryFunctions" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetMemoryFunctions" );
        }
        return ( SDL_GetMemoryFunctions_handle )( dlsym_ptr );
    } ();
}

void SDL_GetMemoryFunctions ( SDL_malloc_func * malloc_func, SDL_calloc_func * calloc_func, SDL_realloc_func * realloc_func, SDL_free_func * free_func );

namespace sym{
    typedef int ( *SDL_SetMemoryFunctions_handle )( SDL_malloc_func malloc_func, SDL_calloc_func calloc_func, SDL_realloc_func realloc_func, SDL_free_func free_func );
    static auto SDL_SetMemoryFunctions = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_SetMemoryFunctions" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_SetMemoryFunctions" );
        }
        return ( SDL_SetMemoryFunctions_handle )( dlsym_ptr );
    } ();
}

int SDL_SetMemoryFunctions ( SDL_malloc_func malloc_func, SDL_calloc_func calloc_func, SDL_realloc_func realloc_func, SDL_free_func free_func );

namespace sym{
    typedef int ( *SDL_GetNumAllocations_handle )(  );
    static auto SDL_GetNumAllocations = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetNumAllocations" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetNumAllocations" );
        }
        return ( SDL_GetNumAllocations_handle )( dlsym_ptr );
    } ();
}

int SDL_GetNumAllocations (  );

namespace sym{
    typedef char * ( *SDL_getenv_handle )( const char * name );
    static auto SDL_getenv = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_getenv" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_getenv" );
        }
        return ( SDL_getenv_handle )( dlsym_ptr );
    } ();
}

char * SDL_getenv ( const char * name );

namespace sym{
    typedef int ( *SDL_setenv_handle )( const char * name, const char * value, int overwrite );
    static auto SDL_setenv = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_setenv" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_setenv" );
        }
        return ( SDL_setenv_handle )( dlsym_ptr );
    } ();
}

int SDL_setenv ( const char * name, const char * value, int overwrite );

namespace sym{
    typedef void ( *SDL_qsort_handle )( void * base, size_t nmemb, size_t size, int (*compare)(const void *, const void *) );
    static auto SDL_qsort = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_qsort" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_qsort" );
        }
        return ( SDL_qsort_handle )( dlsym_ptr );
    } ();
}

void SDL_qsort ( void * base, size_t nmemb, size_t size, int (*compare)(const void *, const void *) );

namespace sym{
    typedef int ( *SDL_abs_handle )( int x );
    static auto SDL_abs = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_abs" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_abs" );
        }
        return ( SDL_abs_handle )( dlsym_ptr );
    } ();
}

int SDL_abs ( int x );

namespace sym{
    typedef int ( *SDL_isdigit_handle )( int x );
    static auto SDL_isdigit = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_isdigit" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_isdigit" );
        }
        return ( SDL_isdigit_handle )( dlsym_ptr );
    } ();
}

int SDL_isdigit ( int x );

namespace sym{
    typedef int ( *SDL_isspace_handle )( int x );
    static auto SDL_isspace = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_isspace" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_isspace" );
        }
        return ( SDL_isspace_handle )( dlsym_ptr );
    } ();
}

int SDL_isspace ( int x );

namespace sym{
    typedef int ( *SDL_toupper_handle )( int x );
    static auto SDL_toupper = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_toupper" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_toupper" );
        }
        return ( SDL_toupper_handle )( dlsym_ptr );
    } ();
}

int SDL_toupper ( int x );

namespace sym{
    typedef int ( *SDL_tolower_handle )( int x );
    static auto SDL_tolower = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_tolower" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_tolower" );
        }
        return ( SDL_tolower_handle )( dlsym_ptr );
    } ();
}

int SDL_tolower ( int x );

namespace sym{
    typedef void * ( *SDL_memset_handle )( void * dst, int c, size_t len );
    static auto SDL_memset = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_memset" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_memset" );
        }
        return ( SDL_memset_handle )( dlsym_ptr );
    } ();
}

void * SDL_memset ( void * dst, int c, size_t len );

namespace sym{
    typedef void * ( *SDL_memcpy_handle )( void * dst, const void * src, size_t len );
    static auto SDL_memcpy = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_memcpy" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_memcpy" );
        }
        return ( SDL_memcpy_handle )( dlsym_ptr );
    } ();
}

void * SDL_memcpy ( void * dst, const void * src, size_t len );

namespace sym{
    typedef void * ( *SDL_memmove_handle )( void * dst, const void * src, size_t len );
    static auto SDL_memmove = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_memmove" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_memmove" );
        }
        return ( SDL_memmove_handle )( dlsym_ptr );
    } ();
}

void * SDL_memmove ( void * dst, const void * src, size_t len );

namespace sym{
    typedef int ( *SDL_memcmp_handle )( const void * s1, const void * s2, size_t len );
    static auto SDL_memcmp = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_memcmp" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_memcmp" );
        }
        return ( SDL_memcmp_handle )( dlsym_ptr );
    } ();
}

int SDL_memcmp ( const void * s1, const void * s2, size_t len );

namespace sym{
    typedef size_t ( *SDL_wcslen_handle )( const wchar_t * wstr );
    static auto SDL_wcslen = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_wcslen" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_wcslen" );
        }
        return ( SDL_wcslen_handle )( dlsym_ptr );
    } ();
}

size_t SDL_wcslen ( const wchar_t * wstr );

namespace sym{
    typedef size_t ( *SDL_wcslcpy_handle )( wchar_t * dst, const wchar_t * src, size_t maxlen );
    static auto SDL_wcslcpy = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_wcslcpy" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_wcslcpy" );
        }
        return ( SDL_wcslcpy_handle )( dlsym_ptr );
    } ();
}

size_t SDL_wcslcpy ( wchar_t * dst, const wchar_t * src, size_t maxlen );

namespace sym{
    typedef size_t ( *SDL_wcslcat_handle )( wchar_t * dst, const wchar_t * src, size_t maxlen );
    static auto SDL_wcslcat = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_wcslcat" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_wcslcat" );
        }
        return ( SDL_wcslcat_handle )( dlsym_ptr );
    } ();
}

size_t SDL_wcslcat ( wchar_t * dst, const wchar_t * src, size_t maxlen );

namespace sym{
    typedef int ( *SDL_wcscmp_handle )( const wchar_t * str1, const wchar_t * str2 );
    static auto SDL_wcscmp = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_wcscmp" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_wcscmp" );
        }
        return ( SDL_wcscmp_handle )( dlsym_ptr );
    } ();
}

int SDL_wcscmp ( const wchar_t * str1, const wchar_t * str2 );

namespace sym{
    typedef size_t ( *SDL_strlen_handle )( const char * str );
    static auto SDL_strlen = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_strlen" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_strlen" );
        }
        return ( SDL_strlen_handle )( dlsym_ptr );
    } ();
}

size_t SDL_strlen ( const char * str );

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
    typedef size_t ( *SDL_utf8strlcpy_handle )( char * dst, const char * src, size_t dst_bytes );
    static auto SDL_utf8strlcpy = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_utf8strlcpy" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_utf8strlcpy" );
        }
        return ( SDL_utf8strlcpy_handle )( dlsym_ptr );
    } ();
}

size_t SDL_utf8strlcpy ( char * dst, const char * src, size_t dst_bytes );

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
    typedef char * ( *SDL_strdup_handle )( const char * str );
    static auto SDL_strdup = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_strdup" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_strdup" );
        }
        return ( SDL_strdup_handle )( dlsym_ptr );
    } ();
}

char * SDL_strdup ( const char * str );

namespace sym{
    typedef char * ( *SDL_strrev_handle )( char * str );
    static auto SDL_strrev = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_strrev" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_strrev" );
        }
        return ( SDL_strrev_handle )( dlsym_ptr );
    } ();
}

char * SDL_strrev ( char * str );

namespace sym{
    typedef char * ( *SDL_strupr_handle )( char * str );
    static auto SDL_strupr = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_strupr" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_strupr" );
        }
        return ( SDL_strupr_handle )( dlsym_ptr );
    } ();
}

char * SDL_strupr ( char * str );

namespace sym{
    typedef char * ( *SDL_strlwr_handle )( char * str );
    static auto SDL_strlwr = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_strlwr" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_strlwr" );
        }
        return ( SDL_strlwr_handle )( dlsym_ptr );
    } ();
}

char * SDL_strlwr ( char * str );

namespace sym{
    typedef char * ( *SDL_strchr_handle )( const char * str, int c );
    static auto SDL_strchr = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_strchr" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_strchr" );
        }
        return ( SDL_strchr_handle )( dlsym_ptr );
    } ();
}

char * SDL_strchr ( const char * str, int c );

namespace sym{
    typedef char * ( *SDL_strrchr_handle )( const char * str, int c );
    static auto SDL_strrchr = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_strrchr" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_strrchr" );
        }
        return ( SDL_strrchr_handle )( dlsym_ptr );
    } ();
}

char * SDL_strrchr ( const char * str, int c );

namespace sym{
    typedef char * ( *SDL_strstr_handle )( const char * haystack, const char * needle );
    static auto SDL_strstr = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_strstr" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_strstr" );
        }
        return ( SDL_strstr_handle )( dlsym_ptr );
    } ();
}

char * SDL_strstr ( const char * haystack, const char * needle );

namespace sym{
    typedef size_t ( *SDL_utf8strlen_handle )( const char * str );
    static auto SDL_utf8strlen = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_utf8strlen" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_utf8strlen" );
        }
        return ( SDL_utf8strlen_handle )( dlsym_ptr );
    } ();
}

size_t SDL_utf8strlen ( const char * str );

namespace sym{
    typedef char * ( *SDL_itoa_handle )( int value, char * str, int radix );
    static auto SDL_itoa = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_itoa" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_itoa" );
        }
        return ( SDL_itoa_handle )( dlsym_ptr );
    } ();
}

char * SDL_itoa ( int value, char * str, int radix );

namespace sym{
    typedef char * ( *SDL_uitoa_handle )( unsigned int value, char * str, int radix );
    static auto SDL_uitoa = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_uitoa" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_uitoa" );
        }
        return ( SDL_uitoa_handle )( dlsym_ptr );
    } ();
}

char * SDL_uitoa ( unsigned int value, char * str, int radix );

namespace sym{
    typedef char * ( *SDL_ltoa_handle )( long value, char * str, int radix );
    static auto SDL_ltoa = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_ltoa" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_ltoa" );
        }
        return ( SDL_ltoa_handle )( dlsym_ptr );
    } ();
}

char * SDL_ltoa ( long value, char * str, int radix );

namespace sym{
    typedef char * ( *SDL_ultoa_handle )( unsigned long value, char * str, int radix );
    static auto SDL_ultoa = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_ultoa" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_ultoa" );
        }
        return ( SDL_ultoa_handle )( dlsym_ptr );
    } ();
}

char * SDL_ultoa ( unsigned long value, char * str, int radix );

namespace sym{
    typedef char * ( *SDL_lltoa_handle )( Sint64 value, char * str, int radix );
    static auto SDL_lltoa = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_lltoa" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_lltoa" );
        }
        return ( SDL_lltoa_handle )( dlsym_ptr );
    } ();
}

char * SDL_lltoa ( Sint64 value, char * str, int radix );

namespace sym{
    typedef char * ( *SDL_ulltoa_handle )( Uint64 value, char * str, int radix );
    static auto SDL_ulltoa = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_ulltoa" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_ulltoa" );
        }
        return ( SDL_ulltoa_handle )( dlsym_ptr );
    } ();
}

char * SDL_ulltoa ( Uint64 value, char * str, int radix );

namespace sym{
    typedef int ( *SDL_atoi_handle )( const char * str );
    static auto SDL_atoi = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_atoi" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_atoi" );
        }
        return ( SDL_atoi_handle )( dlsym_ptr );
    } ();
}

int SDL_atoi ( const char * str );

namespace sym{
    typedef double ( *SDL_atof_handle )( const char * str );
    static auto SDL_atof = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_atof" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_atof" );
        }
        return ( SDL_atof_handle )( dlsym_ptr );
    } ();
}

double SDL_atof ( const char * str );

namespace sym{
    typedef long ( *SDL_strtol_handle )( const char * str, char ** endp, int base );
    static auto SDL_strtol = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_strtol" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_strtol" );
        }
        return ( SDL_strtol_handle )( dlsym_ptr );
    } ();
}

long SDL_strtol ( const char * str, char ** endp, int base );

namespace sym{
    typedef unsigned long ( *SDL_strtoul_handle )( const char * str, char ** endp, int base );
    static auto SDL_strtoul = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_strtoul" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_strtoul" );
        }
        return ( SDL_strtoul_handle )( dlsym_ptr );
    } ();
}

unsigned long SDL_strtoul ( const char * str, char ** endp, int base );

namespace sym{
    typedef Sint64 ( *SDL_strtoll_handle )( const char * str, char ** endp, int base );
    static auto SDL_strtoll = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_strtoll" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_strtoll" );
        }
        return ( SDL_strtoll_handle )( dlsym_ptr );
    } ();
}

Sint64 SDL_strtoll ( const char * str, char ** endp, int base );

namespace sym{
    typedef Uint64 ( *SDL_strtoull_handle )( const char * str, char ** endp, int base );
    static auto SDL_strtoull = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_strtoull" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_strtoull" );
        }
        return ( SDL_strtoull_handle )( dlsym_ptr );
    } ();
}

Uint64 SDL_strtoull ( const char * str, char ** endp, int base );

namespace sym{
    typedef double ( *SDL_strtod_handle )( const char * str, char ** endp );
    static auto SDL_strtod = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_strtod" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_strtod" );
        }
        return ( SDL_strtod_handle )( dlsym_ptr );
    } ();
}

double SDL_strtod ( const char * str, char ** endp );

namespace sym{
    typedef int ( *SDL_strcmp_handle )( const char * str1, const char * str2 );
    static auto SDL_strcmp = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_strcmp" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_strcmp" );
        }
        return ( SDL_strcmp_handle )( dlsym_ptr );
    } ();
}

int SDL_strcmp ( const char * str1, const char * str2 );

namespace sym{
    typedef int ( *SDL_strncmp_handle )( const char * str1, const char * str2, size_t maxlen );
    static auto SDL_strncmp = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_strncmp" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_strncmp" );
        }
        return ( SDL_strncmp_handle )( dlsym_ptr );
    } ();
}

int SDL_strncmp ( const char * str1, const char * str2, size_t maxlen );

namespace sym{
    typedef int ( *SDL_strcasecmp_handle )( const char * str1, const char * str2 );
    static auto SDL_strcasecmp = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_strcasecmp" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_strcasecmp" );
        }
        return ( SDL_strcasecmp_handle )( dlsym_ptr );
    } ();
}

int SDL_strcasecmp ( const char * str1, const char * str2 );

namespace sym{
    typedef int ( *SDL_strncasecmp_handle )( const char * str1, const char * str2, size_t len );
    static auto SDL_strncasecmp = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_strncasecmp" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_strncasecmp" );
        }
        return ( SDL_strncasecmp_handle )( dlsym_ptr );
    } ();
}

int SDL_strncasecmp ( const char * str1, const char * str2, size_t len );

namespace sym{
    typedef int ( *SDL_sscanf_handle )( const char * text, const char * fmt );
    static auto SDL_sscanf = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_sscanf" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_sscanf" );
        }
        return ( SDL_sscanf_handle )( dlsym_ptr );
    } ();
}

int SDL_sscanf ( const char * text, const char * fmt );

namespace sym{
    typedef int ( *SDL_vsscanf_handle )( const char * text, const char * fmt, va_list ap );
    static auto SDL_vsscanf = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_vsscanf" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_vsscanf" );
        }
        return ( SDL_vsscanf_handle )( dlsym_ptr );
    } ();
}

int SDL_vsscanf ( const char * text, const char * fmt, va_list ap );

namespace sym{
    typedef int ( *SDL_snprintf_handle )( char * text, size_t maxlen, const char * fmt );
    static auto SDL_snprintf = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_snprintf" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_snprintf" );
        }
        return ( SDL_snprintf_handle )( dlsym_ptr );
    } ();
}

int SDL_snprintf ( char * text, size_t maxlen, const char * fmt );

namespace sym{
    typedef int ( *SDL_vsnprintf_handle )( char * text, size_t maxlen, const char * fmt, va_list ap );
    static auto SDL_vsnprintf = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_vsnprintf" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_vsnprintf" );
        }
        return ( SDL_vsnprintf_handle )( dlsym_ptr );
    } ();
}

int SDL_vsnprintf ( char * text, size_t maxlen, const char * fmt, va_list ap );

namespace sym{
    typedef double ( *SDL_acos_handle )( double x );
    static auto SDL_acos = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_acos" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_acos" );
        }
        return ( SDL_acos_handle )( dlsym_ptr );
    } ();
}

double SDL_acos ( double x );

namespace sym{
    typedef float ( *SDL_acosf_handle )( float x );
    static auto SDL_acosf = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_acosf" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_acosf" );
        }
        return ( SDL_acosf_handle )( dlsym_ptr );
    } ();
}

float SDL_acosf ( float x );

namespace sym{
    typedef double ( *SDL_asin_handle )( double x );
    static auto SDL_asin = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_asin" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_asin" );
        }
        return ( SDL_asin_handle )( dlsym_ptr );
    } ();
}

double SDL_asin ( double x );

namespace sym{
    typedef float ( *SDL_asinf_handle )( float x );
    static auto SDL_asinf = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_asinf" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_asinf" );
        }
        return ( SDL_asinf_handle )( dlsym_ptr );
    } ();
}

float SDL_asinf ( float x );

namespace sym{
    typedef double ( *SDL_atan_handle )( double x );
    static auto SDL_atan = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_atan" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_atan" );
        }
        return ( SDL_atan_handle )( dlsym_ptr );
    } ();
}

double SDL_atan ( double x );

namespace sym{
    typedef float ( *SDL_atanf_handle )( float x );
    static auto SDL_atanf = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_atanf" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_atanf" );
        }
        return ( SDL_atanf_handle )( dlsym_ptr );
    } ();
}

float SDL_atanf ( float x );

namespace sym{
    typedef double ( *SDL_atan2_handle )( double x, double y );
    static auto SDL_atan2 = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_atan2" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_atan2" );
        }
        return ( SDL_atan2_handle )( dlsym_ptr );
    } ();
}

double SDL_atan2 ( double x, double y );

namespace sym{
    typedef float ( *SDL_atan2f_handle )( float x, float y );
    static auto SDL_atan2f = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_atan2f" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_atan2f" );
        }
        return ( SDL_atan2f_handle )( dlsym_ptr );
    } ();
}

float SDL_atan2f ( float x, float y );

namespace sym{
    typedef double ( *SDL_ceil_handle )( double x );
    static auto SDL_ceil = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_ceil" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_ceil" );
        }
        return ( SDL_ceil_handle )( dlsym_ptr );
    } ();
}

double SDL_ceil ( double x );

namespace sym{
    typedef float ( *SDL_ceilf_handle )( float x );
    static auto SDL_ceilf = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_ceilf" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_ceilf" );
        }
        return ( SDL_ceilf_handle )( dlsym_ptr );
    } ();
}

float SDL_ceilf ( float x );

namespace sym{
    typedef double ( *SDL_copysign_handle )( double x, double y );
    static auto SDL_copysign = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_copysign" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_copysign" );
        }
        return ( SDL_copysign_handle )( dlsym_ptr );
    } ();
}

double SDL_copysign ( double x, double y );

namespace sym{
    typedef float ( *SDL_copysignf_handle )( float x, float y );
    static auto SDL_copysignf = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_copysignf" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_copysignf" );
        }
        return ( SDL_copysignf_handle )( dlsym_ptr );
    } ();
}

float SDL_copysignf ( float x, float y );

namespace sym{
    typedef double ( *SDL_cos_handle )( double x );
    static auto SDL_cos = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_cos" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_cos" );
        }
        return ( SDL_cos_handle )( dlsym_ptr );
    } ();
}

double SDL_cos ( double x );

namespace sym{
    typedef float ( *SDL_cosf_handle )( float x );
    static auto SDL_cosf = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_cosf" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_cosf" );
        }
        return ( SDL_cosf_handle )( dlsym_ptr );
    } ();
}

float SDL_cosf ( float x );

namespace sym{
    typedef double ( *SDL_fabs_handle )( double x );
    static auto SDL_fabs = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_fabs" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_fabs" );
        }
        return ( SDL_fabs_handle )( dlsym_ptr );
    } ();
}

double SDL_fabs ( double x );

namespace sym{
    typedef float ( *SDL_fabsf_handle )( float x );
    static auto SDL_fabsf = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_fabsf" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_fabsf" );
        }
        return ( SDL_fabsf_handle )( dlsym_ptr );
    } ();
}

float SDL_fabsf ( float x );

namespace sym{
    typedef double ( *SDL_floor_handle )( double x );
    static auto SDL_floor = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_floor" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_floor" );
        }
        return ( SDL_floor_handle )( dlsym_ptr );
    } ();
}

double SDL_floor ( double x );

namespace sym{
    typedef float ( *SDL_floorf_handle )( float x );
    static auto SDL_floorf = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_floorf" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_floorf" );
        }
        return ( SDL_floorf_handle )( dlsym_ptr );
    } ();
}

float SDL_floorf ( float x );

namespace sym{
    typedef double ( *SDL_fmod_handle )( double x, double y );
    static auto SDL_fmod = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_fmod" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_fmod" );
        }
        return ( SDL_fmod_handle )( dlsym_ptr );
    } ();
}

double SDL_fmod ( double x, double y );

namespace sym{
    typedef float ( *SDL_fmodf_handle )( float x, float y );
    static auto SDL_fmodf = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_fmodf" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_fmodf" );
        }
        return ( SDL_fmodf_handle )( dlsym_ptr );
    } ();
}

float SDL_fmodf ( float x, float y );

namespace sym{
    typedef double ( *SDL_log_handle )( double x );
    static auto SDL_log = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_log" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_log" );
        }
        return ( SDL_log_handle )( dlsym_ptr );
    } ();
}

double SDL_log ( double x );

namespace sym{
    typedef float ( *SDL_logf_handle )( float x );
    static auto SDL_logf = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_logf" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_logf" );
        }
        return ( SDL_logf_handle )( dlsym_ptr );
    } ();
}

float SDL_logf ( float x );

namespace sym{
    typedef double ( *SDL_log10_handle )( double x );
    static auto SDL_log10 = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_log10" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_log10" );
        }
        return ( SDL_log10_handle )( dlsym_ptr );
    } ();
}

double SDL_log10 ( double x );

namespace sym{
    typedef float ( *SDL_log10f_handle )( float x );
    static auto SDL_log10f = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_log10f" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_log10f" );
        }
        return ( SDL_log10f_handle )( dlsym_ptr );
    } ();
}

float SDL_log10f ( float x );

namespace sym{
    typedef double ( *SDL_pow_handle )( double x, double y );
    static auto SDL_pow = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_pow" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_pow" );
        }
        return ( SDL_pow_handle )( dlsym_ptr );
    } ();
}

double SDL_pow ( double x, double y );

namespace sym{
    typedef float ( *SDL_powf_handle )( float x, float y );
    static auto SDL_powf = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_powf" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_powf" );
        }
        return ( SDL_powf_handle )( dlsym_ptr );
    } ();
}

float SDL_powf ( float x, float y );

namespace sym{
    typedef double ( *SDL_scalbn_handle )( double x, int n );
    static auto SDL_scalbn = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_scalbn" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_scalbn" );
        }
        return ( SDL_scalbn_handle )( dlsym_ptr );
    } ();
}

double SDL_scalbn ( double x, int n );

namespace sym{
    typedef float ( *SDL_scalbnf_handle )( float x, int n );
    static auto SDL_scalbnf = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_scalbnf" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_scalbnf" );
        }
        return ( SDL_scalbnf_handle )( dlsym_ptr );
    } ();
}

float SDL_scalbnf ( float x, int n );

namespace sym{
    typedef double ( *SDL_sin_handle )( double x );
    static auto SDL_sin = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_sin" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_sin" );
        }
        return ( SDL_sin_handle )( dlsym_ptr );
    } ();
}

double SDL_sin ( double x );

namespace sym{
    typedef float ( *SDL_sinf_handle )( float x );
    static auto SDL_sinf = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_sinf" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_sinf" );
        }
        return ( SDL_sinf_handle )( dlsym_ptr );
    } ();
}

float SDL_sinf ( float x );

namespace sym{
    typedef double ( *SDL_sqrt_handle )( double x );
    static auto SDL_sqrt = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_sqrt" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_sqrt" );
        }
        return ( SDL_sqrt_handle )( dlsym_ptr );
    } ();
}

double SDL_sqrt ( double x );

namespace sym{
    typedef float ( *SDL_sqrtf_handle )( float x );
    static auto SDL_sqrtf = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_sqrtf" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_sqrtf" );
        }
        return ( SDL_sqrtf_handle )( dlsym_ptr );
    } ();
}

float SDL_sqrtf ( float x );

namespace sym{
    typedef double ( *SDL_tan_handle )( double x );
    static auto SDL_tan = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_tan" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_tan" );
        }
        return ( SDL_tan_handle )( dlsym_ptr );
    } ();
}

double SDL_tan ( double x );

namespace sym{
    typedef float ( *SDL_tanf_handle )( float x );
    static auto SDL_tanf = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_tanf" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_tanf" );
        }
        return ( SDL_tanf_handle )( dlsym_ptr );
    } ();
}

float SDL_tanf ( float x );

namespace sym{
    typedef SDL_iconv_t ( *SDL_iconv_open_handle )( const char * tocode, const char * fromcode );
    static auto SDL_iconv_open = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_iconv_open" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_iconv_open" );
        }
        return ( SDL_iconv_open_handle )( dlsym_ptr );
    } ();
}

SDL_iconv_t SDL_iconv_open ( const char * tocode, const char * fromcode );

namespace sym{
    typedef int ( *SDL_iconv_close_handle )( SDL_iconv_t cd );
    static auto SDL_iconv_close = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_iconv_close" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_iconv_close" );
        }
        return ( SDL_iconv_close_handle )( dlsym_ptr );
    } ();
}

int SDL_iconv_close ( SDL_iconv_t cd );

namespace sym{
    typedef size_t ( *SDL_iconv_handle )( SDL_iconv_t cd, const char ** inbuf, size_t * inbytesleft, char ** outbuf, size_t * outbytesleft );
    static auto SDL_iconv = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_iconv" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_iconv" );
        }
        return ( SDL_iconv_handle )( dlsym_ptr );
    } ();
}

size_t SDL_iconv ( SDL_iconv_t cd, const char ** inbuf, size_t * inbytesleft, char ** outbuf, size_t * outbytesleft );

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
    typedef void ( *SDL_SetMainReady_handle )(  );
    static auto SDL_SetMainReady = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_SetMainReady" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_SetMainReady" );
        }
        return ( SDL_SetMainReady_handle )( dlsym_ptr );
    } ();
}

void SDL_SetMainReady (  );

namespace sym{
    typedef SDL_AssertState ( *SDL_ReportAssertion_handle )( SDL_AssertData * parm_0, const char * parm_1, const char * parm_2, int parm_3 );
    static auto SDL_ReportAssertion = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_ReportAssertion" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_ReportAssertion" );
        }
        return ( SDL_ReportAssertion_handle )( dlsym_ptr );
    } ();
}

SDL_AssertState SDL_ReportAssertion ( SDL_AssertData * parm_0, const char * parm_1, const char * parm_2, int parm_3 );

namespace sym{
    typedef void ( *SDL_SetAssertionHandler_handle )( SDL_AssertionHandler handler, void * userdata );
    static auto SDL_SetAssertionHandler = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_SetAssertionHandler" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_SetAssertionHandler" );
        }
        return ( SDL_SetAssertionHandler_handle )( dlsym_ptr );
    } ();
}

void SDL_SetAssertionHandler ( SDL_AssertionHandler handler, void * userdata );

namespace sym{
    typedef SDL_AssertionHandler ( *SDL_GetDefaultAssertionHandler_handle )(  );
    static auto SDL_GetDefaultAssertionHandler = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetDefaultAssertionHandler" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetDefaultAssertionHandler" );
        }
        return ( SDL_GetDefaultAssertionHandler_handle )( dlsym_ptr );
    } ();
}

SDL_AssertionHandler SDL_GetDefaultAssertionHandler (  );

namespace sym{
    typedef SDL_AssertionHandler ( *SDL_GetAssertionHandler_handle )( void ** puserdata );
    static auto SDL_GetAssertionHandler = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetAssertionHandler" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetAssertionHandler" );
        }
        return ( SDL_GetAssertionHandler_handle )( dlsym_ptr );
    } ();
}

SDL_AssertionHandler SDL_GetAssertionHandler ( void ** puserdata );

namespace sym{
    typedef const SDL_AssertData * ( *SDL_GetAssertionReport_handle )(  );
    static auto SDL_GetAssertionReport = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetAssertionReport" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetAssertionReport" );
        }
        return ( SDL_GetAssertionReport_handle )( dlsym_ptr );
    } ();
}

const SDL_AssertData * SDL_GetAssertionReport (  );

namespace sym{
    typedef void ( *SDL_ResetAssertionReport_handle )(  );
    static auto SDL_ResetAssertionReport = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_ResetAssertionReport" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_ResetAssertionReport" );
        }
        return ( SDL_ResetAssertionReport_handle )( dlsym_ptr );
    } ();
}

void SDL_ResetAssertionReport (  );

namespace sym{
    typedef SDL_bool ( *SDL_AtomicTryLock_handle )( SDL_SpinLock * lock );
    static auto SDL_AtomicTryLock = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_AtomicTryLock" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_AtomicTryLock" );
        }
        return ( SDL_AtomicTryLock_handle )( dlsym_ptr );
    } ();
}

SDL_bool SDL_AtomicTryLock ( SDL_SpinLock * lock );

namespace sym{
    typedef void ( *SDL_AtomicLock_handle )( SDL_SpinLock * lock );
    static auto SDL_AtomicLock = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_AtomicLock" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_AtomicLock" );
        }
        return ( SDL_AtomicLock_handle )( dlsym_ptr );
    } ();
}

void SDL_AtomicLock ( SDL_SpinLock * lock );

namespace sym{
    typedef void ( *SDL_AtomicUnlock_handle )( SDL_SpinLock * lock );
    static auto SDL_AtomicUnlock = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_AtomicUnlock" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_AtomicUnlock" );
        }
        return ( SDL_AtomicUnlock_handle )( dlsym_ptr );
    } ();
}

void SDL_AtomicUnlock ( SDL_SpinLock * lock );

namespace sym{
    typedef void ( *SDL_MemoryBarrierReleaseFunction_handle )(  );
    static auto SDL_MemoryBarrierReleaseFunction = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_MemoryBarrierReleaseFunction" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_MemoryBarrierReleaseFunction" );
        }
        return ( SDL_MemoryBarrierReleaseFunction_handle )( dlsym_ptr );
    } ();
}

void SDL_MemoryBarrierReleaseFunction (  );

namespace sym{
    typedef void ( *SDL_MemoryBarrierAcquireFunction_handle )(  );
    static auto SDL_MemoryBarrierAcquireFunction = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_MemoryBarrierAcquireFunction" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_MemoryBarrierAcquireFunction" );
        }
        return ( SDL_MemoryBarrierAcquireFunction_handle )( dlsym_ptr );
    } ();
}

void SDL_MemoryBarrierAcquireFunction (  );

namespace sym{
    typedef SDL_bool ( *SDL_AtomicCAS_handle )( SDL_atomic_t * a, int oldval, int newval );
    static auto SDL_AtomicCAS = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_AtomicCAS" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_AtomicCAS" );
        }
        return ( SDL_AtomicCAS_handle )( dlsym_ptr );
    } ();
}

SDL_bool SDL_AtomicCAS ( SDL_atomic_t * a, int oldval, int newval );

namespace sym{
    typedef int ( *SDL_AtomicSet_handle )( SDL_atomic_t * a, int v );
    static auto SDL_AtomicSet = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_AtomicSet" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_AtomicSet" );
        }
        return ( SDL_AtomicSet_handle )( dlsym_ptr );
    } ();
}

int SDL_AtomicSet ( SDL_atomic_t * a, int v );

namespace sym{
    typedef int ( *SDL_AtomicGet_handle )( SDL_atomic_t * a );
    static auto SDL_AtomicGet = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_AtomicGet" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_AtomicGet" );
        }
        return ( SDL_AtomicGet_handle )( dlsym_ptr );
    } ();
}

int SDL_AtomicGet ( SDL_atomic_t * a );

namespace sym{
    typedef int ( *SDL_AtomicAdd_handle )( SDL_atomic_t * a, int v );
    static auto SDL_AtomicAdd = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_AtomicAdd" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_AtomicAdd" );
        }
        return ( SDL_AtomicAdd_handle )( dlsym_ptr );
    } ();
}

int SDL_AtomicAdd ( SDL_atomic_t * a, int v );

namespace sym{
    typedef SDL_bool ( *SDL_AtomicCASPtr_handle )( void ** a, void * oldval, void * newval );
    static auto SDL_AtomicCASPtr = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_AtomicCASPtr" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_AtomicCASPtr" );
        }
        return ( SDL_AtomicCASPtr_handle )( dlsym_ptr );
    } ();
}

SDL_bool SDL_AtomicCASPtr ( void ** a, void * oldval, void * newval );

namespace sym{
    typedef void * ( *SDL_AtomicSetPtr_handle )( void ** a, void * v );
    static auto SDL_AtomicSetPtr = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_AtomicSetPtr" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_AtomicSetPtr" );
        }
        return ( SDL_AtomicSetPtr_handle )( dlsym_ptr );
    } ();
}

void * SDL_AtomicSetPtr ( void ** a, void * v );

namespace sym{
    typedef void * ( *SDL_AtomicGetPtr_handle )( void ** a );
    static auto SDL_AtomicGetPtr = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_AtomicGetPtr" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_AtomicGetPtr" );
        }
        return ( SDL_AtomicGetPtr_handle )( dlsym_ptr );
    } ();
}

void * SDL_AtomicGetPtr ( void ** a );

namespace sym{
    typedef int ( *SDL_SetError_handle )( const char * fmt );
    static auto SDL_SetError = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_SetError" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_SetError" );
        }
        return ( SDL_SetError_handle )( dlsym_ptr );
    } ();
}

int SDL_SetError ( const char * fmt );

namespace sym{
    typedef const char * ( *SDL_GetError_handle )(  );
    static auto SDL_GetError = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetError" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetError" );
        }
        return ( SDL_GetError_handle )( dlsym_ptr );
    } ();
}

const char * SDL_GetError (  );

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
    typedef int ( *SDL_Error_handle )( SDL_errorcode code );
    static auto SDL_Error = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_Error" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_Error" );
        }
        return ( SDL_Error_handle )( dlsym_ptr );
    } ();
}

int SDL_Error ( SDL_errorcode code );

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
    typedef int ( *SDL_LockMutex_handle )( SDL_mutex * mutex );
    static auto SDL_LockMutex = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_LockMutex" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_LockMutex" );
        }
        return ( SDL_LockMutex_handle )( dlsym_ptr );
    } ();
}

int SDL_LockMutex ( SDL_mutex * mutex );

namespace sym{
    typedef int ( *SDL_TryLockMutex_handle )( SDL_mutex * mutex );
    static auto SDL_TryLockMutex = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_TryLockMutex" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_TryLockMutex" );
        }
        return ( SDL_TryLockMutex_handle )( dlsym_ptr );
    } ();
}

int SDL_TryLockMutex ( SDL_mutex * mutex );

namespace sym{
    typedef int ( *SDL_UnlockMutex_handle )( SDL_mutex * mutex );
    static auto SDL_UnlockMutex = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_UnlockMutex" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_UnlockMutex" );
        }
        return ( SDL_UnlockMutex_handle )( dlsym_ptr );
    } ();
}

int SDL_UnlockMutex ( SDL_mutex * mutex );

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
    typedef int ( *SDL_CondWait_handle )( SDL_cond * cond, SDL_mutex * mutex );
    static auto SDL_CondWait = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_CondWait" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_CondWait" );
        }
        return ( SDL_CondWait_handle )( dlsym_ptr );
    } ();
}

int SDL_CondWait ( SDL_cond * cond, SDL_mutex * mutex );

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
    typedef SDL_Thread * ( *SDL_CreateThread_handle )( SDL_ThreadFunction fn, const char * name, void * data );
    static auto SDL_CreateThread = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_CreateThread" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_CreateThread" );
        }
        return ( SDL_CreateThread_handle )( dlsym_ptr );
    } ();
}

SDL_Thread * SDL_CreateThread ( SDL_ThreadFunction fn, const char * name, void * data );

namespace sym{
    typedef const char * ( *SDL_GetThreadName_handle )( SDL_Thread * thread );
    static auto SDL_GetThreadName = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetThreadName" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetThreadName" );
        }
        return ( SDL_GetThreadName_handle )( dlsym_ptr );
    } ();
}

const char * SDL_GetThreadName ( SDL_Thread * thread );

namespace sym{
    typedef SDL_threadID ( *SDL_ThreadID_handle )(  );
    static auto SDL_ThreadID = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_ThreadID" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_ThreadID" );
        }
        return ( SDL_ThreadID_handle )( dlsym_ptr );
    } ();
}

SDL_threadID SDL_ThreadID (  );

namespace sym{
    typedef SDL_threadID ( *SDL_GetThreadID_handle )( SDL_Thread * thread );
    static auto SDL_GetThreadID = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetThreadID" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetThreadID" );
        }
        return ( SDL_GetThreadID_handle )( dlsym_ptr );
    } ();
}

SDL_threadID SDL_GetThreadID ( SDL_Thread * thread );

namespace sym{
    typedef int ( *SDL_SetThreadPriority_handle )( SDL_ThreadPriority priority );
    static auto SDL_SetThreadPriority = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_SetThreadPriority" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_SetThreadPriority" );
        }
        return ( SDL_SetThreadPriority_handle )( dlsym_ptr );
    } ();
}

int SDL_SetThreadPriority ( SDL_ThreadPriority priority );

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
    typedef void ( *SDL_DetachThread_handle )( SDL_Thread * thread );
    static auto SDL_DetachThread = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_DetachThread" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_DetachThread" );
        }
        return ( SDL_DetachThread_handle )( dlsym_ptr );
    } ();
}

void SDL_DetachThread ( SDL_Thread * thread );

namespace sym{
    typedef SDL_TLSID ( *SDL_TLSCreate_handle )(  );
    static auto SDL_TLSCreate = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_TLSCreate" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_TLSCreate" );
        }
        return ( SDL_TLSCreate_handle )( dlsym_ptr );
    } ();
}

SDL_TLSID SDL_TLSCreate (  );

namespace sym{
    typedef void * ( *SDL_TLSGet_handle )( SDL_TLSID id );
    static auto SDL_TLSGet = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_TLSGet" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_TLSGet" );
        }
        return ( SDL_TLSGet_handle )( dlsym_ptr );
    } ();
}

void * SDL_TLSGet ( SDL_TLSID id );

namespace sym{
    typedef int ( *SDL_TLSSet_handle )( SDL_TLSID id, const void * value, void (*destructor)(void *) );
    static auto SDL_TLSSet = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_TLSSet" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_TLSSet" );
        }
        return ( SDL_TLSSet_handle )( dlsym_ptr );
    } ();
}

int SDL_TLSSet ( SDL_TLSID id, const void * value, void (*destructor)(void *) );

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
    typedef SDL_RWops * ( *SDL_RWFromFP_handle )( FILE * fp, SDL_bool autoclose );
    static auto SDL_RWFromFP = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_RWFromFP" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_RWFromFP" );
        }
        return ( SDL_RWFromFP_handle )( dlsym_ptr );
    } ();
}

SDL_RWops * SDL_RWFromFP ( FILE * fp, SDL_bool autoclose );

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
    typedef void * ( *SDL_LoadFile_RW_handle )( SDL_RWops * src, size_t * datasize, int freesrc );
    static auto SDL_LoadFile_RW = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_LoadFile_RW" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_LoadFile_RW" );
        }
        return ( SDL_LoadFile_RW_handle )( dlsym_ptr );
    } ();
}

void * SDL_LoadFile_RW ( SDL_RWops * src, size_t * datasize, int freesrc );

namespace sym{
    typedef Uint8 ( *SDL_ReadU8_handle )( SDL_RWops * src );
    static auto SDL_ReadU8 = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_ReadU8" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_ReadU8" );
        }
        return ( SDL_ReadU8_handle )( dlsym_ptr );
    } ();
}

Uint8 SDL_ReadU8 ( SDL_RWops * src );

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
    typedef size_t ( *SDL_WriteU8_handle )( SDL_RWops * dst, Uint8 value );
    static auto SDL_WriteU8 = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_WriteU8" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_WriteU8" );
        }
        return ( SDL_WriteU8_handle )( dlsym_ptr );
    } ();
}

size_t SDL_WriteU8 ( SDL_RWops * dst, Uint8 value );

namespace sym{
    typedef size_t ( *SDL_WriteLE16_handle )( SDL_RWops * dst, Uint16 value );
    static auto SDL_WriteLE16 = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_WriteLE16" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_WriteLE16" );
        }
        return ( SDL_WriteLE16_handle )( dlsym_ptr );
    } ();
}

size_t SDL_WriteLE16 ( SDL_RWops * dst, Uint16 value );

namespace sym{
    typedef size_t ( *SDL_WriteBE16_handle )( SDL_RWops * dst, Uint16 value );
    static auto SDL_WriteBE16 = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_WriteBE16" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_WriteBE16" );
        }
        return ( SDL_WriteBE16_handle )( dlsym_ptr );
    } ();
}

size_t SDL_WriteBE16 ( SDL_RWops * dst, Uint16 value );

namespace sym{
    typedef size_t ( *SDL_WriteLE32_handle )( SDL_RWops * dst, Uint32 value );
    static auto SDL_WriteLE32 = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_WriteLE32" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_WriteLE32" );
        }
        return ( SDL_WriteLE32_handle )( dlsym_ptr );
    } ();
}

size_t SDL_WriteLE32 ( SDL_RWops * dst, Uint32 value );

namespace sym{
    typedef size_t ( *SDL_WriteBE32_handle )( SDL_RWops * dst, Uint32 value );
    static auto SDL_WriteBE32 = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_WriteBE32" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_WriteBE32" );
        }
        return ( SDL_WriteBE32_handle )( dlsym_ptr );
    } ();
}

size_t SDL_WriteBE32 ( SDL_RWops * dst, Uint32 value );

namespace sym{
    typedef size_t ( *SDL_WriteLE64_handle )( SDL_RWops * dst, Uint64 value );
    static auto SDL_WriteLE64 = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_WriteLE64" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_WriteLE64" );
        }
        return ( SDL_WriteLE64_handle )( dlsym_ptr );
    } ();
}

size_t SDL_WriteLE64 ( SDL_RWops * dst, Uint64 value );

namespace sym{
    typedef size_t ( *SDL_WriteBE64_handle )( SDL_RWops * dst, Uint64 value );
    static auto SDL_WriteBE64 = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_WriteBE64" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_WriteBE64" );
        }
        return ( SDL_WriteBE64_handle )( dlsym_ptr );
    } ();
}

size_t SDL_WriteBE64 ( SDL_RWops * dst, Uint64 value );

namespace sym{
    typedef int ( *SDL_GetNumAudioDrivers_handle )(  );
    static auto SDL_GetNumAudioDrivers = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetNumAudioDrivers" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetNumAudioDrivers" );
        }
        return ( SDL_GetNumAudioDrivers_handle )( dlsym_ptr );
    } ();
}

int SDL_GetNumAudioDrivers (  );

namespace sym{
    typedef const char * ( *SDL_GetAudioDriver_handle )( int index );
    static auto SDL_GetAudioDriver = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetAudioDriver" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetAudioDriver" );
        }
        return ( SDL_GetAudioDriver_handle )( dlsym_ptr );
    } ();
}

const char * SDL_GetAudioDriver ( int index );

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
    typedef const char * ( *SDL_GetCurrentAudioDriver_handle )(  );
    static auto SDL_GetCurrentAudioDriver = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetCurrentAudioDriver" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetCurrentAudioDriver" );
        }
        return ( SDL_GetCurrentAudioDriver_handle )( dlsym_ptr );
    } ();
}

const char * SDL_GetCurrentAudioDriver (  );

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
    typedef int ( *SDL_GetNumAudioDevices_handle )( int iscapture );
    static auto SDL_GetNumAudioDevices = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetNumAudioDevices" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetNumAudioDevices" );
        }
        return ( SDL_GetNumAudioDevices_handle )( dlsym_ptr );
    } ();
}

int SDL_GetNumAudioDevices ( int iscapture );

namespace sym{
    typedef const char * ( *SDL_GetAudioDeviceName_handle )( int index, int iscapture );
    static auto SDL_GetAudioDeviceName = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetAudioDeviceName" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetAudioDeviceName" );
        }
        return ( SDL_GetAudioDeviceName_handle )( dlsym_ptr );
    } ();
}

const char * SDL_GetAudioDeviceName ( int index, int iscapture );

namespace sym{
    typedef SDL_AudioDeviceID ( *SDL_OpenAudioDevice_handle )( const char * device, int iscapture, const SDL_AudioSpec * desired, SDL_AudioSpec * obtained, int allowed_changes );
    static auto SDL_OpenAudioDevice = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_OpenAudioDevice" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_OpenAudioDevice" );
        }
        return ( SDL_OpenAudioDevice_handle )( dlsym_ptr );
    } ();
}

SDL_AudioDeviceID SDL_OpenAudioDevice ( const char * device, int iscapture, const SDL_AudioSpec * desired, SDL_AudioSpec * obtained, int allowed_changes );

namespace sym{
    typedef SDL_AudioStatus ( *SDL_GetAudioStatus_handle )(  );
    static auto SDL_GetAudioStatus = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetAudioStatus" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetAudioStatus" );
        }
        return ( SDL_GetAudioStatus_handle )( dlsym_ptr );
    } ();
}

SDL_AudioStatus SDL_GetAudioStatus (  );

namespace sym{
    typedef SDL_AudioStatus ( *SDL_GetAudioDeviceStatus_handle )( SDL_AudioDeviceID dev );
    static auto SDL_GetAudioDeviceStatus = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetAudioDeviceStatus" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetAudioDeviceStatus" );
        }
        return ( SDL_GetAudioDeviceStatus_handle )( dlsym_ptr );
    } ();
}

SDL_AudioStatus SDL_GetAudioDeviceStatus ( SDL_AudioDeviceID dev );

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
    typedef void ( *SDL_PauseAudioDevice_handle )( SDL_AudioDeviceID dev, int pause_on );
    static auto SDL_PauseAudioDevice = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_PauseAudioDevice" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_PauseAudioDevice" );
        }
        return ( SDL_PauseAudioDevice_handle )( dlsym_ptr );
    } ();
}

void SDL_PauseAudioDevice ( SDL_AudioDeviceID dev, int pause_on );

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
    typedef int ( *SDL_BuildAudioCVT_handle )( SDL_AudioCVT * cvt, SDL_AudioFormat src_format, Uint8 src_channels, int src_rate, SDL_AudioFormat dst_format, Uint8 dst_channels, int dst_rate );
    static auto SDL_BuildAudioCVT = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_BuildAudioCVT" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_BuildAudioCVT" );
        }
        return ( SDL_BuildAudioCVT_handle )( dlsym_ptr );
    } ();
}

int SDL_BuildAudioCVT ( SDL_AudioCVT * cvt, SDL_AudioFormat src_format, Uint8 src_channels, int src_rate, SDL_AudioFormat dst_format, Uint8 dst_channels, int dst_rate );

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
    typedef SDL_AudioStream * ( *SDL_NewAudioStream_handle )( const SDL_AudioFormat src_format, const Uint8 src_channels, const int src_rate, const SDL_AudioFormat dst_format, const Uint8 dst_channels, const int dst_rate );
    static auto SDL_NewAudioStream = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_NewAudioStream" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_NewAudioStream" );
        }
        return ( SDL_NewAudioStream_handle )( dlsym_ptr );
    } ();
}

SDL_AudioStream * SDL_NewAudioStream ( const SDL_AudioFormat src_format, const Uint8 src_channels, const int src_rate, const SDL_AudioFormat dst_format, const Uint8 dst_channels, const int dst_rate );

namespace sym{
    typedef int ( *SDL_AudioStreamPut_handle )( SDL_AudioStream * stream, const void * buf, int len );
    static auto SDL_AudioStreamPut = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_AudioStreamPut" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_AudioStreamPut" );
        }
        return ( SDL_AudioStreamPut_handle )( dlsym_ptr );
    } ();
}

int SDL_AudioStreamPut ( SDL_AudioStream * stream, const void * buf, int len );

namespace sym{
    typedef int ( *SDL_AudioStreamGet_handle )( SDL_AudioStream * stream, void * buf, int len );
    static auto SDL_AudioStreamGet = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_AudioStreamGet" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_AudioStreamGet" );
        }
        return ( SDL_AudioStreamGet_handle )( dlsym_ptr );
    } ();
}

int SDL_AudioStreamGet ( SDL_AudioStream * stream, void * buf, int len );

namespace sym{
    typedef int ( *SDL_AudioStreamAvailable_handle )( SDL_AudioStream * stream );
    static auto SDL_AudioStreamAvailable = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_AudioStreamAvailable" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_AudioStreamAvailable" );
        }
        return ( SDL_AudioStreamAvailable_handle )( dlsym_ptr );
    } ();
}

int SDL_AudioStreamAvailable ( SDL_AudioStream * stream );

namespace sym{
    typedef int ( *SDL_AudioStreamFlush_handle )( SDL_AudioStream * stream );
    static auto SDL_AudioStreamFlush = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_AudioStreamFlush" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_AudioStreamFlush" );
        }
        return ( SDL_AudioStreamFlush_handle )( dlsym_ptr );
    } ();
}

int SDL_AudioStreamFlush ( SDL_AudioStream * stream );

namespace sym{
    typedef void ( *SDL_AudioStreamClear_handle )( SDL_AudioStream * stream );
    static auto SDL_AudioStreamClear = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_AudioStreamClear" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_AudioStreamClear" );
        }
        return ( SDL_AudioStreamClear_handle )( dlsym_ptr );
    } ();
}

void SDL_AudioStreamClear ( SDL_AudioStream * stream );

namespace sym{
    typedef void ( *SDL_FreeAudioStream_handle )( SDL_AudioStream * stream );
    static auto SDL_FreeAudioStream = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_FreeAudioStream" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_FreeAudioStream" );
        }
        return ( SDL_FreeAudioStream_handle )( dlsym_ptr );
    } ();
}

void SDL_FreeAudioStream ( SDL_AudioStream * stream );

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
    typedef void ( *SDL_MixAudioFormat_handle )( Uint8 * dst, const Uint8 * src, SDL_AudioFormat format, Uint32 len, int volume );
    static auto SDL_MixAudioFormat = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_MixAudioFormat" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_MixAudioFormat" );
        }
        return ( SDL_MixAudioFormat_handle )( dlsym_ptr );
    } ();
}

void SDL_MixAudioFormat ( Uint8 * dst, const Uint8 * src, SDL_AudioFormat format, Uint32 len, int volume );

namespace sym{
    typedef int ( *SDL_QueueAudio_handle )( SDL_AudioDeviceID dev, const void * data, Uint32 len );
    static auto SDL_QueueAudio = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_QueueAudio" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_QueueAudio" );
        }
        return ( SDL_QueueAudio_handle )( dlsym_ptr );
    } ();
}

int SDL_QueueAudio ( SDL_AudioDeviceID dev, const void * data, Uint32 len );

namespace sym{
    typedef Uint32 ( *SDL_DequeueAudio_handle )( SDL_AudioDeviceID dev, void * data, Uint32 len );
    static auto SDL_DequeueAudio = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_DequeueAudio" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_DequeueAudio" );
        }
        return ( SDL_DequeueAudio_handle )( dlsym_ptr );
    } ();
}

Uint32 SDL_DequeueAudio ( SDL_AudioDeviceID dev, void * data, Uint32 len );

namespace sym{
    typedef Uint32 ( *SDL_GetQueuedAudioSize_handle )( SDL_AudioDeviceID dev );
    static auto SDL_GetQueuedAudioSize = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetQueuedAudioSize" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetQueuedAudioSize" );
        }
        return ( SDL_GetQueuedAudioSize_handle )( dlsym_ptr );
    } ();
}

Uint32 SDL_GetQueuedAudioSize ( SDL_AudioDeviceID dev );

namespace sym{
    typedef void ( *SDL_ClearQueuedAudio_handle )( SDL_AudioDeviceID dev );
    static auto SDL_ClearQueuedAudio = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_ClearQueuedAudio" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_ClearQueuedAudio" );
        }
        return ( SDL_ClearQueuedAudio_handle )( dlsym_ptr );
    } ();
}

void SDL_ClearQueuedAudio ( SDL_AudioDeviceID dev );

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
    typedef void ( *SDL_LockAudioDevice_handle )( SDL_AudioDeviceID dev );
    static auto SDL_LockAudioDevice = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_LockAudioDevice" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_LockAudioDevice" );
        }
        return ( SDL_LockAudioDevice_handle )( dlsym_ptr );
    } ();
}

void SDL_LockAudioDevice ( SDL_AudioDeviceID dev );

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
    typedef void ( *SDL_UnlockAudioDevice_handle )( SDL_AudioDeviceID dev );
    static auto SDL_UnlockAudioDevice = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_UnlockAudioDevice" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_UnlockAudioDevice" );
        }
        return ( SDL_UnlockAudioDevice_handle )( dlsym_ptr );
    } ();
}

void SDL_UnlockAudioDevice ( SDL_AudioDeviceID dev );

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
    typedef void ( *SDL_CloseAudioDevice_handle )( SDL_AudioDeviceID dev );
    static auto SDL_CloseAudioDevice = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_CloseAudioDevice" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_CloseAudioDevice" );
        }
        return ( SDL_CloseAudioDevice_handle )( dlsym_ptr );
    } ();
}

void SDL_CloseAudioDevice ( SDL_AudioDeviceID dev );

namespace sym{
    typedef int ( *SDL_SetClipboardText_handle )( const char * text );
    static auto SDL_SetClipboardText = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_SetClipboardText" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_SetClipboardText" );
        }
        return ( SDL_SetClipboardText_handle )( dlsym_ptr );
    } ();
}

int SDL_SetClipboardText ( const char * text );

namespace sym{
    typedef char * ( *SDL_GetClipboardText_handle )(  );
    static auto SDL_GetClipboardText = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetClipboardText" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetClipboardText" );
        }
        return ( SDL_GetClipboardText_handle )( dlsym_ptr );
    } ();
}

char * SDL_GetClipboardText (  );

namespace sym{
    typedef SDL_bool ( *SDL_HasClipboardText_handle )(  );
    static auto SDL_HasClipboardText = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_HasClipboardText" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_HasClipboardText" );
        }
        return ( SDL_HasClipboardText_handle )( dlsym_ptr );
    } ();
}

SDL_bool SDL_HasClipboardText (  );

namespace sym{
    typedef int ( *SDL_GetCPUCount_handle )(  );
    static auto SDL_GetCPUCount = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetCPUCount" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetCPUCount" );
        }
        return ( SDL_GetCPUCount_handle )( dlsym_ptr );
    } ();
}

int SDL_GetCPUCount (  );

namespace sym{
    typedef int ( *SDL_GetCPUCacheLineSize_handle )(  );
    static auto SDL_GetCPUCacheLineSize = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetCPUCacheLineSize" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetCPUCacheLineSize" );
        }
        return ( SDL_GetCPUCacheLineSize_handle )( dlsym_ptr );
    } ();
}

int SDL_GetCPUCacheLineSize (  );

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
    typedef SDL_bool ( *SDL_HasSSE3_handle )(  );
    static auto SDL_HasSSE3 = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_HasSSE3" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_HasSSE3" );
        }
        return ( SDL_HasSSE3_handle )( dlsym_ptr );
    } ();
}

SDL_bool SDL_HasSSE3 (  );

namespace sym{
    typedef SDL_bool ( *SDL_HasSSE41_handle )(  );
    static auto SDL_HasSSE41 = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_HasSSE41" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_HasSSE41" );
        }
        return ( SDL_HasSSE41_handle )( dlsym_ptr );
    } ();
}

SDL_bool SDL_HasSSE41 (  );

namespace sym{
    typedef SDL_bool ( *SDL_HasSSE42_handle )(  );
    static auto SDL_HasSSE42 = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_HasSSE42" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_HasSSE42" );
        }
        return ( SDL_HasSSE42_handle )( dlsym_ptr );
    } ();
}

SDL_bool SDL_HasSSE42 (  );

namespace sym{
    typedef SDL_bool ( *SDL_HasAVX_handle )(  );
    static auto SDL_HasAVX = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_HasAVX" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_HasAVX" );
        }
        return ( SDL_HasAVX_handle )( dlsym_ptr );
    } ();
}

SDL_bool SDL_HasAVX (  );

namespace sym{
    typedef SDL_bool ( *SDL_HasAVX2_handle )(  );
    static auto SDL_HasAVX2 = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_HasAVX2" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_HasAVX2" );
        }
        return ( SDL_HasAVX2_handle )( dlsym_ptr );
    } ();
}

SDL_bool SDL_HasAVX2 (  );

namespace sym{
    typedef SDL_bool ( *SDL_HasNEON_handle )(  );
    static auto SDL_HasNEON = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_HasNEON" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_HasNEON" );
        }
        return ( SDL_HasNEON_handle )( dlsym_ptr );
    } ();
}

SDL_bool SDL_HasNEON (  );

namespace sym{
    typedef int ( *SDL_GetSystemRAM_handle )(  );
    static auto SDL_GetSystemRAM = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetSystemRAM" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetSystemRAM" );
        }
        return ( SDL_GetSystemRAM_handle )( dlsym_ptr );
    } ();
}

int SDL_GetSystemRAM (  );

namespace sym{
    typedef const char * ( *SDL_GetPixelFormatName_handle )( Uint32 format );
    static auto SDL_GetPixelFormatName = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetPixelFormatName" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetPixelFormatName" );
        }
        return ( SDL_GetPixelFormatName_handle )( dlsym_ptr );
    } ();
}

const char * SDL_GetPixelFormatName ( Uint32 format );

namespace sym{
    typedef SDL_bool ( *SDL_PixelFormatEnumToMasks_handle )( Uint32 format, int * bpp, Uint32 * Rmask, Uint32 * Gmask, Uint32 * Bmask, Uint32 * Amask );
    static auto SDL_PixelFormatEnumToMasks = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_PixelFormatEnumToMasks" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_PixelFormatEnumToMasks" );
        }
        return ( SDL_PixelFormatEnumToMasks_handle )( dlsym_ptr );
    } ();
}

SDL_bool SDL_PixelFormatEnumToMasks ( Uint32 format, int * bpp, Uint32 * Rmask, Uint32 * Gmask, Uint32 * Bmask, Uint32 * Amask );

namespace sym{
    typedef Uint32 ( *SDL_MasksToPixelFormatEnum_handle )( int bpp, Uint32 Rmask, Uint32 Gmask, Uint32 Bmask, Uint32 Amask );
    static auto SDL_MasksToPixelFormatEnum = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_MasksToPixelFormatEnum" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_MasksToPixelFormatEnum" );
        }
        return ( SDL_MasksToPixelFormatEnum_handle )( dlsym_ptr );
    } ();
}

Uint32 SDL_MasksToPixelFormatEnum ( int bpp, Uint32 Rmask, Uint32 Gmask, Uint32 Bmask, Uint32 Amask );

namespace sym{
    typedef SDL_PixelFormat * ( *SDL_AllocFormat_handle )( Uint32 pixel_format );
    static auto SDL_AllocFormat = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_AllocFormat" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_AllocFormat" );
        }
        return ( SDL_AllocFormat_handle )( dlsym_ptr );
    } ();
}

SDL_PixelFormat * SDL_AllocFormat ( Uint32 pixel_format );

namespace sym{
    typedef void ( *SDL_FreeFormat_handle )( SDL_PixelFormat * format );
    static auto SDL_FreeFormat = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_FreeFormat" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_FreeFormat" );
        }
        return ( SDL_FreeFormat_handle )( dlsym_ptr );
    } ();
}

void SDL_FreeFormat ( SDL_PixelFormat * format );

namespace sym{
    typedef SDL_Palette * ( *SDL_AllocPalette_handle )( int ncolors );
    static auto SDL_AllocPalette = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_AllocPalette" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_AllocPalette" );
        }
        return ( SDL_AllocPalette_handle )( dlsym_ptr );
    } ();
}

SDL_Palette * SDL_AllocPalette ( int ncolors );

namespace sym{
    typedef int ( *SDL_SetPixelFormatPalette_handle )( SDL_PixelFormat * format, SDL_Palette * palette );
    static auto SDL_SetPixelFormatPalette = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_SetPixelFormatPalette" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_SetPixelFormatPalette" );
        }
        return ( SDL_SetPixelFormatPalette_handle )( dlsym_ptr );
    } ();
}

int SDL_SetPixelFormatPalette ( SDL_PixelFormat * format, SDL_Palette * palette );

namespace sym{
    typedef int ( *SDL_SetPaletteColors_handle )( SDL_Palette * palette, const SDL_Color * colors, int firstcolor, int ncolors );
    static auto SDL_SetPaletteColors = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_SetPaletteColors" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_SetPaletteColors" );
        }
        return ( SDL_SetPaletteColors_handle )( dlsym_ptr );
    } ();
}

int SDL_SetPaletteColors ( SDL_Palette * palette, const SDL_Color * colors, int firstcolor, int ncolors );

namespace sym{
    typedef void ( *SDL_FreePalette_handle )( SDL_Palette * palette );
    static auto SDL_FreePalette = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_FreePalette" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_FreePalette" );
        }
        return ( SDL_FreePalette_handle )( dlsym_ptr );
    } ();
}

void SDL_FreePalette ( SDL_Palette * palette );

namespace sym{
    typedef Uint32 ( *SDL_MapRGB_handle )( const SDL_PixelFormat * format, Uint8 r, Uint8 g, Uint8 b );
    static auto SDL_MapRGB = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_MapRGB" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_MapRGB" );
        }
        return ( SDL_MapRGB_handle )( dlsym_ptr );
    } ();
}

Uint32 SDL_MapRGB ( const SDL_PixelFormat * format, Uint8 r, Uint8 g, Uint8 b );

namespace sym{
    typedef Uint32 ( *SDL_MapRGBA_handle )( const SDL_PixelFormat * format, Uint8 r, Uint8 g, Uint8 b, Uint8 a );
    static auto SDL_MapRGBA = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_MapRGBA" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_MapRGBA" );
        }
        return ( SDL_MapRGBA_handle )( dlsym_ptr );
    } ();
}

Uint32 SDL_MapRGBA ( const SDL_PixelFormat * format, Uint8 r, Uint8 g, Uint8 b, Uint8 a );

namespace sym{
    typedef void ( *SDL_GetRGB_handle )( Uint32 pixel, const SDL_PixelFormat * format, Uint8 * r, Uint8 * g, Uint8 * b );
    static auto SDL_GetRGB = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetRGB" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetRGB" );
        }
        return ( SDL_GetRGB_handle )( dlsym_ptr );
    } ();
}

void SDL_GetRGB ( Uint32 pixel, const SDL_PixelFormat * format, Uint8 * r, Uint8 * g, Uint8 * b );

namespace sym{
    typedef void ( *SDL_GetRGBA_handle )( Uint32 pixel, const SDL_PixelFormat * format, Uint8 * r, Uint8 * g, Uint8 * b, Uint8 * a );
    static auto SDL_GetRGBA = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetRGBA" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetRGBA" );
        }
        return ( SDL_GetRGBA_handle )( dlsym_ptr );
    } ();
}

void SDL_GetRGBA ( Uint32 pixel, const SDL_PixelFormat * format, Uint8 * r, Uint8 * g, Uint8 * b, Uint8 * a );

namespace sym{
    typedef void ( *SDL_CalculateGammaRamp_handle )( float gamma, Uint16 * ramp );
    static auto SDL_CalculateGammaRamp = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_CalculateGammaRamp" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_CalculateGammaRamp" );
        }
        return ( SDL_CalculateGammaRamp_handle )( dlsym_ptr );
    } ();
}

void SDL_CalculateGammaRamp ( float gamma, Uint16 * ramp );

namespace sym{
    typedef SDL_bool ( *SDL_HasIntersection_handle )( const SDL_Rect * A, const SDL_Rect * B );
    static auto SDL_HasIntersection = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_HasIntersection" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_HasIntersection" );
        }
        return ( SDL_HasIntersection_handle )( dlsym_ptr );
    } ();
}

SDL_bool SDL_HasIntersection ( const SDL_Rect * A, const SDL_Rect * B );

namespace sym{
    typedef SDL_bool ( *SDL_IntersectRect_handle )( const SDL_Rect * A, const SDL_Rect * B, SDL_Rect * result );
    static auto SDL_IntersectRect = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_IntersectRect" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_IntersectRect" );
        }
        return ( SDL_IntersectRect_handle )( dlsym_ptr );
    } ();
}

SDL_bool SDL_IntersectRect ( const SDL_Rect * A, const SDL_Rect * B, SDL_Rect * result );

namespace sym{
    typedef void ( *SDL_UnionRect_handle )( const SDL_Rect * A, const SDL_Rect * B, SDL_Rect * result );
    static auto SDL_UnionRect = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_UnionRect" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_UnionRect" );
        }
        return ( SDL_UnionRect_handle )( dlsym_ptr );
    } ();
}

void SDL_UnionRect ( const SDL_Rect * A, const SDL_Rect * B, SDL_Rect * result );

namespace sym{
    typedef SDL_bool ( *SDL_EnclosePoints_handle )( const SDL_Point * points, int count, const SDL_Rect * clip, SDL_Rect * result );
    static auto SDL_EnclosePoints = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_EnclosePoints" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_EnclosePoints" );
        }
        return ( SDL_EnclosePoints_handle )( dlsym_ptr );
    } ();
}

SDL_bool SDL_EnclosePoints ( const SDL_Point * points, int count, const SDL_Rect * clip, SDL_Rect * result );

namespace sym{
    typedef SDL_bool ( *SDL_IntersectRectAndLine_handle )( const SDL_Rect * rect, int * X1, int * Y1, int * X2, int * Y2 );
    static auto SDL_IntersectRectAndLine = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_IntersectRectAndLine" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_IntersectRectAndLine" );
        }
        return ( SDL_IntersectRectAndLine_handle )( dlsym_ptr );
    } ();
}

SDL_bool SDL_IntersectRectAndLine ( const SDL_Rect * rect, int * X1, int * Y1, int * X2, int * Y2 );

namespace sym{
    typedef SDL_BlendMode ( *SDL_ComposeCustomBlendMode_handle )( SDL_BlendFactor srcColorFactor, SDL_BlendFactor dstColorFactor, SDL_BlendOperation colorOperation, SDL_BlendFactor srcAlphaFactor, SDL_BlendFactor dstAlphaFactor, SDL_BlendOperation alphaOperation );
    static auto SDL_ComposeCustomBlendMode = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_ComposeCustomBlendMode" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_ComposeCustomBlendMode" );
        }
        return ( SDL_ComposeCustomBlendMode_handle )( dlsym_ptr );
    } ();
}

SDL_BlendMode SDL_ComposeCustomBlendMode ( SDL_BlendFactor srcColorFactor, SDL_BlendFactor dstColorFactor, SDL_BlendOperation colorOperation, SDL_BlendFactor srcAlphaFactor, SDL_BlendFactor dstAlphaFactor, SDL_BlendOperation alphaOperation );

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
    typedef SDL_Surface * ( *SDL_CreateRGBSurfaceWithFormat_handle )( Uint32 flags, int width, int height, int depth, Uint32 format );
    static auto SDL_CreateRGBSurfaceWithFormat = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_CreateRGBSurfaceWithFormat" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_CreateRGBSurfaceWithFormat" );
        }
        return ( SDL_CreateRGBSurfaceWithFormat_handle )( dlsym_ptr );
    } ();
}

SDL_Surface * SDL_CreateRGBSurfaceWithFormat ( Uint32 flags, int width, int height, int depth, Uint32 format );

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
    typedef SDL_Surface * ( *SDL_CreateRGBSurfaceWithFormatFrom_handle )( void * pixels, int width, int height, int depth, int pitch, Uint32 format );
    static auto SDL_CreateRGBSurfaceWithFormatFrom = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_CreateRGBSurfaceWithFormatFrom" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_CreateRGBSurfaceWithFormatFrom" );
        }
        return ( SDL_CreateRGBSurfaceWithFormatFrom_handle )( dlsym_ptr );
    } ();
}

SDL_Surface * SDL_CreateRGBSurfaceWithFormatFrom ( void * pixels, int width, int height, int depth, int pitch, Uint32 format );

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
    typedef int ( *SDL_SetSurfacePalette_handle )( SDL_Surface * surface, SDL_Palette * palette );
    static auto SDL_SetSurfacePalette = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_SetSurfacePalette" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_SetSurfacePalette" );
        }
        return ( SDL_SetSurfacePalette_handle )( dlsym_ptr );
    } ();
}

int SDL_SetSurfacePalette ( SDL_Surface * surface, SDL_Palette * palette );

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
    typedef int ( *SDL_SetSurfaceRLE_handle )( SDL_Surface * surface, int flag );
    static auto SDL_SetSurfaceRLE = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_SetSurfaceRLE" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_SetSurfaceRLE" );
        }
        return ( SDL_SetSurfaceRLE_handle )( dlsym_ptr );
    } ();
}

int SDL_SetSurfaceRLE ( SDL_Surface * surface, int flag );

namespace sym{
    typedef int ( *SDL_SetColorKey_handle )( SDL_Surface * surface, int flag, Uint32 key );
    static auto SDL_SetColorKey = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_SetColorKey" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_SetColorKey" );
        }
        return ( SDL_SetColorKey_handle )( dlsym_ptr );
    } ();
}

int SDL_SetColorKey ( SDL_Surface * surface, int flag, Uint32 key );

namespace sym{
    typedef int ( *SDL_GetColorKey_handle )( SDL_Surface * surface, Uint32 * key );
    static auto SDL_GetColorKey = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetColorKey" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetColorKey" );
        }
        return ( SDL_GetColorKey_handle )( dlsym_ptr );
    } ();
}

int SDL_GetColorKey ( SDL_Surface * surface, Uint32 * key );

namespace sym{
    typedef int ( *SDL_SetSurfaceColorMod_handle )( SDL_Surface * surface, Uint8 r, Uint8 g, Uint8 b );
    static auto SDL_SetSurfaceColorMod = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_SetSurfaceColorMod" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_SetSurfaceColorMod" );
        }
        return ( SDL_SetSurfaceColorMod_handle )( dlsym_ptr );
    } ();
}

int SDL_SetSurfaceColorMod ( SDL_Surface * surface, Uint8 r, Uint8 g, Uint8 b );

namespace sym{
    typedef int ( *SDL_GetSurfaceColorMod_handle )( SDL_Surface * surface, Uint8 * r, Uint8 * g, Uint8 * b );
    static auto SDL_GetSurfaceColorMod = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetSurfaceColorMod" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetSurfaceColorMod" );
        }
        return ( SDL_GetSurfaceColorMod_handle )( dlsym_ptr );
    } ();
}

int SDL_GetSurfaceColorMod ( SDL_Surface * surface, Uint8 * r, Uint8 * g, Uint8 * b );

namespace sym{
    typedef int ( *SDL_SetSurfaceAlphaMod_handle )( SDL_Surface * surface, Uint8 alpha );
    static auto SDL_SetSurfaceAlphaMod = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_SetSurfaceAlphaMod" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_SetSurfaceAlphaMod" );
        }
        return ( SDL_SetSurfaceAlphaMod_handle )( dlsym_ptr );
    } ();
}

int SDL_SetSurfaceAlphaMod ( SDL_Surface * surface, Uint8 alpha );

namespace sym{
    typedef int ( *SDL_GetSurfaceAlphaMod_handle )( SDL_Surface * surface, Uint8 * alpha );
    static auto SDL_GetSurfaceAlphaMod = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetSurfaceAlphaMod" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetSurfaceAlphaMod" );
        }
        return ( SDL_GetSurfaceAlphaMod_handle )( dlsym_ptr );
    } ();
}

int SDL_GetSurfaceAlphaMod ( SDL_Surface * surface, Uint8 * alpha );

namespace sym{
    typedef int ( *SDL_SetSurfaceBlendMode_handle )( SDL_Surface * surface, SDL_BlendMode blendMode );
    static auto SDL_SetSurfaceBlendMode = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_SetSurfaceBlendMode" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_SetSurfaceBlendMode" );
        }
        return ( SDL_SetSurfaceBlendMode_handle )( dlsym_ptr );
    } ();
}

int SDL_SetSurfaceBlendMode ( SDL_Surface * surface, SDL_BlendMode blendMode );

namespace sym{
    typedef int ( *SDL_GetSurfaceBlendMode_handle )( SDL_Surface * surface, SDL_BlendMode * blendMode );
    static auto SDL_GetSurfaceBlendMode = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetSurfaceBlendMode" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetSurfaceBlendMode" );
        }
        return ( SDL_GetSurfaceBlendMode_handle )( dlsym_ptr );
    } ();
}

int SDL_GetSurfaceBlendMode ( SDL_Surface * surface, SDL_BlendMode * blendMode );

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
    typedef SDL_Surface * ( *SDL_DuplicateSurface_handle )( SDL_Surface * surface );
    static auto SDL_DuplicateSurface = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_DuplicateSurface" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_DuplicateSurface" );
        }
        return ( SDL_DuplicateSurface_handle )( dlsym_ptr );
    } ();
}

SDL_Surface * SDL_DuplicateSurface ( SDL_Surface * surface );

namespace sym{
    typedef SDL_Surface * ( *SDL_ConvertSurface_handle )( SDL_Surface * src, const SDL_PixelFormat * fmt, Uint32 flags );
    static auto SDL_ConvertSurface = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_ConvertSurface" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_ConvertSurface" );
        }
        return ( SDL_ConvertSurface_handle )( dlsym_ptr );
    } ();
}

SDL_Surface * SDL_ConvertSurface ( SDL_Surface * src, const SDL_PixelFormat * fmt, Uint32 flags );

namespace sym{
    typedef SDL_Surface * ( *SDL_ConvertSurfaceFormat_handle )( SDL_Surface * src, Uint32 pixel_format, Uint32 flags );
    static auto SDL_ConvertSurfaceFormat = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_ConvertSurfaceFormat" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_ConvertSurfaceFormat" );
        }
        return ( SDL_ConvertSurfaceFormat_handle )( dlsym_ptr );
    } ();
}

SDL_Surface * SDL_ConvertSurfaceFormat ( SDL_Surface * src, Uint32 pixel_format, Uint32 flags );

namespace sym{
    typedef int ( *SDL_ConvertPixels_handle )( int width, int height, Uint32 src_format, const void * src, int src_pitch, Uint32 dst_format, void * dst, int dst_pitch );
    static auto SDL_ConvertPixels = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_ConvertPixels" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_ConvertPixels" );
        }
        return ( SDL_ConvertPixels_handle )( dlsym_ptr );
    } ();
}

int SDL_ConvertPixels ( int width, int height, Uint32 src_format, const void * src, int src_pitch, Uint32 dst_format, void * dst, int dst_pitch );

namespace sym{
    typedef int ( *SDL_FillRect_handle )( SDL_Surface * dst, const SDL_Rect * rect, Uint32 color );
    static auto SDL_FillRect = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_FillRect" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_FillRect" );
        }
        return ( SDL_FillRect_handle )( dlsym_ptr );
    } ();
}

int SDL_FillRect ( SDL_Surface * dst, const SDL_Rect * rect, Uint32 color );

namespace sym{
    typedef int ( *SDL_FillRects_handle )( SDL_Surface * dst, const SDL_Rect * rects, int count, Uint32 color );
    static auto SDL_FillRects = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_FillRects" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_FillRects" );
        }
        return ( SDL_FillRects_handle )( dlsym_ptr );
    } ();
}

int SDL_FillRects ( SDL_Surface * dst, const SDL_Rect * rects, int count, Uint32 color );

namespace sym{
    typedef int ( *SDL_UpperBlit_handle )( SDL_Surface * src, const SDL_Rect * srcrect, SDL_Surface * dst, SDL_Rect * dstrect );
    static auto SDL_UpperBlit = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_UpperBlit" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_UpperBlit" );
        }
        return ( SDL_UpperBlit_handle )( dlsym_ptr );
    } ();
}

int SDL_UpperBlit ( SDL_Surface * src, const SDL_Rect * srcrect, SDL_Surface * dst, SDL_Rect * dstrect );

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
    typedef int ( *SDL_SoftStretch_handle )( SDL_Surface * src, const SDL_Rect * srcrect, SDL_Surface * dst, const SDL_Rect * dstrect );
    static auto SDL_SoftStretch = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_SoftStretch" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_SoftStretch" );
        }
        return ( SDL_SoftStretch_handle )( dlsym_ptr );
    } ();
}

int SDL_SoftStretch ( SDL_Surface * src, const SDL_Rect * srcrect, SDL_Surface * dst, const SDL_Rect * dstrect );

namespace sym{
    typedef int ( *SDL_UpperBlitScaled_handle )( SDL_Surface * src, const SDL_Rect * srcrect, SDL_Surface * dst, SDL_Rect * dstrect );
    static auto SDL_UpperBlitScaled = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_UpperBlitScaled" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_UpperBlitScaled" );
        }
        return ( SDL_UpperBlitScaled_handle )( dlsym_ptr );
    } ();
}

int SDL_UpperBlitScaled ( SDL_Surface * src, const SDL_Rect * srcrect, SDL_Surface * dst, SDL_Rect * dstrect );

namespace sym{
    typedef int ( *SDL_LowerBlitScaled_handle )( SDL_Surface * src, SDL_Rect * srcrect, SDL_Surface * dst, SDL_Rect * dstrect );
    static auto SDL_LowerBlitScaled = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_LowerBlitScaled" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_LowerBlitScaled" );
        }
        return ( SDL_LowerBlitScaled_handle )( dlsym_ptr );
    } ();
}

int SDL_LowerBlitScaled ( SDL_Surface * src, SDL_Rect * srcrect, SDL_Surface * dst, SDL_Rect * dstrect );

namespace sym{
    typedef void ( *SDL_SetYUVConversionMode_handle )( SDL_YUV_CONVERSION_MODE mode );
    static auto SDL_SetYUVConversionMode = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_SetYUVConversionMode" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_SetYUVConversionMode" );
        }
        return ( SDL_SetYUVConversionMode_handle )( dlsym_ptr );
    } ();
}

void SDL_SetYUVConversionMode ( SDL_YUV_CONVERSION_MODE mode );

namespace sym{
    typedef SDL_YUV_CONVERSION_MODE ( *SDL_GetYUVConversionMode_handle )(  );
    static auto SDL_GetYUVConversionMode = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetYUVConversionMode" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetYUVConversionMode" );
        }
        return ( SDL_GetYUVConversionMode_handle )( dlsym_ptr );
    } ();
}

SDL_YUV_CONVERSION_MODE SDL_GetYUVConversionMode (  );

namespace sym{
    typedef SDL_YUV_CONVERSION_MODE ( *SDL_GetYUVConversionModeForResolution_handle )( int width, int height );
    static auto SDL_GetYUVConversionModeForResolution = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetYUVConversionModeForResolution" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetYUVConversionModeForResolution" );
        }
        return ( SDL_GetYUVConversionModeForResolution_handle )( dlsym_ptr );
    } ();
}

SDL_YUV_CONVERSION_MODE SDL_GetYUVConversionModeForResolution ( int width, int height );

namespace sym{
    typedef int ( *SDL_GetNumVideoDrivers_handle )(  );
    static auto SDL_GetNumVideoDrivers = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetNumVideoDrivers" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetNumVideoDrivers" );
        }
        return ( SDL_GetNumVideoDrivers_handle )( dlsym_ptr );
    } ();
}

int SDL_GetNumVideoDrivers (  );

namespace sym{
    typedef const char * ( *SDL_GetVideoDriver_handle )( int index );
    static auto SDL_GetVideoDriver = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetVideoDriver" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetVideoDriver" );
        }
        return ( SDL_GetVideoDriver_handle )( dlsym_ptr );
    } ();
}

const char * SDL_GetVideoDriver ( int index );

namespace sym{
    typedef int ( *SDL_VideoInit_handle )( const char * driver_name );
    static auto SDL_VideoInit = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_VideoInit" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_VideoInit" );
        }
        return ( SDL_VideoInit_handle )( dlsym_ptr );
    } ();
}

int SDL_VideoInit ( const char * driver_name );

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
    typedef const char * ( *SDL_GetCurrentVideoDriver_handle )(  );
    static auto SDL_GetCurrentVideoDriver = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetCurrentVideoDriver" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetCurrentVideoDriver" );
        }
        return ( SDL_GetCurrentVideoDriver_handle )( dlsym_ptr );
    } ();
}

const char * SDL_GetCurrentVideoDriver (  );

namespace sym{
    typedef int ( *SDL_GetNumVideoDisplays_handle )(  );
    static auto SDL_GetNumVideoDisplays = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetNumVideoDisplays" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetNumVideoDisplays" );
        }
        return ( SDL_GetNumVideoDisplays_handle )( dlsym_ptr );
    } ();
}

int SDL_GetNumVideoDisplays (  );

namespace sym{
    typedef const char * ( *SDL_GetDisplayName_handle )( int displayIndex );
    static auto SDL_GetDisplayName = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetDisplayName" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetDisplayName" );
        }
        return ( SDL_GetDisplayName_handle )( dlsym_ptr );
    } ();
}

const char * SDL_GetDisplayName ( int displayIndex );

namespace sym{
    typedef int ( *SDL_GetDisplayBounds_handle )( int displayIndex, SDL_Rect * rect );
    static auto SDL_GetDisplayBounds = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetDisplayBounds" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetDisplayBounds" );
        }
        return ( SDL_GetDisplayBounds_handle )( dlsym_ptr );
    } ();
}

int SDL_GetDisplayBounds ( int displayIndex, SDL_Rect * rect );

namespace sym{
    typedef int ( *SDL_GetDisplayDPI_handle )( int displayIndex, float * ddpi, float * hdpi, float * vdpi );
    static auto SDL_GetDisplayDPI = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetDisplayDPI" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetDisplayDPI" );
        }
        return ( SDL_GetDisplayDPI_handle )( dlsym_ptr );
    } ();
}

int SDL_GetDisplayDPI ( int displayIndex, float * ddpi, float * hdpi, float * vdpi );

namespace sym{
    typedef int ( *SDL_GetDisplayUsableBounds_handle )( int displayIndex, SDL_Rect * rect );
    static auto SDL_GetDisplayUsableBounds = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetDisplayUsableBounds" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetDisplayUsableBounds" );
        }
        return ( SDL_GetDisplayUsableBounds_handle )( dlsym_ptr );
    } ();
}

int SDL_GetDisplayUsableBounds ( int displayIndex, SDL_Rect * rect );

namespace sym{
    typedef int ( *SDL_GetNumDisplayModes_handle )( int displayIndex );
    static auto SDL_GetNumDisplayModes = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetNumDisplayModes" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetNumDisplayModes" );
        }
        return ( SDL_GetNumDisplayModes_handle )( dlsym_ptr );
    } ();
}

int SDL_GetNumDisplayModes ( int displayIndex );

namespace sym{
    typedef int ( *SDL_GetDisplayMode_handle )( int displayIndex, int modeIndex, SDL_DisplayMode * mode );
    static auto SDL_GetDisplayMode = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetDisplayMode" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetDisplayMode" );
        }
        return ( SDL_GetDisplayMode_handle )( dlsym_ptr );
    } ();
}

int SDL_GetDisplayMode ( int displayIndex, int modeIndex, SDL_DisplayMode * mode );

namespace sym{
    typedef int ( *SDL_GetDesktopDisplayMode_handle )( int displayIndex, SDL_DisplayMode * mode );
    static auto SDL_GetDesktopDisplayMode = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetDesktopDisplayMode" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetDesktopDisplayMode" );
        }
        return ( SDL_GetDesktopDisplayMode_handle )( dlsym_ptr );
    } ();
}

int SDL_GetDesktopDisplayMode ( int displayIndex, SDL_DisplayMode * mode );

namespace sym{
    typedef int ( *SDL_GetCurrentDisplayMode_handle )( int displayIndex, SDL_DisplayMode * mode );
    static auto SDL_GetCurrentDisplayMode = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetCurrentDisplayMode" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetCurrentDisplayMode" );
        }
        return ( SDL_GetCurrentDisplayMode_handle )( dlsym_ptr );
    } ();
}

int SDL_GetCurrentDisplayMode ( int displayIndex, SDL_DisplayMode * mode );

namespace sym{
    typedef SDL_DisplayMode * ( *SDL_GetClosestDisplayMode_handle )( int displayIndex, const SDL_DisplayMode * mode, SDL_DisplayMode * closest );
    static auto SDL_GetClosestDisplayMode = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetClosestDisplayMode" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetClosestDisplayMode" );
        }
        return ( SDL_GetClosestDisplayMode_handle )( dlsym_ptr );
    } ();
}

SDL_DisplayMode * SDL_GetClosestDisplayMode ( int displayIndex, const SDL_DisplayMode * mode, SDL_DisplayMode * closest );

namespace sym{
    typedef int ( *SDL_GetWindowDisplayIndex_handle )( SDL_Window * window );
    static auto SDL_GetWindowDisplayIndex = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetWindowDisplayIndex" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetWindowDisplayIndex" );
        }
        return ( SDL_GetWindowDisplayIndex_handle )( dlsym_ptr );
    } ();
}

int SDL_GetWindowDisplayIndex ( SDL_Window * window );

namespace sym{
    typedef int ( *SDL_SetWindowDisplayMode_handle )( SDL_Window * window, const SDL_DisplayMode * mode );
    static auto SDL_SetWindowDisplayMode = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_SetWindowDisplayMode" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_SetWindowDisplayMode" );
        }
        return ( SDL_SetWindowDisplayMode_handle )( dlsym_ptr );
    } ();
}

int SDL_SetWindowDisplayMode ( SDL_Window * window, const SDL_DisplayMode * mode );

namespace sym{
    typedef int ( *SDL_GetWindowDisplayMode_handle )( SDL_Window * window, SDL_DisplayMode * mode );
    static auto SDL_GetWindowDisplayMode = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetWindowDisplayMode" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetWindowDisplayMode" );
        }
        return ( SDL_GetWindowDisplayMode_handle )( dlsym_ptr );
    } ();
}

int SDL_GetWindowDisplayMode ( SDL_Window * window, SDL_DisplayMode * mode );

namespace sym{
    typedef Uint32 ( *SDL_GetWindowPixelFormat_handle )( SDL_Window * window );
    static auto SDL_GetWindowPixelFormat = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetWindowPixelFormat" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetWindowPixelFormat" );
        }
        return ( SDL_GetWindowPixelFormat_handle )( dlsym_ptr );
    } ();
}

Uint32 SDL_GetWindowPixelFormat ( SDL_Window * window );

namespace sym{
    typedef SDL_Window * ( *SDL_CreateWindow_handle )( const char * title, int x, int y, int w, int h, Uint32 flags );
    static auto SDL_CreateWindow = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_CreateWindow" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_CreateWindow" );
        }
        return ( SDL_CreateWindow_handle )( dlsym_ptr );
    } ();
}

SDL_Window * SDL_CreateWindow ( const char * title, int x, int y, int w, int h, Uint32 flags );

namespace sym{
    typedef SDL_Window * ( *SDL_CreateWindowFrom_handle )( const void * data );
    static auto SDL_CreateWindowFrom = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_CreateWindowFrom" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_CreateWindowFrom" );
        }
        return ( SDL_CreateWindowFrom_handle )( dlsym_ptr );
    } ();
}

SDL_Window * SDL_CreateWindowFrom ( const void * data );

namespace sym{
    typedef Uint32 ( *SDL_GetWindowID_handle )( SDL_Window * window );
    static auto SDL_GetWindowID = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetWindowID" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetWindowID" );
        }
        return ( SDL_GetWindowID_handle )( dlsym_ptr );
    } ();
}

Uint32 SDL_GetWindowID ( SDL_Window * window );

namespace sym{
    typedef SDL_Window * ( *SDL_GetWindowFromID_handle )( Uint32 id );
    static auto SDL_GetWindowFromID = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetWindowFromID" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetWindowFromID" );
        }
        return ( SDL_GetWindowFromID_handle )( dlsym_ptr );
    } ();
}

SDL_Window * SDL_GetWindowFromID ( Uint32 id );

namespace sym{
    typedef Uint32 ( *SDL_GetWindowFlags_handle )( SDL_Window * window );
    static auto SDL_GetWindowFlags = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetWindowFlags" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetWindowFlags" );
        }
        return ( SDL_GetWindowFlags_handle )( dlsym_ptr );
    } ();
}

Uint32 SDL_GetWindowFlags ( SDL_Window * window );

namespace sym{
    typedef void ( *SDL_SetWindowTitle_handle )( SDL_Window * window, const char * title );
    static auto SDL_SetWindowTitle = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_SetWindowTitle" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_SetWindowTitle" );
        }
        return ( SDL_SetWindowTitle_handle )( dlsym_ptr );
    } ();
}

void SDL_SetWindowTitle ( SDL_Window * window, const char * title );

namespace sym{
    typedef const char * ( *SDL_GetWindowTitle_handle )( SDL_Window * window );
    static auto SDL_GetWindowTitle = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetWindowTitle" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetWindowTitle" );
        }
        return ( SDL_GetWindowTitle_handle )( dlsym_ptr );
    } ();
}

const char * SDL_GetWindowTitle ( SDL_Window * window );

namespace sym{
    typedef void ( *SDL_SetWindowIcon_handle )( SDL_Window * window, SDL_Surface * icon );
    static auto SDL_SetWindowIcon = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_SetWindowIcon" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_SetWindowIcon" );
        }
        return ( SDL_SetWindowIcon_handle )( dlsym_ptr );
    } ();
}

void SDL_SetWindowIcon ( SDL_Window * window, SDL_Surface * icon );

namespace sym{
    typedef void * ( *SDL_SetWindowData_handle )( SDL_Window * window, const char * name, void * userdata );
    static auto SDL_SetWindowData = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_SetWindowData" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_SetWindowData" );
        }
        return ( SDL_SetWindowData_handle )( dlsym_ptr );
    } ();
}

void * SDL_SetWindowData ( SDL_Window * window, const char * name, void * userdata );

namespace sym{
    typedef void * ( *SDL_GetWindowData_handle )( SDL_Window * window, const char * name );
    static auto SDL_GetWindowData = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetWindowData" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetWindowData" );
        }
        return ( SDL_GetWindowData_handle )( dlsym_ptr );
    } ();
}

void * SDL_GetWindowData ( SDL_Window * window, const char * name );

namespace sym{
    typedef void ( *SDL_SetWindowPosition_handle )( SDL_Window * window, int x, int y );
    static auto SDL_SetWindowPosition = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_SetWindowPosition" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_SetWindowPosition" );
        }
        return ( SDL_SetWindowPosition_handle )( dlsym_ptr );
    } ();
}

void SDL_SetWindowPosition ( SDL_Window * window, int x, int y );

namespace sym{
    typedef void ( *SDL_GetWindowPosition_handle )( SDL_Window * window, int * x, int * y );
    static auto SDL_GetWindowPosition = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetWindowPosition" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetWindowPosition" );
        }
        return ( SDL_GetWindowPosition_handle )( dlsym_ptr );
    } ();
}

void SDL_GetWindowPosition ( SDL_Window * window, int * x, int * y );

namespace sym{
    typedef void ( *SDL_SetWindowSize_handle )( SDL_Window * window, int w, int h );
    static auto SDL_SetWindowSize = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_SetWindowSize" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_SetWindowSize" );
        }
        return ( SDL_SetWindowSize_handle )( dlsym_ptr );
    } ();
}

void SDL_SetWindowSize ( SDL_Window * window, int w, int h );

namespace sym{
    typedef void ( *SDL_GetWindowSize_handle )( SDL_Window * window, int * w, int * h );
    static auto SDL_GetWindowSize = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetWindowSize" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetWindowSize" );
        }
        return ( SDL_GetWindowSize_handle )( dlsym_ptr );
    } ();
}

void SDL_GetWindowSize ( SDL_Window * window, int * w, int * h );

namespace sym{
    typedef int ( *SDL_GetWindowBordersSize_handle )( SDL_Window * window, int * top, int * left, int * bottom, int * right );
    static auto SDL_GetWindowBordersSize = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetWindowBordersSize" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetWindowBordersSize" );
        }
        return ( SDL_GetWindowBordersSize_handle )( dlsym_ptr );
    } ();
}

int SDL_GetWindowBordersSize ( SDL_Window * window, int * top, int * left, int * bottom, int * right );

namespace sym{
    typedef void ( *SDL_SetWindowMinimumSize_handle )( SDL_Window * window, int min_w, int min_h );
    static auto SDL_SetWindowMinimumSize = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_SetWindowMinimumSize" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_SetWindowMinimumSize" );
        }
        return ( SDL_SetWindowMinimumSize_handle )( dlsym_ptr );
    } ();
}

void SDL_SetWindowMinimumSize ( SDL_Window * window, int min_w, int min_h );

namespace sym{
    typedef void ( *SDL_GetWindowMinimumSize_handle )( SDL_Window * window, int * w, int * h );
    static auto SDL_GetWindowMinimumSize = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetWindowMinimumSize" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetWindowMinimumSize" );
        }
        return ( SDL_GetWindowMinimumSize_handle )( dlsym_ptr );
    } ();
}

void SDL_GetWindowMinimumSize ( SDL_Window * window, int * w, int * h );

namespace sym{
    typedef void ( *SDL_SetWindowMaximumSize_handle )( SDL_Window * window, int max_w, int max_h );
    static auto SDL_SetWindowMaximumSize = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_SetWindowMaximumSize" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_SetWindowMaximumSize" );
        }
        return ( SDL_SetWindowMaximumSize_handle )( dlsym_ptr );
    } ();
}

void SDL_SetWindowMaximumSize ( SDL_Window * window, int max_w, int max_h );

namespace sym{
    typedef void ( *SDL_GetWindowMaximumSize_handle )( SDL_Window * window, int * w, int * h );
    static auto SDL_GetWindowMaximumSize = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetWindowMaximumSize" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetWindowMaximumSize" );
        }
        return ( SDL_GetWindowMaximumSize_handle )( dlsym_ptr );
    } ();
}

void SDL_GetWindowMaximumSize ( SDL_Window * window, int * w, int * h );

namespace sym{
    typedef void ( *SDL_SetWindowBordered_handle )( SDL_Window * window, SDL_bool bordered );
    static auto SDL_SetWindowBordered = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_SetWindowBordered" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_SetWindowBordered" );
        }
        return ( SDL_SetWindowBordered_handle )( dlsym_ptr );
    } ();
}

void SDL_SetWindowBordered ( SDL_Window * window, SDL_bool bordered );

namespace sym{
    typedef void ( *SDL_SetWindowResizable_handle )( SDL_Window * window, SDL_bool resizable );
    static auto SDL_SetWindowResizable = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_SetWindowResizable" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_SetWindowResizable" );
        }
        return ( SDL_SetWindowResizable_handle )( dlsym_ptr );
    } ();
}

void SDL_SetWindowResizable ( SDL_Window * window, SDL_bool resizable );

namespace sym{
    typedef void ( *SDL_ShowWindow_handle )( SDL_Window * window );
    static auto SDL_ShowWindow = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_ShowWindow" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_ShowWindow" );
        }
        return ( SDL_ShowWindow_handle )( dlsym_ptr );
    } ();
}

void SDL_ShowWindow ( SDL_Window * window );

namespace sym{
    typedef void ( *SDL_HideWindow_handle )( SDL_Window * window );
    static auto SDL_HideWindow = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_HideWindow" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_HideWindow" );
        }
        return ( SDL_HideWindow_handle )( dlsym_ptr );
    } ();
}

void SDL_HideWindow ( SDL_Window * window );

namespace sym{
    typedef void ( *SDL_RaiseWindow_handle )( SDL_Window * window );
    static auto SDL_RaiseWindow = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_RaiseWindow" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_RaiseWindow" );
        }
        return ( SDL_RaiseWindow_handle )( dlsym_ptr );
    } ();
}

void SDL_RaiseWindow ( SDL_Window * window );

namespace sym{
    typedef void ( *SDL_MaximizeWindow_handle )( SDL_Window * window );
    static auto SDL_MaximizeWindow = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_MaximizeWindow" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_MaximizeWindow" );
        }
        return ( SDL_MaximizeWindow_handle )( dlsym_ptr );
    } ();
}

void SDL_MaximizeWindow ( SDL_Window * window );

namespace sym{
    typedef void ( *SDL_MinimizeWindow_handle )( SDL_Window * window );
    static auto SDL_MinimizeWindow = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_MinimizeWindow" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_MinimizeWindow" );
        }
        return ( SDL_MinimizeWindow_handle )( dlsym_ptr );
    } ();
}

void SDL_MinimizeWindow ( SDL_Window * window );

namespace sym{
    typedef void ( *SDL_RestoreWindow_handle )( SDL_Window * window );
    static auto SDL_RestoreWindow = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_RestoreWindow" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_RestoreWindow" );
        }
        return ( SDL_RestoreWindow_handle )( dlsym_ptr );
    } ();
}

void SDL_RestoreWindow ( SDL_Window * window );

namespace sym{
    typedef int ( *SDL_SetWindowFullscreen_handle )( SDL_Window * window, Uint32 flags );
    static auto SDL_SetWindowFullscreen = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_SetWindowFullscreen" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_SetWindowFullscreen" );
        }
        return ( SDL_SetWindowFullscreen_handle )( dlsym_ptr );
    } ();
}

int SDL_SetWindowFullscreen ( SDL_Window * window, Uint32 flags );

namespace sym{
    typedef SDL_Surface * ( *SDL_GetWindowSurface_handle )( SDL_Window * window );
    static auto SDL_GetWindowSurface = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetWindowSurface" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetWindowSurface" );
        }
        return ( SDL_GetWindowSurface_handle )( dlsym_ptr );
    } ();
}

SDL_Surface * SDL_GetWindowSurface ( SDL_Window * window );

namespace sym{
    typedef int ( *SDL_UpdateWindowSurface_handle )( SDL_Window * window );
    static auto SDL_UpdateWindowSurface = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_UpdateWindowSurface" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_UpdateWindowSurface" );
        }
        return ( SDL_UpdateWindowSurface_handle )( dlsym_ptr );
    } ();
}

int SDL_UpdateWindowSurface ( SDL_Window * window );

namespace sym{
    typedef int ( *SDL_UpdateWindowSurfaceRects_handle )( SDL_Window * window, const SDL_Rect * rects, int numrects );
    static auto SDL_UpdateWindowSurfaceRects = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_UpdateWindowSurfaceRects" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_UpdateWindowSurfaceRects" );
        }
        return ( SDL_UpdateWindowSurfaceRects_handle )( dlsym_ptr );
    } ();
}

int SDL_UpdateWindowSurfaceRects ( SDL_Window * window, const SDL_Rect * rects, int numrects );

namespace sym{
    typedef void ( *SDL_SetWindowGrab_handle )( SDL_Window * window, SDL_bool grabbed );
    static auto SDL_SetWindowGrab = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_SetWindowGrab" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_SetWindowGrab" );
        }
        return ( SDL_SetWindowGrab_handle )( dlsym_ptr );
    } ();
}

void SDL_SetWindowGrab ( SDL_Window * window, SDL_bool grabbed );

namespace sym{
    typedef SDL_bool ( *SDL_GetWindowGrab_handle )( SDL_Window * window );
    static auto SDL_GetWindowGrab = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetWindowGrab" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetWindowGrab" );
        }
        return ( SDL_GetWindowGrab_handle )( dlsym_ptr );
    } ();
}

SDL_bool SDL_GetWindowGrab ( SDL_Window * window );

namespace sym{
    typedef SDL_Window * ( *SDL_GetGrabbedWindow_handle )(  );
    static auto SDL_GetGrabbedWindow = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetGrabbedWindow" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetGrabbedWindow" );
        }
        return ( SDL_GetGrabbedWindow_handle )( dlsym_ptr );
    } ();
}

SDL_Window * SDL_GetGrabbedWindow (  );

namespace sym{
    typedef int ( *SDL_SetWindowBrightness_handle )( SDL_Window * window, float brightness );
    static auto SDL_SetWindowBrightness = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_SetWindowBrightness" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_SetWindowBrightness" );
        }
        return ( SDL_SetWindowBrightness_handle )( dlsym_ptr );
    } ();
}

int SDL_SetWindowBrightness ( SDL_Window * window, float brightness );

namespace sym{
    typedef float ( *SDL_GetWindowBrightness_handle )( SDL_Window * window );
    static auto SDL_GetWindowBrightness = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetWindowBrightness" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetWindowBrightness" );
        }
        return ( SDL_GetWindowBrightness_handle )( dlsym_ptr );
    } ();
}

float SDL_GetWindowBrightness ( SDL_Window * window );

namespace sym{
    typedef int ( *SDL_SetWindowOpacity_handle )( SDL_Window * window, float opacity );
    static auto SDL_SetWindowOpacity = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_SetWindowOpacity" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_SetWindowOpacity" );
        }
        return ( SDL_SetWindowOpacity_handle )( dlsym_ptr );
    } ();
}

int SDL_SetWindowOpacity ( SDL_Window * window, float opacity );

namespace sym{
    typedef int ( *SDL_GetWindowOpacity_handle )( SDL_Window * window, float * out_opacity );
    static auto SDL_GetWindowOpacity = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetWindowOpacity" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetWindowOpacity" );
        }
        return ( SDL_GetWindowOpacity_handle )( dlsym_ptr );
    } ();
}

int SDL_GetWindowOpacity ( SDL_Window * window, float * out_opacity );

namespace sym{
    typedef int ( *SDL_SetWindowModalFor_handle )( SDL_Window * modal_window, SDL_Window * parent_window );
    static auto SDL_SetWindowModalFor = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_SetWindowModalFor" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_SetWindowModalFor" );
        }
        return ( SDL_SetWindowModalFor_handle )( dlsym_ptr );
    } ();
}

int SDL_SetWindowModalFor ( SDL_Window * modal_window, SDL_Window * parent_window );

namespace sym{
    typedef int ( *SDL_SetWindowInputFocus_handle )( SDL_Window * window );
    static auto SDL_SetWindowInputFocus = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_SetWindowInputFocus" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_SetWindowInputFocus" );
        }
        return ( SDL_SetWindowInputFocus_handle )( dlsym_ptr );
    } ();
}

int SDL_SetWindowInputFocus ( SDL_Window * window );

namespace sym{
    typedef int ( *SDL_SetWindowGammaRamp_handle )( SDL_Window * window, const Uint16 * red, const Uint16 * green, const Uint16 * blue );
    static auto SDL_SetWindowGammaRamp = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_SetWindowGammaRamp" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_SetWindowGammaRamp" );
        }
        return ( SDL_SetWindowGammaRamp_handle )( dlsym_ptr );
    } ();
}

int SDL_SetWindowGammaRamp ( SDL_Window * window, const Uint16 * red, const Uint16 * green, const Uint16 * blue );

namespace sym{
    typedef int ( *SDL_GetWindowGammaRamp_handle )( SDL_Window * window, Uint16 * red, Uint16 * green, Uint16 * blue );
    static auto SDL_GetWindowGammaRamp = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetWindowGammaRamp" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetWindowGammaRamp" );
        }
        return ( SDL_GetWindowGammaRamp_handle )( dlsym_ptr );
    } ();
}

int SDL_GetWindowGammaRamp ( SDL_Window * window, Uint16 * red, Uint16 * green, Uint16 * blue );

namespace sym{
    typedef int ( *SDL_SetWindowHitTest_handle )( SDL_Window * window, SDL_HitTest callback, void * callback_data );
    static auto SDL_SetWindowHitTest = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_SetWindowHitTest" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_SetWindowHitTest" );
        }
        return ( SDL_SetWindowHitTest_handle )( dlsym_ptr );
    } ();
}

int SDL_SetWindowHitTest ( SDL_Window * window, SDL_HitTest callback, void * callback_data );

namespace sym{
    typedef void ( *SDL_DestroyWindow_handle )( SDL_Window * window );
    static auto SDL_DestroyWindow = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_DestroyWindow" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_DestroyWindow" );
        }
        return ( SDL_DestroyWindow_handle )( dlsym_ptr );
    } ();
}

void SDL_DestroyWindow ( SDL_Window * window );

namespace sym{
    typedef SDL_bool ( *SDL_IsScreenSaverEnabled_handle )(  );
    static auto SDL_IsScreenSaverEnabled = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_IsScreenSaverEnabled" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_IsScreenSaverEnabled" );
        }
        return ( SDL_IsScreenSaverEnabled_handle )( dlsym_ptr );
    } ();
}

SDL_bool SDL_IsScreenSaverEnabled (  );

namespace sym{
    typedef void ( *SDL_EnableScreenSaver_handle )(  );
    static auto SDL_EnableScreenSaver = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_EnableScreenSaver" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_EnableScreenSaver" );
        }
        return ( SDL_EnableScreenSaver_handle )( dlsym_ptr );
    } ();
}

void SDL_EnableScreenSaver (  );

namespace sym{
    typedef void ( *SDL_DisableScreenSaver_handle )(  );
    static auto SDL_DisableScreenSaver = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_DisableScreenSaver" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_DisableScreenSaver" );
        }
        return ( SDL_DisableScreenSaver_handle )( dlsym_ptr );
    } ();
}

void SDL_DisableScreenSaver (  );

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
    typedef void ( *SDL_GL_UnloadLibrary_handle )(  );
    static auto SDL_GL_UnloadLibrary = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GL_UnloadLibrary" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GL_UnloadLibrary" );
        }
        return ( SDL_GL_UnloadLibrary_handle )( dlsym_ptr );
    } ();
}

void SDL_GL_UnloadLibrary (  );

namespace sym{
    typedef SDL_bool ( *SDL_GL_ExtensionSupported_handle )( const char * extension );
    static auto SDL_GL_ExtensionSupported = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GL_ExtensionSupported" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GL_ExtensionSupported" );
        }
        return ( SDL_GL_ExtensionSupported_handle )( dlsym_ptr );
    } ();
}

SDL_bool SDL_GL_ExtensionSupported ( const char * extension );

namespace sym{
    typedef void ( *SDL_GL_ResetAttributes_handle )(  );
    static auto SDL_GL_ResetAttributes = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GL_ResetAttributes" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GL_ResetAttributes" );
        }
        return ( SDL_GL_ResetAttributes_handle )( dlsym_ptr );
    } ();
}

void SDL_GL_ResetAttributes (  );

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
    typedef SDL_GLContext ( *SDL_GL_CreateContext_handle )( SDL_Window * window );
    static auto SDL_GL_CreateContext = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GL_CreateContext" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GL_CreateContext" );
        }
        return ( SDL_GL_CreateContext_handle )( dlsym_ptr );
    } ();
}

SDL_GLContext SDL_GL_CreateContext ( SDL_Window * window );

namespace sym{
    typedef int ( *SDL_GL_MakeCurrent_handle )( SDL_Window * window, SDL_GLContext context );
    static auto SDL_GL_MakeCurrent = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GL_MakeCurrent" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GL_MakeCurrent" );
        }
        return ( SDL_GL_MakeCurrent_handle )( dlsym_ptr );
    } ();
}

int SDL_GL_MakeCurrent ( SDL_Window * window, SDL_GLContext context );

namespace sym{
    typedef SDL_Window * ( *SDL_GL_GetCurrentWindow_handle )(  );
    static auto SDL_GL_GetCurrentWindow = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GL_GetCurrentWindow" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GL_GetCurrentWindow" );
        }
        return ( SDL_GL_GetCurrentWindow_handle )( dlsym_ptr );
    } ();
}

SDL_Window * SDL_GL_GetCurrentWindow (  );

namespace sym{
    typedef SDL_GLContext ( *SDL_GL_GetCurrentContext_handle )(  );
    static auto SDL_GL_GetCurrentContext = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GL_GetCurrentContext" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GL_GetCurrentContext" );
        }
        return ( SDL_GL_GetCurrentContext_handle )( dlsym_ptr );
    } ();
}

SDL_GLContext SDL_GL_GetCurrentContext (  );

namespace sym{
    typedef void ( *SDL_GL_GetDrawableSize_handle )( SDL_Window * window, int * w, int * h );
    static auto SDL_GL_GetDrawableSize = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GL_GetDrawableSize" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GL_GetDrawableSize" );
        }
        return ( SDL_GL_GetDrawableSize_handle )( dlsym_ptr );
    } ();
}

void SDL_GL_GetDrawableSize ( SDL_Window * window, int * w, int * h );

namespace sym{
    typedef int ( *SDL_GL_SetSwapInterval_handle )( int interval );
    static auto SDL_GL_SetSwapInterval = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GL_SetSwapInterval" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GL_SetSwapInterval" );
        }
        return ( SDL_GL_SetSwapInterval_handle )( dlsym_ptr );
    } ();
}

int SDL_GL_SetSwapInterval ( int interval );

namespace sym{
    typedef int ( *SDL_GL_GetSwapInterval_handle )(  );
    static auto SDL_GL_GetSwapInterval = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GL_GetSwapInterval" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GL_GetSwapInterval" );
        }
        return ( SDL_GL_GetSwapInterval_handle )( dlsym_ptr );
    } ();
}

int SDL_GL_GetSwapInterval (  );

namespace sym{
    typedef void ( *SDL_GL_SwapWindow_handle )( SDL_Window * window );
    static auto SDL_GL_SwapWindow = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GL_SwapWindow" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GL_SwapWindow" );
        }
        return ( SDL_GL_SwapWindow_handle )( dlsym_ptr );
    } ();
}

void SDL_GL_SwapWindow ( SDL_Window * window );

namespace sym{
    typedef void ( *SDL_GL_DeleteContext_handle )( SDL_GLContext context );
    static auto SDL_GL_DeleteContext = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GL_DeleteContext" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GL_DeleteContext" );
        }
        return ( SDL_GL_DeleteContext_handle )( dlsym_ptr );
    } ();
}

void SDL_GL_DeleteContext ( SDL_GLContext context );

namespace sym{
    typedef SDL_Window * ( *SDL_GetKeyboardFocus_handle )(  );
    static auto SDL_GetKeyboardFocus = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetKeyboardFocus" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetKeyboardFocus" );
        }
        return ( SDL_GetKeyboardFocus_handle )( dlsym_ptr );
    } ();
}

SDL_Window * SDL_GetKeyboardFocus (  );

namespace sym{
    typedef const Uint8 * ( *SDL_GetKeyboardState_handle )( int * numkeys );
    static auto SDL_GetKeyboardState = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetKeyboardState" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetKeyboardState" );
        }
        return ( SDL_GetKeyboardState_handle )( dlsym_ptr );
    } ();
}

const Uint8 * SDL_GetKeyboardState ( int * numkeys );

namespace sym{
    typedef SDL_Keymod ( *SDL_GetModState_handle )(  );
    static auto SDL_GetModState = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetModState" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetModState" );
        }
        return ( SDL_GetModState_handle )( dlsym_ptr );
    } ();
}

SDL_Keymod SDL_GetModState (  );

namespace sym{
    typedef void ( *SDL_SetModState_handle )( SDL_Keymod modstate );
    static auto SDL_SetModState = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_SetModState" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_SetModState" );
        }
        return ( SDL_SetModState_handle )( dlsym_ptr );
    } ();
}

void SDL_SetModState ( SDL_Keymod modstate );

namespace sym{
    typedef SDL_Keycode ( *SDL_GetKeyFromScancode_handle )( SDL_Scancode scancode );
    static auto SDL_GetKeyFromScancode = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetKeyFromScancode" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetKeyFromScancode" );
        }
        return ( SDL_GetKeyFromScancode_handle )( dlsym_ptr );
    } ();
}

SDL_Keycode SDL_GetKeyFromScancode ( SDL_Scancode scancode );

namespace sym{
    typedef SDL_Scancode ( *SDL_GetScancodeFromKey_handle )( SDL_Keycode key );
    static auto SDL_GetScancodeFromKey = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetScancodeFromKey" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetScancodeFromKey" );
        }
        return ( SDL_GetScancodeFromKey_handle )( dlsym_ptr );
    } ();
}

SDL_Scancode SDL_GetScancodeFromKey ( SDL_Keycode key );

namespace sym{
    typedef const char * ( *SDL_GetScancodeName_handle )( SDL_Scancode scancode );
    static auto SDL_GetScancodeName = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetScancodeName" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetScancodeName" );
        }
        return ( SDL_GetScancodeName_handle )( dlsym_ptr );
    } ();
}

const char * SDL_GetScancodeName ( SDL_Scancode scancode );

namespace sym{
    typedef SDL_Scancode ( *SDL_GetScancodeFromName_handle )( const char * name );
    static auto SDL_GetScancodeFromName = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetScancodeFromName" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetScancodeFromName" );
        }
        return ( SDL_GetScancodeFromName_handle )( dlsym_ptr );
    } ();
}

SDL_Scancode SDL_GetScancodeFromName ( const char * name );

namespace sym{
    typedef const char * ( *SDL_GetKeyName_handle )( SDL_Keycode key );
    static auto SDL_GetKeyName = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetKeyName" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetKeyName" );
        }
        return ( SDL_GetKeyName_handle )( dlsym_ptr );
    } ();
}

const char * SDL_GetKeyName ( SDL_Keycode key );

namespace sym{
    typedef SDL_Keycode ( *SDL_GetKeyFromName_handle )( const char * name );
    static auto SDL_GetKeyFromName = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetKeyFromName" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetKeyFromName" );
        }
        return ( SDL_GetKeyFromName_handle )( dlsym_ptr );
    } ();
}

SDL_Keycode SDL_GetKeyFromName ( const char * name );

namespace sym{
    typedef void ( *SDL_StartTextInput_handle )(  );
    static auto SDL_StartTextInput = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_StartTextInput" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_StartTextInput" );
        }
        return ( SDL_StartTextInput_handle )( dlsym_ptr );
    } ();
}

void SDL_StartTextInput (  );

namespace sym{
    typedef SDL_bool ( *SDL_IsTextInputActive_handle )(  );
    static auto SDL_IsTextInputActive = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_IsTextInputActive" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_IsTextInputActive" );
        }
        return ( SDL_IsTextInputActive_handle )( dlsym_ptr );
    } ();
}

SDL_bool SDL_IsTextInputActive (  );

namespace sym{
    typedef void ( *SDL_StopTextInput_handle )(  );
    static auto SDL_StopTextInput = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_StopTextInput" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_StopTextInput" );
        }
        return ( SDL_StopTextInput_handle )( dlsym_ptr );
    } ();
}

void SDL_StopTextInput (  );

namespace sym{
    typedef void ( *SDL_SetTextInputRect_handle )( SDL_Rect * rect );
    static auto SDL_SetTextInputRect = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_SetTextInputRect" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_SetTextInputRect" );
        }
        return ( SDL_SetTextInputRect_handle )( dlsym_ptr );
    } ();
}

void SDL_SetTextInputRect ( SDL_Rect * rect );

namespace sym{
    typedef SDL_bool ( *SDL_HasScreenKeyboardSupport_handle )(  );
    static auto SDL_HasScreenKeyboardSupport = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_HasScreenKeyboardSupport" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_HasScreenKeyboardSupport" );
        }
        return ( SDL_HasScreenKeyboardSupport_handle )( dlsym_ptr );
    } ();
}

SDL_bool SDL_HasScreenKeyboardSupport (  );

namespace sym{
    typedef SDL_bool ( *SDL_IsScreenKeyboardShown_handle )( SDL_Window * window );
    static auto SDL_IsScreenKeyboardShown = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_IsScreenKeyboardShown" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_IsScreenKeyboardShown" );
        }
        return ( SDL_IsScreenKeyboardShown_handle )( dlsym_ptr );
    } ();
}

SDL_bool SDL_IsScreenKeyboardShown ( SDL_Window * window );

namespace sym{
    typedef SDL_Window * ( *SDL_GetMouseFocus_handle )(  );
    static auto SDL_GetMouseFocus = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetMouseFocus" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetMouseFocus" );
        }
        return ( SDL_GetMouseFocus_handle )( dlsym_ptr );
    } ();
}

SDL_Window * SDL_GetMouseFocus (  );

namespace sym{
    typedef Uint32 ( *SDL_GetMouseState_handle )( int * x, int * y );
    static auto SDL_GetMouseState = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetMouseState" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetMouseState" );
        }
        return ( SDL_GetMouseState_handle )( dlsym_ptr );
    } ();
}

Uint32 SDL_GetMouseState ( int * x, int * y );

namespace sym{
    typedef Uint32 ( *SDL_GetGlobalMouseState_handle )( int * x, int * y );
    static auto SDL_GetGlobalMouseState = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetGlobalMouseState" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetGlobalMouseState" );
        }
        return ( SDL_GetGlobalMouseState_handle )( dlsym_ptr );
    } ();
}

Uint32 SDL_GetGlobalMouseState ( int * x, int * y );

namespace sym{
    typedef Uint32 ( *SDL_GetRelativeMouseState_handle )( int * x, int * y );
    static auto SDL_GetRelativeMouseState = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetRelativeMouseState" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetRelativeMouseState" );
        }
        return ( SDL_GetRelativeMouseState_handle )( dlsym_ptr );
    } ();
}

Uint32 SDL_GetRelativeMouseState ( int * x, int * y );

namespace sym{
    typedef void ( *SDL_WarpMouseInWindow_handle )( SDL_Window * window, int x, int y );
    static auto SDL_WarpMouseInWindow = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_WarpMouseInWindow" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_WarpMouseInWindow" );
        }
        return ( SDL_WarpMouseInWindow_handle )( dlsym_ptr );
    } ();
}

void SDL_WarpMouseInWindow ( SDL_Window * window, int x, int y );

namespace sym{
    typedef int ( *SDL_WarpMouseGlobal_handle )( int x, int y );
    static auto SDL_WarpMouseGlobal = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_WarpMouseGlobal" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_WarpMouseGlobal" );
        }
        return ( SDL_WarpMouseGlobal_handle )( dlsym_ptr );
    } ();
}

int SDL_WarpMouseGlobal ( int x, int y );

namespace sym{
    typedef int ( *SDL_SetRelativeMouseMode_handle )( SDL_bool enabled );
    static auto SDL_SetRelativeMouseMode = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_SetRelativeMouseMode" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_SetRelativeMouseMode" );
        }
        return ( SDL_SetRelativeMouseMode_handle )( dlsym_ptr );
    } ();
}

int SDL_SetRelativeMouseMode ( SDL_bool enabled );

namespace sym{
    typedef int ( *SDL_CaptureMouse_handle )( SDL_bool enabled );
    static auto SDL_CaptureMouse = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_CaptureMouse" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_CaptureMouse" );
        }
        return ( SDL_CaptureMouse_handle )( dlsym_ptr );
    } ();
}

int SDL_CaptureMouse ( SDL_bool enabled );

namespace sym{
    typedef SDL_bool ( *SDL_GetRelativeMouseMode_handle )(  );
    static auto SDL_GetRelativeMouseMode = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetRelativeMouseMode" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetRelativeMouseMode" );
        }
        return ( SDL_GetRelativeMouseMode_handle )( dlsym_ptr );
    } ();
}

SDL_bool SDL_GetRelativeMouseMode (  );

namespace sym{
    typedef SDL_Cursor * ( *SDL_CreateCursor_handle )( const Uint8 * data, const Uint8 * mask, int w, int h, int hot_x, int hot_y );
    static auto SDL_CreateCursor = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_CreateCursor" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_CreateCursor" );
        }
        return ( SDL_CreateCursor_handle )( dlsym_ptr );
    } ();
}

SDL_Cursor * SDL_CreateCursor ( const Uint8 * data, const Uint8 * mask, int w, int h, int hot_x, int hot_y );

namespace sym{
    typedef SDL_Cursor * ( *SDL_CreateColorCursor_handle )( SDL_Surface * surface, int hot_x, int hot_y );
    static auto SDL_CreateColorCursor = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_CreateColorCursor" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_CreateColorCursor" );
        }
        return ( SDL_CreateColorCursor_handle )( dlsym_ptr );
    } ();
}

SDL_Cursor * SDL_CreateColorCursor ( SDL_Surface * surface, int hot_x, int hot_y );

namespace sym{
    typedef SDL_Cursor * ( *SDL_CreateSystemCursor_handle )( SDL_SystemCursor id );
    static auto SDL_CreateSystemCursor = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_CreateSystemCursor" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_CreateSystemCursor" );
        }
        return ( SDL_CreateSystemCursor_handle )( dlsym_ptr );
    } ();
}

SDL_Cursor * SDL_CreateSystemCursor ( SDL_SystemCursor id );

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
    typedef SDL_Cursor * ( *SDL_GetDefaultCursor_handle )(  );
    static auto SDL_GetDefaultCursor = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetDefaultCursor" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetDefaultCursor" );
        }
        return ( SDL_GetDefaultCursor_handle )( dlsym_ptr );
    } ();
}

SDL_Cursor * SDL_GetDefaultCursor (  );

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
    typedef void ( *SDL_LockJoysticks_handle )(  );
    static auto SDL_LockJoysticks = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_LockJoysticks" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_LockJoysticks" );
        }
        return ( SDL_LockJoysticks_handle )( dlsym_ptr );
    } ();
}

void SDL_LockJoysticks (  );

namespace sym{
    typedef void ( *SDL_UnlockJoysticks_handle )(  );
    static auto SDL_UnlockJoysticks = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_UnlockJoysticks" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_UnlockJoysticks" );
        }
        return ( SDL_UnlockJoysticks_handle )( dlsym_ptr );
    } ();
}

void SDL_UnlockJoysticks (  );

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
    typedef const char * ( *SDL_JoystickNameForIndex_handle )( int device_index );
    static auto SDL_JoystickNameForIndex = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_JoystickNameForIndex" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_JoystickNameForIndex" );
        }
        return ( SDL_JoystickNameForIndex_handle )( dlsym_ptr );
    } ();
}

const char * SDL_JoystickNameForIndex ( int device_index );

namespace sym{
    typedef SDL_JoystickGUID ( *SDL_JoystickGetDeviceGUID_handle )( int device_index );
    static auto SDL_JoystickGetDeviceGUID = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_JoystickGetDeviceGUID" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_JoystickGetDeviceGUID" );
        }
        return ( SDL_JoystickGetDeviceGUID_handle )( dlsym_ptr );
    } ();
}

SDL_JoystickGUID SDL_JoystickGetDeviceGUID ( int device_index );

namespace sym{
    typedef Uint16 ( *SDL_JoystickGetDeviceVendor_handle )( int device_index );
    static auto SDL_JoystickGetDeviceVendor = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_JoystickGetDeviceVendor" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_JoystickGetDeviceVendor" );
        }
        return ( SDL_JoystickGetDeviceVendor_handle )( dlsym_ptr );
    } ();
}

Uint16 SDL_JoystickGetDeviceVendor ( int device_index );

namespace sym{
    typedef Uint16 ( *SDL_JoystickGetDeviceProduct_handle )( int device_index );
    static auto SDL_JoystickGetDeviceProduct = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_JoystickGetDeviceProduct" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_JoystickGetDeviceProduct" );
        }
        return ( SDL_JoystickGetDeviceProduct_handle )( dlsym_ptr );
    } ();
}

Uint16 SDL_JoystickGetDeviceProduct ( int device_index );

namespace sym{
    typedef Uint16 ( *SDL_JoystickGetDeviceProductVersion_handle )( int device_index );
    static auto SDL_JoystickGetDeviceProductVersion = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_JoystickGetDeviceProductVersion" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_JoystickGetDeviceProductVersion" );
        }
        return ( SDL_JoystickGetDeviceProductVersion_handle )( dlsym_ptr );
    } ();
}

Uint16 SDL_JoystickGetDeviceProductVersion ( int device_index );

namespace sym{
    typedef SDL_JoystickType ( *SDL_JoystickGetDeviceType_handle )( int device_index );
    static auto SDL_JoystickGetDeviceType = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_JoystickGetDeviceType" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_JoystickGetDeviceType" );
        }
        return ( SDL_JoystickGetDeviceType_handle )( dlsym_ptr );
    } ();
}

SDL_JoystickType SDL_JoystickGetDeviceType ( int device_index );

namespace sym{
    typedef SDL_JoystickID ( *SDL_JoystickGetDeviceInstanceID_handle )( int device_index );
    static auto SDL_JoystickGetDeviceInstanceID = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_JoystickGetDeviceInstanceID" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_JoystickGetDeviceInstanceID" );
        }
        return ( SDL_JoystickGetDeviceInstanceID_handle )( dlsym_ptr );
    } ();
}

SDL_JoystickID SDL_JoystickGetDeviceInstanceID ( int device_index );

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
    typedef SDL_Joystick * ( *SDL_JoystickFromInstanceID_handle )( SDL_JoystickID joyid );
    static auto SDL_JoystickFromInstanceID = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_JoystickFromInstanceID" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_JoystickFromInstanceID" );
        }
        return ( SDL_JoystickFromInstanceID_handle )( dlsym_ptr );
    } ();
}

SDL_Joystick * SDL_JoystickFromInstanceID ( SDL_JoystickID joyid );

namespace sym{
    typedef const char * ( *SDL_JoystickName_handle )( SDL_Joystick * joystick );
    static auto SDL_JoystickName = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_JoystickName" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_JoystickName" );
        }
        return ( SDL_JoystickName_handle )( dlsym_ptr );
    } ();
}

const char * SDL_JoystickName ( SDL_Joystick * joystick );

namespace sym{
    typedef SDL_JoystickGUID ( *SDL_JoystickGetGUID_handle )( SDL_Joystick * joystick );
    static auto SDL_JoystickGetGUID = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_JoystickGetGUID" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_JoystickGetGUID" );
        }
        return ( SDL_JoystickGetGUID_handle )( dlsym_ptr );
    } ();
}

SDL_JoystickGUID SDL_JoystickGetGUID ( SDL_Joystick * joystick );

namespace sym{
    typedef Uint16 ( *SDL_JoystickGetVendor_handle )( SDL_Joystick * joystick );
    static auto SDL_JoystickGetVendor = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_JoystickGetVendor" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_JoystickGetVendor" );
        }
        return ( SDL_JoystickGetVendor_handle )( dlsym_ptr );
    } ();
}

Uint16 SDL_JoystickGetVendor ( SDL_Joystick * joystick );

namespace sym{
    typedef Uint16 ( *SDL_JoystickGetProduct_handle )( SDL_Joystick * joystick );
    static auto SDL_JoystickGetProduct = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_JoystickGetProduct" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_JoystickGetProduct" );
        }
        return ( SDL_JoystickGetProduct_handle )( dlsym_ptr );
    } ();
}

Uint16 SDL_JoystickGetProduct ( SDL_Joystick * joystick );

namespace sym{
    typedef Uint16 ( *SDL_JoystickGetProductVersion_handle )( SDL_Joystick * joystick );
    static auto SDL_JoystickGetProductVersion = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_JoystickGetProductVersion" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_JoystickGetProductVersion" );
        }
        return ( SDL_JoystickGetProductVersion_handle )( dlsym_ptr );
    } ();
}

Uint16 SDL_JoystickGetProductVersion ( SDL_Joystick * joystick );

namespace sym{
    typedef SDL_JoystickType ( *SDL_JoystickGetType_handle )( SDL_Joystick * joystick );
    static auto SDL_JoystickGetType = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_JoystickGetType" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_JoystickGetType" );
        }
        return ( SDL_JoystickGetType_handle )( dlsym_ptr );
    } ();
}

SDL_JoystickType SDL_JoystickGetType ( SDL_Joystick * joystick );

namespace sym{
    typedef void ( *SDL_JoystickGetGUIDString_handle )( SDL_JoystickGUID guid, char * pszGUID, int cbGUID );
    static auto SDL_JoystickGetGUIDString = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_JoystickGetGUIDString" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_JoystickGetGUIDString" );
        }
        return ( SDL_JoystickGetGUIDString_handle )( dlsym_ptr );
    } ();
}

void SDL_JoystickGetGUIDString ( SDL_JoystickGUID guid, char * pszGUID, int cbGUID );

namespace sym{
    typedef SDL_JoystickGUID ( *SDL_JoystickGetGUIDFromString_handle )( const char * pchGUID );
    static auto SDL_JoystickGetGUIDFromString = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_JoystickGetGUIDFromString" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_JoystickGetGUIDFromString" );
        }
        return ( SDL_JoystickGetGUIDFromString_handle )( dlsym_ptr );
    } ();
}

SDL_JoystickGUID SDL_JoystickGetGUIDFromString ( const char * pchGUID );

namespace sym{
    typedef SDL_bool ( *SDL_JoystickGetAttached_handle )( SDL_Joystick * joystick );
    static auto SDL_JoystickGetAttached = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_JoystickGetAttached" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_JoystickGetAttached" );
        }
        return ( SDL_JoystickGetAttached_handle )( dlsym_ptr );
    } ();
}

SDL_bool SDL_JoystickGetAttached ( SDL_Joystick * joystick );

namespace sym{
    typedef SDL_JoystickID ( *SDL_JoystickInstanceID_handle )( SDL_Joystick * joystick );
    static auto SDL_JoystickInstanceID = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_JoystickInstanceID" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_JoystickInstanceID" );
        }
        return ( SDL_JoystickInstanceID_handle )( dlsym_ptr );
    } ();
}

SDL_JoystickID SDL_JoystickInstanceID ( SDL_Joystick * joystick );

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
    typedef SDL_bool ( *SDL_JoystickGetAxisInitialState_handle )( SDL_Joystick * joystick, int axis, Sint16 * state );
    static auto SDL_JoystickGetAxisInitialState = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_JoystickGetAxisInitialState" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_JoystickGetAxisInitialState" );
        }
        return ( SDL_JoystickGetAxisInitialState_handle )( dlsym_ptr );
    } ();
}

SDL_bool SDL_JoystickGetAxisInitialState ( SDL_Joystick * joystick, int axis, Sint16 * state );

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
    typedef SDL_JoystickPowerLevel ( *SDL_JoystickCurrentPowerLevel_handle )( SDL_Joystick * joystick );
    static auto SDL_JoystickCurrentPowerLevel = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_JoystickCurrentPowerLevel" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_JoystickCurrentPowerLevel" );
        }
        return ( SDL_JoystickCurrentPowerLevel_handle )( dlsym_ptr );
    } ();
}

SDL_JoystickPowerLevel SDL_JoystickCurrentPowerLevel ( SDL_Joystick * joystick );

namespace sym{
    typedef int ( *SDL_GameControllerAddMappingsFromRW_handle )( SDL_RWops * rw, int freerw );
    static auto SDL_GameControllerAddMappingsFromRW = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GameControllerAddMappingsFromRW" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GameControllerAddMappingsFromRW" );
        }
        return ( SDL_GameControllerAddMappingsFromRW_handle )( dlsym_ptr );
    } ();
}

int SDL_GameControllerAddMappingsFromRW ( SDL_RWops * rw, int freerw );

namespace sym{
    typedef int ( *SDL_GameControllerAddMapping_handle )( const char * mappingString );
    static auto SDL_GameControllerAddMapping = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GameControllerAddMapping" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GameControllerAddMapping" );
        }
        return ( SDL_GameControllerAddMapping_handle )( dlsym_ptr );
    } ();
}

int SDL_GameControllerAddMapping ( const char * mappingString );

namespace sym{
    typedef int ( *SDL_GameControllerNumMappings_handle )(  );
    static auto SDL_GameControllerNumMappings = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GameControllerNumMappings" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GameControllerNumMappings" );
        }
        return ( SDL_GameControllerNumMappings_handle )( dlsym_ptr );
    } ();
}

int SDL_GameControllerNumMappings (  );

namespace sym{
    typedef char * ( *SDL_GameControllerMappingForIndex_handle )( int mapping_index );
    static auto SDL_GameControllerMappingForIndex = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GameControllerMappingForIndex" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GameControllerMappingForIndex" );
        }
        return ( SDL_GameControllerMappingForIndex_handle )( dlsym_ptr );
    } ();
}

char * SDL_GameControllerMappingForIndex ( int mapping_index );

namespace sym{
    typedef char * ( *SDL_GameControllerMappingForGUID_handle )( SDL_JoystickGUID guid );
    static auto SDL_GameControllerMappingForGUID = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GameControllerMappingForGUID" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GameControllerMappingForGUID" );
        }
        return ( SDL_GameControllerMappingForGUID_handle )( dlsym_ptr );
    } ();
}

char * SDL_GameControllerMappingForGUID ( SDL_JoystickGUID guid );

namespace sym{
    typedef char * ( *SDL_GameControllerMapping_handle )( SDL_GameController * gamecontroller );
    static auto SDL_GameControllerMapping = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GameControllerMapping" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GameControllerMapping" );
        }
        return ( SDL_GameControllerMapping_handle )( dlsym_ptr );
    } ();
}

char * SDL_GameControllerMapping ( SDL_GameController * gamecontroller );

namespace sym{
    typedef SDL_bool ( *SDL_IsGameController_handle )( int joystick_index );
    static auto SDL_IsGameController = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_IsGameController" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_IsGameController" );
        }
        return ( SDL_IsGameController_handle )( dlsym_ptr );
    } ();
}

SDL_bool SDL_IsGameController ( int joystick_index );

namespace sym{
    typedef const char * ( *SDL_GameControllerNameForIndex_handle )( int joystick_index );
    static auto SDL_GameControllerNameForIndex = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GameControllerNameForIndex" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GameControllerNameForIndex" );
        }
        return ( SDL_GameControllerNameForIndex_handle )( dlsym_ptr );
    } ();
}

const char * SDL_GameControllerNameForIndex ( int joystick_index );

namespace sym{
    typedef SDL_GameController * ( *SDL_GameControllerOpen_handle )( int joystick_index );
    static auto SDL_GameControllerOpen = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GameControllerOpen" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GameControllerOpen" );
        }
        return ( SDL_GameControllerOpen_handle )( dlsym_ptr );
    } ();
}

SDL_GameController * SDL_GameControllerOpen ( int joystick_index );

namespace sym{
    typedef SDL_GameController * ( *SDL_GameControllerFromInstanceID_handle )( SDL_JoystickID joyid );
    static auto SDL_GameControllerFromInstanceID = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GameControllerFromInstanceID" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GameControllerFromInstanceID" );
        }
        return ( SDL_GameControllerFromInstanceID_handle )( dlsym_ptr );
    } ();
}

SDL_GameController * SDL_GameControllerFromInstanceID ( SDL_JoystickID joyid );

namespace sym{
    typedef const char * ( *SDL_GameControllerName_handle )( SDL_GameController * gamecontroller );
    static auto SDL_GameControllerName = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GameControllerName" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GameControllerName" );
        }
        return ( SDL_GameControllerName_handle )( dlsym_ptr );
    } ();
}

const char * SDL_GameControllerName ( SDL_GameController * gamecontroller );

namespace sym{
    typedef Uint16 ( *SDL_GameControllerGetVendor_handle )( SDL_GameController * gamecontroller );
    static auto SDL_GameControllerGetVendor = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GameControllerGetVendor" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GameControllerGetVendor" );
        }
        return ( SDL_GameControllerGetVendor_handle )( dlsym_ptr );
    } ();
}

Uint16 SDL_GameControllerGetVendor ( SDL_GameController * gamecontroller );

namespace sym{
    typedef Uint16 ( *SDL_GameControllerGetProduct_handle )( SDL_GameController * gamecontroller );
    static auto SDL_GameControllerGetProduct = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GameControllerGetProduct" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GameControllerGetProduct" );
        }
        return ( SDL_GameControllerGetProduct_handle )( dlsym_ptr );
    } ();
}

Uint16 SDL_GameControllerGetProduct ( SDL_GameController * gamecontroller );

namespace sym{
    typedef Uint16 ( *SDL_GameControllerGetProductVersion_handle )( SDL_GameController * gamecontroller );
    static auto SDL_GameControllerGetProductVersion = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GameControllerGetProductVersion" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GameControllerGetProductVersion" );
        }
        return ( SDL_GameControllerGetProductVersion_handle )( dlsym_ptr );
    } ();
}

Uint16 SDL_GameControllerGetProductVersion ( SDL_GameController * gamecontroller );

namespace sym{
    typedef SDL_bool ( *SDL_GameControllerGetAttached_handle )( SDL_GameController * gamecontroller );
    static auto SDL_GameControllerGetAttached = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GameControllerGetAttached" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GameControllerGetAttached" );
        }
        return ( SDL_GameControllerGetAttached_handle )( dlsym_ptr );
    } ();
}

SDL_bool SDL_GameControllerGetAttached ( SDL_GameController * gamecontroller );

namespace sym{
    typedef SDL_Joystick * ( *SDL_GameControllerGetJoystick_handle )( SDL_GameController * gamecontroller );
    static auto SDL_GameControllerGetJoystick = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GameControllerGetJoystick" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GameControllerGetJoystick" );
        }
        return ( SDL_GameControllerGetJoystick_handle )( dlsym_ptr );
    } ();
}

SDL_Joystick * SDL_GameControllerGetJoystick ( SDL_GameController * gamecontroller );

namespace sym{
    typedef int ( *SDL_GameControllerEventState_handle )( int state );
    static auto SDL_GameControllerEventState = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GameControllerEventState" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GameControllerEventState" );
        }
        return ( SDL_GameControllerEventState_handle )( dlsym_ptr );
    } ();
}

int SDL_GameControllerEventState ( int state );

namespace sym{
    typedef void ( *SDL_GameControllerUpdate_handle )(  );
    static auto SDL_GameControllerUpdate = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GameControllerUpdate" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GameControllerUpdate" );
        }
        return ( SDL_GameControllerUpdate_handle )( dlsym_ptr );
    } ();
}

void SDL_GameControllerUpdate (  );

namespace sym{
    typedef SDL_GameControllerAxis ( *SDL_GameControllerGetAxisFromString_handle )( const char * pchString );
    static auto SDL_GameControllerGetAxisFromString = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GameControllerGetAxisFromString" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GameControllerGetAxisFromString" );
        }
        return ( SDL_GameControllerGetAxisFromString_handle )( dlsym_ptr );
    } ();
}

SDL_GameControllerAxis SDL_GameControllerGetAxisFromString ( const char * pchString );

namespace sym{
    typedef const char * ( *SDL_GameControllerGetStringForAxis_handle )( SDL_GameControllerAxis axis );
    static auto SDL_GameControllerGetStringForAxis = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GameControllerGetStringForAxis" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GameControllerGetStringForAxis" );
        }
        return ( SDL_GameControllerGetStringForAxis_handle )( dlsym_ptr );
    } ();
}

const char * SDL_GameControllerGetStringForAxis ( SDL_GameControllerAxis axis );

namespace sym{
    typedef SDL_GameControllerButtonBind ( *SDL_GameControllerGetBindForAxis_handle )( SDL_GameController * gamecontroller, SDL_GameControllerAxis axis );
    static auto SDL_GameControllerGetBindForAxis = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GameControllerGetBindForAxis" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GameControllerGetBindForAxis" );
        }
        return ( SDL_GameControllerGetBindForAxis_handle )( dlsym_ptr );
    } ();
}

SDL_GameControllerButtonBind SDL_GameControllerGetBindForAxis ( SDL_GameController * gamecontroller, SDL_GameControllerAxis axis );

namespace sym{
    typedef Sint16 ( *SDL_GameControllerGetAxis_handle )( SDL_GameController * gamecontroller, SDL_GameControllerAxis axis );
    static auto SDL_GameControllerGetAxis = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GameControllerGetAxis" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GameControllerGetAxis" );
        }
        return ( SDL_GameControllerGetAxis_handle )( dlsym_ptr );
    } ();
}

Sint16 SDL_GameControllerGetAxis ( SDL_GameController * gamecontroller, SDL_GameControllerAxis axis );

namespace sym{
    typedef SDL_GameControllerButton ( *SDL_GameControllerGetButtonFromString_handle )( const char * pchString );
    static auto SDL_GameControllerGetButtonFromString = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GameControllerGetButtonFromString" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GameControllerGetButtonFromString" );
        }
        return ( SDL_GameControllerGetButtonFromString_handle )( dlsym_ptr );
    } ();
}

SDL_GameControllerButton SDL_GameControllerGetButtonFromString ( const char * pchString );

namespace sym{
    typedef const char * ( *SDL_GameControllerGetStringForButton_handle )( SDL_GameControllerButton button );
    static auto SDL_GameControllerGetStringForButton = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GameControllerGetStringForButton" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GameControllerGetStringForButton" );
        }
        return ( SDL_GameControllerGetStringForButton_handle )( dlsym_ptr );
    } ();
}

const char * SDL_GameControllerGetStringForButton ( SDL_GameControllerButton button );

namespace sym{
    typedef SDL_GameControllerButtonBind ( *SDL_GameControllerGetBindForButton_handle )( SDL_GameController * gamecontroller, SDL_GameControllerButton button );
    static auto SDL_GameControllerGetBindForButton = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GameControllerGetBindForButton" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GameControllerGetBindForButton" );
        }
        return ( SDL_GameControllerGetBindForButton_handle )( dlsym_ptr );
    } ();
}

SDL_GameControllerButtonBind SDL_GameControllerGetBindForButton ( SDL_GameController * gamecontroller, SDL_GameControllerButton button );

namespace sym{
    typedef Uint8 ( *SDL_GameControllerGetButton_handle )( SDL_GameController * gamecontroller, SDL_GameControllerButton button );
    static auto SDL_GameControllerGetButton = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GameControllerGetButton" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GameControllerGetButton" );
        }
        return ( SDL_GameControllerGetButton_handle )( dlsym_ptr );
    } ();
}

Uint8 SDL_GameControllerGetButton ( SDL_GameController * gamecontroller, SDL_GameControllerButton button );

namespace sym{
    typedef void ( *SDL_GameControllerClose_handle )( SDL_GameController * gamecontroller );
    static auto SDL_GameControllerClose = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GameControllerClose" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GameControllerClose" );
        }
        return ( SDL_GameControllerClose_handle )( dlsym_ptr );
    } ();
}

void SDL_GameControllerClose ( SDL_GameController * gamecontroller );

namespace sym{
    typedef int ( *SDL_GetNumTouchDevices_handle )(  );
    static auto SDL_GetNumTouchDevices = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetNumTouchDevices" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetNumTouchDevices" );
        }
        return ( SDL_GetNumTouchDevices_handle )( dlsym_ptr );
    } ();
}

int SDL_GetNumTouchDevices (  );

namespace sym{
    typedef SDL_TouchID ( *SDL_GetTouchDevice_handle )( int index );
    static auto SDL_GetTouchDevice = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetTouchDevice" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetTouchDevice" );
        }
        return ( SDL_GetTouchDevice_handle )( dlsym_ptr );
    } ();
}

SDL_TouchID SDL_GetTouchDevice ( int index );

namespace sym{
    typedef int ( *SDL_GetNumTouchFingers_handle )( SDL_TouchID touchID );
    static auto SDL_GetNumTouchFingers = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetNumTouchFingers" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetNumTouchFingers" );
        }
        return ( SDL_GetNumTouchFingers_handle )( dlsym_ptr );
    } ();
}

int SDL_GetNumTouchFingers ( SDL_TouchID touchID );

namespace sym{
    typedef SDL_Finger * ( *SDL_GetTouchFinger_handle )( SDL_TouchID touchID, int index );
    static auto SDL_GetTouchFinger = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetTouchFinger" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetTouchFinger" );
        }
        return ( SDL_GetTouchFinger_handle )( dlsym_ptr );
    } ();
}

SDL_Finger * SDL_GetTouchFinger ( SDL_TouchID touchID, int index );

namespace sym{
    typedef int ( *SDL_RecordGesture_handle )( SDL_TouchID touchId );
    static auto SDL_RecordGesture = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_RecordGesture" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_RecordGesture" );
        }
        return ( SDL_RecordGesture_handle )( dlsym_ptr );
    } ();
}

int SDL_RecordGesture ( SDL_TouchID touchId );

namespace sym{
    typedef int ( *SDL_SaveAllDollarTemplates_handle )( SDL_RWops * dst );
    static auto SDL_SaveAllDollarTemplates = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_SaveAllDollarTemplates" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_SaveAllDollarTemplates" );
        }
        return ( SDL_SaveAllDollarTemplates_handle )( dlsym_ptr );
    } ();
}

int SDL_SaveAllDollarTemplates ( SDL_RWops * dst );

namespace sym{
    typedef int ( *SDL_SaveDollarTemplate_handle )( SDL_GestureID gestureId, SDL_RWops * dst );
    static auto SDL_SaveDollarTemplate = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_SaveDollarTemplate" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_SaveDollarTemplate" );
        }
        return ( SDL_SaveDollarTemplate_handle )( dlsym_ptr );
    } ();
}

int SDL_SaveDollarTemplate ( SDL_GestureID gestureId, SDL_RWops * dst );

namespace sym{
    typedef int ( *SDL_LoadDollarTemplates_handle )( SDL_TouchID touchId, SDL_RWops * src );
    static auto SDL_LoadDollarTemplates = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_LoadDollarTemplates" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_LoadDollarTemplates" );
        }
        return ( SDL_LoadDollarTemplates_handle )( dlsym_ptr );
    } ();
}

int SDL_LoadDollarTemplates ( SDL_TouchID touchId, SDL_RWops * src );

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
    typedef int ( *SDL_PeepEvents_handle )( SDL_Event * events, int numevents, SDL_eventaction action, Uint32 minType, Uint32 maxType );
    static auto SDL_PeepEvents = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_PeepEvents" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_PeepEvents" );
        }
        return ( SDL_PeepEvents_handle )( dlsym_ptr );
    } ();
}

int SDL_PeepEvents ( SDL_Event * events, int numevents, SDL_eventaction action, Uint32 minType, Uint32 maxType );

namespace sym{
    typedef SDL_bool ( *SDL_HasEvent_handle )( Uint32 type );
    static auto SDL_HasEvent = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_HasEvent" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_HasEvent" );
        }
        return ( SDL_HasEvent_handle )( dlsym_ptr );
    } ();
}

SDL_bool SDL_HasEvent ( Uint32 type );

namespace sym{
    typedef SDL_bool ( *SDL_HasEvents_handle )( Uint32 minType, Uint32 maxType );
    static auto SDL_HasEvents = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_HasEvents" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_HasEvents" );
        }
        return ( SDL_HasEvents_handle )( dlsym_ptr );
    } ();
}

SDL_bool SDL_HasEvents ( Uint32 minType, Uint32 maxType );

namespace sym{
    typedef void ( *SDL_FlushEvent_handle )( Uint32 type );
    static auto SDL_FlushEvent = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_FlushEvent" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_FlushEvent" );
        }
        return ( SDL_FlushEvent_handle )( dlsym_ptr );
    } ();
}

void SDL_FlushEvent ( Uint32 type );

namespace sym{
    typedef void ( *SDL_FlushEvents_handle )( Uint32 minType, Uint32 maxType );
    static auto SDL_FlushEvents = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_FlushEvents" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_FlushEvents" );
        }
        return ( SDL_FlushEvents_handle )( dlsym_ptr );
    } ();
}

void SDL_FlushEvents ( Uint32 minType, Uint32 maxType );

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
    typedef int ( *SDL_WaitEventTimeout_handle )( SDL_Event * event, int timeout );
    static auto SDL_WaitEventTimeout = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_WaitEventTimeout" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_WaitEventTimeout" );
        }
        return ( SDL_WaitEventTimeout_handle )( dlsym_ptr );
    } ();
}

int SDL_WaitEventTimeout ( SDL_Event * event, int timeout );

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
    typedef void ( *SDL_SetEventFilter_handle )( SDL_EventFilter filter, void * userdata );
    static auto SDL_SetEventFilter = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_SetEventFilter" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_SetEventFilter" );
        }
        return ( SDL_SetEventFilter_handle )( dlsym_ptr );
    } ();
}

void SDL_SetEventFilter ( SDL_EventFilter filter, void * userdata );

namespace sym{
    typedef SDL_bool ( *SDL_GetEventFilter_handle )( SDL_EventFilter * filter, void ** userdata );
    static auto SDL_GetEventFilter = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetEventFilter" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetEventFilter" );
        }
        return ( SDL_GetEventFilter_handle )( dlsym_ptr );
    } ();
}

SDL_bool SDL_GetEventFilter ( SDL_EventFilter * filter, void ** userdata );

namespace sym{
    typedef void ( *SDL_AddEventWatch_handle )( SDL_EventFilter filter, void * userdata );
    static auto SDL_AddEventWatch = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_AddEventWatch" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_AddEventWatch" );
        }
        return ( SDL_AddEventWatch_handle )( dlsym_ptr );
    } ();
}

void SDL_AddEventWatch ( SDL_EventFilter filter, void * userdata );

namespace sym{
    typedef void ( *SDL_DelEventWatch_handle )( SDL_EventFilter filter, void * userdata );
    static auto SDL_DelEventWatch = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_DelEventWatch" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_DelEventWatch" );
        }
        return ( SDL_DelEventWatch_handle )( dlsym_ptr );
    } ();
}

void SDL_DelEventWatch ( SDL_EventFilter filter, void * userdata );

namespace sym{
    typedef void ( *SDL_FilterEvents_handle )( SDL_EventFilter filter, void * userdata );
    static auto SDL_FilterEvents = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_FilterEvents" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_FilterEvents" );
        }
        return ( SDL_FilterEvents_handle )( dlsym_ptr );
    } ();
}

void SDL_FilterEvents ( SDL_EventFilter filter, void * userdata );

namespace sym{
    typedef Uint8 ( *SDL_EventState_handle )( Uint32 type, int state );
    static auto SDL_EventState = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_EventState" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_EventState" );
        }
        return ( SDL_EventState_handle )( dlsym_ptr );
    } ();
}

Uint8 SDL_EventState ( Uint32 type, int state );

namespace sym{
    typedef Uint32 ( *SDL_RegisterEvents_handle )( int numevents );
    static auto SDL_RegisterEvents = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_RegisterEvents" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_RegisterEvents" );
        }
        return ( SDL_RegisterEvents_handle )( dlsym_ptr );
    } ();
}

Uint32 SDL_RegisterEvents ( int numevents );

namespace sym{
    typedef char * ( *SDL_GetBasePath_handle )(  );
    static auto SDL_GetBasePath = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetBasePath" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetBasePath" );
        }
        return ( SDL_GetBasePath_handle )( dlsym_ptr );
    } ();
}

char * SDL_GetBasePath (  );

namespace sym{
    typedef char * ( *SDL_GetPrefPath_handle )( const char * org, const char * app );
    static auto SDL_GetPrefPath = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetPrefPath" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetPrefPath" );
        }
        return ( SDL_GetPrefPath_handle )( dlsym_ptr );
    } ();
}

char * SDL_GetPrefPath ( const char * org, const char * app );

namespace sym{
    typedef int ( *SDL_NumHaptics_handle )(  );
    static auto SDL_NumHaptics = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_NumHaptics" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_NumHaptics" );
        }
        return ( SDL_NumHaptics_handle )( dlsym_ptr );
    } ();
}

int SDL_NumHaptics (  );

namespace sym{
    typedef const char * ( *SDL_HapticName_handle )( int device_index );
    static auto SDL_HapticName = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_HapticName" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_HapticName" );
        }
        return ( SDL_HapticName_handle )( dlsym_ptr );
    } ();
}

const char * SDL_HapticName ( int device_index );

namespace sym{
    typedef SDL_Haptic * ( *SDL_HapticOpen_handle )( int device_index );
    static auto SDL_HapticOpen = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_HapticOpen" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_HapticOpen" );
        }
        return ( SDL_HapticOpen_handle )( dlsym_ptr );
    } ();
}

SDL_Haptic * SDL_HapticOpen ( int device_index );

namespace sym{
    typedef int ( *SDL_HapticOpened_handle )( int device_index );
    static auto SDL_HapticOpened = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_HapticOpened" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_HapticOpened" );
        }
        return ( SDL_HapticOpened_handle )( dlsym_ptr );
    } ();
}

int SDL_HapticOpened ( int device_index );

namespace sym{
    typedef int ( *SDL_HapticIndex_handle )( SDL_Haptic * haptic );
    static auto SDL_HapticIndex = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_HapticIndex" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_HapticIndex" );
        }
        return ( SDL_HapticIndex_handle )( dlsym_ptr );
    } ();
}

int SDL_HapticIndex ( SDL_Haptic * haptic );

namespace sym{
    typedef int ( *SDL_MouseIsHaptic_handle )(  );
    static auto SDL_MouseIsHaptic = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_MouseIsHaptic" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_MouseIsHaptic" );
        }
        return ( SDL_MouseIsHaptic_handle )( dlsym_ptr );
    } ();
}

int SDL_MouseIsHaptic (  );

namespace sym{
    typedef SDL_Haptic * ( *SDL_HapticOpenFromMouse_handle )(  );
    static auto SDL_HapticOpenFromMouse = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_HapticOpenFromMouse" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_HapticOpenFromMouse" );
        }
        return ( SDL_HapticOpenFromMouse_handle )( dlsym_ptr );
    } ();
}

SDL_Haptic * SDL_HapticOpenFromMouse (  );

namespace sym{
    typedef int ( *SDL_JoystickIsHaptic_handle )( SDL_Joystick * joystick );
    static auto SDL_JoystickIsHaptic = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_JoystickIsHaptic" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_JoystickIsHaptic" );
        }
        return ( SDL_JoystickIsHaptic_handle )( dlsym_ptr );
    } ();
}

int SDL_JoystickIsHaptic ( SDL_Joystick * joystick );

namespace sym{
    typedef SDL_Haptic * ( *SDL_HapticOpenFromJoystick_handle )( SDL_Joystick * joystick );
    static auto SDL_HapticOpenFromJoystick = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_HapticOpenFromJoystick" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_HapticOpenFromJoystick" );
        }
        return ( SDL_HapticOpenFromJoystick_handle )( dlsym_ptr );
    } ();
}

SDL_Haptic * SDL_HapticOpenFromJoystick ( SDL_Joystick * joystick );

namespace sym{
    typedef void ( *SDL_HapticClose_handle )( SDL_Haptic * haptic );
    static auto SDL_HapticClose = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_HapticClose" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_HapticClose" );
        }
        return ( SDL_HapticClose_handle )( dlsym_ptr );
    } ();
}

void SDL_HapticClose ( SDL_Haptic * haptic );

namespace sym{
    typedef int ( *SDL_HapticNumEffects_handle )( SDL_Haptic * haptic );
    static auto SDL_HapticNumEffects = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_HapticNumEffects" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_HapticNumEffects" );
        }
        return ( SDL_HapticNumEffects_handle )( dlsym_ptr );
    } ();
}

int SDL_HapticNumEffects ( SDL_Haptic * haptic );

namespace sym{
    typedef int ( *SDL_HapticNumEffectsPlaying_handle )( SDL_Haptic * haptic );
    static auto SDL_HapticNumEffectsPlaying = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_HapticNumEffectsPlaying" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_HapticNumEffectsPlaying" );
        }
        return ( SDL_HapticNumEffectsPlaying_handle )( dlsym_ptr );
    } ();
}

int SDL_HapticNumEffectsPlaying ( SDL_Haptic * haptic );

namespace sym{
    typedef unsigned int ( *SDL_HapticQuery_handle )( SDL_Haptic * haptic );
    static auto SDL_HapticQuery = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_HapticQuery" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_HapticQuery" );
        }
        return ( SDL_HapticQuery_handle )( dlsym_ptr );
    } ();
}

unsigned int SDL_HapticQuery ( SDL_Haptic * haptic );

namespace sym{
    typedef int ( *SDL_HapticNumAxes_handle )( SDL_Haptic * haptic );
    static auto SDL_HapticNumAxes = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_HapticNumAxes" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_HapticNumAxes" );
        }
        return ( SDL_HapticNumAxes_handle )( dlsym_ptr );
    } ();
}

int SDL_HapticNumAxes ( SDL_Haptic * haptic );

namespace sym{
    typedef int ( *SDL_HapticEffectSupported_handle )( SDL_Haptic * haptic, SDL_HapticEffect * effect );
    static auto SDL_HapticEffectSupported = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_HapticEffectSupported" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_HapticEffectSupported" );
        }
        return ( SDL_HapticEffectSupported_handle )( dlsym_ptr );
    } ();
}

int SDL_HapticEffectSupported ( SDL_Haptic * haptic, SDL_HapticEffect * effect );

namespace sym{
    typedef int ( *SDL_HapticNewEffect_handle )( SDL_Haptic * haptic, SDL_HapticEffect * effect );
    static auto SDL_HapticNewEffect = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_HapticNewEffect" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_HapticNewEffect" );
        }
        return ( SDL_HapticNewEffect_handle )( dlsym_ptr );
    } ();
}

int SDL_HapticNewEffect ( SDL_Haptic * haptic, SDL_HapticEffect * effect );

namespace sym{
    typedef int ( *SDL_HapticUpdateEffect_handle )( SDL_Haptic * haptic, int effect, SDL_HapticEffect * data );
    static auto SDL_HapticUpdateEffect = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_HapticUpdateEffect" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_HapticUpdateEffect" );
        }
        return ( SDL_HapticUpdateEffect_handle )( dlsym_ptr );
    } ();
}

int SDL_HapticUpdateEffect ( SDL_Haptic * haptic, int effect, SDL_HapticEffect * data );

namespace sym{
    typedef int ( *SDL_HapticRunEffect_handle )( SDL_Haptic * haptic, int effect, Uint32 iterations );
    static auto SDL_HapticRunEffect = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_HapticRunEffect" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_HapticRunEffect" );
        }
        return ( SDL_HapticRunEffect_handle )( dlsym_ptr );
    } ();
}

int SDL_HapticRunEffect ( SDL_Haptic * haptic, int effect, Uint32 iterations );

namespace sym{
    typedef int ( *SDL_HapticStopEffect_handle )( SDL_Haptic * haptic, int effect );
    static auto SDL_HapticStopEffect = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_HapticStopEffect" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_HapticStopEffect" );
        }
        return ( SDL_HapticStopEffect_handle )( dlsym_ptr );
    } ();
}

int SDL_HapticStopEffect ( SDL_Haptic * haptic, int effect );

namespace sym{
    typedef void ( *SDL_HapticDestroyEffect_handle )( SDL_Haptic * haptic, int effect );
    static auto SDL_HapticDestroyEffect = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_HapticDestroyEffect" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_HapticDestroyEffect" );
        }
        return ( SDL_HapticDestroyEffect_handle )( dlsym_ptr );
    } ();
}

void SDL_HapticDestroyEffect ( SDL_Haptic * haptic, int effect );

namespace sym{
    typedef int ( *SDL_HapticGetEffectStatus_handle )( SDL_Haptic * haptic, int effect );
    static auto SDL_HapticGetEffectStatus = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_HapticGetEffectStatus" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_HapticGetEffectStatus" );
        }
        return ( SDL_HapticGetEffectStatus_handle )( dlsym_ptr );
    } ();
}

int SDL_HapticGetEffectStatus ( SDL_Haptic * haptic, int effect );

namespace sym{
    typedef int ( *SDL_HapticSetGain_handle )( SDL_Haptic * haptic, int gain );
    static auto SDL_HapticSetGain = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_HapticSetGain" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_HapticSetGain" );
        }
        return ( SDL_HapticSetGain_handle )( dlsym_ptr );
    } ();
}

int SDL_HapticSetGain ( SDL_Haptic * haptic, int gain );

namespace sym{
    typedef int ( *SDL_HapticSetAutocenter_handle )( SDL_Haptic * haptic, int autocenter );
    static auto SDL_HapticSetAutocenter = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_HapticSetAutocenter" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_HapticSetAutocenter" );
        }
        return ( SDL_HapticSetAutocenter_handle )( dlsym_ptr );
    } ();
}

int SDL_HapticSetAutocenter ( SDL_Haptic * haptic, int autocenter );

namespace sym{
    typedef int ( *SDL_HapticPause_handle )( SDL_Haptic * haptic );
    static auto SDL_HapticPause = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_HapticPause" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_HapticPause" );
        }
        return ( SDL_HapticPause_handle )( dlsym_ptr );
    } ();
}

int SDL_HapticPause ( SDL_Haptic * haptic );

namespace sym{
    typedef int ( *SDL_HapticUnpause_handle )( SDL_Haptic * haptic );
    static auto SDL_HapticUnpause = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_HapticUnpause" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_HapticUnpause" );
        }
        return ( SDL_HapticUnpause_handle )( dlsym_ptr );
    } ();
}

int SDL_HapticUnpause ( SDL_Haptic * haptic );

namespace sym{
    typedef int ( *SDL_HapticStopAll_handle )( SDL_Haptic * haptic );
    static auto SDL_HapticStopAll = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_HapticStopAll" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_HapticStopAll" );
        }
        return ( SDL_HapticStopAll_handle )( dlsym_ptr );
    } ();
}

int SDL_HapticStopAll ( SDL_Haptic * haptic );

namespace sym{
    typedef int ( *SDL_HapticRumbleSupported_handle )( SDL_Haptic * haptic );
    static auto SDL_HapticRumbleSupported = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_HapticRumbleSupported" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_HapticRumbleSupported" );
        }
        return ( SDL_HapticRumbleSupported_handle )( dlsym_ptr );
    } ();
}

int SDL_HapticRumbleSupported ( SDL_Haptic * haptic );

namespace sym{
    typedef int ( *SDL_HapticRumbleInit_handle )( SDL_Haptic * haptic );
    static auto SDL_HapticRumbleInit = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_HapticRumbleInit" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_HapticRumbleInit" );
        }
        return ( SDL_HapticRumbleInit_handle )( dlsym_ptr );
    } ();
}

int SDL_HapticRumbleInit ( SDL_Haptic * haptic );

namespace sym{
    typedef int ( *SDL_HapticRumblePlay_handle )( SDL_Haptic * haptic, float strength, Uint32 length );
    static auto SDL_HapticRumblePlay = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_HapticRumblePlay" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_HapticRumblePlay" );
        }
        return ( SDL_HapticRumblePlay_handle )( dlsym_ptr );
    } ();
}

int SDL_HapticRumblePlay ( SDL_Haptic * haptic, float strength, Uint32 length );

namespace sym{
    typedef int ( *SDL_HapticRumbleStop_handle )( SDL_Haptic * haptic );
    static auto SDL_HapticRumbleStop = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_HapticRumbleStop" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_HapticRumbleStop" );
        }
        return ( SDL_HapticRumbleStop_handle )( dlsym_ptr );
    } ();
}

int SDL_HapticRumbleStop ( SDL_Haptic * haptic );

namespace sym{
    typedef SDL_bool ( *SDL_SetHintWithPriority_handle )( const char * name, const char * value, SDL_HintPriority priority );
    static auto SDL_SetHintWithPriority = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_SetHintWithPriority" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_SetHintWithPriority" );
        }
        return ( SDL_SetHintWithPriority_handle )( dlsym_ptr );
    } ();
}

SDL_bool SDL_SetHintWithPriority ( const char * name, const char * value, SDL_HintPriority priority );

namespace sym{
    typedef SDL_bool ( *SDL_SetHint_handle )( const char * name, const char * value );
    static auto SDL_SetHint = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_SetHint" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_SetHint" );
        }
        return ( SDL_SetHint_handle )( dlsym_ptr );
    } ();
}

SDL_bool SDL_SetHint ( const char * name, const char * value );

namespace sym{
    typedef const char * ( *SDL_GetHint_handle )( const char * name );
    static auto SDL_GetHint = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetHint" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetHint" );
        }
        return ( SDL_GetHint_handle )( dlsym_ptr );
    } ();
}

const char * SDL_GetHint ( const char * name );

namespace sym{
    typedef SDL_bool ( *SDL_GetHintBoolean_handle )( const char * name, SDL_bool default_value );
    static auto SDL_GetHintBoolean = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetHintBoolean" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetHintBoolean" );
        }
        return ( SDL_GetHintBoolean_handle )( dlsym_ptr );
    } ();
}

SDL_bool SDL_GetHintBoolean ( const char * name, SDL_bool default_value );

namespace sym{
    typedef void ( *SDL_AddHintCallback_handle )( const char * name, SDL_HintCallback callback, void * userdata );
    static auto SDL_AddHintCallback = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_AddHintCallback" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_AddHintCallback" );
        }
        return ( SDL_AddHintCallback_handle )( dlsym_ptr );
    } ();
}

void SDL_AddHintCallback ( const char * name, SDL_HintCallback callback, void * userdata );

namespace sym{
    typedef void ( *SDL_DelHintCallback_handle )( const char * name, SDL_HintCallback callback, void * userdata );
    static auto SDL_DelHintCallback = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_DelHintCallback" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_DelHintCallback" );
        }
        return ( SDL_DelHintCallback_handle )( dlsym_ptr );
    } ();
}

void SDL_DelHintCallback ( const char * name, SDL_HintCallback callback, void * userdata );

namespace sym{
    typedef void ( *SDL_ClearHints_handle )(  );
    static auto SDL_ClearHints = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_ClearHints" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_ClearHints" );
        }
        return ( SDL_ClearHints_handle )( dlsym_ptr );
    } ();
}

void SDL_ClearHints (  );

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
    typedef void ( *SDL_LogSetAllPriority_handle )( SDL_LogPriority priority );
    static auto SDL_LogSetAllPriority = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_LogSetAllPriority" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_LogSetAllPriority" );
        }
        return ( SDL_LogSetAllPriority_handle )( dlsym_ptr );
    } ();
}

void SDL_LogSetAllPriority ( SDL_LogPriority priority );

namespace sym{
    typedef void ( *SDL_LogSetPriority_handle )( int category, SDL_LogPriority priority );
    static auto SDL_LogSetPriority = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_LogSetPriority" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_LogSetPriority" );
        }
        return ( SDL_LogSetPriority_handle )( dlsym_ptr );
    } ();
}

void SDL_LogSetPriority ( int category, SDL_LogPriority priority );

namespace sym{
    typedef SDL_LogPriority ( *SDL_LogGetPriority_handle )( int category );
    static auto SDL_LogGetPriority = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_LogGetPriority" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_LogGetPriority" );
        }
        return ( SDL_LogGetPriority_handle )( dlsym_ptr );
    } ();
}

SDL_LogPriority SDL_LogGetPriority ( int category );

namespace sym{
    typedef void ( *SDL_LogResetPriorities_handle )(  );
    static auto SDL_LogResetPriorities = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_LogResetPriorities" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_LogResetPriorities" );
        }
        return ( SDL_LogResetPriorities_handle )( dlsym_ptr );
    } ();
}

void SDL_LogResetPriorities (  );

namespace sym{
    typedef void ( *SDL_Log_handle )( const char * fmt );
    static auto SDL_Log = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_Log" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_Log" );
        }
        return ( SDL_Log_handle )( dlsym_ptr );
    } ();
}

void SDL_Log ( const char * fmt );

namespace sym{
    typedef void ( *SDL_LogVerbose_handle )( int category, const char * fmt );
    static auto SDL_LogVerbose = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_LogVerbose" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_LogVerbose" );
        }
        return ( SDL_LogVerbose_handle )( dlsym_ptr );
    } ();
}

void SDL_LogVerbose ( int category, const char * fmt );

namespace sym{
    typedef void ( *SDL_LogDebug_handle )( int category, const char * fmt );
    static auto SDL_LogDebug = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_LogDebug" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_LogDebug" );
        }
        return ( SDL_LogDebug_handle )( dlsym_ptr );
    } ();
}

void SDL_LogDebug ( int category, const char * fmt );

namespace sym{
    typedef void ( *SDL_LogInfo_handle )( int category, const char * fmt );
    static auto SDL_LogInfo = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_LogInfo" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_LogInfo" );
        }
        return ( SDL_LogInfo_handle )( dlsym_ptr );
    } ();
}

void SDL_LogInfo ( int category, const char * fmt );

namespace sym{
    typedef void ( *SDL_LogWarn_handle )( int category, const char * fmt );
    static auto SDL_LogWarn = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_LogWarn" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_LogWarn" );
        }
        return ( SDL_LogWarn_handle )( dlsym_ptr );
    } ();
}

void SDL_LogWarn ( int category, const char * fmt );

namespace sym{
    typedef void ( *SDL_LogError_handle )( int category, const char * fmt );
    static auto SDL_LogError = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_LogError" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_LogError" );
        }
        return ( SDL_LogError_handle )( dlsym_ptr );
    } ();
}

void SDL_LogError ( int category, const char * fmt );

namespace sym{
    typedef void ( *SDL_LogCritical_handle )( int category, const char * fmt );
    static auto SDL_LogCritical = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_LogCritical" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_LogCritical" );
        }
        return ( SDL_LogCritical_handle )( dlsym_ptr );
    } ();
}

void SDL_LogCritical ( int category, const char * fmt );

namespace sym{
    typedef void ( *SDL_LogMessage_handle )( int category, SDL_LogPriority priority, const char * fmt );
    static auto SDL_LogMessage = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_LogMessage" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_LogMessage" );
        }
        return ( SDL_LogMessage_handle )( dlsym_ptr );
    } ();
}

void SDL_LogMessage ( int category, SDL_LogPriority priority, const char * fmt );

namespace sym{
    typedef void ( *SDL_LogMessageV_handle )( int category, SDL_LogPriority priority, const char * fmt, va_list ap );
    static auto SDL_LogMessageV = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_LogMessageV" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_LogMessageV" );
        }
        return ( SDL_LogMessageV_handle )( dlsym_ptr );
    } ();
}

void SDL_LogMessageV ( int category, SDL_LogPriority priority, const char * fmt, va_list ap );

namespace sym{
    typedef void ( *SDL_LogGetOutputFunction_handle )( SDL_LogOutputFunction * callback, void ** userdata );
    static auto SDL_LogGetOutputFunction = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_LogGetOutputFunction" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_LogGetOutputFunction" );
        }
        return ( SDL_LogGetOutputFunction_handle )( dlsym_ptr );
    } ();
}

void SDL_LogGetOutputFunction ( SDL_LogOutputFunction * callback, void ** userdata );

namespace sym{
    typedef void ( *SDL_LogSetOutputFunction_handle )( SDL_LogOutputFunction callback, void * userdata );
    static auto SDL_LogSetOutputFunction = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_LogSetOutputFunction" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_LogSetOutputFunction" );
        }
        return ( SDL_LogSetOutputFunction_handle )( dlsym_ptr );
    } ();
}

void SDL_LogSetOutputFunction ( SDL_LogOutputFunction callback, void * userdata );

namespace sym{
    typedef int ( *SDL_ShowMessageBox_handle )( const SDL_MessageBoxData * messageboxdata, int * buttonid );
    static auto SDL_ShowMessageBox = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_ShowMessageBox" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_ShowMessageBox" );
        }
        return ( SDL_ShowMessageBox_handle )( dlsym_ptr );
    } ();
}

int SDL_ShowMessageBox ( const SDL_MessageBoxData * messageboxdata, int * buttonid );

namespace sym{
    typedef int ( *SDL_ShowSimpleMessageBox_handle )( Uint32 flags, const char * title, const char * message, SDL_Window * window );
    static auto SDL_ShowSimpleMessageBox = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_ShowSimpleMessageBox" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_ShowSimpleMessageBox" );
        }
        return ( SDL_ShowSimpleMessageBox_handle )( dlsym_ptr );
    } ();
}

int SDL_ShowSimpleMessageBox ( Uint32 flags, const char * title, const char * message, SDL_Window * window );

namespace sym{
    typedef SDL_PowerState ( *SDL_GetPowerInfo_handle )( int * secs, int * pct );
    static auto SDL_GetPowerInfo = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetPowerInfo" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetPowerInfo" );
        }
        return ( SDL_GetPowerInfo_handle )( dlsym_ptr );
    } ();
}

SDL_PowerState SDL_GetPowerInfo ( int * secs, int * pct );

namespace sym{
    typedef int ( *SDL_GetNumRenderDrivers_handle )(  );
    static auto SDL_GetNumRenderDrivers = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetNumRenderDrivers" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetNumRenderDrivers" );
        }
        return ( SDL_GetNumRenderDrivers_handle )( dlsym_ptr );
    } ();
}

int SDL_GetNumRenderDrivers (  );

namespace sym{
    typedef int ( *SDL_GetRenderDriverInfo_handle )( int index, SDL_RendererInfo * info );
    static auto SDL_GetRenderDriverInfo = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetRenderDriverInfo" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetRenderDriverInfo" );
        }
        return ( SDL_GetRenderDriverInfo_handle )( dlsym_ptr );
    } ();
}

int SDL_GetRenderDriverInfo ( int index, SDL_RendererInfo * info );

namespace sym{
    typedef int ( *SDL_CreateWindowAndRenderer_handle )( int width, int height, Uint32 window_flags, SDL_Window ** window, SDL_Renderer ** renderer );
    static auto SDL_CreateWindowAndRenderer = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_CreateWindowAndRenderer" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_CreateWindowAndRenderer" );
        }
        return ( SDL_CreateWindowAndRenderer_handle )( dlsym_ptr );
    } ();
}

int SDL_CreateWindowAndRenderer ( int width, int height, Uint32 window_flags, SDL_Window ** window, SDL_Renderer ** renderer );

namespace sym{
    typedef SDL_Renderer * ( *SDL_CreateRenderer_handle )( SDL_Window * window, int index, Uint32 flags );
    static auto SDL_CreateRenderer = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_CreateRenderer" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_CreateRenderer" );
        }
        return ( SDL_CreateRenderer_handle )( dlsym_ptr );
    } ();
}

SDL_Renderer * SDL_CreateRenderer ( SDL_Window * window, int index, Uint32 flags );

namespace sym{
    typedef SDL_Renderer * ( *SDL_CreateSoftwareRenderer_handle )( SDL_Surface * surface );
    static auto SDL_CreateSoftwareRenderer = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_CreateSoftwareRenderer" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_CreateSoftwareRenderer" );
        }
        return ( SDL_CreateSoftwareRenderer_handle )( dlsym_ptr );
    } ();
}

SDL_Renderer * SDL_CreateSoftwareRenderer ( SDL_Surface * surface );

namespace sym{
    typedef SDL_Renderer * ( *SDL_GetRenderer_handle )( SDL_Window * window );
    static auto SDL_GetRenderer = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetRenderer" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetRenderer" );
        }
        return ( SDL_GetRenderer_handle )( dlsym_ptr );
    } ();
}

SDL_Renderer * SDL_GetRenderer ( SDL_Window * window );

namespace sym{
    typedef int ( *SDL_GetRendererInfo_handle )( SDL_Renderer * renderer, SDL_RendererInfo * info );
    static auto SDL_GetRendererInfo = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetRendererInfo" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetRendererInfo" );
        }
        return ( SDL_GetRendererInfo_handle )( dlsym_ptr );
    } ();
}

int SDL_GetRendererInfo ( SDL_Renderer * renderer, SDL_RendererInfo * info );

namespace sym{
    typedef int ( *SDL_GetRendererOutputSize_handle )( SDL_Renderer * renderer, int * w, int * h );
    static auto SDL_GetRendererOutputSize = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetRendererOutputSize" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetRendererOutputSize" );
        }
        return ( SDL_GetRendererOutputSize_handle )( dlsym_ptr );
    } ();
}

int SDL_GetRendererOutputSize ( SDL_Renderer * renderer, int * w, int * h );

namespace sym{
    typedef SDL_Texture * ( *SDL_CreateTexture_handle )( SDL_Renderer * renderer, Uint32 format, int access, int w, int h );
    static auto SDL_CreateTexture = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_CreateTexture" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_CreateTexture" );
        }
        return ( SDL_CreateTexture_handle )( dlsym_ptr );
    } ();
}

SDL_Texture * SDL_CreateTexture ( SDL_Renderer * renderer, Uint32 format, int access, int w, int h );

namespace sym{
    typedef SDL_Texture * ( *SDL_CreateTextureFromSurface_handle )( SDL_Renderer * renderer, SDL_Surface * surface );
    static auto SDL_CreateTextureFromSurface = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_CreateTextureFromSurface" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_CreateTextureFromSurface" );
        }
        return ( SDL_CreateTextureFromSurface_handle )( dlsym_ptr );
    } ();
}

SDL_Texture * SDL_CreateTextureFromSurface ( SDL_Renderer * renderer, SDL_Surface * surface );

namespace sym{
    typedef int ( *SDL_QueryTexture_handle )( SDL_Texture * texture, Uint32 * format, int * access, int * w, int * h );
    static auto SDL_QueryTexture = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_QueryTexture" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_QueryTexture" );
        }
        return ( SDL_QueryTexture_handle )( dlsym_ptr );
    } ();
}

int SDL_QueryTexture ( SDL_Texture * texture, Uint32 * format, int * access, int * w, int * h );

namespace sym{
    typedef int ( *SDL_SetTextureColorMod_handle )( SDL_Texture * texture, Uint8 r, Uint8 g, Uint8 b );
    static auto SDL_SetTextureColorMod = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_SetTextureColorMod" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_SetTextureColorMod" );
        }
        return ( SDL_SetTextureColorMod_handle )( dlsym_ptr );
    } ();
}

int SDL_SetTextureColorMod ( SDL_Texture * texture, Uint8 r, Uint8 g, Uint8 b );

namespace sym{
    typedef int ( *SDL_GetTextureColorMod_handle )( SDL_Texture * texture, Uint8 * r, Uint8 * g, Uint8 * b );
    static auto SDL_GetTextureColorMod = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetTextureColorMod" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetTextureColorMod" );
        }
        return ( SDL_GetTextureColorMod_handle )( dlsym_ptr );
    } ();
}

int SDL_GetTextureColorMod ( SDL_Texture * texture, Uint8 * r, Uint8 * g, Uint8 * b );

namespace sym{
    typedef int ( *SDL_SetTextureAlphaMod_handle )( SDL_Texture * texture, Uint8 alpha );
    static auto SDL_SetTextureAlphaMod = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_SetTextureAlphaMod" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_SetTextureAlphaMod" );
        }
        return ( SDL_SetTextureAlphaMod_handle )( dlsym_ptr );
    } ();
}

int SDL_SetTextureAlphaMod ( SDL_Texture * texture, Uint8 alpha );

namespace sym{
    typedef int ( *SDL_GetTextureAlphaMod_handle )( SDL_Texture * texture, Uint8 * alpha );
    static auto SDL_GetTextureAlphaMod = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetTextureAlphaMod" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetTextureAlphaMod" );
        }
        return ( SDL_GetTextureAlphaMod_handle )( dlsym_ptr );
    } ();
}

int SDL_GetTextureAlphaMod ( SDL_Texture * texture, Uint8 * alpha );

namespace sym{
    typedef int ( *SDL_SetTextureBlendMode_handle )( SDL_Texture * texture, SDL_BlendMode blendMode );
    static auto SDL_SetTextureBlendMode = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_SetTextureBlendMode" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_SetTextureBlendMode" );
        }
        return ( SDL_SetTextureBlendMode_handle )( dlsym_ptr );
    } ();
}

int SDL_SetTextureBlendMode ( SDL_Texture * texture, SDL_BlendMode blendMode );

namespace sym{
    typedef int ( *SDL_GetTextureBlendMode_handle )( SDL_Texture * texture, SDL_BlendMode * blendMode );
    static auto SDL_GetTextureBlendMode = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetTextureBlendMode" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetTextureBlendMode" );
        }
        return ( SDL_GetTextureBlendMode_handle )( dlsym_ptr );
    } ();
}

int SDL_GetTextureBlendMode ( SDL_Texture * texture, SDL_BlendMode * blendMode );

namespace sym{
    typedef int ( *SDL_UpdateTexture_handle )( SDL_Texture * texture, const SDL_Rect * rect, const void * pixels, int pitch );
    static auto SDL_UpdateTexture = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_UpdateTexture" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_UpdateTexture" );
        }
        return ( SDL_UpdateTexture_handle )( dlsym_ptr );
    } ();
}

int SDL_UpdateTexture ( SDL_Texture * texture, const SDL_Rect * rect, const void * pixels, int pitch );

namespace sym{
    typedef int ( *SDL_UpdateYUVTexture_handle )( SDL_Texture * texture, const SDL_Rect * rect, const Uint8 * Yplane, int Ypitch, const Uint8 * Uplane, int Upitch, const Uint8 * Vplane, int Vpitch );
    static auto SDL_UpdateYUVTexture = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_UpdateYUVTexture" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_UpdateYUVTexture" );
        }
        return ( SDL_UpdateYUVTexture_handle )( dlsym_ptr );
    } ();
}

int SDL_UpdateYUVTexture ( SDL_Texture * texture, const SDL_Rect * rect, const Uint8 * Yplane, int Ypitch, const Uint8 * Uplane, int Upitch, const Uint8 * Vplane, int Vpitch );

namespace sym{
    typedef int ( *SDL_LockTexture_handle )( SDL_Texture * texture, const SDL_Rect * rect, void ** pixels, int * pitch );
    static auto SDL_LockTexture = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_LockTexture" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_LockTexture" );
        }
        return ( SDL_LockTexture_handle )( dlsym_ptr );
    } ();
}

int SDL_LockTexture ( SDL_Texture * texture, const SDL_Rect * rect, void ** pixels, int * pitch );

namespace sym{
    typedef void ( *SDL_UnlockTexture_handle )( SDL_Texture * texture );
    static auto SDL_UnlockTexture = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_UnlockTexture" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_UnlockTexture" );
        }
        return ( SDL_UnlockTexture_handle )( dlsym_ptr );
    } ();
}

void SDL_UnlockTexture ( SDL_Texture * texture );

namespace sym{
    typedef SDL_bool ( *SDL_RenderTargetSupported_handle )( SDL_Renderer * renderer );
    static auto SDL_RenderTargetSupported = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_RenderTargetSupported" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_RenderTargetSupported" );
        }
        return ( SDL_RenderTargetSupported_handle )( dlsym_ptr );
    } ();
}

SDL_bool SDL_RenderTargetSupported ( SDL_Renderer * renderer );

namespace sym{
    typedef int ( *SDL_SetRenderTarget_handle )( SDL_Renderer * renderer, SDL_Texture * texture );
    static auto SDL_SetRenderTarget = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_SetRenderTarget" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_SetRenderTarget" );
        }
        return ( SDL_SetRenderTarget_handle )( dlsym_ptr );
    } ();
}

int SDL_SetRenderTarget ( SDL_Renderer * renderer, SDL_Texture * texture );

namespace sym{
    typedef SDL_Texture * ( *SDL_GetRenderTarget_handle )( SDL_Renderer * renderer );
    static auto SDL_GetRenderTarget = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetRenderTarget" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetRenderTarget" );
        }
        return ( SDL_GetRenderTarget_handle )( dlsym_ptr );
    } ();
}

SDL_Texture * SDL_GetRenderTarget ( SDL_Renderer * renderer );

namespace sym{
    typedef int ( *SDL_RenderSetLogicalSize_handle )( SDL_Renderer * renderer, int w, int h );
    static auto SDL_RenderSetLogicalSize = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_RenderSetLogicalSize" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_RenderSetLogicalSize" );
        }
        return ( SDL_RenderSetLogicalSize_handle )( dlsym_ptr );
    } ();
}

int SDL_RenderSetLogicalSize ( SDL_Renderer * renderer, int w, int h );

namespace sym{
    typedef void ( *SDL_RenderGetLogicalSize_handle )( SDL_Renderer * renderer, int * w, int * h );
    static auto SDL_RenderGetLogicalSize = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_RenderGetLogicalSize" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_RenderGetLogicalSize" );
        }
        return ( SDL_RenderGetLogicalSize_handle )( dlsym_ptr );
    } ();
}

void SDL_RenderGetLogicalSize ( SDL_Renderer * renderer, int * w, int * h );

namespace sym{
    typedef int ( *SDL_RenderSetIntegerScale_handle )( SDL_Renderer * renderer, SDL_bool enable );
    static auto SDL_RenderSetIntegerScale = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_RenderSetIntegerScale" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_RenderSetIntegerScale" );
        }
        return ( SDL_RenderSetIntegerScale_handle )( dlsym_ptr );
    } ();
}

int SDL_RenderSetIntegerScale ( SDL_Renderer * renderer, SDL_bool enable );

namespace sym{
    typedef SDL_bool ( *SDL_RenderGetIntegerScale_handle )( SDL_Renderer * renderer );
    static auto SDL_RenderGetIntegerScale = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_RenderGetIntegerScale" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_RenderGetIntegerScale" );
        }
        return ( SDL_RenderGetIntegerScale_handle )( dlsym_ptr );
    } ();
}

SDL_bool SDL_RenderGetIntegerScale ( SDL_Renderer * renderer );

namespace sym{
    typedef int ( *SDL_RenderSetViewport_handle )( SDL_Renderer * renderer, const SDL_Rect * rect );
    static auto SDL_RenderSetViewport = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_RenderSetViewport" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_RenderSetViewport" );
        }
        return ( SDL_RenderSetViewport_handle )( dlsym_ptr );
    } ();
}

int SDL_RenderSetViewport ( SDL_Renderer * renderer, const SDL_Rect * rect );

namespace sym{
    typedef void ( *SDL_RenderGetViewport_handle )( SDL_Renderer * renderer, SDL_Rect * rect );
    static auto SDL_RenderGetViewport = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_RenderGetViewport" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_RenderGetViewport" );
        }
        return ( SDL_RenderGetViewport_handle )( dlsym_ptr );
    } ();
}

void SDL_RenderGetViewport ( SDL_Renderer * renderer, SDL_Rect * rect );

namespace sym{
    typedef int ( *SDL_RenderSetClipRect_handle )( SDL_Renderer * renderer, const SDL_Rect * rect );
    static auto SDL_RenderSetClipRect = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_RenderSetClipRect" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_RenderSetClipRect" );
        }
        return ( SDL_RenderSetClipRect_handle )( dlsym_ptr );
    } ();
}

int SDL_RenderSetClipRect ( SDL_Renderer * renderer, const SDL_Rect * rect );

namespace sym{
    typedef void ( *SDL_RenderGetClipRect_handle )( SDL_Renderer * renderer, SDL_Rect * rect );
    static auto SDL_RenderGetClipRect = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_RenderGetClipRect" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_RenderGetClipRect" );
        }
        return ( SDL_RenderGetClipRect_handle )( dlsym_ptr );
    } ();
}

void SDL_RenderGetClipRect ( SDL_Renderer * renderer, SDL_Rect * rect );

namespace sym{
    typedef SDL_bool ( *SDL_RenderIsClipEnabled_handle )( SDL_Renderer * renderer );
    static auto SDL_RenderIsClipEnabled = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_RenderIsClipEnabled" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_RenderIsClipEnabled" );
        }
        return ( SDL_RenderIsClipEnabled_handle )( dlsym_ptr );
    } ();
}

SDL_bool SDL_RenderIsClipEnabled ( SDL_Renderer * renderer );

namespace sym{
    typedef int ( *SDL_RenderSetScale_handle )( SDL_Renderer * renderer, float scaleX, float scaleY );
    static auto SDL_RenderSetScale = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_RenderSetScale" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_RenderSetScale" );
        }
        return ( SDL_RenderSetScale_handle )( dlsym_ptr );
    } ();
}

int SDL_RenderSetScale ( SDL_Renderer * renderer, float scaleX, float scaleY );

namespace sym{
    typedef void ( *SDL_RenderGetScale_handle )( SDL_Renderer * renderer, float * scaleX, float * scaleY );
    static auto SDL_RenderGetScale = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_RenderGetScale" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_RenderGetScale" );
        }
        return ( SDL_RenderGetScale_handle )( dlsym_ptr );
    } ();
}

void SDL_RenderGetScale ( SDL_Renderer * renderer, float * scaleX, float * scaleY );

namespace sym{
    typedef int ( *SDL_SetRenderDrawColor_handle )( SDL_Renderer * renderer, Uint8 r, Uint8 g, Uint8 b, Uint8 a );
    static auto SDL_SetRenderDrawColor = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_SetRenderDrawColor" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_SetRenderDrawColor" );
        }
        return ( SDL_SetRenderDrawColor_handle )( dlsym_ptr );
    } ();
}

int SDL_SetRenderDrawColor ( SDL_Renderer * renderer, Uint8 r, Uint8 g, Uint8 b, Uint8 a );

namespace sym{
    typedef int ( *SDL_GetRenderDrawColor_handle )( SDL_Renderer * renderer, Uint8 * r, Uint8 * g, Uint8 * b, Uint8 * a );
    static auto SDL_GetRenderDrawColor = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetRenderDrawColor" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetRenderDrawColor" );
        }
        return ( SDL_GetRenderDrawColor_handle )( dlsym_ptr );
    } ();
}

int SDL_GetRenderDrawColor ( SDL_Renderer * renderer, Uint8 * r, Uint8 * g, Uint8 * b, Uint8 * a );

namespace sym{
    typedef int ( *SDL_SetRenderDrawBlendMode_handle )( SDL_Renderer * renderer, SDL_BlendMode blendMode );
    static auto SDL_SetRenderDrawBlendMode = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_SetRenderDrawBlendMode" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_SetRenderDrawBlendMode" );
        }
        return ( SDL_SetRenderDrawBlendMode_handle )( dlsym_ptr );
    } ();
}

int SDL_SetRenderDrawBlendMode ( SDL_Renderer * renderer, SDL_BlendMode blendMode );

namespace sym{
    typedef int ( *SDL_GetRenderDrawBlendMode_handle )( SDL_Renderer * renderer, SDL_BlendMode * blendMode );
    static auto SDL_GetRenderDrawBlendMode = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetRenderDrawBlendMode" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetRenderDrawBlendMode" );
        }
        return ( SDL_GetRenderDrawBlendMode_handle )( dlsym_ptr );
    } ();
}

int SDL_GetRenderDrawBlendMode ( SDL_Renderer * renderer, SDL_BlendMode * blendMode );

namespace sym{
    typedef int ( *SDL_RenderClear_handle )( SDL_Renderer * renderer );
    static auto SDL_RenderClear = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_RenderClear" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_RenderClear" );
        }
        return ( SDL_RenderClear_handle )( dlsym_ptr );
    } ();
}

int SDL_RenderClear ( SDL_Renderer * renderer );

namespace sym{
    typedef int ( *SDL_RenderDrawPoint_handle )( SDL_Renderer * renderer, int x, int y );
    static auto SDL_RenderDrawPoint = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_RenderDrawPoint" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_RenderDrawPoint" );
        }
        return ( SDL_RenderDrawPoint_handle )( dlsym_ptr );
    } ();
}

int SDL_RenderDrawPoint ( SDL_Renderer * renderer, int x, int y );

namespace sym{
    typedef int ( *SDL_RenderDrawPoints_handle )( SDL_Renderer * renderer, const SDL_Point * points, int count );
    static auto SDL_RenderDrawPoints = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_RenderDrawPoints" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_RenderDrawPoints" );
        }
        return ( SDL_RenderDrawPoints_handle )( dlsym_ptr );
    } ();
}

int SDL_RenderDrawPoints ( SDL_Renderer * renderer, const SDL_Point * points, int count );

namespace sym{
    typedef int ( *SDL_RenderDrawLine_handle )( SDL_Renderer * renderer, int x1, int y1, int x2, int y2 );
    static auto SDL_RenderDrawLine = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_RenderDrawLine" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_RenderDrawLine" );
        }
        return ( SDL_RenderDrawLine_handle )( dlsym_ptr );
    } ();
}

int SDL_RenderDrawLine ( SDL_Renderer * renderer, int x1, int y1, int x2, int y2 );

namespace sym{
    typedef int ( *SDL_RenderDrawLines_handle )( SDL_Renderer * renderer, const SDL_Point * points, int count );
    static auto SDL_RenderDrawLines = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_RenderDrawLines" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_RenderDrawLines" );
        }
        return ( SDL_RenderDrawLines_handle )( dlsym_ptr );
    } ();
}

int SDL_RenderDrawLines ( SDL_Renderer * renderer, const SDL_Point * points, int count );

namespace sym{
    typedef int ( *SDL_RenderDrawRect_handle )( SDL_Renderer * renderer, const SDL_Rect * rect );
    static auto SDL_RenderDrawRect = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_RenderDrawRect" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_RenderDrawRect" );
        }
        return ( SDL_RenderDrawRect_handle )( dlsym_ptr );
    } ();
}

int SDL_RenderDrawRect ( SDL_Renderer * renderer, const SDL_Rect * rect );

namespace sym{
    typedef int ( *SDL_RenderDrawRects_handle )( SDL_Renderer * renderer, const SDL_Rect * rects, int count );
    static auto SDL_RenderDrawRects = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_RenderDrawRects" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_RenderDrawRects" );
        }
        return ( SDL_RenderDrawRects_handle )( dlsym_ptr );
    } ();
}

int SDL_RenderDrawRects ( SDL_Renderer * renderer, const SDL_Rect * rects, int count );

namespace sym{
    typedef int ( *SDL_RenderFillRect_handle )( SDL_Renderer * renderer, const SDL_Rect * rect );
    static auto SDL_RenderFillRect = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_RenderFillRect" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_RenderFillRect" );
        }
        return ( SDL_RenderFillRect_handle )( dlsym_ptr );
    } ();
}

int SDL_RenderFillRect ( SDL_Renderer * renderer, const SDL_Rect * rect );

namespace sym{
    typedef int ( *SDL_RenderFillRects_handle )( SDL_Renderer * renderer, const SDL_Rect * rects, int count );
    static auto SDL_RenderFillRects = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_RenderFillRects" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_RenderFillRects" );
        }
        return ( SDL_RenderFillRects_handle )( dlsym_ptr );
    } ();
}

int SDL_RenderFillRects ( SDL_Renderer * renderer, const SDL_Rect * rects, int count );

namespace sym{
    typedef int ( *SDL_RenderCopy_handle )( SDL_Renderer * renderer, SDL_Texture * texture, const SDL_Rect * srcrect, const SDL_Rect * dstrect );
    static auto SDL_RenderCopy = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_RenderCopy" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_RenderCopy" );
        }
        return ( SDL_RenderCopy_handle )( dlsym_ptr );
    } ();
}

int SDL_RenderCopy ( SDL_Renderer * renderer, SDL_Texture * texture, const SDL_Rect * srcrect, const SDL_Rect * dstrect );

namespace sym{
    typedef int ( *SDL_RenderCopyEx_handle )( SDL_Renderer * renderer, SDL_Texture * texture, const SDL_Rect * srcrect, const SDL_Rect * dstrect, const double angle, const SDL_Point * center, const SDL_RendererFlip flip );
    static auto SDL_RenderCopyEx = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_RenderCopyEx" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_RenderCopyEx" );
        }
        return ( SDL_RenderCopyEx_handle )( dlsym_ptr );
    } ();
}

int SDL_RenderCopyEx ( SDL_Renderer * renderer, SDL_Texture * texture, const SDL_Rect * srcrect, const SDL_Rect * dstrect, const double angle, const SDL_Point * center, const SDL_RendererFlip flip );

namespace sym{
    typedef int ( *SDL_RenderReadPixels_handle )( SDL_Renderer * renderer, const SDL_Rect * rect, Uint32 format, void * pixels, int pitch );
    static auto SDL_RenderReadPixels = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_RenderReadPixels" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_RenderReadPixels" );
        }
        return ( SDL_RenderReadPixels_handle )( dlsym_ptr );
    } ();
}

int SDL_RenderReadPixels ( SDL_Renderer * renderer, const SDL_Rect * rect, Uint32 format, void * pixels, int pitch );

namespace sym{
    typedef void ( *SDL_RenderPresent_handle )( SDL_Renderer * renderer );
    static auto SDL_RenderPresent = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_RenderPresent" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_RenderPresent" );
        }
        return ( SDL_RenderPresent_handle )( dlsym_ptr );
    } ();
}

void SDL_RenderPresent ( SDL_Renderer * renderer );

namespace sym{
    typedef void ( *SDL_DestroyTexture_handle )( SDL_Texture * texture );
    static auto SDL_DestroyTexture = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_DestroyTexture" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_DestroyTexture" );
        }
        return ( SDL_DestroyTexture_handle )( dlsym_ptr );
    } ();
}

void SDL_DestroyTexture ( SDL_Texture * texture );

namespace sym{
    typedef void ( *SDL_DestroyRenderer_handle )( SDL_Renderer * renderer );
    static auto SDL_DestroyRenderer = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_DestroyRenderer" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_DestroyRenderer" );
        }
        return ( SDL_DestroyRenderer_handle )( dlsym_ptr );
    } ();
}

void SDL_DestroyRenderer ( SDL_Renderer * renderer );

namespace sym{
    typedef int ( *SDL_GL_BindTexture_handle )( SDL_Texture * texture, float * texw, float * texh );
    static auto SDL_GL_BindTexture = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GL_BindTexture" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GL_BindTexture" );
        }
        return ( SDL_GL_BindTexture_handle )( dlsym_ptr );
    } ();
}

int SDL_GL_BindTexture ( SDL_Texture * texture, float * texw, float * texh );

namespace sym{
    typedef int ( *SDL_GL_UnbindTexture_handle )( SDL_Texture * texture );
    static auto SDL_GL_UnbindTexture = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GL_UnbindTexture" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GL_UnbindTexture" );
        }
        return ( SDL_GL_UnbindTexture_handle )( dlsym_ptr );
    } ();
}

int SDL_GL_UnbindTexture ( SDL_Texture * texture );

namespace sym{
    typedef void * ( *SDL_RenderGetMetalLayer_handle )( SDL_Renderer * renderer );
    static auto SDL_RenderGetMetalLayer = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_RenderGetMetalLayer" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_RenderGetMetalLayer" );
        }
        return ( SDL_RenderGetMetalLayer_handle )( dlsym_ptr );
    } ();
}

void * SDL_RenderGetMetalLayer ( SDL_Renderer * renderer );

namespace sym{
    typedef void * ( *SDL_RenderGetMetalCommandEncoder_handle )( SDL_Renderer * renderer );
    static auto SDL_RenderGetMetalCommandEncoder = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_RenderGetMetalCommandEncoder" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_RenderGetMetalCommandEncoder" );
        }
        return ( SDL_RenderGetMetalCommandEncoder_handle )( dlsym_ptr );
    } ();
}

void * SDL_RenderGetMetalCommandEncoder ( SDL_Renderer * renderer );

namespace sym{
    typedef SDL_Window * ( *SDL_CreateShapedWindow_handle )( const char * title, unsigned int x, unsigned int y, unsigned int w, unsigned int h, Uint32 flags );
    static auto SDL_CreateShapedWindow = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_CreateShapedWindow" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_CreateShapedWindow" );
        }
        return ( SDL_CreateShapedWindow_handle )( dlsym_ptr );
    } ();
}

SDL_Window * SDL_CreateShapedWindow ( const char * title, unsigned int x, unsigned int y, unsigned int w, unsigned int h, Uint32 flags );

namespace sym{
    typedef SDL_bool ( *SDL_IsShapedWindow_handle )( const SDL_Window * window );
    static auto SDL_IsShapedWindow = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_IsShapedWindow" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_IsShapedWindow" );
        }
        return ( SDL_IsShapedWindow_handle )( dlsym_ptr );
    } ();
}

SDL_bool SDL_IsShapedWindow ( const SDL_Window * window );

namespace sym{
    typedef int ( *SDL_SetWindowShape_handle )( SDL_Window * window, SDL_Surface * shape, SDL_WindowShapeMode * shape_mode );
    static auto SDL_SetWindowShape = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_SetWindowShape" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_SetWindowShape" );
        }
        return ( SDL_SetWindowShape_handle )( dlsym_ptr );
    } ();
}

int SDL_SetWindowShape ( SDL_Window * window, SDL_Surface * shape, SDL_WindowShapeMode * shape_mode );

namespace sym{
    typedef int ( *SDL_GetShapedWindowMode_handle )( SDL_Window * window, SDL_WindowShapeMode * shape_mode );
    static auto SDL_GetShapedWindowMode = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetShapedWindowMode" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetShapedWindowMode" );
        }
        return ( SDL_GetShapedWindowMode_handle )( dlsym_ptr );
    } ();
}

int SDL_GetShapedWindowMode ( SDL_Window * window, SDL_WindowShapeMode * shape_mode );

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
    typedef Uint64 ( *SDL_GetPerformanceCounter_handle )(  );
    static auto SDL_GetPerformanceCounter = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetPerformanceCounter" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetPerformanceCounter" );
        }
        return ( SDL_GetPerformanceCounter_handle )( dlsym_ptr );
    } ();
}

Uint64 SDL_GetPerformanceCounter (  );

namespace sym{
    typedef Uint64 ( *SDL_GetPerformanceFrequency_handle )(  );
    static auto SDL_GetPerformanceFrequency = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetPerformanceFrequency" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetPerformanceFrequency" );
        }
        return ( SDL_GetPerformanceFrequency_handle )( dlsym_ptr );
    } ();
}

Uint64 SDL_GetPerformanceFrequency (  );

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
    typedef SDL_TimerID ( *SDL_AddTimer_handle )( Uint32 interval, SDL_TimerCallback callback, void * param );
    static auto SDL_AddTimer = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_AddTimer" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_AddTimer" );
        }
        return ( SDL_AddTimer_handle )( dlsym_ptr );
    } ();
}

SDL_TimerID SDL_AddTimer ( Uint32 interval, SDL_TimerCallback callback, void * param );

namespace sym{
    typedef SDL_bool ( *SDL_RemoveTimer_handle )( SDL_TimerID id );
    static auto SDL_RemoveTimer = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_RemoveTimer" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_RemoveTimer" );
        }
        return ( SDL_RemoveTimer_handle )( dlsym_ptr );
    } ();
}

SDL_bool SDL_RemoveTimer ( SDL_TimerID id );

namespace sym{
    typedef void ( *SDL_GetVersion_handle )( SDL_version * ver );
    static auto SDL_GetVersion = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetVersion" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetVersion" );
        }
        return ( SDL_GetVersion_handle )( dlsym_ptr );
    } ();
}

void SDL_GetVersion ( SDL_version * ver );

namespace sym{
    typedef const char * ( *SDL_GetRevision_handle )(  );
    static auto SDL_GetRevision = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetRevision" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetRevision" );
        }
        return ( SDL_GetRevision_handle )( dlsym_ptr );
    } ();
}

const char * SDL_GetRevision (  );

namespace sym{
    typedef int ( *SDL_GetRevisionNumber_handle )(  );
    static auto SDL_GetRevisionNumber = [] () {
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "SDL_GetRevisionNumber" );
        if ( !dlsym_ptr ) {
            printf ( "Unable to find function: %s\n", "SDL_GetRevisionNumber" );
        }
        return ( SDL_GetRevisionNumber_handle )( dlsym_ptr );
    } ();
}

int SDL_GetRevisionNumber (  );

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
