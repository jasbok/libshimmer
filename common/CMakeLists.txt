###############################################################################
#   List common headers.
###############################################################################
set( COMMON_HEADERS
        common.h
        coords.h
        dims.h
        env.h
        file.h
        img.h
        str.h )


###############################################################################
#   List common sources.
###############################################################################
set( COMMON_SOURCES
        env.cpp
        file.cpp
        img.cpp
        str.cpp )


###############################################################################
#   Build common shared library.
###############################################################################
add_library( common SHARED ${COMMON_HEADERS} ${COMMON_SOURCES} )
target_include_directories( common PRIVATE ${EXTERNAL_INCLUDE_DIR} )
target_link_libraries( common stdc++fs )

###############################################################################
#   Install libs and shaders
###############################################################################
install( TARGETS common DESTINATION lib )


###############################################################################
#   Build catch tests.
###############################################################################
add_subdirectory( catch )
