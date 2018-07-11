find_package( SDL )
find_package( SDL2 MODULE REQUIRED )

###############################################################################
# Generate SDL sym and tracer files.
###############################################################################
set ( SDL_COMMAND
    ${CMAKE_BINARY_DIR}/apigen/apigen
      ${SDL_INCLUDE_DIR}/SDL.h
      -header "${ROOT}/api/SDL_sym.h"
      -source "${ROOT}/api/tracers/SDL_tracer.cpp"
      -- -I /usr/lib/clang/6.0.1/include/ )

message("apigen SDL command: ${SDL_COMMAND}")

execute_process(
  COMMAND ${SDL_COMMAND}
  OUTPUT_VARIABLE APIGEN_OUT )

message( "SDL apigen output: '${APIGEN_OUT}'" )


###############################################################################
# Build and install SDL tracer.
###############################################################################
add_library( trace_sdl SHARED tracers/SDL_tracer.cpp )
target_include_directories( trace_sdl
    PRIVATE ${ROOT} ${SDL_INCLUDE_DIR} ${SDL_INCLUDE_DIRS} )
target_link_libraries( trace_sdl ${SDL_LIBRARIES} )

install( TARGETS trace_sdl DESTINATION lib )


###############################################################################
# Generate SDL2 sym and tracer files.
###############################################################################
set ( SDL2_COMMAND
    ${CMAKE_BINARY_DIR}/apigen/apigen
      ${SDL2_INCLUDE_DIR}/SDL.h
      -header "${ROOT}/api/SDL2_sym.h"
      -source "${ROOT}/api/tracers/SDL2_tracer.cpp"
      -- -I /usr/lib/clang/6.0.1/include/
    )
message("apigen SDL2 command: ${SDL2_COMMAND}")

execute_process(
  COMMAND ${SDL2_COMMAND}
  OUTPUT_VARIABLE APIGEN_OUT )

message( "SDL2 apigen output: '${APIGEN_OUT}'" )


###############################################################################
# Build and install SDL2 tracer.
###############################################################################
add_library( trace_sdl2 SHARED tracers/SDL2_tracer.cpp )

target_include_directories( trace_sdl2 PRIVATE
    ${ROOT}
    ${SDL2_INCLUDE_DIR}
    ${SDL2_INCLUDE_DIRS} )

target_link_libraries( trace_sdl2 ${SDL2_LIBRARIES} )

install( TARGETS trace_sdl2 DESTINATION lib )
