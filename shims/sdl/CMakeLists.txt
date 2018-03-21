###############################################################################
#   Find and store SDL paths.
###############################################################################
find_package(SDL)


###############################################################################
#   Set SDL2 shim include directory.
###############################################################################
set( SDL_SHIM_INCLUDE_DIR ${SHIMS_ROOT}/sdl/includes )


###############################################################################
#   Find all header files for SDL2 shim.
###############################################################################
file(GLOB_RECURSE HEADERS ${SDL_SHIM_INCLUDE_DIR}/*.h)


###############################################################################
#   Set include directories.
###############################################################################
set( INCLUDES
        ${ROOT}
        ${SDL_INCLUDE_DIR}
        ${SDL_SHIM_INCLUDE_DIR} )

include_directories(${INCLUDES})


###############################################################################
#   Set sources.
###############################################################################
set( SOURCES
        sources/event.cpp
        sources/mouse.cpp
        sources/shim.cpp
        sources/video.cpp)


###############################################################################
#   Build shim library.
###############################################################################
add_library(shimmer_sdl SHARED ${SOURCES} ${HEADERS})
target_link_libraries(shimmer_sdl shimmer ${ALL_OPENGL_LIBRARIES})


###############################################################################
#   Install libs and shaders
###############################################################################
set_target_properties( shimmer_sdl PROPERTIES
                            INSTALL_RPATH_USE_LINK_PATH TRUE
                            INSTALL_RPATH ${CMAKE_INSTALL_PREFIX}/lib )

install( TARGETS shimmer_sdl DESTINATION lib )
