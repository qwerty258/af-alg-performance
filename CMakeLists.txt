cmake_minimum_required(VERSION 3.0.0)

project(af-alg-perf)

add_executable(af-alg-perf.elf
    af-alg-perf.c
    testconfigs.cpp)

target_link_options(af-alg-perf.elf PRIVATE
    -lpthread
    -ljsoncpp)

target_compile_options(af-alg-perf.elf PRIVATE
    -Wall
    -Wextra)
