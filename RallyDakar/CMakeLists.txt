cmake_minimum_required(VERSION 4.1)
project(RallyDakar C)

set(CMAKE_C_STANDARD 23)

add_executable(RallyDakar main.c
        inc/Common.h
        inc/TeamInfo.h
        inc/VehicleHealth.h
        inc/Stage.h
        inc/TerrainType.h
        inc/StageResult.h
        src/TeamInfo.c
        inc/Ansi.h)
