###############################################################################
#   Copy data files to binary directory.
###############################################################################
set(DATA_IMG_SRC ${CMAKE_CURRENT_SOURCE_DIR}/data/img)
set(DATA_IMG_DEST ${CMAKE_CURRENT_BINARY_DIR}/data/img)

set(DATA_GLSL_SRC ${CMAKE_CURRENT_SOURCE_DIR}/data/glsl)
set(DATA_GLSL_DEST ${CMAKE_CURRENT_BINARY_DIR}/data/glsl)

configure_file(${DATA_IMG_SRC}/ck4.png ${DATA_IMG_DEST}/ck4.png COPYONLY)
configure_file(${DATA_IMG_SRC}/cursor.png ${DATA_IMG_DEST}/cursor.png COPYONLY)
configure_file(${DATA_IMG_SRC}/doom.gif ${DATA_IMG_DEST}/doom.gif COPYONLY)
configure_file(${DATA_IMG_SRC}/wolf.png ${DATA_IMG_DEST}/wolf.png COPYONLY)

configure_file(${DATA_GLSL_SRC}/example.frag ${DATA_GLSL_DEST}/example.frag COPYONLY)
configure_file(${DATA_GLSL_SRC}/example.vert ${DATA_GLSL_DEST}/example.vert COPYONLY)

###############################################################################
#   Set include directories.
###############################################################################
include_directories(
    ${GLPP_ROOT}/includes
    ${INCLUDES}
    ${EXTERNAL_ROOT}/includes)


###############################################################################
#   SDL2 simple example program.
###############################################################################
add_executable( sdl2_simple sdl2_simple.cpp stb_image.cpp)
target_link_libraries( sdl2_simple ${SDL2_LIBRARIES} )


###############################################################################
#   SDL2 OpenGL example program.
###############################################################################
add_executable( sdl2_opengl sdl2_opengl.cpp stb_image.cpp )
target_link_libraries( sdl2_opengl shimmer glpp ${SDL2_LIBRARIES} )
