###############################################################################
#   Find and store OpenGL, GLEW and GLM paths.
###############################################################################
find_package( GLEW )
find_package( glm )
find_package( OpenGL )

set( OPENGL_INCLUDES
        ${GLEW_INCLUDE_DIRS}
        ${GLM_INCLUDE_DIRS}
        ${OPENGL_INCLUDE_DIR} )

set( OPENGL_LIBRARIES
        ${GLEW_LIBRARIES}
        ${OPENGL_LIBRARIES} )


###############################################################################
#   Configure external include directories.
###############################################################################
set( EXTERNAL_INCLUDE_DIR ${EXTERNAL_ROOT}/includes )

set ( EXTERNAL_INCLUDES
        ${EXTERNAL_INCLUDE_DIR}
        ${OPENGL_INCLUDES} )


###############################################################################
#   List external target link libraries
###############################################################################
set( TARGET_LINK_LIBRARIES
        ${CMAKE_THREAD_LIBS_INIT}
        ${OPENGL_LIBRARIES} )


###############################################################################
#   Configure GLPP include directories.
###############################################################################
set( INCLUDE_DIR ${GLPP_ROOT}/includes )

set( INCLUDES
        ${INCLUDE_DIR} )


###############################################################################
#   List all headers, required by some IDEs.
###############################################################################
set( HEADERS
        ${EXTERNAL_INCLUDE_DIR}/catch/catch.hpp
        ${INCLUDE_DIR}/attribute.h
        ${INCLUDE_DIR}/buffer.h
        ${INCLUDE_DIR}/camera.h
        ${INCLUDE_DIR}/cube.h
        ${INCLUDE_DIR}/element_array_buffer.h
        ${INCLUDE_DIR}/enums.h
        ${INCLUDE_DIR}/framebuffer.h
        ${INCLUDE_DIR}/glpp.h
        ${INCLUDE_DIR}/mbuffer.h
        ${INCLUDE_DIR}/mesh.h
        ${INCLUDE_DIR}/pixels.h
        ${INCLUDE_DIR}/program.h
        ${INCLUDE_DIR}/quad.h
        ${INCLUDE_DIR}/shader.h
        ${INCLUDE_DIR}/specs.h
        ${INCLUDE_DIR}/texture.h
        ${INCLUDE_DIR}/texture_2d.h
        ${INCLUDE_DIR}/uniform.h
        ${INCLUDE_DIR}/utils.h
        ${INCLUDE_DIR}/vertex_array.h
        ${INCLUDE_DIR}/vertex_attrib.h
        ${INCLUDE_DIR}/vertex_buffer.h)


###############################################################################
#   List GLPP sources.
###############################################################################
set( SOURCES_DIR ${GLPP_ROOT}/sources )

set( SOURCES
        ${SOURCES_DIR}/attribute.cpp
        ${SOURCES_DIR}/camera.cpp
        ${SOURCES_DIR}/element_array_buffer.cpp
        ${SOURCES_DIR}/framebuffer.cpp
        ${SOURCES_DIR}/pixels.cpp
        ${SOURCES_DIR}/program.cpp
        ${SOURCES_DIR}/shader.cpp
        ${SOURCES_DIR}/stb_image.cpp
        ${SOURCES_DIR}/texture.cpp
        ${SOURCES_DIR}/texture_2d.cpp
        ${SOURCES_DIR}/uniform.cpp
        ${SOURCES_DIR}/utils.cpp
        ${SOURCES_DIR}/vertex_array.cpp)


###############################################################################
#   Build GLPP shared library.
###############################################################################
include_directories( ${INCLUDES} ${EXTERNAL_INCLUDES} )
add_library( glpp SHARED ${HEADERS} ${SOURCES} )
target_link_libraries( glpp ${TARGET_LINK_LIBRARIES} )
