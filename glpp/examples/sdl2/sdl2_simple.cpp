#include <SDL2/SDL.h>

#include <iostream>
#include <string>

SDL_Window*   WINDOW;
SDL_Renderer* RENDERER;
SDL_Surface*  IMAGE;
SDL_Texture*  TEXTURE;

bool RUNNING = true;

void cleanup() {
    if ( WINDOW ) SDL_DestroyWindow ( WINDOW );

    if ( RENDERER ) SDL_DestroyRenderer ( RENDERER );

    if ( IMAGE ) SDL_FreeSurface ( IMAGE );

    if ( TEXTURE ) SDL_DestroyTexture ( TEXTURE );
}

void poll_events() {
    SDL_Event event;

    while ( SDL_PollEvent ( &event ) ) {
        if ( event.type == SDL_QUIT ) {
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

int main ( int argc, char** argv ) {
    if ( SDL_Init ( SDL_INIT_VIDEO ) != 0 ) {
        return sdl_error ( "Error) Unable to initialise SDL2: ", false );
    }

    if ( ( WINDOW = SDL_CreateWindow ( "SDL2 Example",
                                       100,
                                       100,
                                       320,
                                       240,
                                       SDL_WINDOW_SHOWN ) ) == nullptr ) {
        return sdl_error ( "Error) Unable to create SDL2 window: " );
    }

    if ( ( RENDERER =
               SDL_CreateRenderer ( WINDOW, -1,
                                    SDL_RENDERER_ACCELERATED |
                                    SDL_RENDERER_PRESENTVSYNC ) ) == nullptr ) {
        return sdl_error ( "Error) Unable to create SDL2 renderer: " );
    }

    if ( ( IMAGE = SDL_LoadBMP ( "data/img/ck4.bmp" ) ) == nullptr ) {
        return sdl_error ( "Error) Unable to load test image: " );
    }


    if ( ( TEXTURE =
               SDL_CreateTextureFromSurface ( RENDERER, IMAGE ) ) == nullptr ) {
        return sdl_error ( "Error) Unable to create texture from image: " );
    }

    while ( RUNNING ) {
        SDL_RenderClear ( RENDERER );
        SDL_RenderCopy ( RENDERER, TEXTURE, NULL, NULL );
        SDL_RenderPresent ( RENDERER );

        SDL_Delay ( 10 );

        poll_events();
    }

    cleanup();
    SDL_Quit();

    return 0;
}
