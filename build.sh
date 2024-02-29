#!/bin/sh

CLANG_PATH=/usr/bin/clang++

cd build
cmake -GNinja -DCMAKE_CXX_COMPILER=${CLANG_PATH} -DCMAKE_BUILD_TYPE=Release ..
cmake --build .