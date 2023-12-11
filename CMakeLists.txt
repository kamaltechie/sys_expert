cmake_minimum_required(VERSION 3.26)
project(system_expert C)

set(CMAKE_C_STANDARD 11)

add_executable(system_expert system_expert.c
        system_expert.h
        main.c)
