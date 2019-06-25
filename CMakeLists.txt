cmake_minimum_required(VERSION 3.10)
project(Faltu_C__)

#set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -pthread")

add_executable(VM main.cpp VM.cpp VM.h VM-inst.h)
#add_executable(Faltu_C__ lc3.c)