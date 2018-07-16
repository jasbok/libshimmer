###############################################################################
#   Main CMake project file.
###############################################################################
cmake_minimum_required( VERSION 3.8 )
project( libshimmer CXX )


###############################################################################
#   Configure Compiler
###############################################################################
set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )
set( CMAKE_CXX_EXTENSIONS ON )
set( CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -DDEBUG" )
set( CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall -O3" )

###############################################################################
#   Set Cmake modules path.
###############################################################################
set( CMAKE_MODULE_PATH
        ${CMAKE_MODULE_PATH}
        ${CMAKE_SOURCE_DIR}/cmake/modules/ )


###############################################################################
#   Set root directories.
###############################################################################
set( ROOT ${CMAKE_SOURCE_DIR} )


###############################################################################
#   Set external include directories.
###############################################################################
set( CATCH_INCLUDES ${EXTERNAL_ROOT}/includes/catch )


###############################################################################
#   Set fmt header and source variables
###############################################################################
set( FMT_INCLUDE_DIR ${ROOT}/external/fmt )
set( FMT_HEADERS ${FMT_INCLUDE_DIR}/format.h )
set( FMT_SOURCES ${FMT_INCLUDE_DIR}/format.cc )


###############################################################################
#   Build libraries
###############################################################################
add_subdirectory( apigen )
add_subdirectory( api )
add_subdirectory( common )
add_subdirectory( glpp )
add_subdirectory( shimmer )
add_subdirectory( shims/sdl )
add_subdirectory( shims/sdl2 )
add_subdirectory( shaders )
