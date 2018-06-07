#include "SDL_apigen.h"
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


void * SDL_revcpy ( void * dst, const void * src, size_t len ) {
            TRACE();
            return sym::SDL_revcpy ( dst, src, len );
        }

size_t SDL_strlcpy ( char * dst, const char * src, size_t maxlen ) {
            TRACE();
            return sym::SDL_strlcpy ( dst, src, maxlen );
        }

size_t SDL_strlcat ( char * dst, const char * src, size_t maxlen ) {
            TRACE();
            return sym::SDL_strlcat ( dst, src, maxlen );
        }

char * SDL_strrev ( char * string ) {
            TRACE();
            return sym::SDL_strrev ( string );
        }

char * SDL_strupr ( char * string ) {
            TRACE();
            return sym::SDL_strupr ( string );
        }

char * SDL_strlwr ( char * string ) {
            TRACE();
            return sym::SDL_strlwr ( string );
        }

char * SDL_ltoa ( long value, char * string, int radix ) {
            TRACE();
            return sym::SDL_ltoa ( value, string, radix );
        }

char * SDL_ultoa ( unsigned long value, char * string, int radix ) {
            TRACE();
            return sym::SDL_ultoa ( value, string, radix );
        }

char * SDL_lltoa ( Sint64 value, char * string, int radix ) {
            TRACE();
            return sym::SDL_lltoa ( value, string, radix );
        }

char * SDL_ulltoa ( Uint64 value, char * string, int radix ) {
            TRACE();
            return sym::SDL_ulltoa ( value, string, radix );
        }

size_t SDL_iconv ( iconv_t cd, const char ** inbuf, size_t * inbytesleft, char ** outbuf, size_t * outbytesleft ) {
            TRACE();
            return sym::SDL_iconv ( cd, inbuf, inbytesleft, outbuf, outbytesleft );
        }

char * SDL_iconv_string ( const char * tocode, const char * fromcode, const char * inbuf, size_t inbytesleft ) {
            TRACE();
            return sym::SDL_iconv_string ( tocode, fromcode, inbuf, inbytesleft );
        }

void SDL_SetError ( const char * fmt ) {
            TRACE();
            return sym::SDL_SetError ( fmt );
        }

char * SDL_GetError (  ) {
            TRACE();
            return sym::SDL_GetError (  );
        }

void SDL_ClearError (  ) {
            TRACE();
            return sym::SDL_ClearError (  );
        }

void SDL_Error ( SDL_errorcode code ) {
            TRACE();
            return sym::SDL_Error ( code );
        }

SDL_mutex * SDL_CreateMutex (  ) {
            TRACE();
            return sym::SDL_CreateMutex (  );
        }

int SDL_mutexP ( SDL_mutex * mutex ) {
            TRACE();
            return sym::SDL_mutexP ( mutex );
        }

