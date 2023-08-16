cmake_minimum_required(VERSION 3.10)
project(chessEngine)

# Add the thc-chess-library as a CMake submodule
add_subdirectory(external/thc-chess-library)

# Add your source files
add_executable(chessEngine chessEngine/main.cpp)

# Link against thc_chess_static
target_link_libraries(chessEngine PRIVATE thc_chess_static)
