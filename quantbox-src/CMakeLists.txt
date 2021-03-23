cmake_minimum_required(VERSION 3.5)

project(Exchange LANGUAGES C)

add_executable(Exchange main.c
    order.h
    order_list.h
    executer.h
    )
