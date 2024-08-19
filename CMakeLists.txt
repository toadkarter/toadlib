cmake_minimum_required(VERSION 3.28)
project(toadlib C)

set(CMAKE_C_STANDARD 99)

add_library(toadlib STATIC library.c)
