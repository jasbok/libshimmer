###############################################################################
#   Copy data files to binary directory.
###############################################################################
set(DATA_SRC ${CMAKE_CURRENT_SOURCE_DIR}/data)
set(DATA_DEST ${CMAKE_CURRENT_BINARY_DIR}/data)

configure_file(${DATA_SRC}/ck4.png ${DATA_DEST}/ck4.png COPYONLY)
configure_file(${DATA_SRC}/cursor.png ${DATA_DEST}/cursor.png COPYONLY)
configure_file(${DATA_SRC}/doom.gif ${DATA_DEST}/doom.gif COPYONLY)
configure_file(${DATA_SRC}/wolf.png ${DATA_DEST}/wolf.png COPYONLY)

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
