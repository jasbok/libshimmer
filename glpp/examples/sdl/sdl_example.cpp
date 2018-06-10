#include "glpp/includes/program.h"
#include "glpp/includes/shader.h"

#include "SDL.h"

static const SDL_VideoInfo* VIDEO_INFO = nullptr;
static SDL_Surface* VIDEO              = nullptr;

static bool RUNNING = true;

void init_sdl() {
    printf ( "[INFO] Initialising SDL...\n" );

    if ( SDL_Init ( SDL_INIT_VIDEO | SDL_INIT_EVERYTHING ) < 0 ) {
        printf ( "[ERROR] Failed to initialise SDL: %s\n", SDL_GetError() );

        exit ( 1 );
    }
}

void setup_video() {
    printf ( "[INFO] Configuring video...\n" );

    VIDEO_INFO = SDL_GetVideoInfo();

    if ( VIDEO_INFO == nullptr ) {
        printf ( "[ERROR] Failed to get video info: %s\n", SDL_GetError() );

        exit ( 1 );
    }

    VIDEO = SDL_SetVideoMode ( VIDEO_INFO->current_w,
                               VIDEO_INFO->current_h,
                               VIDEO_INFO->vfmt->BitsPerPixel,
                               SDL_OPENGL );

    if ( VIDEO == nullptr ) {
        printf ( "[ERROR] Failed to set SDL video mode: %s\n", SDL_GetError() );

        exit ( 1 );
    }
}

void init_glew() {
    printf ( "[INFO] Configuring glew...\n" );

    glewExperimental = GL_TRUE;

    GLenum glew_err = glewInit();

    if ( glew_err ) {
        printf ( "[ERROR] Unable to initialise GLEW: %s\n",
                 glewGetErrorString ( glew_err ) );

        SDL_Quit();
        exit ( 1 );
    }
}

void setup_shaders() {}

void setup_opengl() {
    printf ( "[INFO] Configuring opengl...\n" );
    init_glew();
    setup_shaders();
}

void cleanup() {
    printf ( "[INFO] Quiting GLPP SDL example.\n" );

    SDL_FreeSurface ( VIDEO );

    SDL_Quit();
}

void render() {}

void input() {
    SDL_Event event;

    while ( SDL_PollEvent ( &event ) ) {
        switch ( event.type ) {
        case SDL_KEYUP:
            RUNNING = false;
            break;
        }
    }
}

int main ( int argc, char* argv[] ) {
    printf ( "[INFO] Starting GLPP SDL example.\n" );
    init_sdl();
    setup_video();
    setup_opengl();

    while ( RUNNING ) {
        input();
        render();
        SDL_Delay ( 30 );
    }

    cleanup();

    return 0;
}
