cmake_minimum_required(VERSION 3.25)
project(ihm_robot)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


set(HEADERS
        MainWindow.h
        homeButton.h
        Homologation.h
        InGame.h
        TeamChooser.h
        TestMode.h
        TestModeBtn.h
        preparation/TiretteState.h
        preparation/Lidar.h
        PreparationMatch.h
        preparation/OneItemPreparation.h
)

set(SOURCES
        main.cpp
        MainWindow.cpp
        homeButton.cpp
        Homologation.cpp
        InGame.cpp
        TeamChooser.cpp
        TestMode.cpp
        TestModeBtn.cpp
        PreparationMatch.cpp
        preparation/Lidar.cpp
        preparation/OneItemPreparation.cpp
        preparation/TiretteState.cpp
)

set(TCP
        tcp/TCPServer.hpp
        tcp/TCPServer.cpp
        tcp/utils.hpp
)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        Network
        REQUIRED)

add_executable(ihm_robot resource.qrc ${HEADERS} ${SOURCES} ${TCP})

target_link_libraries(ihm_robot
        Qt::Core
        Qt::Gui
        Qt::Widgets
        Qt::Network
)

