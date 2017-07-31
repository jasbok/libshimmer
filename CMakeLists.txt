###############################################################################
#   Main CMake project file.
###############################################################################
cmake_minimum_required( VERSION 3.8 )
project( libshimmer CXX )


###############################################################################
#   Configure Compiler
###############################################################################
set( CMAKE_CXX_STANDARD 14 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )
set( CMAKE_CXX_EXTENSIONS OFF )
set( CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -DDEBUG" )
set( CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall -O3" )


###############################################################################
#   Set Cmake modules path.
###############################################################################
set( CMAKE_MODULE_PATH
        ${CMAKE_MODULE_PATH}
        ${CMAKE_SOURCE_DIR}/cmake/modules/ )


###############################################################################
#   Set libshimmer and shims root directories.
###############################################################################
set( EXTERNAL_ROOT ${CMAKE_SOURCE_DIR}/external )
set( LIB_SHIMMER_ROOT ${CMAKE_SOURCE_DIR}/libshimmer )
set( SHIMS_ROOT ${CMAKE_SOURCE_DIR}/shims )


###############################################################################
#   Build libshimmer
###############################################################################
add_subdirectory( libshimmer )


###############################################################################
#   Build individual shims
###############################################################################
add_subdirectory( shims )