int SDL_mutexV ( SDL_mutex * mutex ) {
            TRACE();
            return sym::SDL_mutexV ( mutex );
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

int SDL_CondWait ( SDL_cond * cond, SDL_mutex * mut ) {
            TRACE();
            return sym::SDL_CondWait ( cond, mut );
        }

int SDL_CondWaitTimeout ( SDL_cond * cond, SDL_mutex * mutex, Uint32 ms ) {
            TRACE();
            return sym::SDL_CondWaitTimeout ( cond, mutex, ms );
        }

SDL_Thread * SDL_CreateThread ( int (*fn)(void *), void * data ) {
            TRACE();
            return sym::SDL_CreateThread ( fn, data );
        }

Uint32 SDL_ThreadID (  ) {
            TRACE();
            return sym::SDL_ThreadID (  );
        }

Uint32 SDL_GetThreadID ( SDL_Thread * thread ) {
            TRACE();
            return sym::SDL_GetThreadID ( thread );
        }

void SDL_WaitThread ( SDL_Thread * thread, int * status ) {
            TRACE();
            return sym::SDL_WaitThread ( thread, status );
        }

void SDL_KillThread ( SDL_Thread * thread ) {
            TRACE();
            return sym::SDL_KillThread ( thread );
        }

SDL_RWops * SDL_RWFromFile ( const char * file, const char * mode ) {
            TRACE();
            return sym::SDL_RWFromFile ( file, mode );
        }

SDL_RWops * SDL_RWFromFP ( FILE * fp, int autoclose ) {
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

int SDL_WriteLE16 ( SDL_RWops * dst, Uint16 value ) {
            TRACE();
            return sym::SDL_WriteLE16 ( dst, value );
        }

int SDL_WriteBE16 ( SDL_RWops * dst, Uint16 value ) {
            TRACE();
            return sym::SDL_WriteBE16 ( dst, value );
        }

int SDL_WriteLE32 ( SDL_RWops * dst, Uint32 value ) {
            TRACE();
            return sym::SDL_WriteLE32 ( dst, value );
        }

int SDL_WriteBE32 ( SDL_RWops * dst, Uint32 value ) {
            TRACE();
            return sym::SDL_WriteBE32 ( dst, value );
        }

int SDL_WriteLE64 ( SDL_RWops * dst, Uint64 value ) {
            TRACE();
            return sym::SDL_WriteLE64 ( dst, value );
        }

int SDL_WriteBE64 ( SDL_RWops * dst, Uint64 value ) {
            TRACE();
            return sym::SDL_WriteBE64 ( dst, value );
        }

int SDL_AudioInit ( const char * driver_name ) {
            TRACE();
            return sym::SDL_AudioInit ( driver_name );
        }

void SDL_AudioQuit (  ) {
            TRACE();
            return sym::SDL_AudioQuit (  );
        }

char * SDL_AudioDriverName ( char * namebuf, int maxlen ) {
            TRACE();
            return sym::SDL_AudioDriverName ( namebuf, maxlen );
        }

int SDL_OpenAudio ( SDL_AudioSpec * desired, SDL_AudioSpec * obtained ) {
            TRACE();
            return sym::SDL_OpenAudio ( desired, obtained );
        }

SDL_audiostatus SDL_GetAudioStatus (  ) {
            TRACE();
            return sym::SDL_GetAudioStatus (  );
        }

void SDL_PauseAudio ( int pause_on ) {
            TRACE();
            return sym::SDL_PauseAudio ( pause_on );
        }

SDL_AudioSpec * SDL_LoadWAV_RW ( SDL_RWops * src, int freesrc, SDL_AudioSpec * spec, Uint8 ** audio_buf, Uint32 * audio_len ) {
            TRACE();
            return sym::SDL_LoadWAV_RW ( src, freesrc, spec, audio_buf, audio_len );
        }

void SDL_FreeWAV ( Uint8 * audio_buf ) {
            TRACE();
            return sym::SDL_FreeWAV ( audio_buf );
        }

int SDL_BuildAudioCVT ( SDL_AudioCVT * cvt, Uint16 src_format, Uint8 src_channels, int src_rate, Uint16 dst_format, Uint8 dst_channels, int dst_rate ) {
            TRACE();
            return sym::SDL_BuildAudioCVT ( cvt, src_format, src_channels, src_rate, dst_format, dst_channels, dst_rate );
        }

int SDL_ConvertAudio ( SDL_AudioCVT * cvt ) {
            TRACE();
            return sym::SDL_ConvertAudio ( cvt );
        }

void SDL_MixAudio ( Uint8 * dst, const Uint8 * src, Uint32 len, int volume ) {
            TRACE();
            return sym::SDL_MixAudio ( dst, src, len, volume );
        }

void SDL_LockAudio (  ) {
            TRACE();
            return sym::SDL_LockAudio (  );
        }

void SDL_UnlockAudio (  ) {
            TRACE();
            return sym::SDL_UnlockAudio (  );
        }

void SDL_CloseAudio (  ) {
            TRACE();
            return sym::SDL_CloseAudio (  );
        }

int SDL_CDNumDrives (  ) {
            TRACE();
            return sym::SDL_CDNumDrives (  );
        }

const char * SDL_CDName ( int drive ) {
            TRACE();
            return sym::SDL_CDName ( drive );
        }

SDL_CD * SDL_CDOpen ( int drive ) {
            TRACE();
            return sym::SDL_CDOpen ( drive );
        }

CDstatus SDL_CDStatus ( SDL_CD * cdrom ) {
            TRACE();
            return sym::SDL_CDStatus ( cdrom );
        }

int SDL_CDPlayTracks ( SDL_CD * cdrom, int start_track, int start_frame, int ntracks, int nframes ) {
            TRACE();
            return sym::SDL_CDPlayTracks ( cdrom, start_track, start_frame, ntracks, nframes );
        }

int SDL_CDPlay ( SDL_CD * cdrom, int start, int length ) {
            TRACE();
            return sym::SDL_CDPlay ( cdrom, start, length );
        }

int SDL_CDPause ( SDL_CD * cdrom ) {
            TRACE();
            return sym::SDL_CDPause ( cdrom );
        }

int SDL_CDResume ( SDL_CD * cdrom ) {
            TRACE();
            return sym::SDL_CDResume ( cdrom );
        }

int SDL_CDStop ( SDL_CD * cdrom ) {
            TRACE();
            return sym::SDL_CDStop ( cdrom );
        }

int SDL_CDEject ( SDL_CD * cdrom ) {
            TRACE();
            return sym::SDL_CDEject ( cdrom );
        }

void SDL_CDClose ( SDL_CD * cdrom ) {
            TRACE();
            return sym::SDL_CDClose ( cdrom );
        }

SDL_bool SDL_HasRDTSC (  ) {
            TRACE();
            return sym::SDL_HasRDTSC (  );
        }

SDL_bool SDL_HasMMX (  ) {
            TRACE();
            return sym::SDL_HasMMX (  );
        }

SDL_bool SDL_HasMMXExt (  ) {
            TRACE();
            return sym::SDL_HasMMXExt (  );
        }

SDL_bool SDL_Has3DNow (  ) {
            TRACE();
            return sym::SDL_Has3DNow (  );
        }

SDL_bool SDL_Has3DNowExt (  ) {
            TRACE();
            return sym::SDL_Has3DNowExt (  );
        }

SDL_bool SDL_HasSSE (  ) {
            TRACE();
            return sym::SDL_HasSSE (  );
        }

SDL_bool SDL_HasSSE2 (  ) {
            TRACE();
            return sym::SDL_HasSSE2 (  );
        }

SDL_bool SDL_HasAltiVec (  ) {
            TRACE();
            return sym::SDL_HasAltiVec (  );
        }

Uint8 SDL_GetAppState (  ) {
            TRACE();
            return sym::SDL_GetAppState (  );
        }

int SDL_EnableUNICODE ( int enable ) {
            TRACE();
            return sym::SDL_EnableUNICODE ( enable );
        }

int SDL_EnableKeyRepeat ( int delay, int interval ) {
            TRACE();
            return sym::SDL_EnableKeyRepeat ( delay, interval );
        }

void SDL_GetKeyRepeat ( int * delay, int * interval ) {
            TRACE();
            return sym::SDL_GetKeyRepeat ( delay, interval );
        }

Uint8 * SDL_GetKeyState ( int * numkeys ) {
            TRACE();
            return sym::SDL_GetKeyState ( numkeys );
        }

SDLMod SDL_GetModState (  ) {
            TRACE();
            return sym::SDL_GetModState (  );
        }

void SDL_SetModState ( SDLMod modstate ) {
            TRACE();
            return sym::SDL_SetModState ( modstate );
        }

char * SDL_GetKeyName ( SDLKey key ) {
            TRACE();
            return sym::SDL_GetKeyName ( key );
        }

int SDL_VideoInit ( const char * driver_name, Uint32 flags ) {
            TRACE();
            return sym::SDL_VideoInit ( driver_name, flags );
        }

void SDL_VideoQuit (  ) {
            TRACE();
            return sym::SDL_VideoQuit (  );
        }

char * SDL_VideoDriverName ( char * namebuf, int maxlen ) {
            TRACE();
            return sym::SDL_VideoDriverName ( namebuf, maxlen );
        }

SDL_Surface * SDL_GetVideoSurface (  ) {
            TRACE();
            return sym::SDL_GetVideoSurface (  );
        }

const SDL_VideoInfo * SDL_GetVideoInfo (  ) {
            TRACE();
            return sym::SDL_GetVideoInfo (  );
        }

int SDL_VideoModeOK ( int width, int height, int bpp, Uint32 flags ) {
            TRACE();
            return sym::SDL_VideoModeOK ( width, height, bpp, flags );
        }

SDL_Rect ** SDL_ListModes ( SDL_PixelFormat * format, Uint32 flags ) {
            TRACE();
            return sym::SDL_ListModes ( format, flags );
        }

SDL_Surface * SDL_SetVideoMode ( int width, int height, int bpp, Uint32 flags ) {
            TRACE();
            return sym::SDL_SetVideoMode ( width, height, bpp, flags );
        }

void SDL_UpdateRects ( SDL_Surface * screen, int numrects, SDL_Rect * rects ) {
            TRACE();
            return sym::SDL_UpdateRects ( screen, numrects, rects );
        }

void SDL_UpdateRect ( SDL_Surface * screen, Sint32 x, Sint32 y, Uint32 w, Uint32 h ) {
            TRACE();
            return sym::SDL_UpdateRect ( screen, x, y, w, h );
        }

int SDL_Flip ( SDL_Surface * screen ) {
            TRACE();
            return sym::SDL_Flip ( screen );
        }

int SDL_SetGamma ( float red, float green, float blue ) {
            TRACE();
            return sym::SDL_SetGamma ( red, green, blue );
        }

int SDL_SetGammaRamp ( const Uint16 * red, const Uint16 * green, const Uint16 * blue ) {
            TRACE();
            return sym::SDL_SetGammaRamp ( red, green, blue );
        }

int SDL_GetGammaRamp ( Uint16 * red, Uint16 * green, Uint16 * blue ) {
            TRACE();
            return sym::SDL_GetGammaRamp ( red, green, blue );
        }

int SDL_SetColors ( SDL_Surface * surface, SDL_Color * colors, int firstcolor, int ncolors ) {
            TRACE();
            return sym::SDL_SetColors ( surface, colors, firstcolor, ncolors );
        }

int SDL_SetPalette ( SDL_Surface * surface, int flags, SDL_Color * colors, int firstcolor, int ncolors ) {
            TRACE();
            return sym::SDL_SetPalette ( surface, flags, colors, firstcolor, ncolors );
        }

Uint32 SDL_MapRGB ( const SDL_PixelFormat *const format, const Uint8 r, const Uint8 g, const Uint8 b ) {
            TRACE();
            return sym::SDL_MapRGB ( format, r, g, b );
        }

Uint32 SDL_MapRGBA ( const SDL_PixelFormat *const format, const Uint8 r, const Uint8 g, const Uint8 b, const Uint8 a ) {
            TRACE();
            return sym::SDL_MapRGBA ( format, r, g, b, a );
        }

void SDL_GetRGB ( Uint32 pixel, const SDL_PixelFormat *const fmt, Uint8 * r, Uint8 * g, Uint8 * b ) {
            TRACE();
            return sym::SDL_GetRGB ( pixel, fmt, r, g, b );
        }

void SDL_GetRGBA ( Uint32 pixel, const SDL_PixelFormat *const fmt, Uint8 * r, Uint8 * g, Uint8 * b, Uint8 * a ) {
            TRACE();
            return sym::SDL_GetRGBA ( pixel, fmt, r, g, b, a );
        }

SDL_Surface * SDL_CreateRGBSurface ( Uint32 flags, int width, int height, int depth, Uint32 Rmask, Uint32 Gmask, Uint32 Bmask, Uint32 Amask ) {
            TRACE();
            return sym::SDL_CreateRGBSurface ( flags, width, height, depth, Rmask, Gmask, Bmask, Amask );
        }

SDL_Surface * SDL_CreateRGBSurfaceFrom ( void * pixels, int width, int height, int depth, int pitch, Uint32 Rmask, Uint32 Gmask, Uint32 Bmask, Uint32 Amask ) {
            TRACE();
            return sym::SDL_CreateRGBSurfaceFrom ( pixels, width, height, depth, pitch, Rmask, Gmask, Bmask, Amask );
        }

void SDL_FreeSurface ( SDL_Surface * surface ) {
            TRACE();
            return sym::SDL_FreeSurface ( surface );
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

int SDL_SetColorKey ( SDL_Surface * surface, Uint32 flag, Uint32 key ) {
            TRACE();
            return sym::SDL_SetColorKey ( surface, flag, key );
        }

int SDL_SetAlpha ( SDL_Surface * surface, Uint32 flag, Uint8 alpha ) {
            TRACE();
            return sym::SDL_SetAlpha ( surface, flag, alpha );
        }

SDL_bool SDL_SetClipRect ( SDL_Surface * surface, const SDL_Rect * rect ) {
            TRACE();
            return sym::SDL_SetClipRect ( surface, rect );
        }

void SDL_GetClipRect ( SDL_Surface * surface, SDL_Rect * rect ) {
            TRACE();
            return sym::SDL_GetClipRect ( surface, rect );
        }

SDL_Surface * SDL_ConvertSurface ( SDL_Surface * src, SDL_PixelFormat * fmt, Uint32 flags ) {
            TRACE();
            return sym::SDL_ConvertSurface ( src, fmt, flags );
        }

int SDL_UpperBlit ( SDL_Surface * src, SDL_Rect * srcrect, SDL_Surface * dst, SDL_Rect * dstrect ) {
            TRACE();
            return sym::SDL_UpperBlit ( src, srcrect, dst, dstrect );
        }

int SDL_LowerBlit ( SDL_Surface * src, SDL_Rect * srcrect, SDL_Surface * dst, SDL_Rect * dstrect ) {
            TRACE();
            return sym::SDL_LowerBlit ( src, srcrect, dst, dstrect );
        }

int SDL_FillRect ( SDL_Surface * dst, SDL_Rect * dstrect, Uint32 color ) {
            TRACE();
            return sym::SDL_FillRect ( dst, dstrect, color );
        }

SDL_Surface * SDL_DisplayFormat ( SDL_Surface * surface ) {
            TRACE();
            return sym::SDL_DisplayFormat ( surface );
        }

SDL_Surface * SDL_DisplayFormatAlpha ( SDL_Surface * surface ) {
            TRACE();
            return sym::SDL_DisplayFormatAlpha ( surface );
        }

SDL_Overlay * SDL_CreateYUVOverlay ( int width, int height, Uint32 format, SDL_Surface * display ) {
            TRACE();
            return sym::SDL_CreateYUVOverlay ( width, height, format, display );
        }

int SDL_LockYUVOverlay ( SDL_Overlay * overlay ) {
            TRACE();
            return sym::SDL_LockYUVOverlay ( overlay );
        }

void SDL_UnlockYUVOverlay ( SDL_Overlay * overlay ) {
            TRACE();
            return sym::SDL_UnlockYUVOverlay ( overlay );
        }

int SDL_DisplayYUVOverlay ( SDL_Overlay * overlay, SDL_Rect * dstrect ) {
            TRACE();
            return sym::SDL_DisplayYUVOverlay ( overlay, dstrect );
        }

void SDL_FreeYUVOverlay ( SDL_Overlay * overlay ) {
            TRACE();
            return sym::SDL_FreeYUVOverlay ( overlay );
        }

int SDL_GL_LoadLibrary ( const char * path ) {
            TRACE();
            return sym::SDL_GL_LoadLibrary ( path );
        }

void * SDL_GL_GetProcAddress ( const char * proc ) {
            TRACE();
            return sym::SDL_GL_GetProcAddress ( proc );
        }

int SDL_GL_SetAttribute ( SDL_GLattr attr, int value ) {
            TRACE();
            return sym::SDL_GL_SetAttribute ( attr, value );
        }

int SDL_GL_GetAttribute ( SDL_GLattr attr, int * value ) {
            TRACE();
            return sym::SDL_GL_GetAttribute ( attr, value );
        }

void SDL_GL_SwapBuffers (  ) {
            TRACE();
            return sym::SDL_GL_SwapBuffers (  );
        }

void SDL_GL_UpdateRects ( int numrects, SDL_Rect * rects ) {
            TRACE();
            return sym::SDL_GL_UpdateRects ( numrects, rects );
        }

void SDL_GL_Lock (  ) {
            TRACE();
            return sym::SDL_GL_Lock (  );
        }

void SDL_GL_Unlock (  ) {
            TRACE();
            return sym::SDL_GL_Unlock (  );
        }

void SDL_WM_SetCaption ( const char * title, const char * icon ) {
            TRACE();
            return sym::SDL_WM_SetCaption ( title, icon );
        }

void SDL_WM_GetCaption ( char ** title, char ** icon ) {
            TRACE();
            return sym::SDL_WM_GetCaption ( title, icon );
        }

void SDL_WM_SetIcon ( SDL_Surface * icon, Uint8 * mask ) {
            TRACE();
            return sym::SDL_WM_SetIcon ( icon, mask );
        }

int SDL_WM_IconifyWindow (  ) {
            TRACE();
            return sym::SDL_WM_IconifyWindow (  );
        }

int SDL_WM_ToggleFullScreen ( SDL_Surface * surface ) {
            TRACE();
            return sym::SDL_WM_ToggleFullScreen ( surface );
        }

SDL_GrabMode SDL_WM_GrabInput ( SDL_GrabMode mode ) {
            TRACE();
            return sym::SDL_WM_GrabInput ( mode );
        }

int SDL_SoftStretch ( SDL_Surface * src, SDL_Rect * srcrect, SDL_Surface * dst, SDL_Rect * dstrect ) {
            TRACE();
            return sym::SDL_SoftStretch ( src, srcrect, dst, dstrect );
        }

Uint8 SDL_GetMouseState ( int * x, int * y ) {
            TRACE();
            return sym::SDL_GetMouseState ( x, y );
        }

Uint8 SDL_GetRelativeMouseState ( int * x, int * y ) {
            TRACE();
            return sym::SDL_GetRelativeMouseState ( x, y );
        }

void SDL_WarpMouse ( Uint16 x, Uint16 y ) {
            TRACE();
            return sym::SDL_WarpMouse ( x, y );
        }

SDL_Cursor * SDL_CreateCursor ( Uint8 * data, Uint8 * mask, int w, int h, int hot_x, int hot_y ) {
            TRACE();
            return sym::SDL_CreateCursor ( data, mask, w, h, hot_x, hot_y );
        }

void SDL_SetCursor ( SDL_Cursor * cursor ) {
            TRACE();
            return sym::SDL_SetCursor ( cursor );
        }

SDL_Cursor * SDL_GetCursor (  ) {
            TRACE();
            return sym::SDL_GetCursor (  );
        }

void SDL_FreeCursor ( SDL_Cursor * cursor ) {
            TRACE();
            return sym::SDL_FreeCursor ( cursor );
        }

int SDL_ShowCursor ( int toggle ) {
            TRACE();
            return sym::SDL_ShowCursor ( toggle );
        }

int SDL_NumJoysticks (  ) {
            TRACE();
            return sym::SDL_NumJoysticks (  );
        }

const char * SDL_JoystickName ( int device_index ) {
            TRACE();
            return sym::SDL_JoystickName ( device_index );
        }

SDL_Joystick * SDL_JoystickOpen ( int device_index ) {
            TRACE();
            return sym::SDL_JoystickOpen ( device_index );
        }

int SDL_JoystickOpened ( int device_index ) {
            TRACE();
            return sym::SDL_JoystickOpened ( device_index );
        }

int SDL_JoystickIndex ( SDL_Joystick * joystick ) {
            TRACE();
            return sym::SDL_JoystickIndex ( joystick );
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

void SDL_PumpEvents (  ) {
            TRACE();
            return sym::SDL_PumpEvents (  );
        }

int SDL_PeepEvents ( SDL_Event * events, int numevents, SDL_eventaction action, Uint32 mask ) {
            TRACE();
            return sym::SDL_PeepEvents ( events, numevents, action, mask );
        }

int SDL_PollEvent ( SDL_Event * event ) {
            TRACE();
            return sym::SDL_PollEvent ( event );
        }

int SDL_WaitEvent ( SDL_Event * event ) {
            TRACE();
            return sym::SDL_WaitEvent ( event );
        }

int SDL_PushEvent ( SDL_Event * event ) {
            TRACE();
            return sym::SDL_PushEvent ( event );
        }

void SDL_SetEventFilter ( SDL_EventFilter filter ) {
            TRACE();
            return sym::SDL_SetEventFilter ( filter );
        }

SDL_EventFilter SDL_GetEventFilter (  ) {
            TRACE();
            return sym::SDL_GetEventFilter (  );
        }

Uint8 SDL_EventState ( Uint8 type, int state ) {
            TRACE();
            return sym::SDL_EventState ( type, state );
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

Uint32 SDL_GetTicks (  ) {
            TRACE();
            return sym::SDL_GetTicks (  );
        }

void SDL_Delay ( Uint32 ms ) {
            TRACE();
            return sym::SDL_Delay ( ms );
        }

int SDL_SetTimer ( Uint32 interval, SDL_TimerCallback callback ) {
            TRACE();
            return sym::SDL_SetTimer ( interval, callback );
        }

SDL_TimerID SDL_AddTimer ( Uint32 interval, SDL_NewTimerCallback callback, void * param ) {
            TRACE();
            return sym::SDL_AddTimer ( interval, callback, param );
        }

SDL_bool SDL_RemoveTimer ( SDL_TimerID t ) {
            TRACE();
            return sym::SDL_RemoveTimer ( t );
        }

const SDL_version * SDL_Linked_Version (  ) {
            TRACE();
            return sym::SDL_Linked_Version (  );
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
