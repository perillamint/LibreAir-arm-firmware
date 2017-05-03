#!/bin/bash

CMAKE_BUILD_TYPE=Debug
CMAKE_MODULE_PATH=$(pwd)/stm32-cmake/cmake
CMAKE_TOOLCHAIN_FILE=$(pwd)/stm32-cmake/cmake/gcc_stm32.cmake
CHIBIOS_ROOT=$(pwd)/ChibiOS/

set -e

if [ ! -d build ]; then
   mkdir build
fi

cd build
cmake -DCMAKE_MODULE_PATH=$CMAKE_MODULE_PATH \
      -DCMAKE_TOOLCHAIN_FILE=$CMAKE_TOOLCHAIN_FILE \
      -DCMAKE_BUILD_TYPE=$CMAKE_BUILD_TYPE \
      -DCHIBIOS_ROOT=$CHIBIOS_ROOT ..

make -j9
