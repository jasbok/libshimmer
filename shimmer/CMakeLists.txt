###############################################################################
#   Copy default files.
###############################################################################
set(DATA_GLSL_SRC ${CMAKE_CURRENT_SOURCE_DIR}/data/glsl)
set(DATA_GLSL_DEST ${CMAKE_CURRENT_BINARY_DIR}/data/glsl)

configure_file(${DATA_GLSL_SRC}/surface.vert ${DATA_GLSL_DEST}/surface.vert COPYONLY)
configure_file(${DATA_GLSL_SRC}/default.frag ${DATA_GLSL_DEST}/default.frag COPYONLY)


###############################################################################
#   List all headers, required by some IDEs.
###############################################################################
set( HEADERS
        configuration.h
        config_variables.h.in
        input.h
        renderer.h
        video.h )


###############################################################################
#   List project sources.
###############################################################################
set( SOURCES_DIR ${LIB_SHIMMER_ROOT}/sources )

set( SOURCES
        src/configuration.cpp
        src/input.cpp
        src/renderer.cpp
        src/video.cpp )


###############################################################################
#   Replace build variables.
###############################################################################
configure_file( config_variables.h.in ${CMAKE_CURRENT_SOURCE_DIR}/config_variables.h )


###############################################################################
#   Build shared library.
###############################################################################
add_library( shimmer SHARED ${HEADERS} ${SOURCES} )

target_include_directories( shimmer PRIVATE
    .
    ${ROOT}
    ${ROOT}/external )

target_link_libraries( shimmer
    common
    glpp
    ${CMAKE_THREAD_LIBS_INIT}
    ${FREETYPE_LIBRARIES}
    ${PNG_LIBRARIES}
    ${OPENGL_LIBRARIES} )


###############################################################################
#   Build catch tests.
###############################################################################
add_subdirectory( catch )


###############################################################################
#   Install libs and shaders
###############################################################################
set( INSTALL_PREFIX ${CMAKE_INSTALL_PREFIX} )
set( INSTALL_DATA ${INSTALL_PREFIX}/share )
set( INSTALL_FONTS ${INSTALL_DATA}/fonts )
set( INSTALL_IMAGES ${INSTALL_DATA}/images )
set( INSTALL_SHADERS ${INSTALL_DATA}/shaders )

set_target_properties( shimmer PROPERTIES
                            INSTALL_RPATH_USE_LINK_PATH TRUE
                            INSTALL_RPATH ${CMAKE_INSTALL_PREFIX}/lib )

install( TARGETS shimmer DESTINATION lib )

