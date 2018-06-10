#define DEBUG

#include "common/file.h"
#include "glpp/includes/debug.h"
#include "glpp/includes/element_array_buffer.h"
#include "glpp/includes/program.h"
#include "glpp/includes/shader.h"
#include "glpp/includes/vertex_array.h"
#include "glpp/includes/vertex_attrib.h"
#include "glpp/includes/vertex_buffer.h"

#include "SDL.h"

#include <memory>

static const SDL_VideoInfo* VIDEO_INFO = nullptr;
static SDL_Surface* VIDEO              = nullptr;

static bool RUNNING = true;

static std::unique_ptr<glpp::program> PROGRAM;
static std::unique_ptr<glpp::vertex_buffer> VBO;
static std::unique_ptr<glpp::element_array_buffer> EBO;
static std::unique_ptr<glpp::vertex_array> VAO;

void init_sdl() {
    printf ( "[INFO] Initialising SDL...\n" );

    if ( SDL_Init ( SDL_INIT_VIDEO ) < 0 ) {
        printf ( "[ERROR] Failed to initialise SDL: %s\n", SDL_GetError() );

        exit ( 1 );
    }

    atexit ( SDL_Quit );
}

void setup_video() {
    printf ( "[INFO] Configuring video...\n" );

    VIDEO_INFO = SDL_GetVideoInfo();

    if ( VIDEO_INFO == nullptr ) {
        printf ( "[ERROR] Failed to get video info: %s\n", SDL_GetError() );

        exit ( 1 );
    }

    VIDEO = SDL_SetVideoMode ( 640, // VIDEO_INFO->current_w,
                               480, // VIDEO_INFO->current_h,
                               VIDEO_INFO->vfmt->BitsPerPixel,
                               SDL_OPENGL );

    if ( VIDEO == nullptr ) {
        printf ( "[ERROR] Failed to set SDL video mode: %s\n", SDL_GetError() );

        exit ( 1 );
    }
}

void init_glew() {
    printf ( "[INFO] Configuring GLEW...\n" );

    glewExperimental = GL_TRUE;

    GLenum glew_err = glewInit();

    if ( glew_err ) {
        printf ( "[ERROR] Unable to initialise GLEW: %s\n",
                 glewGetErrorString ( glew_err ) );

        exit ( 1 );
    }
}

void setup_shaders() {
    printf ( "[INFO] Configuring shaders...\n" );

    auto vs_source = common::file::read_all ( "example.vert" );
    auto fs_source = common::file::read_all ( "example.frag" );

    auto vs = glpp::shader::create().vertex ( vs_source );
    auto fs = glpp::shader::create().fragment ( fs_source );

    vs.compile_and_throw();
    fs.compile_and_throw();

    PROGRAM = std::make_unique<glpp::program>();

    PROGRAM
        ->attach ( vs )
        .attach ( fs )
        .link_and_throw()
        .detach ( vs )
        .detach ( fs );

    GLPP_CHECK_ERROR ( "Shader setup." );
}

void setup_buffers() {
    printf ( "[INFO] Configuring buffers...\n" );

    std::vector<GLfloat> vertices = {
        // position (2)     // colour (3)
        0.5f,   0.5f, 1.0f, 0.0f, 0.0f,
        -0.5f,  0.5f, 0.0f, 1.0f, 0.0f,
        -0.5f, -0.5f, 1.0f, 0.0f, 1.0f,
        0.5f,  -0.5f, 1.0f, 1.0f, 1.0f
    };

    VBO = std::make_unique<glpp::vertex_buffer>();
    VBO->bind()
        .data ( vertices );
    glpp::vertex_buffer::unbind(); // Call static unbind function.

    std::vector<GLuint> indices = {
        0, 1, 3,
        1, 2, 3
    };

    EBO = std::make_unique<glpp::element_array_buffer>();
    EBO->bind()
        .data ( indices )
        .unbind(); // Chain static unbind()

    GLPP_CHECK_ERROR ( "Buffer setup." );
}

void setup_quad() {
    printf ( "[INFO] Configuring quad...\n" );

    VAO = std::make_unique<glpp::vertex_array>();
    VAO->bind();

    VBO->bind();
    EBO->bind();

    PROGRAM->use();
    auto position_location = PROGRAM->attribute_location ( "position" );
    auto colour_location   = PROGRAM->attribute_location ( "colour" );

    printf ( "[DEBUG] Position attrib location: %i\n", position_location );
    printf ( "[DEBUG] Colour attrib location: %i\n",   colour_location );

    auto vertex_attrib_arrays =
        glpp::vertex_attrib_builder<GLfloat>::sequential ( {
        { "position", 2, position_location },
        { "colour", 3, colour_location }
    } );

    auto& position_attrib_array = vertex_attrib_arrays[0];
    auto& colour_attrib_array   = vertex_attrib_arrays[1];

    position_attrib_array
        .define_pointer()
        .enable_array();

    colour_attrib_array
        .define_pointer()
        .enable_array();

    glpp::vertex_array::unbind();
    glpp::vertex_buffer::unbind();
    glpp::element_array_buffer::unbind();

    // OR use abbreviation typedefs
    // glpp::vao::unbind();
    // glpp::vbo::unbind();
    // glpp::ebo::unbind();

    GLPP_CHECK_ERROR ( "Quad setup." );
}

void setup_opengl() {
    printf ( "[INFO] Configuring OpenGL...\n" );

    init_glew();

    try {
        setup_shaders();
    } catch ( std::runtime_error ex ) {
        printf ( "[SEVERE] Failed to setup shaders => %s\n", ex.what() );
        exit ( 1 );
    }

    setup_buffers();
    setup_quad();
}

void draw_quad() {
    printf ( "[DEBUG] Drawing quad...\n" );
    PROGRAM->use();
    VAO->bind();

    glDrawElements ( GL_TRIANGLES,
                     static_cast<GLint>( EBO->elements() ),
                     GL_UNSIGNED_INT,
                     nullptr );

    glpp::program::unbind();
    glpp::vertex_array::unbind();

    GLPP_CHECK_ERROR ( "Draw Quad." );
}

void cleanup() {
    printf ( "[INFO] Quiting GLPP SDL example.\n" );

    SDL_FreeSurface ( VIDEO );
}

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

        glClearColor ( 0.2f, 0.2f, 0.2f, 1.0 );
        glClear ( GL_COLOR_BUFFER_BIT );

        draw_quad();

        SDL_GL_SwapBuffers();
        SDL_Delay ( 200 );
    }

    cleanup();

    return 0;
}
