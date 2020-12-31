cmake_minimum_required(VERSION 3.5)

project(freedesktop)
find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(PkgConfig REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(DtkWidget REQUIRED)
SET(CMAKE_AUTOMOC ON)
SET(CMAKE_INCLUDE_CURRENT_DIR ON)
SET(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)

set(main_SOURCE
   ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/exam.h
   )
add_executable(${PROJECT_NAME} ${main_SOURCE})
target_include_directories(${PROJECT_NAME} PUBLIC ${DtkWidget_INCLUDE_DIRS} ${OBJECT_BINARY_DIR})
target_link_libraries(
    ${PROJECT_NAME}
    Qt5::Widgets
    Qt5::Core
    Qt5::Gui
    ${DtkWidget_LIBRARIES}
    ${Qt5Widgets_LIBRARIES}
)
#set(EXECUTABLE_OUTPUT_PATH
#    ${CMAKE_CURRENT_SOURCE_DIR}
#)

