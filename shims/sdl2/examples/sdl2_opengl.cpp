#include <GL/glew.h>
#include <SDL2/SDL.h>

#include <iostream>
#include <string>

SDL_Window*   WINDOW;
SDL_Renderer* RENDERER;

SDL_GLContext GL_CONTEXT;

bool RUNNING = true;

void cleanup() {
    if ( WINDOW ) SDL_DestroyWindow ( WINDOW );
}

void poll_events() {
    SDL_Event event;

    while ( SDL_PollEvent ( &event ) ) {
        if ( (event.type == SDL_QUIT) ) {
            RUNNING = false;
        }
    }
}

int sdl_error ( const std::string& err, bool do_quit = true ) {
    std::cerr << err << SDL_GetError() << std::endl;
    cleanup();

    if ( do_quit ) SDL_Quit();

    return 1;
}

int setup_opengl() {
    return 0;
}

int main ( int argc, char** argv ) {
    if ( SDL_Init ( SDL_INIT_VIDEO ) != 0 ) {
        return sdl_error ( "Error) Unable to initialise SDL2: ", false );
    }

    if ( (WINDOW = SDL_CreateWindow ( "SDL2 Example",
                                      100,
                                      100,
                                      320,
                                      240,
                                      SDL_WINDOW_OPENGL |
                                      SDL_WINDOW_SHOWN )) == nullptr ) {
        return sdl_error ( "Error) Unable to create SDL2 window: " );
    }

    SDL_GL_SetAttribute ( SDL_GL_CONTEXT_PROFILE_MASK,
                          SDL_GL_CONTEXT_PROFILE_CORE );

    SDL_GL_SetAttribute ( SDL_GL_CONTEXT_MAJOR_VERSION, 3 );
    SDL_GL_SetAttribute ( SDL_GL_CONTEXT_MINOR_VERSION, 2 );
    SDL_GL_SetAttribute ( SDL_GL_DOUBLEBUFFER,          1 );

    if ( (GL_CONTEXT = SDL_GL_CreateContext ( WINDOW )) == nullptr ) {
        return sdl_error ( "Error) Unable to create OpenGL context: " );
    }

    glewExperimental = GL_TRUE;

    GLenum glew_err = glewInit();

    if ( glew_err ) {
        std::cerr << "Error) Unable to initialise GLEW: "
                  << glewGetErrorString ( glew_err ) << std::endl;

        cleanup();
        SDL_Quit();

        return 1;
    }

    glClearColor(0.0f, 0.75f, 0.0f, 1.0f);

    while ( RUNNING ) {
        glClear(GL_COLOR_BUFFER_BIT);
        SDL_GL_SwapWindow(WINDOW);

        SDL_Delay ( 10 );

        poll_events();
    }

    cleanup();
    SDL_Quit();

    return 0;
}
