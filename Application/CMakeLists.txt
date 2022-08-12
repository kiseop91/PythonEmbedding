cmake_minimum_required(VERSION 3.4)
project(Application)

set(TargetName Application)

find_package(Python 3.10 COMPONENTS Interpreter Development REQUIRED)

add_executable(${TargetName} src/main.cpp)
target_link_libraries(${TargetName} PUBLIC pyInterpreter)


if(WIN32)
    add_custom_command(TARGET ${TargetName} POST_BUILD 
    COMMAND ${Python_EXECUTABLE} -m venv $<TARGET_FILE_DIR:${TargetName}>/${CMAKE_BUILD_TYPE}/..
    COMMAND $<TARGET_FILE_DIR:${TargetName}>/${CMAKE_BUILD_TYPE}/../Scripts/activate.bat
    COMMAND $<TARGET_FILE_DIR:${TargetName}>/${CMAKE_BUILD_TYPE}/../Scripts/pip.exe install -r ${CMAKE_SOURCE_DIR}/requirements.txt > pip_install.log)
else()
    add_custom_command(TARGET ${TargetName} POST_BUILD 
    COMMAND ${Python_EXECUTABLE} -m venv $<TARGET_FILE_DIR:${TargetName}>/${CMAKE_BUILD_TYPE}/..
    COMMAND $<TARGET_FILE_DIR:${TargetName}>/${CMAKE_BUILD_TYPE}/../Scripts/activate
    COMMAND python -m pip install -r ${CMAKE_SOURCE_DIR}/requirements.txt > pip_install.log)
endif()