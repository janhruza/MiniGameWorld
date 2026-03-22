cmake_minimum_required(VERSION 4.1)
project(MotoGP C)

set(CMAKE_C_STANDARD 23)

add_executable(MotoGP main.c
        inc/Common.h
        inc/DriverInfo.h
        src/DriverInfo.c
        inc/UI/Ansi.h
        inc/UI/ConsoleMenu.h
        src/ConsoleMenu.c
        inc/GameSession.h
        src/Common.c
        src/GameSession.c
        inc/Debug.h
        inc/TeamInfo.h
        inc/TrackInfo.h)
