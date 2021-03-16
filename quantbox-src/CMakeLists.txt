cmake_minimum_required(VERSION 3.5)

project(quantbox-src LANGUAGES C)

add_executable(quantbox-src main.c types.h order.h order.c trade.h trade.c command.h command.c)
