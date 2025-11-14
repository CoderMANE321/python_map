cmake_minimum_required(VERSION 3.10)
project(PythonMap)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add include directory
include_directories(include)

# Build the executable
add_executable(Map
    src/main.cpp
    src/string.cpp
    src/stack.cpp
    src/queue.cpp
    src/list.cpp
    src/dict.cpp
)
