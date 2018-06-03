execute_process(
  COMMAND llvm-config --includedir
  OUTPUT_VARIABLE LLVM_INCLUDE_DIR)

set(LIB_DIRS /lib /usr/lib)

find_library(LLVM_LIBRARY NAMES LLVM)

set(LLVM_LIBRARIES
    ${LLVM_LIBRARY} )

set(LLVM_INCLUDE_DIRS ${LLVM_INCLUDE_DIR})

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(LLVM DEFAULT_MSG LLVM_LIBRARY LLVM_INCLUDE_DIR)

mark_as_advanced(LLVM_INCLUDE_DIR LLVM_LIBRARY)
