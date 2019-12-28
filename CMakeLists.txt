cmake_minimum_required(VERSION 3.15)
project(kMeans_OMP)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp")
add_executable(kMeans_OMP main.cpp csvio.h csvio.cpp Point.h Cluster.h Utilities.h Utilities.cpp csv_generator.cpp)