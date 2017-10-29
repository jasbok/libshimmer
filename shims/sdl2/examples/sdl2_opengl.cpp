#include "glpp.h"

#include "stb/stb_image.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
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

int init_opengl() {
    if ( SDL_Init ( SDL_INIT_VIDEO ) != 0 ) {
        return sdl_error ( "Error) Unable to initialise SDL2: ", false );
    }

    if ( (WINDOW = SDL_CreateWindow ( "SDL2 Example",
                                      100,
                                      100,
                                      1600,
                                      900,
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

    return 0;
}

glpp::texture_2d load_texture ( const std::string& path ) {
    int width, height, channels;
    uint8_t* data =
        stbi_load ( path.c_str(), &width, &height, &channels, 0 );

    if ( !data ) {
        std::cerr << "Could not load image..." << std::endl;

        return glpp::texture_2d (
            glpp::texture_2d::internal_format::rgb );
    }

    auto format = channels == 3
                  ? glpp::pixels::format::rgb
                  : glpp::pixels::format::rgba;

    glpp::texture_2d texture ( glpp::texture_2d::internal_format::rgb );

    texture.bind();

    texture.image ( glpp::pixels ( std::unique_ptr<uint8_t>( data ),
                                   { static_cast<GLuint>(width),
                                     static_cast<GLuint>(height) },
                                   format,
                                   glpp::pixels::type::gl_unsigned_byte ) );
    texture.generate_mipmap();

    return texture;
}

int main ( int argc, char** argv ) {
    init_opengl();

    glpp::shader fragment ( glpp::shader::type::fragment,
        R"(
        #version 330 core

        out vec4 FragColor;

        in vec3 f_colour;
        in vec2 f_texcoord;

        uniform sampler2D tex_a;
        uniform sampler2D tex_b;
        uniform float factor;

        void main()
        {
            FragColor = mix(texture(tex_a, f_texcoord), texture(tex_b, f_texcoord), factor) + vec4(f_colour, 1.0f);
        }
        )" );

    if ( !fragment.compile().compile_status() ) {
        std::cerr << "Unable to compile fragment shader:\n"
                  << fragment.info_log()
                  << std::endl;
    }

    glpp::shader vertex ( glpp::shader::type::vertex,
        R"(
        #version 330 core
        layout (location = 8) in vec3 position;
        layout (location = 4) in vec3 colour;
        layout (location = 13) in vec2 texcoord;

        out vec3 f_colour;
        out vec2 f_texcoord;

        uniform mat4 model;
        uniform mat4 view;
        uniform mat4 projection;

        void main()
        {
            gl_Position = projection * view * model * vec4(position, 1.0);
            f_colour = colour;
            f_texcoord = texcoord;
        }
        )" );

    if ( !vertex.compile().compile_status() ) {
        std::cerr << "Unable to compile vertex shader:\n"
                  << vertex.info_log()
                  << std::endl;
    }

    glpp::program prog;
    prog.attach ( fragment ).attach ( vertex ).link()
        .detach ( fragment ).detach ( vertex );

    if ( !prog.link_status() ) {
        std::cerr << "Unable to link shaders into program:\n"
                  << prog.info_log()
                  << std::endl;
    }

    prog.use()
        .uniform ( "tex_a", 1 )
        .uniform ( "tex_b", 2 );

    glpp::texture_2d texture_a      = load_texture ( "data/ck4.png" );
    glpp::texture_2d texture_b      = load_texture ( "data/wolf.png" );
    glpp::texture_2d texture_c      = load_texture ( "data/doom.gif" );
    glpp::texture_2d texture_cursor = load_texture ( "data/cursor.png" );

    int texture_a_unit = 1;
    int texture_b_unit = 2;
    int texture_c_unit = 0;

    texture_a.bind_texture_unit ( texture_a_unit )
        .min_filter ( glpp::texture_2d::min_filter::nearest )
        .mag_filter ( glpp::texture_2d::mag_filter::nearest );

    texture_b.bind_texture_unit ( texture_b_unit )
        .min_filter ( glpp::texture_2d::min_filter::nearest )
        .mag_filter ( glpp::texture_2d::mag_filter::nearest );

    texture_c.bind_texture_unit ( texture_c_unit )
        .min_filter ( glpp::texture_2d::min_filter::nearest )
        .mag_filter ( glpp::texture_2d::mag_filter::nearest );

    auto position_location = prog.attribute_location ( "position" );
    auto colour_location   = prog.attribute_location ( "colour" );
    auto texcoord_location = prog.attribute_location ( "texcoord" );

    glpp::vertex_buffer<GL_FLOAT> vbo;

    glpp::buffer<GL_ELEMENT_ARRAY_BUFFER> ebo;

    glpp::vertex_array vao;
    vao.bind();

    vbo.bind().data<GLfloat>( {
        // Top Right
        1.0f, 1.0f, 0.0f,
        1.0f, 0.0f, 0.0f,
        1.0f, 0.0f,

        // Bottom Right
        1.0f, -1.0f, 0.0f,
        0.0f, 1.0f, 0.0f,
        1.0f, 1.0f,

        // Bottom Left
        -1.0f, -1.0f, 0.0f,
        0.0f, 0.0f, 1.0f,
        0.0f, 1.0f,

        // TOP Left
        -1.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f,
        0.0f, 0.0f
    } )
        .attribute_pointers ( {
        { position_location, 3 },
        { colour_location, 3 },
        { texcoord_location, 2 }
    } );

    vao.enable_attribute_arrays ( {
        position_location,
        colour_location,
        texcoord_location
    } );

    ebo.bind().data<GLuint>( {
        0, 1, 3,
        1, 2, 3
    } );

    vao.unbind();
    ebo.unbind();
    vbo.unbind();

    float factor = 0.0f;
    float update = 0.001f;

    glm::mat4 model = glm::rotate ( glm::mat4 ( 1.0f ),
                                    glm::radians ( -0.0f ),
                                    glm::  vec3 ( 0.0f, 1.0f, 0.0f ) );

    glm::mat4 view = glm::translate ( glm::mat4 ( 1.0f ),
                                      glm::vec3 ( 0.0f, 0.0f, -5.0f ) );

    glm::mat4 projection = glm::perspective ( glm::radians ( 60.0f ),
                                              1600.0f / 900.0f,
                                              0.1f,
                                              100.0f );

    glEnable ( GL_DEPTH_TEST );

    while ( RUNNING ) {
        GLPP_CHECK_ERROR ( "GL Error" );

        glClear ( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

        factor += update;
        factor  = factor > 1.0f ? 0.0f : factor;

        if ( factor == 0.0f ) {
            texture_a_unit = --texture_a_unit < 0 ? 2 : texture_a_unit;
            texture_b_unit = --texture_b_unit < 0 ? 2 : texture_b_unit;
            texture_c_unit = --texture_c_unit < 0 ? 2 : texture_c_unit;

            texture_a.bind_texture_unit ( texture_a_unit );
            texture_b.bind_texture_unit ( texture_b_unit );
            texture_c.bind_texture_unit ( texture_c_unit );
        }

        prog.uniform ( "factor",     factor );
        prog.uniform ( "model",      model );
        prog.uniform ( "view",       view );
        prog.uniform ( "projection", projection );
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
