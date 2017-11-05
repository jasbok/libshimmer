#include "glpp.h"

#include <SDL2/SDL.h>

SDL_Window*   WINDOW;
SDL_Renderer* RENDERER;

SDL_GLContext GL_CONTEXT;
static const unsigned int SCREEN_WIDTH  = 1600;
static const unsigned int SCREEN_HEIGHT = 900;

static const unsigned int RENDER_TARGET_WIDTH  = 320;
static const unsigned int RENDER_TARGET_HEIGHT = 240;

static const bool USE_FULLSCREEN = false;

glpp::camera camera;
glpp::camera render_target_camera;
glm::vec3    move;
glm::vec3    rotate;
float move_rate   = 1;
float rotate_rate = 1;

bool mouse_left_down  = false;
bool mouse_right_down = false;
glm::ivec2 mouse_coords;

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
        else if ( (event.type == SDL_MOUSEBUTTONDOWN)
                  || (event.type == SDL_MOUSEBUTTONUP) ) {
            bool button_down = (event.type == SDL_MOUSEBUTTONDOWN);

            switch ( event.button.button ) {
            case SDL_BUTTON_LEFT:
                mouse_left_down = button_down;
                break;

            case SDL_BUTTON_RIGHT:
                mouse_right_down = button_down;
                break;
            }
        }
        else if ( (event.type == SDL_KEYDOWN)
                  || (event.type == SDL_KEYUP) ) {
            bool key_down = event.type == SDL_KEYDOWN;

            switch ( event.key.keysym.sym ) {
            case SDLK_q:
                RUNNING = false;
                break;

            case SDLK_w:
                move.z = 1 * key_down;
                break;

            case SDLK_s:
                move.z = -1 * key_down;
                break;

            case SDLK_a:
                move.x = 1 * key_down;
                break;

            case SDLK_d:
                move.x = -1 * key_down;
                break;

            case SDLK_e:
                move.y = 1 * key_down;
                break;

            case SDLK_c:
                move.y = -1 * key_down;
                break;

            case SDLK_LEFT:
                rotate.y = 1 * key_down;
                break;

            case SDLK_RIGHT:
                rotate.y = -1 * key_down;
                break;

            case SDLK_UP:
                rotate.x = -1 * key_down;
                break;

            case SDLK_DOWN:
                rotate.x = 1 * key_down;
                break;
            }
        }
    }
}

