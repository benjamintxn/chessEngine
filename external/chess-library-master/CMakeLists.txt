cmake_minimum_required(VERSION 3.25)
project(chess_library)

set(CMAKE_CXX_STANDARD 17)

# Library source files
set(CHESS_LIBRARY_SOURCES
    src/chess.hpp
    src/main.cpp)

# Create the chess library
add_library(chess_library ${CHESS_LIBRARY_SOURCES})

# Test source files
set(CHESS_LIBRARY_TEST_SOURCES
    tests/doctest/doctest.hpp
    tests/hash.cpp
    tests/main.cpp
    tests/perft.cpp
    tests/san.cpp)

# Create tests executable
add_executable(chess_library_tests ${CHESS_LIBRARY_TEST_SOURCES})

# Link the library to the tests executable
target_link_libraries(chess_library_tests PRIVATE chess_library)
