#!/bin/bash

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

COMPILER_CC=/usr/bin/gcc
COMPILER_CXX=/usr/bin/g++

BUILD_SYSTEM=ninja
THREADS=8

IGNORE_ERRORS=false

RUN_BUILD=false
RUN_CATCH=false
RUN_CLEAN=false
RUN_CPPCHECK=false
RUN_SCAN_BUILD=false
RUN_UNCRUSTIFY=false
RUN_VALGRIND=false

TAGS=
ENABLE_LOGGING=

BLUE='\033[1;34m'
YELLOW='\033[1;33m'
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m'

function err {
    printf "$RED----- $1 -----\n$NC"
    [[ $IGNORE_ERRORS == true ]] || exit 1
}

function warn {
    printf "$YELLOW##### $1 #####\n$NC"
}

function info {
    printf "$BLUE$1\n$NC"
}

function header {
    printf "$BLUE***** $1 *****\n$NC"
}

function success {
    printf "$GREEN+++++ $1 +++++\n$NC"
}

###############################################################################
#                       ***** Parse script arguemnts. *****                   #
###############################################################################
for i in "$@"
do
case $i in
    -m|--build-system)
    BUILD_SYSTEM="$2"
    info "==> Using $BUILD_SYSTEM build system."
    shift
    ;;

    -j|--threads)
    THREADS="$2"
    info "==> Using $THREADS threads."
    shift
    ;;

    --ignore-errors)
    info "==> Ignoring errors."
    IGNORE_ERRORS=true
    shift
    ;;

    --all)
    info "==> Running all facilities."
    RUN_BUILD=true
    RUN_CATCH=true
    RUN_CLEAN=true
    RUN_CPPCHECK=true
    RUN_SCAN_BUILD=true
    RUN_UNCRUSTIFY=true
    RUN_VALGRIND=true
    shift
    ;;

    --cppcheck)
    info "==> Enabled cppcheck run."
    RUN_CPPCHECK=true
    shift
    ;;

    --scan-build)
    info "==> Enabled scan-build run."
    RUN_SCAN_BUILD=true
    RUN_CLEAN=true
    RUN_BUILD=true
    shift
    ;;

    --uncrustify)
    info "==> Enabled uncrustify run."
    RUN_UNCRUSTIFY=true
    shift
    ;;

    --clean)
    info "==> Enabled clean run."
    RUN_CLEAN=true
    shift
    ;;

    --build)
    info "==> Enabled build run."
    RUN_BUILD=true
    shift
    ;;

    --catch)
    info "==> Enabled catch run."
    RUN_CATCH=true
    shift
    ;;

    --enable-logging)
    info "==> Enabling application logging during various test runs."
    ENABLE_LOGGING=--enable-logging
    shift
    ;;

    --tags)
    TAGS="$2"
    info "==> Using the following test tags: $TAGS"
    shift
    ;;

    --valgrind)
    info "==> Enabled valgrind run."
    RUN_VALGRIND=true
    shift
    ;;
esac
done

###############################################################################
#               ***** Format the source code with uncrustify. *****           #
###############################################################################
if [[ $RUN_UNCRUSTIFY == true ]]
then
    header "Running uncrustify on source files."
    cd $DIR

    LIBSHIMMER_SOURCE=($(find libshimmer \( -name *.h                   \
                                            -o -name *.hpp              \
                                            -o -name *.cpp \)))

    SHIMS_SOURCE=($(find shims \(   -name *.h                           \
                                    -o -name *.hpp                      \
                                    -o -name *.cpp \)))

    for src in "${LIBSHIMMER_SOURCE[@]}" "${SHIMS_SOURCE[@]}"
    do
        info "Running uncrustify on: $src"

        uncrustify  -q --check                                              \
                    --config "uncrustify.cfg"                               \
                    "$src"                                                  \
            ||  uncrustify  -q --config "uncrustify.cfg"                    \
                            --no-backup                                     \
                            "$src"                                          \
            ||  err "Uncrustify failed to format the source file: $src."
    done
fi

