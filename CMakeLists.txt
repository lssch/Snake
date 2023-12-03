cmake_minimum_required(VERSION 3.26)
project(snake_game)

set(CMAKE_CXX_STANDARD 23)

FIND_PACKAGE( OpenCV REQUIRED )
INCLUDE_DIRECTORIES( ${OpenCV_INCLUDE_DIRS} )

ADD_EXECUTABLE(snake_game main.cpp
        Snake/Snake.cpp
        Snake/Snake.h
        Fields/Fields.cpp
        Fields/Fields.h)
TARGET_LINK_LIBRARIES (snake_game ${OpenCV_LIBS})