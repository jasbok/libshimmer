###############################################################################
#   Copy data file over.
###############################################################################
set( DEST ${CMAKE_CURRENT_BINARY_DIR} )

configure_file( example.frag ${DEST}/example.frag COPYONLY )
configure_file( example.vert ${DEST}/example.vert COPYONLY )

configure_file( monster-bash.png ${DEST}/monster-bash.png COPYONLY )

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
    ${EXTERNAL_INCLUDE_DIR}
    ${GLPP_INCLUDE_DIR}
    ${SDL_INCLUDE_DIR} )
