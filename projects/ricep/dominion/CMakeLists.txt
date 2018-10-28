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
        rngs.h )

add_executable(
        unittest1
        unittest1.c
        utils.h utils.c
        dominion.c
        dominion.h
        rngs.c
        rngs.h)

add_executable(
        unittest2
        unittest2.c
        utils.h utils.c
        dominion.c
        dominion.h
        rngs.c
        rngs.h)

add_executable(
        unittest3
        unittest3.c
        utils.h utils.c
        dominion.c
        dominion.h
        rngs.c
        rngs.h)

add_executable(
        unittest4
        unittest4.c
        utils.h utils.c
        dominion.c
        dominion.h
        rngs.c
        rngs.h)
