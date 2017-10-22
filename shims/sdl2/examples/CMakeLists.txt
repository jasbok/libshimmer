###############################################################################
#   Find and store SDL2 paths.
###############################################################################
find_package(SDL2)


###############################################################################
#   Copy data files to binary directory.
###############################################################################
set(DATA_SRC ${CMAKE_CURRENT_SOURCE_DIR}/data)
set(DATA_DEST ${CMAKE_CURRENT_BINARY_DIR}/data)

configure_file(${DATA_SRC}/ck4.bmp ${DATA_DEST}/ck4.bmp COPYONLY)
configure_file(${DATA_SRC}/ck4.png ${DATA_DEST}/ck4.png COPYONLY)


###############################################################################
#   SDL2 example program.
###############################################################################
include_directories( ${INCLUDES} ${EXTERNAL_INCLUDES} )
add_executable( sdl2_example sdl2_example.cpp )
target_link_libraries( sdl2_example ${SDL2_LIBRARIES} )

