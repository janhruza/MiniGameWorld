cmake_minimum_required(VERSION 4.1)
project(CitizenDB C)

set(CMAKE_C_STANDARD 23)

# find_package(raylib REQUIRED)
# target_link_libraries(CitizenDB PRIVATE raylib m)

add_executable(CitizenDB main.c
        inc/Person.h
        inc/Common.h
        src/Person.c
        src/Common.c
        inc/UI/Screens.h
        src/UI/Screens.c "inc/LinkedList.h" "src/LinkdedList.c" "inc/AppState.h" "src/AppState.c" "inc/Commands.h" "src/Commands.c")