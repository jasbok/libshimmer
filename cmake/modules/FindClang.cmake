execute_process(
  COMMAND llvm-config --cxxflags
  OUTPUT_VARIABLE CLANG_DEFINITIONS)

set(CLANG_DEFINITIONS ${CLANG_DEFINITIONS} "-fno-rtti")

execute_process(
  COMMAND llvm-config --includedir
  OUTPUT_VARIABLE CLANG_INCLUDE_DIR)

set(LIB_DIRS /lib /usr/lib)

find_library(CLANG_LIBRARY NAMES clang)
find_library(CLANG_AST_LIBRARY clangAST )
find_library(CLANG_AST_MATCHERS_LIBRARY clangASTMatchers )
find_library(CLANG_BASIC_LIBRARY clangBasic )
find_library(CLANG_FRONTEND_LIBRARY clangFrontend )
find_library(CLANG_LEX_LIBRARY clangLex )
find_library(CLANG_TOOLING_LIBRARY clangTooling )

set(CLANG_LIBRARIES
    ${CLANG_LIBRARY}
    ${CLANG_AST_LIBRARY}
    ${CLANG_AST_MATCHERS_LIBRARY}
    ${CLANG_BASIC_LIBRARY}
    ${CLANG_FRONTEND_LIBRARY}
    ${CLANG_LEX_LIBRARY}
    ${CLANG_TOOLING_LIBRARY})

set(CLANG_INCLUDE_DIRS ${CLANG_INCLUDE_DIR})

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(CLANG DEFAULT_MSG CLANG_LIBRARY CLANG_INCLUDE_DIR)

mark_as_advanced(CLANG_INCLUDE_DIR CLANG_LIBRARY)
