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
        inc/Ansi.h
        inc/VehicleInfo.h
        src/VehicleInfo.c
        inc/GameSession.h
        src/GameSession.c
        inc/UI/ConsoleMenu.h
        src/ConsoleMenu.c
        src/Common.c
        src/Stage.c
        src/AppMenus.c
        inc/UI/AppMenus.h)
