###############################################################################
#   Configure include directories.
###############################################################################
include_directories(
    ${ROOT}
    ${CATCH_INCLUDES} )


###############################################################################
#   Collect all test files.
###############################################################################
set ( CATCH_TESTS
        coords.cpp
        dims.cpp
        str.cpp)


###############################################################################
#   Build shared library
###############################################################################
add_executable( catch_common catch.cpp ${SOURCES} ${CATCH_TESTS} )
#target_link_libraries( catch_common common )
set_target_properties(catch_common PROPERTIES OUTPUT_NAME "catch" )
