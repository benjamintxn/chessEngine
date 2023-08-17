cmake_minimum_required(VERSION 3.10)
project(chessEngine)

set(CMAKE_CXX_STANDARD 17)

# Add the chess-library-master as a CMake submodule
add_subdirectory(external/chess-library-master)

# Add source files
add_executable(chessEngine
    src/main.cpp
    src/functionality.hpp # Add your header file here
)

# Link libraries
target_link_libraries(chessEngine PRIVATE chess_library)
target_link_libraries(chessEngine PRIVATE sfml-graphics sfml-window sfml-system)

# Include directories for external libraries
target_include_directories(chessEngine PRIVATE external/chess-library-master/src)

# Include the chessEngine library for your header
target_include_directories(chessEngine PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# Add SFML include directories
find_package(SFML 2.6 COMPONENTS graphics window system REQUIRED)
target_include_directories(chessEngine PRIVATE ${SFML_INCLUDE_DIR})
