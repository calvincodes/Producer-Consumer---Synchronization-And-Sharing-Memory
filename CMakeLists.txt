cmake_minimum_required(VERSION 3.12)
project(os_hw2 C)

set(CMAKE_C_STANDARD 99)

add_executable(os_hw2 main.c reader.c reader.h munch1.c munch1.h queue.c queue.h constants.c constants.h)