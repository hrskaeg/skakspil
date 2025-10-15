#include "perft.h"
#include <iostream>

namespace Testing {

long perft(Game& game, int depth) {
    if (depth == 0)
        return 1;

    long nodes = 0;
    std::vector<Move> moves = game.generateAllMoves(game.getTurn());

    for (const Move& move : moves) {
        Game nextState = game;  // copy whole game
        nextState.tryMove(move);
        nodes += perft(nextState, depth - 1);
    }

    return nodes;
}

void runPerftSuite(Game& game, int maxDepth) {
    for (int d = 1; d <= maxDepth; ++d) {
        long nodes = perft(game, d);
        std::cout << "Perft(" << d << ") = " << nodes << std::endl;
    }
}

}