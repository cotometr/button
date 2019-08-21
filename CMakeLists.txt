cmake_minimum_required(VERSION 3.6)
project(button)

set(CMAKE_CXX_STANDARD 11)

include_directories(/opt/arduino-1.8.2/libraries/SoftwareSerial)
include_directories(/opt/arduino-1.8.2/hardware/arduino/avr/cores/arduino)
include_directories(/opt/arduino-1.8.2/hardware/arduino/variants/micro)
include_directories(../log)

set(SOURCE_FILES test/main.cpp button.cpp button.h)
#set(SOURCE_FILES test/main.cpp)

add_executable(lipo ${SOURCE_FILES})