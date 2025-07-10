cmake_minimum_required(VERSION 3.14)
project(mycelium_cpp_core)

set(CMAKE_CXX_STANDARD 17)

# Include directories
include_directories(include)

# Core source files
file(GLOB SOURCES "src/*.cpp")

# Create a static or shared library
add_library(mycelium_core ${SOURCES})

# Optional: enable testing
enable_testing()
add_subdirectory(tests)
