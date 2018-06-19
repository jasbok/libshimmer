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
        attribute.h
        buffer.h
        cube.h
        element_array_buffer.h
        entity.h
        enums.h
        framebuffer.h
        mbuffer.h
        mesh.h
        pixels.h
        program.h
        quad.h
        resource_loader.h
        scene.h
        scene_phase.h
        shader.h
        specs.h
        texture.h
        texture_2d.h
        texture_unit.h
        texture_units.h
        uniform.h
        vertex_array.h
        vertex_attrib.h
        vertex_buffer.h)


###############################################################################
#   List GLPP sources.
###############################################################################
set( GLPP_SOURCES
        src/attribute.cpp
        src/debug.cpp
        src/element_array_buffer.cpp
        src/entity.cpp
        src/framebuffer.cpp
        src/pixels.cpp
        src/program.cpp
        src/resource_loader.cpp
        src/scene.cpp
        src/scene_phase.cpp
        src/shader.cpp
        src/texture.cpp
        src/texture_2d.cpp
        src/texture_unit.cpp
        src/texture_units.cpp
        src/uniform.cpp
        src/vertex_array.cpp
        src/vertex_attrib.cpp )


###############################################################################
#   Build GLPP shared library.
###############################################################################
add_library( glpp SHARED ${GLPP_HEADERS} ${GLPP_SOURCES} )

target_include_directories( glpp PRIVATE
    .
    ${ROOT}
    ${ROOT}/external
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
add_subdirectory( examples/sdl2 )
