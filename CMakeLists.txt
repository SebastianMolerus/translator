cmake_minimum_required(VERSION 3.16)
project(translator)

set(CMAKE_CXX_STANDARD 20)

add_executable(translator main.cpp Parser.cpp Lexer.cpp)