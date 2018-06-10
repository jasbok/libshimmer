###############################################################################
#   Copy data file over.
###############################################################################
set(SDL_DATA_SRC ${GLPP_ROOT}/examples/sdl)
set(SDL_DATA_DEST ${CMAKE_CURRENT_BINARY_DIR})

set (COMMON_CATCH_DATA ${COMMON_ROOT}/catch/data)
configure_file(${SDL_DATA_SRC}/example.frag ${SDL_DATA_DEST}/example.frag COPYONLY)
configure_file(${SDL_DATA_SRC}/example.vert ${SDL_DATA_DEST}/example.vert COPYONLY)

###############################################################################
#   Find and store SDL paths.
###############################################################################
find_package( SDL )


###############################################################################
#   Set include directories.
###############################################################################
set( INCLUDES
        ${SDL_INCLUDE_DIR}
        ${GLPP_ROOT}/includes )

include_directories( ${INCLUDES} )


###############################################################################
#   Set sources.
###############################################################################
set( SOURCES
        sdl_example.cpp )


###############################################################################
#   Build shim library.
###############################################################################
add_executable( glpp_sdl_example ${SOURCES} ${HEADERS} )
target_link_libraries( glpp_sdl_example common glpp ${SDL_LIBRARY} ${ALL_OPENGL_LIBRARIES} )
