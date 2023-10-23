cmake_minimum_required(VERSION 3.26)
project(Projeto)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Projeto
        Class.cpp
        Class.h
        main.cpp
        Menu.cpp
        Menu.h
        Schedule.cpp
        Schedule.h
        Student.cpp
        Student.h
        Turma.cpp
        Turma.h)
