cmake_minimum_required(VERSION 3.16)
project(skakspil LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_WIN32_EXECUTABLE OFF)

# --- Build reusable library (core game logic) ---
add_library(skakspil_lib
    src/board.cpp
    src/game.cpp
    src/rules.cpp
    src/move.cpp
    src/piece_rules/rules_pawn.cpp
    src/piece_rules/rules_rook.cpp
    src/piece_rules/rules_bishop.cpp
    src/piece_rules/rules_queen.cpp
    src/piece_rules/rules_knight.cpp
    src/piece_rules/rules_king.cpp
    src/utils/perft.cpp
    src/utils/fen.cpp
)

target_include_directories(skakspil_lib PUBLIC ${PROJECT_SOURCE_DIR}/src/include)

# --- Build the CLI executable ---
add_executable(skakspil src/main.cpp)
target_link_libraries(skakspil PRIVATE skakspil_lib)



# --- CTest ---
enable_testing()

# --- Pull in tests from top-level /tests ---
add_subdirectory(tests)
