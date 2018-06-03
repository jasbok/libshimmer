find_package(SDL2 MODULE REQUIRED)

include_directories(includes)

execute_process(
  COMMAND ${CMAKE_BINARY_DIR}/apigen/apigen
  ${SDL2_INCLUDE_DIR}/SDL.h
  -header "${API_ROOT}/includes/SDL2_apigen.h"
  -source "${API_ROOT}/tracers/SDL2_tracer.cpp"
  -- -I /usr/lib/clang/6.0.0/include/
  OUTPUT_VARIABLE APIGEN_OUT )

message("SDL2 apigen output: ${APIGEN_OUT}" )

add_library(trace_sdl2 SHARED tracers/SDL2_tracer.cpp)
target_include_directories(trace_sdl2 PRIVATE ${SDL2_INCLUDE_DIR} ${SDL2_INCLUDE_DIRS})
target_link_libraries(trace_sdl2 ${SDL2_LIBRARIES})
