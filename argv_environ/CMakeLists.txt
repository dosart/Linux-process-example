cmake_minimum_required(VERSION 3.16)

set(PROJECT_NAME argv_and_environ)
project(${PROJECT_NAME} VERSION 0.0.1 LANGUAGES C)


add_executable(${PROJECT_NAME} main.c)

set_target_properties(${PROJECT_NAME} PROPERTIES
        C_STANDARD 11
        C_STANDARD_REQUIRED ON)
add_compile_options(
        -Werror

        -Wall
        -Wextra
        -Wpedantic

        -Wcast-align
        -Wcast-qual
        -Wconversion
        -Wenum-compare
        -Wfloat-equal
        -Wredundant-decls
        -Wsign-conversion)
