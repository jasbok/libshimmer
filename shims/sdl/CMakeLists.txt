###############################################################################
#   Find and store SDL paths.
###############################################################################
find_package( SDL )

###############################################################################
#   Set SDL2 shim include directory.
###############################################################################
set( SDL_SHIM_INCLUDE_DIR ${SHIMS_ROOT}/sdl/includes )


###############################################################################
#   Find all header files for SDL shim.
###############################################################################
set( HEADERS
        events.h
        input.h
        shim.h
        video.h
        window.h )


###############################################################################
#   Set sources.
###############################################################################
set( SOURCES
        src/events.cpp
        src/input.cpp
        src/sdl.cpp
        src/shim.cpp
        src/video.cpp
        src/window.cpp )


###############################################################################
#   Build shim library.
###############################################################################
add_library( shimmer_sdl SHARED ${SOURCES} ${HEADERS} )

target_include_directories( shimmer_sdl PRIVATE .
    ${ROOT}
    ${ROOT}/external
    ${SDL_INCLUDE_DIR} )

target_link_libraries( shimmer_sdl
    common
    glpp
    shimmer )


###############################################################################
#   Install libs and shaders
###############################################################################
set_target_properties( shimmer_sdl PROPERTIES
                            INSTALL_RPATH_USE_LINK_PATH TRUE
                            INSTALL_RPATH ${CMAKE_INSTALL_PREFIX}/lib )

install( TARGETS shimmer_sdl DESTINATION lib )
