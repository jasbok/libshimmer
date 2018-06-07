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
        includes/common.h
        includes/decl.h
        includes/fdecl_matcher.h
        includes/function.h
        includes/decl.h
        includes/header.h
        includes/output.h
        includes/parameter.h
        includes/source.h
        includes/type.h )

include_directories( includes
    ${ROOT}
    ${EXTERNAL_ROOT}/includes )


###############################################################################
#   Set apigen sources.
###############################################################################
set( APIGEN_SOURCES apigen.cpp
        ${FMT_SOURCES}
        sources/common.cpp
        sources/fdecl_matcher.cpp
        sources/function.cpp
        sources/header.cpp
        sources/output.cpp
        sources/parameter.cpp
        sources/source.cpp
        sources/type.cpp )


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

target_link_libraries( apigen ${APIGEN_LIBRARIES} )
