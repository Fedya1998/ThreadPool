cmake_minimum_required(VERSION 3.13)
project(ThreadPool)

set(CMAKE_CXX_STANDARD 17)

add_executable(ThreadPool main.cpp ThreadPool.cpp ThreadPool.h Task.cpp Task.h)