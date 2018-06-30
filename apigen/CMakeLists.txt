###############################################################################
#   Configure Clang and LLVM
###############################################################################
find_package( Clang MODULE )
find_package( LLVM MODULE )
find_package( Filesystem MODULE )


###############################################################################
#   Set apigen includes.
###############################################################################
set( APIGEN_INCLUDES
        common.h
        decl.h
        fdecl_matcher.h
        function.h
        decl.h
        header.h
        output.h
        parameter.h
        source.h
        type.h )


###############################################################################
#   Set apigen sources.
###############################################################################
set( APIGEN_SOURCES apigen.cpp
        ${FMT_SOURCES}
        src/common.cpp
        src/fdecl_matcher.cpp
        src/function.cpp
        src/header.cpp
        src/output.cpp
        src/parameter.cpp
        src/source.cpp
        src/type.cpp )


###############################################################################
#   Set apigen link libraries.
###############################################################################
set( APIGEN_LIBRARIES
        common
        ${CLANG_LIBRARIES}
        ${LLVM_LIBRARIES}
        ${FILESYSTEM_LIBRARIES} )


###############################################################################
#   Build apigen.
###############################################################################
add_executable( apigen ${APIGEN_SOURCES} ${APIGEN_INCLUDES} )

target_include_directories( apigen PRIVATE
    .
    ${ROOT} )

target_link_libraries( apigen ${APIGEN_LIBRARIES} )

