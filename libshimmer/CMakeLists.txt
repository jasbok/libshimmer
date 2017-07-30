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
#   Find libpng.
###############################################################################
find_package(PNG)

add_definitions(${PNG_DEFINITIONS})


###############################################################################
#   Find Freetype.
###############################################################################
find_package( Freetype )


###############################################################################
#   Find Threads (pthread needed by spdlog).
###############################################################################
find_package ( Threads )


###############################################################################
#   Configure external include directories.
###############################################################################
set( EXTERNAL_INCLUDE_DIR ${EXTERNAL_ROOT}/includes )

set ( EXTERNAL_INCLUDES
        ${EXTERNAL_INCLUDE_DIR}
        ${FREETYPE_INCLUDE_DIRS}
        ${PNG_INCLUDE_DIRS}
        ${OPENGL_INCLUDES} )


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
        ${INCLUDE_DIR}
        ${INCLUDE_DIR}/api
        ${INCLUDE_DIR}/keyboard
        ${INCLUDE_DIR}/macros
        ${INCLUDE_DIR}/mouse
        ${INCLUDE_DIR}/renderer
        ${INCLUDE_DIR}/renderer/common
        ${INCLUDE_DIR}/renderer/glsl
        ${INCLUDE_DIR}/renderer/opengl
        ${INCLUDE_DIR}/utilities
        ${INCLUDE_DIR}/window )


###############################################################################
#   List all headers, required by some IDEs.
###############################################################################
#file( GLOB_RECURSE HEADERS ${INCLUDE_DIR}/*.h* ${EXTERNAL_INCLUDE_DIR}/*.h* )

set( HEADERS
        ${EXTERNAL_INCLUDE_DIR}/catch/catch.hpp
        ${EXTERNAL_INCLUDE_DIR}/spdlog/spdlog.h
        ${INCLUDE_DIR}/keyboard/keyboard.h
        ${INCLUDE_DIR}/mouse/mouse.h
        ${INCLUDE_DIR}/renderer/common/image.h
        ${INCLUDE_DIR}/renderer/common/texture.h
        ${INCLUDE_DIR}/renderer/opengl/gl_enum.h
        ${INCLUDE_DIR}/renderer/opengl/gl_pixel.h
        ${INCLUDE_DIR}/renderer/opengl/gl_program.h
        ${INCLUDE_DIR}/renderer/opengl/gl_program_manager.h
        ${INCLUDE_DIR}/renderer/opengl/gl_program_variable.h
        ${INCLUDE_DIR}/renderer/opengl/gl_shader.h
        ${INCLUDE_DIR}/renderer/opengl/gl_shader_compiler.h
        ${INCLUDE_DIR}/renderer/opengl/gl_shader_linker.h
        ${INCLUDE_DIR}/renderer/opengl/gl_shader_manager.h
        ${INCLUDE_DIR}/renderer/opengl/gl_texture.h
        ${INCLUDE_DIR}/renderer/opengl/gl_texture_loader.h
        ${INCLUDE_DIR}/renderer/glsl/glsl_qualifier.h
        ${INCLUDE_DIR}/renderer/glsl/glsl_type.h
        ${INCLUDE_DIR}/renderer/glsl/glsl_variable.h
        ${INCLUDE_DIR}/renderer/glsl/glsl_variable_extractor.h
        ${INCLUDE_DIR}/renderer/renderer.h
        ${INCLUDE_DIR}/shimmer.h
        ${INCLUDE_DIR}/utilities/cache.hpp
        ${INCLUDE_DIR}/utilities/file_reader.h
        ${INCLUDE_DIR}/utilities/png_reader.h
        ${INCLUDE_DIR}/utilities/regex_helper.h
        ${INCLUDE_DIR}/utilities/simple_cache.hpp
        ${INCLUDE_DIR}/window/window.h )


###############################################################################
#   List project sources.
###############################################################################
set( SOURCES_DIR ${LIB_SHIMMER_ROOT}/sources )

set( SOURCES
        ${SOURCES_DIR}/keyboard/keyboard.cpp
        ${SOURCES_DIR}/mouse/mouse.cpp
        ${SOURCES_DIR}/renderer/common/image.cpp
        ${SOURCES_DIR}/renderer/common/texture.cpp
        ${SOURCES_DIR}/renderer/opengl/gl_enum.cpp
        ${SOURCES_DIR}/renderer/opengl/gl_pixel.cpp
        ${SOURCES_DIR}/renderer/opengl/gl_program.cpp
        ${SOURCES_DIR}/renderer/opengl/gl_program_manager.cpp
        ${SOURCES_DIR}/renderer/opengl/gl_program_variable.cpp
        ${SOURCES_DIR}/renderer/opengl/gl_shader.cpp
        ${SOURCES_DIR}/renderer/opengl/gl_shader_compiler.cpp
        ${SOURCES_DIR}/renderer/opengl/gl_shader_linker.cpp
        ${SOURCES_DIR}/renderer/opengl/gl_shader_manager.cpp
        ${SOURCES_DIR}/renderer/opengl/gl_texture.cpp
        ${SOURCES_DIR}/renderer/opengl/gl_texture_loader.cpp
        ${SOURCES_DIR}/renderer/glsl/glsl_qualifier.cpp
        ${SOURCES_DIR}/renderer/glsl/glsl_type.cpp
        ${SOURCES_DIR}/renderer/glsl/glsl_variable.cpp
        ${SOURCES_DIR}/renderer/glsl/glsl_variable_extractor.cpp
        ${SOURCES_DIR}/renderer/renderer.cpp
        ${SOURCES_DIR}/shimmer.cpp
        ${SOURCES_DIR}/utilities/file_reader.cpp
        ${SOURCES_DIR}/utilities/png_reader.cpp
        ${SOURCES_DIR}/utilities/regex_helper.cpp
        ${SOURCES_DIR}/window/window.cpp )


###############################################################################
#   Build shared library.
###############################################################################
include_directories( ${INCLUDES} ${EXTERNAL_INCLUDES} )
add_library( shimmer SHARED ${HEADERS} ${SOURCES} )
target_link_libraries( shimmer ${TARGET_LINK_LIBRARIES} )


###############################################################################
#   Build catch tests.
###############################################################################
add_subdirectory( catch )
