#include "perft.h"
#include <iostream>
#include <vector>
#include <iostream>

namespace Testing {

long perft(Game& game, int depth) {
    if (depth == 0)
        return 1;

    long nodes = 0;
    auto moves = game.generateAllMoves(game.getTurn());

    for (const auto& m : moves) {
        Game next = game;
        auto res = next.tryMove(m);
        if (res != MoveStatus::Success){continue;};
        nodes += perft(next, depth - 1);
    }

    return nodes;
}

void runPerftSuite(Game& game, int maxDepth) {
    for (int d = 1; d <= maxDepth; ++d) {
        long n = perft(game, d);
        std::cout << "Perft(" << d << ") = " << n << "\n";
    }
}

void perftDivide(Game& game, int depth) {
    auto moves = game.generateAllMoves(game.getTurn());
    for (const auto& m : moves) {
        Game next = game;
        auto res = next.tryMove(m);                     
        if (res == MoveStatus::Success) {
            auto nodes = Testing::perft(next, depth - 1);
            std::cout << m.toString() << ": " << nodes << "\n";
        }
    }
}

} // namespace Testing
