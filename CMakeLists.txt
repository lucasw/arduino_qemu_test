cmake_minimum_required(VERSION 3.16)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/arduino-cmake/cmake/ArduinoToolchain.cmake)
project(arduino_qemu_test)


message(STATUS "Using toolchain file: ${CMAKE_TOOLCHAIN_FILE}")

set(ARDUINO_DEFAULT_BOARD mega2560)
set(ARDUINO_DEFAULT_PORT /dev/ttyUSB0)

generate_arduino_firmware(test
  SKETCH src/test.ino)
