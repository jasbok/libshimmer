#include "common/atlas.h"
#include "common/camera.h"
#include "common/file.h"
#include "common/fonts.h"

#include "glpp/cube.h"
#include "glpp/entity.h"
#include "glpp/framebuffer.h"
#include "glpp/program.h"
#include "glpp/quad.h"
#include "glpp/resource_loader.h"
#include "glpp/scene.h"
#include "glpp/texture_2d.h"

#include <SDL2/SDL.h>

SDL_Window*   WINDOW;
SDL_Renderer* RENDERER;

SDL_GLContext GL_CONTEXT;

static const glpp::dims_2u SCREEN_DIMS     = { 1600, 900 };
static const glpp::dims_2u FBO_RENDER_DIMS = { 320, 240 };

auto camera               = std::make_shared<common::camera>();
auto render_target_camera = std::make_shared<common::camera>();

glm::vec3 move;
glm::vec3 rotate;
float     move_rate   = 2.5f;
float     rotate_rate = 2.5f;

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
        else if ( ( event.type == SDL_MOUSEBUTTONDOWN )
                  || ( event.type == SDL_MOUSEBUTTONUP ) ) {
            bool button_down = ( event.type == SDL_MOUSEBUTTONDOWN );

            switch ( event.button.button ) {
            case SDL_BUTTON_LEFT:
                mouse_left_down = button_down;
                break;

            case SDL_BUTTON_RIGHT:
                mouse_right_down = button_down;
                break;
            }
        }
        else if ( ( event.type == SDL_KEYDOWN )
                  || ( event.type == SDL_KEYUP ) ) {
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

        camera->rotate ( mouse_rotate * 0.25f );
    }

    camera->
        move ( move * move_rate )
        .rotate ( rotate * rotate_rate );
}

