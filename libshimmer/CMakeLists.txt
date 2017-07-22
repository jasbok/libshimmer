###############################################################################
#   Find and store OpenGL, GLEW and GLM paths.
###############################################################################
find_package(OpenGL)
find_package(GLEW)
find_package(glm)

set( OPENGL_INCLUDES
        ${OPENGL_INCLUDE_DIR}
        ${GLEW_INCLUDE_DIRS}
        ${GLM_INCLUDE_DIRS} )

set( OPENGL_LIBRARIES
        ${OPENGL_LIBRARIES}
        ${GLEW_LIBRARIES} )


###############################################################################
#   Find Freetype.
###############################################################################
find_package(Freetype)


###############################################################################
#   Find Threads (pthread needed by spdlog).
###############################################################################
find_package (Threads)


###############################################################################
#   Configure include directories.
###############################################################################
set( INCLUDE_DIR ${LIB_SHIMMER_ROOT}/includes )
set( SOURCES_DIR ${LIB_SHIMMER_ROOT}/sources )

set( INCLUDES
        ${OPENGL_INCLUDES}
        ${FREETYPE_INCLUDE_DIRS}
        ${INCLUDE_DIR}
        ${INCLUDE_DIR}/api
        ${INCLUDE_DIR}/keyboard
        ${INCLUDE_DIR}/mouse
        ${INCLUDE_DIR}/renderer
        ${INCLUDE_DIR}/renderer/opengl
        ${INCLUDE_DIR}/spdlog
        ${INCLUDE_DIR}/utilities
        ${INCLUDE_DIR}/window )

include_directories(${INCLUDES})


###############################################################################
#   List all headers
###############################################################################
file( GLOB_RECURSE HEADERS ${INCLUDE_DIR}/*.h* )


###############################################################################
#   List sources
###############################################################################
set( SOURCES
        ${SOURCES_DIR}/keyboard/keyboard.cpp
        ${SOURCES_DIR}/mouse/mouse.cpp
        ${SOURCES_DIR}/renderer/opengl/gl_shader_compiler.cpp
        ${SOURCES_DIR}/renderer/opengl/gl_shader_linker.cpp
        ${SOURCES_DIR}/renderer/renderer.cpp
        ${SOURCES_DIR}/shimmer.cpp
        ${SOURCES_DIR}/utilities/file_reader.cpp
        ${SOURCES_DIR}/window/window.cpp )


###############################################################################
#   List target link libraries
###############################################################################
set( TARGET_LINK_LIBRARIES
        ${CMAKE_THREAD_LIBS_INIT}
        ${FREETYPE_LIBRARIES}
        ${OPENGL_LIBRARIES} )

message("TARGET_LINK_LIBRARIES: " ${TARGET_LINK_LIBRARIES})


###############################################################################
#   Build shared library
###############################################################################
add_library( shimmer SHARED ${SOURCES} ${HEADERS} )
target_link_libraries( shimmer ${TARGET_LINK_LIBRARIES} )


###############################################################################
#   Build catch tests
###############################################################################
add_subdirectory( catch )
