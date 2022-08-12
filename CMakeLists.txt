cmake_minimum_required(VERSION 3.16.2 FATAL_ERROR)

project(example LANGUAGES CXX VERSION 1.0.0)

add_subdirectory(PyInterpreter)
add_subdirectory(Application)

add_dependencies(Application pyInterpreter)