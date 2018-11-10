cmake_minimum_required(VERSION 3.12)
#
message("CMAKE_BUILD_TYPE is ${CMAKE_BUILD_TYPE}")#
message("initially CMAKE_CXX_FLAGS_DEBUG   were   ${CMAKE_CXX_FLAGS_DEBUG}")
message("initially CMAKE_CXX_FLAGS_DEBUG   were   ${CMAKE_CXX_FLAGS_RELEASE}")
#
project(engine_sim)
#
set(CMAKE_CXX_STANDARD 14)
#
set(CMAKE_CXX_FLAGS_DEBUG    "-Wall  -g")
#
set(CMAKE_CXX_FLAGS_RELEASE  "-O3 -DNDEBUG")
#
message("CMAKE_CXX_FLAGS_DEBUG   is   ${CMAKE_CXX_FLAGS_DEBUG}")
message("CMAKE_CXX_FLAGS_DEBUG   is   ${CMAKE_CXX_FLAGS_RELEASE}")
#
include_directories(components)
#
add_executable(engine_sim
        main.cpp
        tests.cpp
        tests.h
                components/ButterflyValve.cpp
                components/ButterflyValve.h
        components/utilities.h
        components/utilities.cpp
                components/Crankshaft.cpp
                components/Crankshaft.h
                components/CombustionChamber.cpp
                components/CombustionChamber.h
                components/CrankPin.cpp
                components/CrankPin.h
                components/EngineInfo.cpp
                components/EngineInfo.h
                components/SolverInfo.cpp
                components/SolverInfo.h components/Constants.cpp components/Constants.h)


