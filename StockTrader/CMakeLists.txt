cmake_minimum_required(VERSION 4.1)
project(MGW C)

set(CMAKE_C_STANDARD 23)

add_executable(MGW Source.c
        inc/data/GlobalData.h
        inc/data/Player.h
        inc/data/Stock.h
        inc/GameSession.h
        inc/UIActions.h
        inc/Values.h)
