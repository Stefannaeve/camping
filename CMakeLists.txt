cmake_minimum_required(VERSION 3.29)
project(teltTur C)

set(CMAKE_C_STANDARD 11)

add_executable(teltTur main.c
        headers/main.h
        headers/log.h
        log.c
        Arraylist.c
        Arraylist.h)
