set(DATA_GLSL_SRC ${CMAKE_CURRENT_SOURCE_DIR}/glsl)
set(DATA_GLSL_DEST ${CMAKE_CURRENT_BINARY_DIR}/glsl)

set(DATA_GLSL_1_3_SRC ${CMAKE_CURRENT_SOURCE_DIR}/glsl1.3)
set(DATA_GLSL_1_3_DEST ${CMAKE_CURRENT_BINARY_DIR}/glsl1.3)

configure_file(${DATA_GLSL_1_3_SRC}/default.vert ${DATA_GLSL_1_3_DEST}/default.vert COPYONLY)
configure_file(${DATA_GLSL_1_3_SRC}/model.vert ${DATA_GLSL_1_3_DEST}/model.vert COPYONLY)
configure_file(${DATA_GLSL_1_3_SRC}/default.frag ${DATA_GLSL_1_3_DEST}/default.frag COPYONLY)
configure_file(${DATA_GLSL_1_3_SRC}/xbrz3x.frag ${DATA_GLSL_1_3_DEST}/xbrz3x.frag COPYONLY)
configure_file(${DATA_GLSL_1_3_SRC}/xbrz4x.frag ${DATA_GLSL_1_3_DEST}/xbrz4x.frag COPYONLY)
configure_file(${DATA_GLSL_1_3_SRC}/ui.vert ${DATA_GLSL_1_3_DEST}/ui.vert COPYONLY)

file(GLOB glsl "${CMAKE_CURRENT_SOURCE_DIR}/glsl/*")
install(FILES ${glsl} DESTINATION "shimmer/shaders/glsl")

file(GLOB glsl_1_3 "${CMAKE_CURRENT_SOURCE_DIR}/glsl1.3/*")
install(FILES ${glsl_1_3} DESTINATION "shimmer/shaders")
