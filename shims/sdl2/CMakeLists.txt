###############################################################################
#   Find and store SDL2 paths.
###############################################################################
find_package(SDL2 MODULE REQUIRED)


###############################################################################
#   Set SDL2 shim include directory.
###############################################################################
set( SDL2_SHIM_INCLUDE_DIR ${SHIMS_ROOT}/sdl2/includes )


###############################################################################
#   Find all header files for SDL2 shim.
###############################################################################
file(GLOB_RECURSE HEADERS ${SDL2_SHIM_INCLUDE_DIR}/*.h)


###############################################################################
#   Set include directories.
###############################################################################
set( INCLUDES
        ${ROOT}
        ${SDL2_INCLUDE_DIR}
        ${SDL2_SHIM_INCLUDE_DIR} )

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
add_library(shimmer_sdl2 SHARED ${SOURCES} ${HEADERS})
target_link_libraries(shimmer_sdl2 shimmer ${ALL_OPENGL_LIBRARIES})


###############################################################################
#   Build example programs.
###############################################################################
add_subdirectory( examples )


###############################################################################
#   Install libs and shaders
###############################################################################
set_target_properties( shimmer_sdl2 PROPERTIES
                            INSTALL_RPATH_USE_LINK_PATH TRUE
                            INSTALL_RPATH ${CMAKE_INSTALL_PREFIX}/lib )

install( TARGETS shimmer_sdl2 DESTINATION lib )
