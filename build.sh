#!/bin/sh
build() {
    git submodule update --init --recursive 
    if [ ! -d "build" ] ; then
        cmake -B build
    fi
    cmake --build build
}

if [ "$1" = "--build" ] ; then 
    build
elif [ "$1" = "--run" ] ; then
    build
    ./Piceasel
elif [ "$1" = "--run-tests" ] ; then 
    build
    ctest --test-dir build/tests
elif [ "$1" = "--clean" ] ; then
    if [ -d "build" ] ; then
        cmake --build build -t clean
    fi
else
    echo "./build.sh --help: Show this menu."
    echo "./build.sh --build: Build the debug version of the Piceasel executable without running it."
    echo "./build.sh --run: Build and run the debug version of the Piceasel executable."
    echo "./build.sh --run-tests: Build and run the testing suite."
    echo "./build.sh --clean: Clean the CMake cache. Note that this will not remove generated build files."
fi