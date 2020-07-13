# CMakeList.txt : CMake project for Client, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("Client")
# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

# Find the QtWidgets library
find_package(Qt5Widgets)

add_executable (Client  "Client.cpp" "Client.h" "Main.cpp"  "mainwindow.cpp" "mainwindow.h" )

target_link_libraries(Client Qt5::Widgets)

# TODO: Add tests and install targets if needed.
