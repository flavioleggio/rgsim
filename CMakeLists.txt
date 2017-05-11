cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
project(rgsim C CXX)

find_package(gazebo REQUIRED)
find_package(Boost 1.40 COMPONENTS system REQUIRED)

set(CMAKE_CXX_FLAGS "-g -Wall -std=c++11")

include_directories(
  ${GAZEBO_INCLUDE_DIRS}
  ${SDF_INCLUDE_DIRS}
  ${CMAKE_CURRENT_BINARY_DIR}/models/robot/msgs
  )

add_subdirectory(models/robot)
add_subdirectory(lib)
add_subdirectory(tools)
