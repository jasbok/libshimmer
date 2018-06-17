###############################################################################
#   Find and store FreeType paths.
###############################################################################
find_package( Freetype )


###############################################################################
#   List common headers.
###############################################################################
set( COMMON_HEADERS
        atlas.h
        common.h
        coords.h
        dims.h
        env.h
        fonts.h
        file.h
        freetype.h
        img.h
        range.h
        str.h
        unicodes.h )


###############################################################################
#   List common sources.
###############################################################################
set( COMMON_SOURCES
        src/atlas.cpp
        src/env.cpp
        src/file.cpp
        src/fonts.cpp
        src/freetype.cpp
        src/img.cpp
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
