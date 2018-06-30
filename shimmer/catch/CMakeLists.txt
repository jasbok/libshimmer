###############################################################################
#   List sources
###############################################################################
set( CATCH_SOURCES
        aspect.cpp
        display.cpp
        event_collector.cpp
        event_exchange.cpp
        mouse.cpp
        pipeline.cpp
        window.cpp
        catch.cpp )


###############################################################################
#   Build catch executable
###############################################################################
add_executable( catch catch.cpp ${CATCH_TESTS} )

target_include_directories( catch PRIVATE
    .
    ${ROOT}
    ${ROOT}/external )

target_link_libraries( catch shimmer ${TARGET_LINK_LIBRARIES} )


###############################################################################
#   Copy data files.
###############################################################################
configure_file(data/file_reader/simple.txt data/file_reader/simple.txt COPYONLY)
configure_file(data/glsl/garbage data/glsl/garbage COPYONLY)
configure_file(data/glsl/simple.fs data/glsl/simple.fs COPYONLY)
configure_file(data/glsl/simple.vs data/glsl/simple.vs COPYONLY)
configure_file(data/images/8x9x8_rgb.png data/images/8x9x8_rgb.png COPYONLY)
configure_file(data/images/8x9x8_rgba.png data/images/8x9x8_rgba.png COPYONLY)
configure_file(data/images/8x9x8_rgb_b.png data/images/8x9x8_rgb_b.png COPYONLY)
configure_file(data/images/8x9x8_rgba_b.png data/images/8x9x8_rgba_b.png COPYONLY)
configure_file(data/images/8x9x8_rgb_adam7.png data/images/8x9x8_rgb_adam7.png COPYONLY)
configure_file(data/images/8x9x8_rgba_adam7.png data/images/8x9x8_rgba_adam7.png COPYONLY)
configure_file(data/images/8x9x8_rgb.jpeg data/images/8x9x8_rgb.jpeg COPYONLY)
configure_file(data/images/8x9x8_rgba.jpeg data/images/8x9x8_rgba.jpeg COPYONLY)
configure_file(data/images/8x9x8_rgba.jpeg data/images/8x9x8_rgba.jpeg COPYONLY)

configure_file(data/config/pipeline.json data/config/pipeline.json COPYONLY)

###############################################################################
#   Add the CTest unit tests to the project.
###############################################################################
enable_testing()

# add_test( file_reader catch "[file_reader]" )
