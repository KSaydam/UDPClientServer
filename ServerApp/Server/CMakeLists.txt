# CMakeList.txt : CMake project for Server, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("Server")

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

# Find the QtWidgets library
find_package(Qt5Widgets)
find_package(Qt5 COMPONENTS Network REQUIRED)

# Use the Widgets module from Qt 5.
# TODO: Add tests and install
add_executable (Server  "main.cpp" "mainwindow.cpp"  "UDPListener.cpp" "UDPListener.h" "UDPSocketProtocol.cpp" "UDPSocketProtocol.h" "mainwindow.h" "ui_mainwindow.h")

target_link_libraries(Server Qt5::Widgets)
target_link_libraries(Server Qt5::Network)
# Add source to this project's executable.