void update_cursor ( const std::shared_ptr<glpp::entity>& cursor ) {
    SDL_GetMouseState ( &mouse_coords.x, &mouse_coords.y );
    cursor->position ( { mouse_coords.x, mouse_coords.y, 0 } );
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

    if ( ( WINDOW = SDL_CreateWindow ( "SDL2 Example",
                                       100,
                                       100,
                                       SCREEN_DIMS.width,
                                       SCREEN_DIMS.height,
                                       SDL_WINDOW_OPENGL |
                                       SDL_WINDOW_SHOWN ) ) == nullptr ) {
        return sdl_error ( "Error) Unable to create SDL2 window: " );
    }

    SDL_GL_SetAttribute ( SDL_GL_CONTEXT_PROFILE_MASK,
                          SDL_GL_CONTEXT_PROFILE_CORE );

    SDL_GL_SetAttribute ( SDL_GL_CONTEXT_MAJOR_VERSION, 3 );
    SDL_GL_SetAttribute ( SDL_GL_CONTEXT_MINOR_VERSION, 3 );
    SDL_GL_SetAttribute ( SDL_GL_DOUBLEBUFFER,          1 );

    SDL_ShowCursor ( 0 );


    if ( ( GL_CONTEXT = SDL_GL_CreateContext ( WINDOW ) ) == nullptr ) {
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

std::shared_ptr<glpp::texture_2d> load_texture ( const std::string& path ) {
    auto img_path = common::file::find ( path, { "data/img" } );
    auto img      = common::img::read ( img_path );

    auto tex = std::make_shared<glpp::texture_2d>();

    tex->bind();
    tex->image ( img )
        .filters ( glpp::texture_2d::filter::nearest )
        .wrap ( glpp::texture_2d::texture_wrap::mirrored_repeat )
        .unbind();

    return tex;
}

std::shared_ptr<glpp::texture_2d> create_rgb_texture ( const glpp::dims_2u& dims )
{
    auto tex = std::make_shared<glpp::texture_2d>();


    tex->bind();
    tex->image ( glpp::texture_2d::internal_format::rgb, dims )
        .min_filter ( glpp::texture_2d::min_filter::nearest )
        .mag_filter ( glpp::texture_2d::mag_filter::nearest );


    tex->generate_mipmaps();

    return tex;
}

std::shared_ptr<glpp::texture_2d> create_depth_texture (
    const glpp::dims_2u& dims )
{
    auto tex = std::make_shared<glpp::texture_2d>();

    tex->bind();
    tex->image ( glpp::texture_2d::internal_format::depth_component, dims );
    tex->generate_mipmaps();

    return tex;
}

std::shared_ptr<glpp::framebuffer> create_framebuffer (
    const glpp::texture_2d& colour,
    const glpp::texture_2d& depth ) {
    auto fbo = std::make_shared<glpp::framebuffer>();

    fbo->bind()
        .attach_color ( colour )
        .attach_depth ( depth )
        .unbind();

    return fbo;
}

int main ( int argc, char** argv ) {
#ifdef DEBUG
    printf ( "======= Debug Build Active =======\n" );
#endif // ifdef DEBUG

    init_opengl();

    glpp::resource_loader loader ( { "data/glsl" } );

    auto texture_a      = load_texture ( "ck4.bmp" );
    auto texture_b      = load_texture ( "wolf.png" );
    auto texture_c      = load_texture ( "doom.gif" );
    auto texture_cursor = load_texture ( "cursor.png" );

    auto render_target       = create_rgb_texture ( FBO_RENDER_DIMS );
    auto render_target_depth = create_depth_texture ( FBO_RENDER_DIMS );

    auto fbo = create_framebuffer ( *render_target, *render_target_depth );

    auto cube = glpp::cube<GLfloat>::make_shared ( { 1.0f, 1.0f, 1.0f } );

    auto cube_textures = glpp::texture_units::make_shared ( { texture_c,
                                                              texture_b,
                                                              texture_a } );
    auto program =
        std::make_shared<glpp::program>( loader.program ( "example.vert",
                                                          "example.frag" ) );
    program->use().uniform ( "texture_a", 0 ).uniform ( "texture_b", 1 );

    auto outer_cube = std::make_shared<glpp::entity>();
    outer_cube->
        program ( program )
        .textures ( cube_textures )
        .mesh ( cube )
        .scale ( { 500.0, 250.0, 500.0 } );

    auto avatar = std::make_shared<glpp::entity>();
    avatar->
        program ( program )
        .textures ( cube_textures )
        .mesh ( cube )
        .scale ( { 5.0, 5.0, 10.0 } );


    auto quad = glpp::quad<GLfloat>::make_shared ( { 1.0, 0.75 } );

    auto mirror_textures = glpp::texture_units::make_shared ( { render_target,
                                                                render_target,
                                                                render_target } );
    auto mirror = std::make_shared<glpp::entity>();
    mirror->
        program ( program )
        .textures ( mirror_textures )
        .mesh ( quad )
        .position ( { 0.0f, 0.0f, 100.0f } )
        .rotation ( { 0.0f, 180.0f, 180.0f } )
        .scale ( { 25.0f, 25.0f, 25.0f } );


    auto cursor_program = std::make_shared<glpp::program>(
        loader.program ( "ui.vert",
                         "default.frag" ) );

    program->use().uniform ( "tex", 0 );


    auto cursor_textures =
        glpp::texture_units::make_shared ( { texture_cursor } );

    auto cursor_quad =
        glpp::quad<GLfloat>::make_shared ( texture_cursor->dims() );

    auto cursor = std::make_shared<glpp::entity>();
    cursor->
        program ( cursor_program )
        .textures ( cursor_textures )
        .mesh ( cursor_quad )
        .rotate ( { 180, 0, 0 } )
        .scale ( { 0.25, 0.25, 1 } );


    std::vector<common::range_uint> unicodes = {
        common::unicodes::basic_latin,
        common::unicodes::latin_1_supplement,
    };

    auto mode7_path = common::file::find ( "MODES___.TTF", { "data/fonts" } );

    auto xol_reg_path = common::file::find ( "Xolonium-Regular.ttf",
                                             { "data/fonts" } );

    auto xol_bold_path = common::file::find ( "Xolonium-Bold.ttf",
                                              { "data/fonts" } );

    auto glyphs = common::fonts::load ( {
        { "mode_seven_13", mode7_path, 13, unicodes },
        { "xolonium_regular_13", xol_reg_path, 13, unicodes },
        { "xolonium_bold_13", xol_bold_path, 13, unicodes },
        { "mode_seven_21", mode7_path, 24, unicodes },
        { "xolonium_regular_21", xol_reg_path, 24, unicodes },
        { "xolonium_bold_21", xol_bold_path, 24, unicodes }
    }, 96 );

    common::atlas::sort ( glyphs.bitmaps );
    auto atlas = common::atlas::build ( glyphs.bitmaps );

    auto atlas_texture = std::make_shared<glpp::texture_2d>();

    atlas_texture->bind();
    atlas_texture->image ( atlas.texture );
    atlas_texture->generate_mipmaps();

    auto atlas_textures = glpp::texture_units::make_shared ( { atlas_texture,
                                                               atlas_texture,
                                                               atlas_texture } );

    auto font_atlas = std::make_shared<glpp::entity>();
    font_atlas->
        program ( program )
        .textures ( atlas_textures )
        .mesh ( quad )
        .position ( { 100.0f, 0.0f, 0.0f } )
        .rotation ( { 0.0f, -90.0f, 0.0f } )
        .scale ( { 25.0f, 25.0f, 25.0f } );

    render_target_camera->
        position ( { 0.0f, 0.0f, 150.0f } )
        .rotation ( { 0.0f, 180.0f, 0.0f } )
        .perspective ( 30.0f, 1.0f, 0.1f, 1000.0f );

    auto mirror_viewport = std::make_shared<glpp::viewport_int>();
    mirror_viewport->dims = FBO_RENDER_DIMS;

    glpp::scene_phase mirror_scene ( "mirror",
        render_target_camera,
        mirror_viewport,
        fbo );

    mirror_scene
        .add ( outer_cube )
        .add ( avatar )
        .capabilities ( { GL_DEPTH_TEST } )
        .clear_bits ( { GL_COLOR_BUFFER_BIT, GL_DEPTH_BUFFER_BIT } );


    auto main_viewport = std::make_shared<glpp::viewport_int>();
    main_viewport->dims = SCREEN_DIMS;

    camera->perspective ( 50,
                          SCREEN_DIMS.wh_ratio(),
                          0.01f,
                          2000.0f );

    glpp::scene_phase main_scene ( "main",
        camera,
        main_viewport );

    main_scene
        .add ( outer_cube )
        .add ( mirror )
        .add ( font_atlas )
        .capabilities ( { GL_DEPTH_TEST } )
        .clear_bits ( { GL_COLOR_BUFFER_BIT, GL_DEPTH_BUFFER_BIT } );

    glpp::scene_phase ui_scene ( "ui" );
    ui_scene.camera()->screen ( SCREEN_DIMS );
    ui_scene
        .add ( cursor )
        .capabilities ( { GL_BLEND } )
        .blend_function ( { GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA } );

    glpp::scene scene;

    scene.add ( std::move ( mirror_scene ) );

    scene.add ( std::move ( main_scene ) );
    scene.add ( std::move ( ui_scene ) );

    float factor = 0.0f;
    float update = 0.0005f;

    while ( RUNNING ) {
        factor += update;
        factor  = factor > 1.0f ? 0.0f : factor;

        program->use();
        program->uniform ( "blend_factor", factor );

        if ( factor == 0.0f ) {
            auto& textures = cube_textures->textures();
            auto  back     = textures.back();
            textures.pop_back();
            textures.insert ( textures.begin(), back );
        }

        update_camera();
        avatar->
            position ( camera->position() )
            .rotation ( camera->rotation() * glm::vec3 ( -1.0f, 1.0f, 1.0f ) );

        update_cursor ( cursor );

        scene.draw();

        SDL_GL_SwapWindow ( WINDOW );

        poll_events();

        SDL_Delay ( 10 );
    }

    cleanup();
    SDL_Quit();

    return 0;
}
