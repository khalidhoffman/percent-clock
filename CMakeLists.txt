cmake_minimum_required(VERSION 2.8.11)

project(percent-clock)

include_directories(./lib/)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

set(CMAKE_CXX_STANDARD 14)
# Find the QtWidgets library
find_package(Qt5Widgets)

find_package(Qt5Core)

get_target_property(QtCore_location Qt5::Core LOCATION)

add_executable(percent-clock src/main.cpp lib/Clock.cpp lib/TextDisplay.cpp lib/TimePoint.cpp)

target_link_libraries(percent-clock Qt5::Widgets)

set(EXECUTABLE_OUTPUT_PATH  ${CMAKE_SOURCE_DIR}/bin/)
