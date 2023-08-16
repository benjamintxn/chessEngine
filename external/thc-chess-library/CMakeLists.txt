# CMakeLists.txt for thc-chess-library

# Define the library target
add_library(thc_chess_static STATIC
    src/thc.cpp
    src/thc.h
    # Add other source files here
)

# Set include directories for the library
target_include_directories(thc_chess_static PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

# Export the target so other projects can use it
export(TARGETS thc_chess_static FILE thc-chess-targets.cmake)

# Set variables for external projects to use
set(THC_CHESS_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/src CACHE INTERNAL "thc-chess-library include directory")
set(THC_CHESS_LIBRARIES thc_chess_static CACHE INTERNAL "thc-chess-library libraries")
