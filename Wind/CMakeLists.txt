cmake_minimum_required(VERSION 3.18)
project("RichMan" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(MSVC)
    add_compile_options("/source-charset:utf-8")
endif()

add_executable(
    ${PROJECT_NAME}
    main.cpp
    Dice.h
    Dice.cpp
    Node.h
    Node.cpp
    Player.h
    Player.cpp
    RaceTrack.h
    RaceTrack.cpp
)
