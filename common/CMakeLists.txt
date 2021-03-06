###############################################################################
#   Find and store FreeType paths.
###############################################################################
find_package( Freetype )


###############################################################################
#   List common headers.
###############################################################################
set( COMMON_HEADERS
        atlas.h
        buffer.h
        camera.h
        common.h
        coords.h
        dims.h
        ellipse.h
        env.h
        fonts.h
        file.h
        freetype.h
        logger.h
        img.h
        json.h
        limiter.h
        range.h
        rectangle.h
        str.h
        series.h
        unicodes.h )


###############################################################################
#   List common sources.
###############################################################################
set( COMMON_SOURCES
        ${ROOT}/external/fmt/format.cc
        ${ROOT}/external/fmt/printf.cc
        src/atlas.cpp
        src/camera.cpp
        src/ellipse.cpp
        src/env.cpp
        src/file.cpp
        src/fonts.cpp
        src/freetype.cpp
        src/logger.cpp
        src/img.cpp
        src/json.cpp
        src/limiter.cpp
        src/rectangle.cpp
        src/str.cpp )


###############################################################################
#   Build common shared library.
###############################################################################
add_library( common SHARED ${COMMON_HEADERS} ${COMMON_SOURCES} )

target_include_directories( common PRIVATE
    .
    ${ROOT}
    ${FREETYPE_INCLUDE_DIRS} )

target_link_libraries( common
    stdc++fs
    ${FREETYPE_LIBRARIES} )

###############################################################################
#   Install libs and shaders
###############################################################################
install( TARGETS common DESTINATION lib )


###############################################################################
#   Build catch tests.
###############################################################################
add_subdirectory( catch )
