cmake_minimum_required(VERSION 3.15)
project(untitled C)

set(CMAKE_C_STANDARD 99)

add_executable(main main.c gost.c navso.c vsitr.c shnauder.c mashingAlgos.h util.c util.h)
