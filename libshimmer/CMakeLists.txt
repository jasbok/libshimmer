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
        application.h
        aspect.h
        aspect_ratio.h
        config.h
        configuration.h
        config_variables.h.in
        connector.h
        coords.h
        dims.h
        display.h
        environment.h
        event.h
        event_collector.h
        event_connector.h
        event_exchange.h
        event_logger.h
        event_receiver.h
        exchange.h
        file_reader.h
        general_options.h
        image_reader.h
        json.h
        logger.h
        macros.h
        mouse.h
        options.h
        pipeline.h
        receiver.h
        renderer.h
        shader_options.h
        shader_reader.h
        shimmer.h
        system.h
        video_options.h
        window.h )


###############################################################################
#   List project sources.
###############################################################################
set( SOURCES_DIR ${LIB_SHIMMER_ROOT}/sources )

set( SOURCES
        src/aspect.cpp
        src/aspect_ratio.cpp
        src/config.cpp
        src/dims.cpp
        src/display.cpp
        src/environment.cpp
        src/event.cpp
        src/event_collector.cpp
        src/event_logger.cpp
        src/file_reader.cpp
        src/general_options.cpp
        src/image_reader.cpp
        src/json.cpp
        src/logger.cpp
        src/mouse.cpp
        src/options.cpp
        src/pipeline.cpp
        src/renderer.cpp
        src/shader_options.cpp
        src/shader_reader.cpp
        src/shimmer.cpp
        src/system.cpp
        src/video_options.cpp
        src/window.cpp )


###############################################################################
#   Replace build variables.
###############################################################################
configure_file( config_variables.h.in config_variables.h )


###############################################################################
#   Build shared library.
###############################################################################
add_library( shimmer SHARED ${HEADERS} ${SOURCES} )

target_include_directories( shimmer PRIVATE .
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

