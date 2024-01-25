cmake_minimum_required(VERSION 3.27)
project(ihm_robot)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(ihm_robot main.cpp)
target_link_libraries(ihm_robot
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

