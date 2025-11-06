cmake_minimum_required(VERSION 3.24)
project(2526_TI301_PJT C)

set(CMAKE_C_STANDARD 11)

add_executable(TI_301_PJT
        main.c 
        utils.c 
        hasse.c
        cell.h
        hasse.h
        cell.c
        list.h
        list.c
        tableau.c
        tableau.h)