void update_camera() {
    glm::ivec2 previous_mouse_coords = mouse_coords;
    SDL_GetMouseState ( &mouse_coords.x, &mouse_coords.y );

    if ( mouse_left_down ) {
        glm::vec3 mouse_rotate {
            mouse_coords.y - previous_mouse_coords.y,
            previous_mouse_coords.x - mouse_coords.x,
            0
        };

        camera.rotate ( mouse_rotate * 0.25f );
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
                                      SCREEN_WIDTH,
                                      SCREEN_HEIGHT,
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

int main ( int argc, char** argv ) {
    init_opengl();

    glpp::shader fragment ( glpp::shader::type::fragment,
        glpp::utils::read_all ( "data/glsl/example.frag" ) );

    if ( !fragment.compile().compile_status() ) {
        std::cerr << "Unable to compile fragment shader:\n"
                  << fragment.info_log()
                  << std::endl;
    }

    glpp::shader vertex ( glpp::shader::type::vertex,
        glpp::utils::read_all ( "data/glsl/example.vert" ) );

    if ( !vertex.compile().compile_status() ) {
        std::cerr << "Unable to compile vertex shader:\n"
                  << vertex.info_log()
                  << std::endl;
    }

    glpp::program program;
    program.attach ( fragment ).attach ( vertex ).link()
        .detach ( fragment ).detach ( vertex );

    if ( !program.link_status() ) {
        std::cerr << "Unable to link shaders into program:\n"
                  << program.info_log()
                  << std::endl;
    }

    program.use()
        .uniform ( "tex_a", 1 )
        .uniform ( "tex_b", 2 );

    glpp::texture_2d texture_a = glpp::utils::texture_2d_from (
        "data/img/ck4.png" );
    glpp::texture_2d texture_b = glpp::utils::texture_2d_from (
        "data/img/wolf.png" );
    glpp::texture_2d texture_c = glpp::utils::texture_2d_from (
        "data/img/doom.gif" );
    glpp::texture_2d texture_cursor = glpp::utils::texture_2d_from (
        "data/img/cursor.png" );

    int texture_a_unit = 1;
    int texture_b_unit = 2;
    int texture_c_unit = 0;

    texture_a.bind_texture_unit ( texture_a_unit )
        .min_filter ( glpp::texture_2d::min_filter::nearest )
        .mag_filter ( glpp::texture_2d::mag_filter::nearest )
        .wrap_s ( glpp::texture_2d::texture_wrap::mirrored_repeat )
        .wrap_t ( glpp::texture_2d::texture_wrap::mirrored_repeat );

    texture_b.bind_texture_unit ( texture_b_unit )
        .min_filter ( glpp::texture_2d::min_filter::nearest )
        .mag_filter ( glpp::texture_2d::mag_filter::nearest )
        .wrap_s ( glpp::texture_2d::texture_wrap::mirrored_repeat )
        .wrap_t ( glpp::texture_2d::texture_wrap::mirrored_repeat );

    texture_c.bind_texture_unit ( texture_c_unit )
        .min_filter ( glpp::texture_2d::min_filter::nearest )
        .mag_filter ( glpp::texture_2d::mag_filter::nearest )
        .wrap_s ( glpp::texture_2d::texture_wrap::mirrored_repeat )
        .wrap_t ( glpp::texture_2d::texture_wrap::mirrored_repeat );


    glpp::framebuffer fbo;

    std::cout << "Creating render texture...\n";
    glpp::texture_2d render_target ( glpp::texture_2d::internal_format::rgb );
    render_target.bind();
    render_target.min_filter ( glpp::texture_2d::min_filter::nearest )
        .mag_filter ( glpp::texture_2d::mag_filter::nearest );
    render_target.image ( glpp::pixels ( nullptr,
                                         { RENDER_TARGET_WIDTH, RENDER_TARGET_HEIGHT },
                                         glpp::pixels::format::rgb,
                                         glpp::pixels::type::gl_unsigned_byte ) );

    render_target.generate_mipmaps();
    fbo.bind().attach_color ( render_target );

    GLPP_CHECK_ERROR ( "Created and attached render target." );

    std::cout << "Creating depth texture...\n";
    glpp::texture_2d render_target_depth ( glpp::texture_2d::internal_format::depth_component );
    render_target_depth.bind();
    render_target_depth.image ( glpp::pixels ( nullptr,
                                               { RENDER_TARGET_WIDTH, RENDER_TARGET_HEIGHT },
                                               glpp::pixels::format::depth_component,
                                               glpp::pixels::type::gl_float ) );

    GLPP_CHECK_ERROR ( "Created render depth target." );

    render_target_depth.generate_mipmaps();
    fbo.attach_depth ( render_target_depth ).unbind();

    GLPP_CHECK_ERROR ( "Attached render depth target." );

    glpp::cube<GLfloat> cube ( { 100.0, 75.0, 100.0 } );
    cube.bind().program ( program );

    glpp::quad<GLfloat> quad ( { 25.0, 25.0 } );
    quad.bind().program ( program );

    float factor = 0.0f;
    float update = 0.001f;

    glm::mat4 cube_model = glm::mat4 ( 1.0f );

    glm::mat4 user_model = glm::scale ( glm::mat4 ( 1.0f ), glm::vec3 ( 0.1, 0.1, 0.1 ) );

    glm::mat4 quad_model = glm::translate ( glm::mat4 ( 1.0f ),
                                            glm::vec3 ( 0.0f, 0.0f, 50.0f ) );
    quad_model = glm::rotate ( quad_model,
                               glm::radians ( 180.0f ),
                               glm::vec3 ( 0.0f, 0.0f, 1.0f ) );

    glm::mat4 projection = glm::perspective ( glm::radians ( 50.0f ),
                                              1600.0f / 900.0f,
                                              0.01f,
                                              1000.0f );

    glEnable ( GL_DEPTH_TEST );

    program.uniform ( "projection", projection );

    while ( RUNNING ) {
        GLPP_CHECK_ERROR ( "GL Error" );

        glClear ( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

        factor += update;
        factor  = factor > 1.0f ? 0.0f : factor;
        program.uniform ( "factor", factor );

        if ( factor == 0.0f ) {
            texture_a_unit = --texture_a_unit < 0 ? 2 : texture_a_unit;
            texture_b_unit = --texture_b_unit < 0 ? 2 : texture_b_unit;
            texture_c_unit = --texture_c_unit < 0 ? 2 : texture_c_unit;
        }

        texture_a.bind_texture_unit ( texture_a_unit );
        texture_b.bind_texture_unit ( texture_b_unit );
        texture_c.bind_texture_unit ( texture_c_unit );

        update_camera();

        program.uniform ( "view", render_target_camera.view() );
        fbo.bind();
        glClear ( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
        glViewport ( 0, 0, RENDER_TARGET_WIDTH, RENDER_TARGET_HEIGHT );
        cube.bind();

        program.uniform ( "model", cube_model );
        cube.draw();

        std::cout << camera.rotation().x << "\n";
        std::cout << camera.rotation().y << "\n";
        std::cout << camera.rotation().z << "\n";

        user_model = glm::translate ( glm::mat4 ( 1.0 ), camera.position() );
        user_model = glm::rotate ( user_model,
                                   glm::radians ( 90.0f ),
                                   camera.rotation() / 360.0f );
        user_model = glm::scale ( user_model, glm::vec3 ( 0.02f, 0.02f, 0.02f ) );


        program.uniform ( "model", user_model );
        cube.draw();

        cube.unbind();
        fbo.unbind();

        glViewport ( 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT );

        program.uniform ( "view", camera
                              .move ( move * move_rate )
                              .rotate ( rotate * rotate_rate )
                              .view() );

        program.uniform ( "model", cube_model );
        cube.bind().draw().unbind();

        render_target.bind();
        render_target.generate_mipmaps();
        render_target.bind_texture_unit ( 0 );
        render_target.bind_texture_unit ( 1 );
        render_target.bind_texture_unit ( 2 );

        // render_target_camera.rotate ( { 0.01f, 0.2f, 0.0f } );

        program.uniform ( "model", quad_model );
        quad.bind().draw().unbind();

        SDL_GL_SwapWindow ( WINDOW );

        SDL_Delay ( 10 );

        poll_events();
    }

    cleanup();
    SDL_Quit();

    return 0;
}
