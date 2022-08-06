#!/bin/sh
# cmake -B build && cmake --build build
cmake -B build && cmake --build build && cd build/debug && cmake -DCMAKE_BUILD_TYPE=Debug ../../ && cmake --build . -j$(nproc)