###############################################################################
#                    ***** Perform cppcheck analysis. *****                   #
###############################################################################
if [[ $RUN_CPPCHECK == true ]]
then
    header "Running cppcheck analysis."
    cd $DIR

    cppcheck    -j $THREADS                                 \
                --error-exitcode=1                          \
                --quiet                                     \
                --enable=all                                \
                -I libshimmer/includes/                     \
                -I libshimmer/includes/api                  \
                -I libshimmer/includes/keyboard             \
                -I libshimmer/includes/macros               \
                -I libshimmer/includes/mouse                \
                -I libshimmer/includes/renderer             \
                -I libshimmer/includes/renderer/common      \
                -I libshimmer/includes/renderer/glsl        \
                -I libshimmer/includes/renderer/opengl      \
                -I libshimmer/includes/utilities            \
                -I libshimmer/includes/window               \
                libshimmer/ shims/                          \
                || err "Errors were reported by cppcheck."

    success "No errors were reported by cppcheck."
fi

###############################################################################
#               ***** Clean, configure and build project. *****               #
###############################################################################

if [[ $RUN_CLEAN == true || $RUN_BUILD == true ]]
then
    header "Clean, configure and build project."
    cd $DIR

    if [[ $RUN_CLEAN == true ]]
    then
        info "Removing old build directory."
        rm -r build && mkdir -p build
        RUN_BUILD=true
    fi

    if [[ $RUN_BUILD == true ]]
    then
        cd build
        info "Configuring and building project using $BUILD_SYSTEM."
        info "Using $THREADS threads to build project."

        export CC=$COMPILER_CC
        export CXX=$COMPILER_CXX

        CMAKE_COMMAND=
        BUILD_COMMAND=

        if [[ $BUILD_SYSTEM == "ninja" ]]
        then
            CMAKE_COMMAND="cmake -GNinja .."
            BUILD_COMMAND="ninja -j$THREADS"

        elif [[ $BUILD_SYSTEM == "make" ]]
        then
            CMAKE_COMMAND="cmake .."
            BUILD_COMMAND="make -j$THREADS"
        else
            err "Uknown build system: $BUILD_SYSTEM"
        fi

        $CMAKE_COMMAND || err "Failed to configure project."
        if [[ $RUN_SCAN_BUILD == false ]]
        then
            $BUILD_COMMAND || err "Failed to build project."
            success "Project configured and built successfully."
        else
            scan-build --status-bugs $BUILD_COMMAND \
                    || err "The scan-build run failed with errors."
            success "Scan-build showed no errors during build."
        fi

    fi
fi

###############################################################################
#                   ***** Run all catch unit tests. *****                     #
###############################################################################
if [[ $RUN_CATCH == true ]]
then
    header "Run all catch unit tests."
    cd $DIR

    if [[ -n $TAGS ]]
    then
        TESTS=($TAGS)
    else
        TESTS=($(find libshimmer/catch/tests/ -name *.cpp \
                    | sed -e 's|.*/\(.*\).cpp|\1|g'))
    fi

    cd $DIR/build/libshimmer/catch
    for test in "${TESTS[@]}"
    do
        info "Running catch test: $test"
        ./catch --abort "[$test]" -- $ENABLE_LOGGING   \
            || err "A catch test run failed."
    done

    success "All catch test runs passed successfully."
fi

###############################################################################
#               ***** Run valgrind on all unit tests. *****                   #
###############################################################################
if [[ $RUN_VALGRIND == true ]]
then
    header "Run valgrind on all unit tests."
    cd $DIR

    if [[ -n $TAGS ]]
    then
        TESTS=($TAGS)
    else
        TESTS=($(find libshimmer/catch/tests/ -name *.cpp \
                    | sed -e 's|.*/\(.*\).cpp|\1|g'))
    fi

    SUPPRESSIONS=$DIR/suppressions
    cd $DIR/build/libshimmer/catch
    for test in "${TESTS[@]}"
    do
        PASS=0
        info "Running valgrind test: $test"
        valgrind    --tool=memcheck                         \
                    --leak-check=full                       \
                    --suppressions=$SUPPRESSIONS            \
                    --gen-suppressions=all                  \
                    --quiet                                 \
                    --error-exitcode=1                      \
                    ./catch "[$test]" -- $ENABLE_LOGGING    \
                        || err "A valgrind test run failed."
    done

    success "All valgrind test runs passed."
fi

###############################################################################
#                           ***** Success. *****                              #
###############################################################################

if [[ $IGNORE_ERRORS == false ]]
then
echo "========================================================================"
success "Project built and analysed successfully."
echo "========================================================================"

else
echo "========================================================================"
info "Project built and analysed (errors ignored)."
echo "========================================================================"
fi

exit 0
