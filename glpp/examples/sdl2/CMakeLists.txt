###############################################################################
#   Copy data files to binary directory.
###############################################################################
set(DATA_IMG_SRC ../data/img)
set(DATA_IMG_DEST ${CMAKE_CURRENT_BINARY_DIR}/data/img)

set(DATA_GLSL_SRC ../data/glsl)
set(DATA_GLSL_DEST ${CMAKE_CURRENT_BINARY_DIR}/data/glsl)

set(DATA_GLSL_2_1_SRC ../data/glsl2.1)
set(DATA_GLSL_2_1_DEST ${CMAKE_CURRENT_BINARY_DIR}/data/glsl2.1)

set(DATA_FONTS_SRC ../data/fonts)
set(DATA_FONTS_DEST ${CMAKE_CURRENT_BINARY_DIR}/data/fonts)

configure_file(${DATA_IMG_SRC}/ck4.bmp ${DATA_IMG_DEST}/ck4.bmp COPYONLY)
configure_file(${DATA_IMG_SRC}/ck4.png ${DATA_IMG_DEST}/ck4.png COPYONLY)
configure_file(${DATA_IMG_SRC}/cursor.png ${DATA_IMG_DEST}/cursor.png COPYONLY)
configure_file(${DATA_IMG_SRC}/doom.gif ${DATA_IMG_DEST}/doom.gif COPYONLY)
configure_file(${DATA_IMG_SRC}/wolf.png ${DATA_IMG_DEST}/wolf.png COPYONLY)

configure_file(${DATA_GLSL_2_1_SRC}/example.frag ${DATA_GLSL_2_1_DEST}/example.frag COPYONLY)
configure_file(${DATA_GLSL_2_1_SRC}/example.vert ${DATA_GLSL_2_1_DEST}/example.vert COPYONLY)
configure_file(${DATA_GLSL_2_1_SRC}/default.frag ${DATA_GLSL_2_1_DEST}/default.frag COPYONLY)
configure_file(${DATA_GLSL_2_1_SRC}/xbrz3x.frag ${DATA_GLSL_2_1_DEST}/xbrz3x.frag COPYONLY)
configure_file(${DATA_GLSL_2_1_SRC}/xbrz4x.frag ${DATA_GLSL_2_1_DEST}/xbrz4x.frag COPYONLY)
configure_file(${DATA_GLSL_2_1_SRC}/ui.vert ${DATA_GLSL_2_1_DEST}/ui.vert COPYONLY)

configure_file(${DATA_GLSL_SRC}/example.frag ${DATA_GLSL_DEST}/example.frag COPYONLY)
configure_file(${DATA_GLSL_SRC}/example.vert ${DATA_GLSL_DEST}/example.vert COPYONLY)
configure_file(${DATA_GLSL_SRC}/default.frag ${DATA_GLSL_DEST}/default.frag COPYONLY)
configure_file(${DATA_GLSL_SRC}/ui.vert ${DATA_GLSL_DEST}/ui.vert COPYONLY)

configure_file(${DATA_FONTS_SRC}/mode_seven/MODES___.TTF ${DATA_FONTS_DEST}/MODES___.TTF COPYONLY)
configure_file(${DATA_FONTS_SRC}/xolonium/Xolonium-Regular.ttf ${DATA_FONTS_DEST}/Xolonium-Regular.ttf COPYONLY)
configure_file(${DATA_FONTS_SRC}/xolonium/Xolonium-Bold.ttf ${DATA_FONTS_DEST}/Xolonium-Bold.ttf COPYONLY)
configure_file(${DATA_FONTS_SRC}/xolonium/Xolonium-Regular.otf ${DATA_FONTS_DEST}/Xolonium-Regular.otf COPYONLY)
configure_file(${DATA_FONTS_SRC}/xolonium/Xolonium-Bold.otf ${DATA_FONTS_DEST}/Xolonium-Bold.otf COPYONLY)


###############################################################################
#   Find and store SDL2 paths.
###############################################################################
find_package(SDL2 MODULE REQUIRED)


###############################################################################
#   SDL2 simple example program.
###############################################################################
add_executable( sdl2_simple sdl2_simple.cpp)

target_include_directories(sdl2_simple
    PRIVATE ${EXTERNAL_INCLUDE_DIR} ${SDL2_INCLUDE_DIRS} )

target_link_libraries( sdl2_simple ${SDL2_LIBRARY} )


###############################################################################
#   SDL2 OpenGL example program.
###############################################################################
add_executable( sdl2_opengl sdl2_opengl.cpp)

target_include_directories(sdl2_opengl PRIVATE
    .
    ${ROOT}
    ${ROOT}/external
    ${GLPP_INCLUDE_DIR}
    ${EXTERNAL_INCLUDE_DIR}
    ${SDL2_INCLUDE_DIRS} )

target_link_libraries( sdl2_opengl
    common
    glpp
    ${SDL2_LIBRARY}
    ${CMAKE_THREAD_LIBS_INIT}
    ${FREETYPE_LIBRARIES}
    ${GLEW_LIBRARIES}
    ${OPENGL_LIBRARIES} )
