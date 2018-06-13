###############################################################################
#   Build Variables
###############################################################################
set(INSTALL_PREFIX ${CMAKE_INSTALL_PREFIX})
set(INSTALL_DATA ${INSTALL_PREFIX}/share)
set(INSTALL_FONTS ${INSTALL_DATA}/fonts)
set(INSTALL_IMAGES ${INSTALL_DATA}/images)
set(INSTALL_SHADERS ${INSTALL_DATA}/shaders)

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
        ${INCLUDE_DIR}/application.h
        ${INCLUDE_DIR}/aspect.h
        ${INCLUDE_DIR}/aspect_ratio.h
        ${INCLUDE_DIR}/config.h
        ${INCLUDE_DIR}/config_variables.h.in
        ${INCLUDE_DIR}/connector.h
        ${INCLUDE_DIR}/coords.h
        ${INCLUDE_DIR}/dims.h
        ${INCLUDE_DIR}/display.h
        ${INCLUDE_DIR}/environment.h
        ${INCLUDE_DIR}/event.h
        ${INCLUDE_DIR}/event_collector.h
        ${INCLUDE_DIR}/event_connector.h
        ${INCLUDE_DIR}/event_exchange.h
        ${INCLUDE_DIR}/event_logger.h
        ${INCLUDE_DIR}/event_receiver.h
        ${INCLUDE_DIR}/exchange.h
        ${INCLUDE_DIR}/file_reader.h
        ${INCLUDE_DIR}/general_options.h
        ${INCLUDE_DIR}/image_reader.h
        ${INCLUDE_DIR}/json.h
        ${INCLUDE_DIR}/limiter.h
        ${INCLUDE_DIR}/logger.h
        ${INCLUDE_DIR}/macros.h
        ${INCLUDE_DIR}/mouse.h
        ${INCLUDE_DIR}/options.h
        ${INCLUDE_DIR}/pipeline.h
        ${INCLUDE_DIR}/receiver.h
        ${INCLUDE_DIR}/renderer.h
        ${INCLUDE_DIR}/shader_options.h
        ${INCLUDE_DIR}/shader_reader.h
        ${INCLUDE_DIR}/shimmer.h
        ${INCLUDE_DIR}/system.h
        ${INCLUDE_DIR}/video_options.h
        ${INCLUDE_DIR}/window.h )


###############################################################################
#   List project sources.
###############################################################################
set( SOURCES_DIR ${LIB_SHIMMER_ROOT}/sources )

set( SOURCES
        ${SOURCES_DIR}/aspect.cpp
        ${SOURCES_DIR}/aspect_ratio.cpp
        ${SOURCES_DIR}/config.cpp
        ${SOURCES_DIR}/dims.cpp
        ${SOURCES_DIR}/display.cpp
        ${SOURCES_DIR}/environment.cpp
        ${SOURCES_DIR}/event.cpp
        ${SOURCES_DIR}/event_collector.cpp
        ${SOURCES_DIR}/event_logger.cpp
        ${SOURCES_DIR}/file_reader.cpp
        ${SOURCES_DIR}/general_options.cpp
        ${SOURCES_DIR}/image_reader.cpp
        ${SOURCES_DIR}/json.cpp
        ${SOURCES_DIR}/limiter.cpp
        ${SOURCES_DIR}/logger.cpp
        ${SOURCES_DIR}/mouse.cpp
        ${SOURCES_DIR}/options.cpp
        ${SOURCES_DIR}/pipeline.cpp
        ${SOURCES_DIR}/renderer.cpp
        ${SOURCES_DIR}/shader_options.cpp
        ${SOURCES_DIR}/shader_reader.cpp
        ${SOURCES_DIR}/shimmer.cpp
        ${SOURCES_DIR}/system.cpp
        ${SOURCES_DIR}/video_options.cpp
        ${SOURCES_DIR}/window.cpp )

###############################################################################
#   Replace build variables.
###############################################################################
configure_file( ${INCLUDE_DIR}/config_variables.h.in ${INCLUDE_DIR}/config_variables.h )


###############################################################################
#   Build shared library.
###############################################################################
include_directories( ${INCLUDES})
include_directories( SYSTEM ${EXTERNAL_INCLUDES} )

add_library( shimmer SHARED ${HEADERS} ${SOURCES} )
target_include_directories( shimmer PUBLIC ${INCLUDES} ${ALL_INCLUDE_DIRECTORIES} )
target_link_libraries( shimmer common glpp ${TARGET_LINK_LIBRARIES} )


###############################################################################
#   Build catch tests.
###############################################################################
add_subdirectory( catch )


###############################################################################
#   Install libs and shaders
###############################################################################
set_target_properties( shimmer PROPERTIES
                            INSTALL_RPATH_USE_LINK_PATH TRUE
                            INSTALL_RPATH ${CMAKE_INSTALL_PREFIX}/lib )

install( TARGETS shimmer DESTINATION lib )

