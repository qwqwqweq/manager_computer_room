cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_COMPILER "E:/mingw64/bin/g++.exe")
project(RoomManagementSystem)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES
	main.cpp
	student.cpp
	teacher.cpp
	manager.cpp
)

set(HEADERS
	identity.hpp
	student.hpp
	teacher.hpp
	manager.hpp
	global_file.hpp
)

include_directories(${CMAKE_SOURCE_DIR})

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
