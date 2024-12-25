cmake_minimum_required(VERSION 3.10.0)

project(af-alg-perf)

#set(CMAKE_VERBOSE_MAKEFILE on)

add_executable(af-alg-perf.elf
    af-alg-perf.c
    testconfigs.cpp)

# This is a test of cmake feature
# we can set individual file compile flags
# and target compile options
#set(MYPROPS "Some Text")
#get_source_file_property(MYPROPS af-alg-perf.c COMPILE_FLAGS)
#message(${MYPROPS})
#set_source_files_properties(af-alg-perf.c COMPILE_FLAGS "-DABS")
#get_source_file_property(MYPROPS af-alg-perf.c COMPILE_FLAGS)
#message(${MYPROPS})

target_link_options(af-alg-perf.elf PRIVATE
    -lpthread
    -ljsoncpp)

target_compile_options(af-alg-perf.elf PRIVATE
    -Wall
    -Wextra)
