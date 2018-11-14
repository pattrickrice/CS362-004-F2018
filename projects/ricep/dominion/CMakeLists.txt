cmake_minimum_required(VERSION 3.12)
project(dominion)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")
include_directories(.)

add_executable(playdom
        dominion.c
        dominion.h
        dominion_helpers.h
        interface.c
        interface.h
        Makefile
        playdom.c
        rngs.c
        rngs.h randomtestcard1.c)

# required instead of -lm flag
target_link_libraries(playdom m)

add_executable(
        randomtestcard1
        randomtestcard1.c
        dominion.c
        dominion.h
        rngs.c
        rngs.h)

add_executable(
        randomtestcard2
        randomtestcard2.c
        dominion.c
        dominion.h
        rngs.c
        rngs.h)

add_executable(
        randomtestcard3
        randomtestcard3.c
        dominion.c
        dominion.h
        rngs.c
        rngs.h)