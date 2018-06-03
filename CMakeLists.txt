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
set( CMAKE_CXX_EXTENSIONS OFF )
set( CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -DDEBUG -std=c++17" )
set( CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall -O3 -std=c++17" )

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

set( API_ROOT ${CMAKE_SOURCE_DIR}/api )
set( COMMON_ROOT ${CMAKE_SOURCE_DIR}/common )
set( EXTERNAL_ROOT ${CMAKE_SOURCE_DIR}/external )
set( GLPP_ROOT ${CMAKE_SOURCE_DIR}/glpp )
set( LIB_SHIMMER_ROOT ${CMAKE_SOURCE_DIR}/libshimmer )
set( SHIMS_ROOT ${CMAKE_SOURCE_DIR}/shims )


###############################################################################
#   Set external include directories.
###############################################################################
set( CATCH_INCLUDES ${EXTERNAL_ROOT}/includes/catch )


###############################################################################
#   Set fmt header and source variables
###############################################################################
set( FMT_INCLUDE_DIR ${EXTERNAL_ROOT}/includes/fmt )
set( FMT_INCLUDE_DIRS ${FMT_INCLUDE_DIR})
set( FMT_HEADERS ${FMT_INCLUDE_DIR}/format.h )
set( FMT_SOURCES ${FMT_INCLUDE_DIR}/format.cc )


###############################################################################
#   Build API generator
###############################################################################
add_subdirectory( apigen )


###############################################################################
#   Build API Tracers
###############################################################################
add_subdirectory( api )


###############################################################################
#   Build common
###############################################################################
add_subdirectory( common )


###############################################################################
#   Build glpp
###############################################################################
add_subdirectory( glpp )


###############################################################################
#   Build libshimmer
###############################################################################
add_subdirectory( libshimmer )


###############################################################################
#   Build individual shims
###############################################################################
add_subdirectory( shims )


###############################################################################
#   Install shaders
###############################################################################
add_subdirectory( shaders )


###############################################################################
#   Print out all cmake variables
###############################################################################
#get_cmake_property(_variableNames VARIABLES)
#list (SORT _variableNames)
#foreach (_variableName ${_variableNames})
#    message(STATUS "${_variableName}=${${_variableName}}")
#endforeach()
