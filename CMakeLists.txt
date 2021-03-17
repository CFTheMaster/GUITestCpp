cmake_minimum_required(VERSION 3.16.0)

project(GUITest VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(app_icon_resource_windows "${CMAKE_CURRENT_SOURCE_DIR}/GUI/resources/profile.rc")

find_package(Qt6 COMPONENTS Widgets REQUIRED)
find_package(Qt6 COMPONENTS Network REQUIRED)

add_executable(GUITest
    GUI/mainwindow.ui
    GUI/mainwindow.cpp
    GUI/main.cpp
    GUI/resources.qrc
    ${app_icon_resource_windows}
)

target_link_libraries(GUITest PRIVATE Qt6::Widgets)
target_link_libraries(GUITest PRIVATE Qt6::Network)
