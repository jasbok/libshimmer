###############################################################################
#   Find and store OpenGL, GLEW and GLM paths.
###############################################################################
find_package( GLEW )
find_package( glm )

set( OpenGL_GL_PREFERENCE GLVND )
find_package( OpenGL )

set( OPENGL_INCLUDES
        ${GLEW_INCLUDE_DIRS}
        ${GLM_INCLUDE_DIRS}
        ${OPENGL_INCLUDE_DIR} )

set( OPENGL_LIBRARIES
        ${GLEW_LIBRARIES}
        ${OPENGL_LIBRARIES} )


###############################################################################
#   Find and store FreeType paths.
###############################################################################
find_package( Freetype )

set( FREETYPE_INCLUDES ${FREETYPE_INCLUDE_DIRS} )
set( FREETYPE_LIBRARIES ${FREETYPE_LIBRARIES} )


###############################################################################
#   Configure external include directories.
###############################################################################
set( EXTERNAL_INCLUDE_DIR ${EXTERNAL_ROOT}/includes )

set ( EXTERNAL_INCLUDES
        ${EXTERNAL_INCLUDE_DIR}
        ${FREETYPE_INCLUDES}
        ${OPENGL_INCLUDES} )


###############################################################################
#   List external target link libraries
###############################################################################
set( TARGET_LINK_LIBRARIES
        ${CMAKE_THREAD_LIBS_INIT}
        ${FREETYPE_LIBRARIES}
        ${OPENGL_LIBRARIES} )


###############################################################################
#   Configure GLPP include directories.
###############################################################################
set( INCLUDE_DIR ${GLPP_ROOT}/includes )

set( INCLUDES
        ${ROOT}
        ${INCLUDE_DIR} )


###############################################################################
#   List all headers, required by some IDEs.
###############################################################################
set( HEADERS
        ${EXTERNAL_INCLUDE_DIR}/catch/catch.hpp
        ${INCLUDE_DIR}/atlas_builder.h
        ${INCLUDE_DIR}/attribute.h
        ${INCLUDE_DIR}/bitmap.h
        ${INCLUDE_DIR}/buffer.h
        ${INCLUDE_DIR}/camera.h
        ${INCLUDE_DIR}/cube.h
        ${INCLUDE_DIR}/element_array_buffer.h
        ${INCLUDE_DIR}/entity.h
        ${INCLUDE_DIR}/enums.h
        ${INCLUDE_DIR}/font_loader.h
        ${INCLUDE_DIR}/font_spec.h
        ${INCLUDE_DIR}/framebuffer.h
        ${INCLUDE_DIR}/ft_wrapper.h
        ${INCLUDE_DIR}/ft_wrapper_impl.h
        ${INCLUDE_DIR}/glpp.h
        ${INCLUDE_DIR}/glyph.h
        ${INCLUDE_DIR}/material.h
        ${INCLUDE_DIR}/mbuffer.h
        ${INCLUDE_DIR}/mesh.h
        ${INCLUDE_DIR}/pixels.h
        ${INCLUDE_DIR}/program.h
        ${INCLUDE_DIR}/quad.h
        ${INCLUDE_DIR}/resource_loader.h
        ${INCLUDE_DIR}/scene.h
        ${INCLUDE_DIR}/scene_phase.h
        ${INCLUDE_DIR}/shader.h
        ${INCLUDE_DIR}/specs.h
        ${INCLUDE_DIR}/text.h
        ${INCLUDE_DIR}/texture.h
        ${INCLUDE_DIR}/texture_2d.h
        ${INCLUDE_DIR}/texture_unit.h
        ${INCLUDE_DIR}/texture_units.h
        ${INCLUDE_DIR}/uniform.h
        ${INCLUDE_DIR}/vertex_array.h
        ${INCLUDE_DIR}/vertex_attrib.h
        ${INCLUDE_DIR}/vertex_buffer.h)


###############################################################################
#   List GLPP sources.
###############################################################################
set( SOURCES_DIR ${GLPP_ROOT}/sources )

set( SOURCES
        ${SOURCES_DIR}/attribute.cpp
        ${SOURCES_DIR}/atlas_builder.cpp
        ${SOURCES_DIR}/bitmap.cpp
        ${SOURCES_DIR}/camera.cpp
        ${SOURCES_DIR}/debug.cpp
        ${SOURCES_DIR}/element_array_buffer.cpp
        ${SOURCES_DIR}/entity.cpp
        ${SOURCES_DIR}/font_loader.cpp
        ${SOURCES_DIR}/font_spec.cpp
        ${SOURCES_DIR}/framebuffer.cpp
        ${SOURCES_DIR}/ft_wrapper.cpp
        ${SOURCES_DIR}/ft_wrapper_impl.cpp
        ${SOURCES_DIR}/glyph.cpp
        ${SOURCES_DIR}/material.cpp
        ${SOURCES_DIR}/pixels.cpp
        ${SOURCES_DIR}/program.cpp
        ${SOURCES_DIR}/resource_loader.cpp
        ${SOURCES_DIR}/scene.cpp
        ${SOURCES_DIR}/scene_phase.cpp
        ${SOURCES_DIR}/shader.cpp
        ${SOURCES_DIR}/stb_image.cpp
        ${SOURCES_DIR}/text.cpp
        ${SOURCES_DIR}/texture.cpp
        ${SOURCES_DIR}/texture_2d.cpp
        ${SOURCES_DIR}/texture_unit.cpp
        ${SOURCES_DIR}/texture_units.cpp
        ${SOURCES_DIR}/uniform.cpp
        ${SOURCES_DIR}/vertex_array.cpp)


###############################################################################
#   Build GLPP shared library.
###############################################################################
add_library( glpp SHARED ${HEADERS} ${SOURCES} )
target_include_directories( glpp PUBLIC ${INCLUDES} ${EXTERNAL_INCLUDES} )
target_link_libraries( glpp ${TARGET_LINK_LIBRARIES} )


###############################################################################
#   Install libs and shaders
###############################################################################
install( TARGETS glpp DESTINATION lib )
