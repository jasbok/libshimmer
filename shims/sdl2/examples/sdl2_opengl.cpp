#include "glpp.h"

// #include <GL/glew.h>
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
        if ( event.type == SDL_QUIT ) {
            RUNNING = false;
        }
        else if ( event.type == SDL_KEYDOWN ) {
            if ( event.key.keysym.sym == SDLK_q ) {
                RUNNING = false;
            }
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
    SDL_GL_SetAttribute ( SDL_GL_CONTEXT_MINOR_VERSION, 3 );
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

    glpp::shader fragment ( glpp::shader::type::gl_fragment_shader,
        R"(
        #version 330 core
        out vec4 FragColor;

        void main()
        {
            FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);
        }
        )" );

    if ( !fragment.compile().compile_status() ) {
        std::cerr << "Unable to compile fragment shader:\n"
                  << fragment.info_log()
                  << std::endl;
    }

    glpp::shader vertex ( glpp::shader::type::gl_vertex_shader,
        R"(
        #version 330 core
        layout (location = 0) in vec3 aPos;

        void main()
        {
            gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
        }
        )" );

    if ( !vertex.compile().compile_status() ) {
        std::cerr << "Unable to compile vertex shader:\n"
                  << vertex.info_log()
                  << std::endl;
    }

    glpp::program prog;

    if ( !prog.attach ( fragment )
         .attach ( vertex )
         .link()
         .link_status() ) {
        std::cerr << "Unable to link shaders into program:\n"
                  << prog.info_log()
                  << std::endl;
    }

    prog.detach ( fragment ).detach ( vertex );

    glpp::buffer vbo (
        glpp::buffer::target::gl_array_buffer,
        glpp::buffer::usage::gl_static_draw );

    vbo.bind().data<GLfloat>( {
        0.5f, 0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f,
        -0.5f, 0.5f, 0.0f
    } );

    glpp::buffer ebo (
        glpp::buffer::target::gl_element_array_buffer,
        glpp::buffer::usage::gl_static_draw );

    ebo.bind().data<GLuint>( {
        0, 1, 3,
        1, 2, 3
    } );

    glpp::vertex_array vao;
    vao.bind();

    glpp::vertex_attrib attrib ( glpp::vertex_attrib::type::gl_float, 3 );
    attrib.define_pointer().enable_array();

    ebo.bind();
    vao.unbind();

    vbo.unbind();
    ebo.unbind();

    while ( RUNNING ) {
        glClear ( GL_COLOR_BUFFER_BIT );
        prog.use();
        vao.bind();

        glDrawElements ( GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0 );

        SDL_GL_SwapWindow ( WINDOW );

        SDL_Delay ( 10 );

        poll_events();
    }

    cleanup();
    SDL_Quit();

    return 0;
}
