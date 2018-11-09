cmake_minimum_required(VERSION 3.12)
project(engine_sim)

set(CMAKE_CXX_STANDARD 14)

include_directories(components)

add_executable(engine_sim
                   main.cpp
        components/ButterflyValve.cpp
        components/ButterflyValve.h
        components/utility.h)
