###############################################################################
#   Copy data file over.
###############################################################################
set( DEST ${CMAKE_CURRENT_BINARY_DIR} )

configure_file( data/example.frag ${DEST}/data/example.frag COPYONLY )
configure_file( data/example.vert ${DEST}/data/example.vert COPYONLY )

configure_file( data/monster-bash.png ${DEST}/data/monster-bash.png COPYONLY )

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
