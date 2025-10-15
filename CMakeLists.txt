cmake_minimum_required(VERSION 3.16)
project(skakspil LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_WIN32_EXECUTABLE OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add your source files
add_executable(skakspil
    src/main.cpp
    src/board.cpp
    src/game.cpp
    src/rules.cpp
    src/piece_rules/rules_pawn.cpp
    src/piece_rules/rules_rook.cpp
    src/piece_rules/rules_bishop.cpp
    src/piece_rules/rules_queen.cpp
    src/piece_rules/rules_knight.cpp
    src/piece_rules/rules_king.cpp)

target_include_directories(skakspil PRIVATE src/include)

enable_testing()
add_subdirectory(tests)
