cmake_minimum_required(VERSION 3.4)
project(PythonInterpreter)

set(TargetName pyInterpreter)

find_package(pybind11 REQUIRED)  # or `add_subdirectory(pybind11)`
add_library(${TargetName} src/PyInterpreter.cpp)

target_include_directories(${TargetName} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(${TargetName} PRIVATE pybind11::embed)
