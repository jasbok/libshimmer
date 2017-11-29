###############################################################################
#   Copy default files.
###############################################################################
set(DATA_GLSL_SRC ${CMAKE_CURRENT_SOURCE_DIR}/data/glsl)
set(DATA_GLSL_DEST ${CMAKE_CURRENT_BINARY_DIR}/data/glsl)

configure_file(${DATA_GLSL_SRC}/surface.vert ${DATA_GLSL_DEST}/surface.vert COPYONLY)
configure_file(${DATA_GLSL_SRC}/default.frag ${DATA_GLSL_DEST}/default.frag COPYONLY)


###############################################################################
#   Configure external include directories.
###############################################################################
set( EXTERNAL_INCLUDE_DIR ${EXTERNAL_ROOT}/includes )

set ( EXTERNAL_INCLUDES
        ${EXTERNAL_INCLUDE_DIR} )


###############################################################################
#   List external target link libraries
###############################################################################
set( TARGET_LINK_LIBRARIES
        ${CMAKE_THREAD_LIBS_INIT}
        ${FREETYPE_LIBRARIES}
        ${PNG_LIBRARIES}
        ${OPENGL_LIBRARIES} )


###############################################################################
#   Configure project include directories.
###############################################################################
set( INCLUDE_DIR ${LIB_SHIMMER_ROOT}/includes )

set( INCLUDES
        ${GLPP_ROOT}/includes
        ${INCLUDE_DIR}
        ${INCLUDE_DIR}/macros)


###############################################################################
#   List all headers, required by some IDEs.
###############################################################################
#file( GLOB_RECURSE HEADERS ${INCLUDE_DIR}/*.h* ${EXTERNAL_INCLUDE_DIR}/*.h* )

set( HEADERS
        ${EXTERNAL_INCLUDE_DIR}/catch/catch.hpp
        ${INCLUDE_DIR}/macros.h
        ${INCLUDE_DIR}/options.h
        ${INCLUDE_DIR}/renderer.h
        ${INCLUDE_DIR}/shimmer.h )


###############################################################################
#   List project sources.
###############################################################################
set( SOURCES_DIR ${LIB_SHIMMER_ROOT}/sources )

set( SOURCES
        ${SOURCES_DIR}/options.cpp
        ${SOURCES_DIR}/renderer.cpp
        ${SOURCES_DIR}/shimmer.cpp )


###############################################################################
#   Build shared library.
###############################################################################
include_directories( ${INCLUDES} ${EXTERNAL_INCLUDES} )

add_library( shimmer SHARED ${HEADERS} ${SOURCES} )
target_include_directories( shimmer PUBLIC ${INCLUDES} ${EXTERNAL_INCLUDES} )
target_link_libraries( shimmer glpp ${TARGET_LINK_LIBRARIES} )


###############################################################################
#   Build catch tests.
###############################################################################
#add_subdirectory( catch )
