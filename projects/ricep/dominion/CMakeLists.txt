cmake_minimum_required(VERSION 3.12)
project(dominion)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")
include_directories(.)

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

add_library(utils utils.c utils.h)
add_library(rngs rngs.h rngs.c)

add_library(dominion dominion.c rngs)

add_executable(playdom playdom.c dominion.c rngs.h rngs.c)

add_executable(badTestDrawCard badTestDrawCard.c dominion rngs utils.c utils.h)

add_executable(testBuyCard testBuyCard.c dominion.c rngs.h rngs.c)

add_test(testAll dominion.o testSuite.c dominion.o rngs)

add_library(interface interface.h interface.c)

add_library(player player.c dominion rngs interface)

add_executable(
        randomtestcard1
        randomtestcard1.c
        dominion
        rngs
        utils)

target_link_libraries(randomtestcard1 m)
target_link_libraries(playdom m)
