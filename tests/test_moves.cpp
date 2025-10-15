#include "../src/include/board.h"
#include "../src/include/rules.h"
#include "../src/include/game.h"
#include <cassert>
#include <iostream>

int main() {
    std::cout << "Running basic chess tests...\n";

    Board board;
    board.setupDefault();

    // Example 1: Pawn move
    Move pawnMove{{1, 0}, {3, 0}}; // white pawn forward two
    assert(Rules::isValidMove(board, pawnMove) && "Pawn should be able to move 2 steps from start");

    // Example 2: Illegal rook move (blocked by pawn)
    Move rookMove{{0, 0}, {0, 3}};
    assert(!Rules::isValidMove(board, rookMove) && "Rook cannot move through pieces");

    // Example 3: Knight jump over pieces
    Move knightMove{{0, 1}, {2, 2}};
    assert(Rules::isValidMove(board, knightMove) && "Knight should jump over pieces");

    std::cout << "✅ All tests passed!\n";
    return 0;
}
