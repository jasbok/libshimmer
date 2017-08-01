###############################################################################
#   Find GLUT.
###############################################################################
find_package( GLUT )


###############################################################################
#   Configure include directories.
###############################################################################
set( CATCH_INCLUDES
        ${GLUT_INCLUDE_DIRS}
        ${INCLUDES}
        ${EXTERNAL_INCLUDES} )

include_directories( ${CATCH_INCLUDES} )


###############################################################################
#   Collect all test files.
###############################################################################
file( GLOB_RECURSE CATCH_TESTS ${LIB_SHIMMER_ROOT}/catch/tests/*.cpp )


###############################################################################
#   List sources
###############################################################################
set( CATCH_SOURCES
        ${SOURCES}
        ${CATCH_TESTS}
        catch.cpp )


###############################################################################
#   Build shared library
###############################################################################
add_executable( catch ${CATCH_SOURCES} ${HEADERS} )
target_link_libraries( catch ${TARGET_LINK_LIBRARIES} ${GLUT_LIBRARY} )


###############################################################################
#   Copy data files.
###############################################################################
configure_file(data/file_reader/simple.txt data/file_reader/simple.txt COPYONLY)
configure_file(data/glsl/garbage data/glsl/garbage COPYONLY)
configure_file(data/glsl/simple.fs data/glsl/simple.fs COPYONLY)
configure_file(data/glsl/simple.vs data/glsl/simple.vs COPYONLY)
configure_file(data/images/8x9x8_rgb.png data/images/8x9x8_rgb.png COPYONLY)
configure_file(data/images/8x9x8_rgba.png data/images/8x9x8_rgba.png COPYONLY)
configure_file(data/images/8x9x8_rgb_adam7.png data/images/8x9x8_rgb_adam7.png COPYONLY)
configure_file(data/images/8x9x8_rgba_adam7.png data/images/8x9x8_rgba_adam7.png COPYONLY)
configure_file(data/images/8x9x8_rgb.jpeg data/images/8x9x8_rgb.jpeg COPYONLY)
configure_file(data/images/8x9x8_rgba.jpeg data/images/8x9x8_rgba.jpeg COPYONLY)

###############################################################################
#   Add the CTest unit tests to the project.
###############################################################################
enable_testing()

add_test( file_reader catch "[file_reader]" )
add_test( gl_pixel catch "[gl_pixel]" )
add_test( gl_program_manager catch "[gl_program_manager]" )
add_test( gl_shader_compiler catch "[gl_shader_compiler]" )
add_test( gl_shader_linker catch "[gl_shader_linker]" )
add_test( gl_shader_manager catch "[gl_shader_manager]" )
add_test( glsl_variable_extractor catch "[glsl_variable_extractor]" )
add_test( regex_helper catch "[regex_helper]" )
add_test( simple_cache catch "[simple_cache]" )
