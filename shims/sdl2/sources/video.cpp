#include "video.h"

SDL_Window* SDL_CreateWindow ( const char* title,
                               int         x,
                               int         y,
                               int         w,
                               int         h,
                               Uint32      flags ) {
    SHIM_LOG();

    std::string wtitle = title;
    glpp::coords_2i coords ( x, y );
    glpp::dims_2u   dims ( w, h );

    libshimmer->create_window ( wtitle, coords, dims );

    if ( libshimmer->scaling_enabled() ) flags |= SDL_WINDOW_RESIZABLE;

    return sym::SDL_CreateWindow ( wtitle.c_str(),
                                   coords.x,
                                   coords.y,
                                   dims.width,
                                   dims.height,
                                   flags );
}

void SDL_RenderPresent ( SDL_Renderer* renderer ) {
    SHIM_LOG ( 10 );
    sym::SDL_RenderPresent ( renderer );
}

void (*glew_glBindFramebuffer)(GLenum, GLuint);

void sym_glBindFramebuffer (     GLenum target,
                                 GLuint framebuffer ) {
    printf("framebuffer\n");
    glew_glBindFramebuffer(target, framebuffer);
}

GLenum glewInit() {
    SHIM_LOG ( 1 );

    auto result = sym::glewInit();

    glew_glBindFramebuffer = glBindFramebuffer;
    glBindFramebuffer = sym_glBindFramebuffer;

    return result;
}
