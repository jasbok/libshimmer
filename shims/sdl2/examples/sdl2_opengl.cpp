#include "glpp.h"

#include <SDL2/SDL.h>

SDL_Window*   WINDOW;
SDL_Renderer* RENDERER;

SDL_GLContext GL_CONTEXT;
static const unsigned int SCREEN_WIDTH  = 800;
static const unsigned int SCREEN_HEIGHT = 480;

static const unsigned int RENDER_TARGET_WIDTH  = 320;
static const unsigned int RENDER_TARGET_HEIGHT = 240;

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
                rotate.y = -1 * key_down;
                break;

            case SDLK_RIGHT:
                rotate.y = 1 * key_down;
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
            mouse_coords.x - previous_mouse_coords.x,
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

    glpp::resource_loader loader ( { "data/glsl", "data/img" } );

    glpp::program program = loader.program ( "example.vert", "example.frag" );
    program.use().uniform ( "texture_a", 1 ).uniform ( "texture_b", 2 );

    glpp::texture_2d texture_a      = loader.texture_2d ( "ck4.png" );
    glpp::texture_2d texture_b      = loader.texture_2d ( "wolf.png" );
    glpp::texture_2d texture_c      = loader.texture_2d ( "doom.gif" );
    glpp::texture_2d texture_cursor = loader.texture_2d ( "cursor.png" );

    int texture_a_unit = 1;
    int texture_b_unit = 2;
    int texture_c_unit = 0;

    texture_a.bind_texture_unit ( texture_a_unit )
        .filters ( glpp::texture_2d::filter::nearest )
        .wrap ( glpp::texture_2d::texture_wrap::mirrored_repeat );

    texture_b.bind_texture_unit ( texture_b_unit )
        .filters ( glpp::texture_2d::filter::nearest )
        .wrap ( glpp::texture_2d::texture_wrap::mirrored_repeat );

    texture_c.bind_texture_unit ( texture_c_unit )
        .filters ( glpp::texture_2d::filter::nearest )
        .wrap ( glpp::texture_2d::texture_wrap::mirrored_repeat );

    glpp::framebuffer fbo;

    glpp::texture_2d render_target ( glpp::texture_2d::internal_format::rgb );
    render_target.bind();
    render_target.min_filter ( glpp::texture_2d::min_filter::nearest )
        .mag_filter ( glpp::texture_2d::mag_filter::nearest );
    render_target.image ( glpp::pixels ( nullptr,
                                         { RENDER_TARGET_WIDTH,
                                           RENDER_TARGET_HEIGHT },
                                         glpp::pixels::format::rgb,
                                         glpp::pixels::type::gl_unsigned_byte ) );

    fbo.bind().attach_color ( render_target );

    glpp::texture_2d render_target_depth (
        glpp::texture_2d::internal_format::depth_component );
    render_target_depth.bind();
    render_target_depth.image ( glpp::pixels ( nullptr,
                                               { RENDER_TARGET_WIDTH,
                                                 RENDER_TARGET_HEIGHT },
                                               glpp::pixels::format::
                                                   depth_component,
                                               glpp::pixels::type::gl_float ) );

    fbo.attach_depth ( render_target_depth ).unbind();

    glpp::cube<GLfloat> cube ( { 1.0, 1.0, 1.0 } );
    cube.bind().program ( program );

    glpp::quad<GLfloat> quad ( { 1.0, 0.75 } );
    quad.bind().program ( program );


    glpp::entity outer_cube;
    outer_cube.scale ( { 500.0, 250.0, 500.0 } );

    glpp::entity avatar;
    avatar.scale ( { 5.0, 5.0, 10.0 } );

    glpp::entity mirror;
    mirror.position ( { 0.0f, 0.0f, 100.0f } )
        .rotation ( { 0.0f, 180.0f, 180.0f } )
        .scale ( { 25.0f, 25.0f, 25.0f } );

    glpp::entity font_atlas;
    font_atlas.position ( { 100.0f, 0.0f, 0.0f } )
        .rotation ( { 0.0f, -90.0f, 0.0f } )
        .scale ( { 25.0f, 25.0f, 25.0f } );

    render_target_camera
        .position ( { 0.0f, 0.0f, 150.0f } )
        .rotation ( { 0.0f, 180.0f, 0.0f } );

    glm::mat4 projection = glm::perspective ( glm::radians ( 50.0f ),
                                              1600.0f / 900.0f,
                                              0.01f,
                                              2000.0f );


    glEnable ( GL_DEPTH_TEST );

    program.uniform ( "projection", projection );

    float factor = 0.0f;
    float update = 0.001f;

    glpp::font_loader font_loader ( { "data/fonts", "/usr/share/fonts/TTF" } );
    glpp::font_atlas  font ( font_loader.load ( "MODES___.TTF", 21, 96 ) );

    while ( RUNNING ) {
        GLPP_CHECK_ERROR ( "GL Error" );

        glClear ( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

        factor += update;
        factor  = factor > 1.0f ? 0.0f : factor;
        program.uniform ( "blend_factor", factor );

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
        program.uniform ( "projection",
                          glm::perspective ( glm::radians ( 30.0f ),
                                             1.0f,
                                             0.1f,
                                             1000.0f ) );
        glClear ( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
        glViewport ( 0, 0, RENDER_TARGET_WIDTH, RENDER_TARGET_HEIGHT );

        cube.bind();

        avatar.position ( camera.position() ).rotation (
            camera.rotation() * glm::vec3 ( -1.0f, 1.0f, 1.0f ) );
        program.uniform ( "model", avatar.model() );
        cube.draw();

        program.uniform ( "model", outer_cube.model() );
        cube.draw();

        cube.unbind();
        fbo.unbind();

        program.uniform ( "projection", projection );
        glViewport ( 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT );

        program.uniform ( "view", camera
                              .move ( move * move_rate )
                              .rotate ( rotate * rotate_rate )
                              .view() );

        program.uniform ( "model", outer_cube.model() );
        cube.bind().draw().unbind();

        render_target.bind();
        render_target.generate_mipmaps();
        render_target.bind_texture_unit ( 0 );
        render_target.bind_texture_unit ( 1 );
        render_target.bind_texture_unit ( 2 );

        program.uniform ( "model", mirror.model() );
        quad.bind().draw().unbind();

        font.texture().bind();
        font.texture().generate_mipmaps();
        font.texture().bind_texture_unit ( 0 );
        font.texture().bind_texture_unit ( 1 );
        font.texture().bind_texture_unit ( 2 );

        program.uniform ( "model", font_atlas.model() );
        quad.bind().draw().unbind();

        SDL_GL_SwapWindow ( WINDOW );

        SDL_Delay ( 10 );

        poll_events();
    }

    cleanup();
    SDL_Quit();

    return 0;
}
