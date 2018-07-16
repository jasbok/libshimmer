###############################################################################
#   Find and store SDL2 paths.
###############################################################################
find_package( SDL2 MODULE REQUIRED )


###############################################################################
#   Set SDL2 shim include directory.
###############################################################################
set( SDL2_SHIM_INCLUDE_DIR ${SHIMS_ROOT}/sdl2/includes )


###############################################################################
#   Find all header files for SDL2 shim.
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
        src/sdl2.cpp
        src/shim.cpp
        src/video.cpp
        src/window.cpp )


###############################################################################
#   Build shim library.
###############################################################################
add_library(shimmer_sdl2 SHARED ${SOURCES} ${HEADERS})

target_include_directories( shimmer_sdl2 PRIVATE
    .
    ${ROOT}
    ${ROOT}/external
    ${SDL2_INCLUDE_DIR} )

target_link_libraries( shimmer_sdl2
    shimmer )


###############################################################################
#   Install libs and shaders
###############################################################################
set_target_properties( shimmer_sdl2 PROPERTIES
                            INSTALL_RPATH_USE_LINK_PATH TRUE
                            INSTALL_RPATH ${CMAKE_INSTALL_PREFIX}/lib )

install( TARGETS shimmer_sdl2 DESTINATION lib )
