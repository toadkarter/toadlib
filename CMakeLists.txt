cmake_minimum_required(VERSION 3.25)
project(toadlib C)

set(CMAKE_C_STANDARD 99)

include_directories(include)
file(GLOB SRC_FILES "src/*.c")

add_library(toadlib STATIC ${SRC_FILES})
