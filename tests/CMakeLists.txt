add_executable(test_moves ${CMAKE_CURRENT_SOURCE_DIR}/test_moves.cpp)
target_include_directories(test_moves PRIVATE ${PROJECT_SOURCE_DIR}/src/include)

# ✅ Link to the reusable core logic library
target_link_libraries(test_moves PRIVATE skakspil_lib)

add_test(NAME TestMoves COMMAND test_moves)

add_test(NAME SkakspilRuns
    COMMAND powershell -NoProfile -ExecutionPolicy Bypass -Command
            "echo 'exit' | & '$<TARGET_FILE:skakspil>'"
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

# --- test_perft --------------------------------------------------------------
add_executable(test_perft
    ${CMAKE_CURRENT_SOURCE_DIR}/test_perft.cpp
)
target_include_directories(test_perft PRIVATE
    ${PROJECT_SOURCE_DIR}/src/include
)
target_link_libraries(test_perft PRIVATE skakspil_lib)
add_test(NAME PerftTest COMMAND test_perft)
