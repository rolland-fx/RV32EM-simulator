cmake_minimum_required(VERSION 3.16)
project(RV32EM_simulator C)

set(CMAKE_C_STANDARD 99)

add_executable(RV32EM_simulator main.c cmake-build-debug/RV32EM.h)