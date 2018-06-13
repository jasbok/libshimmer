###############################################################################
#   Find and store OpenGL, GLEW and GLM paths.
###############################################################################
set( OpenGL_GL_PREFERENCE GLVND )
find_package( OpenGL )
find_package( GLEW )
find_package( glm )


###############################################################################
#   Find and store FreeType paths.
###############################################################################
find_package( Freetype )


###############################################################################
#   List all headers, required by some IDEs.
###############################################################################
set( GLPP_HEADERS
        ${EXTERNAL_INCLUDE_DIR}/catch/catch.hpp
        includes/atlas_builder.h
        includes/attribute.h
        includes/bitmap.h
        includes/buffer.h
        includes/camera.h
        includes/cube.h
        includes/element_array_buffer.h
        includes/entity.h
        includes/enums.h
        includes/font_loader.h
        includes/font_spec.h
        includes/framebuffer.h
        includes/ft_wrapper.h
        includes/ft_wrapper_impl.h
        includes/glpp.h
        includes/glyph.h
        includes/material.h
        includes/mbuffer.h
        includes/mesh.h
        includes/pixels.h
        includes/program.h
        includes/quad.h
        includes/resource_loader.h
        includes/scene.h
        includes/scene_phase.h
        includes/shader.h
        includes/specs.h
        includes/text.h
        includes/texture.h
        includes/texture_2d.h
        includes/texture_unit.h
        includes/texture_units.h
        includes/uniform.h
        includes/vertex_array.h
        includes/vertex_attrib.h
        includes/vertex_buffer.h)


###############################################################################
#   List GLPP sources.
###############################################################################
set( GLPP_SOURCES
        sources/attribute.cpp
        sources/atlas_builder.cpp
        sources/bitmap.cpp
        sources/camera.cpp
        sources/debug.cpp
        sources/element_array_buffer.cpp
        sources/entity.cpp
        sources/font_loader.cpp
        sources/font_spec.cpp
        sources/framebuffer.cpp
        sources/ft_wrapper.cpp
        sources/ft_wrapper_impl.cpp
        sources/glyph.cpp
        sources/material.cpp
        sources/pixels.cpp
        sources/program.cpp
        sources/resource_loader.cpp
        sources/scene.cpp
        sources/scene_phase.cpp
        sources/shader.cpp
        sources/text.cpp
        sources/texture.cpp
        sources/texture_2d.cpp
        sources/texture_unit.cpp
        sources/texture_units.cpp
        sources/uniform.cpp
        sources/vertex_array.cpp
        sources/vertex_attrib.cpp )


###############################################################################
#   Build GLPP shared library.
###############################################################################
add_library( glpp SHARED ${GLPP_HEADERS} ${GLPP_SOURCES} )

target_include_directories( glpp PRIVATE
    includes
    ${ROOT}
    ${EXTERNAL_INCLUDE_DIR}
    ${FREETYPE_INCLUDES}
    ${GLEW_INCLUDE_DIRS}
    ${GLM_INCLUDE_DIRS}
    ${OPENGL_INCLUDE_DIR}
    ${FREETYPE_INCLUDE_DIRS} )

target_link_libraries( glpp PRIVATE
    ${CMAKE_THREAD_LIBS_INIT}
    ${FREETYPE_LIBRARIES}
    ${GLEW_LIBRARIES}
    ${OPENGL_LIBRARIES} )


###############################################################################
#   Install libs and shaders.
###############################################################################
install( TARGETS glpp DESTINATION lib )


###############################################################################
#   Build examples.
###############################################################################
add_subdirectory( examples/sdl )
