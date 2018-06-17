###############################################################################
#   Copy all data files over.
###############################################################################
set( DATA_SRC ${CMAKE_CURRENT_SOURCE_DIR}/data )
set( DATA_DEST ${CMAKE_CURRENT_BINARY_DIR}/data )

configure_file( ${DATA_SRC}/text/file_a.txt ${DATA_DEST}/text/file_a.txt COPYONLY )
configure_file( ${DATA_SRC}/text/file_b.txt ${DATA_DEST}/text/file_b.txt COPYONLY )
configure_file( ${DATA_SRC}/text/file_c ${DATA_DEST}/text/file_c COPYONLY )
configure_file( ${DATA_SRC}/text/file_multiline.txt ${DATA_DEST}/text/file_multiline.txt COPYONLY )

configure_file( ${DATA_SRC}/image/test.png ${DATA_DEST}/image/test.png COPYONLY )
configure_file( ${DATA_SRC}/image/test.jpg ${DATA_DEST}/image/test.jpg COPYONLY )

configure_file( ${DATA_SRC}/search_test_a ${DATA_DEST}/search_test_a COPYONLY )
configure_file( ${DATA_SRC}/text/search_test_a ${DATA_DEST}/text/search_test_a COPYONLY )
configure_file( ${DATA_SRC}/search_test_b ${DATA_DEST}/search_test_b COPYONLY )
configure_file( ${DATA_SRC}/text/search_test_c ${DATA_DEST}/text/search_test_c COPYONLY )

###############################################################################
#   Collect all test files.
###############################################################################
set ( CATCH_TESTS
        coords.cpp
        dims.cpp
        file.cpp
        img.cpp
        str.cpp)


###############################################################################
#   Build shared library
###############################################################################
add_executable( catch_common catch.cpp ${CATCH_TESTS} )
target_link_libraries( catch_common common )
target_include_directories(catch_common PRIVATE ${ROOT})
set_target_properties( catch_common PROPERTIES OUTPUT_NAME "catch" )
