PROJECT(exam)
find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Test REQUIRED)
SET(CMAKE_AUTOMOC ON)
SET(CMAKE_INCLUDE_CURRENT_DIR ON)
SET(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)
ENABLE_TESTING()

#同理，查找当前文件夹中所有的ui文件
FILE(GLOB UI_FILES "./*.ui")
#通过Ui文件生成对应的头文件，一定要添加
qt5_wrap_ui(WRAP_FILES ${UI_FILES})

set( mainwindow_SOURCE
    ${CMAKE_CURRENT_SOURCE_DIR}/mainwindow.h
    ${CMAKE_CURRENT_SOURCE_DIR}/autotest.h
    ${CMAKE_CURRENT_SOURCE_DIR}/mainwindow.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/mainwindow.ui
    ${CMAKE_CURRENT_SOURCE_DIR}/autotest.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)
add_executable(${PROJECT_NAME} ${mainwindow_SOURCE})
add_test(${PROJECT_NAME} COMMAND ${PROJECT_NAME})
target_link_libraries(
    ${PROJECT_NAME}
    Qt5::Widgets
    Qt5::Core
    Qt5::Gui
    Qt5::Test
)


