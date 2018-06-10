###############################################################################
#   Copy all data files over.
###############################################################################
set(DATA_SRC ${COMMON_ROOT}/catch/data)
set(DATA_DEST ${CMAKE_CURRENT_BINARY_DIR}/data/)

set (COMMON_CATCH_DATA ${COMMON_ROOT}/catch/data)
configure_file(${DATA_SRC}/file_a.txt ${DATA_DEST}/file_a.txt COPYONLY)
configure_file(${DATA_SRC}/file_b.txt ${DATA_DEST}/file_b.txt COPYONLY)
configure_file(${DATA_SRC}/file_c ${DATA_DEST}/file_c COPYONLY)
configure_file(${DATA_SRC}/file_multiline.txt ${DATA_DEST}/file_multiline.txt COPYONLY)

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
        file.cpp
        str.cpp)


###############################################################################
#   Build shared library
###############################################################################
add_executable( catch_common catch.cpp ${SOURCES} ${CATCH_TESTS} )
#target_link_libraries( catch_common common )
set_target_properties(catch_common PROPERTIES OUTPUT_NAME "catch" )
