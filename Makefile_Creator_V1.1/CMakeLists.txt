cmake_minimum_required(VERSION 3.17)
project(Makefile_Creator_V1_1 C)

set(CMAKE_C_STANDARD 99)

add_executable(Makefile_Creator_V1_1 main.c manual_config.c auto_config.c print.c mc_header.h)