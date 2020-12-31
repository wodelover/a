cmake_minimum_required(VERSION 3.5)

project(exam)

SET(CMAKE_INCLUDE_CURRENT_DIR ON)
SET(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)

set( exam_SOURCE
   ${CMAKE_CURRENT_SOURCE_DIR}/exam.h
   ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

include_directories(../include)
link_directories(../lib)

add_executable(${PROJECT_NAME} ${exam_SOURCE})

target_link_libraries(${PROJECT_NAME} pthread libgtest.a)

