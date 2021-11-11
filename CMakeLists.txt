cmake_minimum_required(VERSION 3.17)
project(Project C)

set(CMAKE_C_STANDARD 11)

add_executable(Project main.c Parser.c Parser.h Testing.c Testing.h)