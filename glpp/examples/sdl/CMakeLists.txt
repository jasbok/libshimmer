###############################################################################
#   Copy data file over.
###############################################################################
set( DEST ${CMAKE_CURRENT_BINARY_DIR} )

configure_file( ../data/glsl/sdl_example.frag ${DEST}/data/glsl/sdl_example.frag COPYONLY )
configure_file( ../data/glsl/sdl_example.vert ${DEST}/data/glsl/sdl_example.vert COPYONLY )

configure_file( ../data/img/mbash.png ${DEST}/data/img/mbash.png COPYONLY )

###############################################################################
#   Find and store SDL paths.
###############################################################################
find_package( SDL )


###############################################################################
#   Set sources.
###############################################################################
set( SOURCES
        sdl_example.cpp )


###############################################################################
#   Build shim library.
###############################################################################
add_executable( glpp_sdl_example ${SOURCES} ${HEADERS} )

target_link_libraries( glpp_sdl_example
    common
    glpp
    ${SDL_LIBRARY}
    ${GLEW_LIBRARIES}
    ${OPENGL_LIBRARIES} )

target_include_directories( glpp_sdl_example PRIVATE
    ${ROOT}
    ${ROOT}/external
    ${GLPP_INCLUDE_DIR}
    ${SDL_INCLUDE_DIR} )
