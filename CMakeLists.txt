cmake_minimum_required(VERSION 3.25)
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

add_executable(ihm_robot main.cpp resource.qrc
        MainWindow.cpp
        MainWindow.h
        homeButton.cpp
        homeButton.h
        Homologation.cpp
        Homologation.h
        InGame.cpp
        InGame.h
        TeamChooser.cpp
        TeamChooser.h
        TestMode.cpp
        TestMode.h
)

target_link_libraries(ihm_robot
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

