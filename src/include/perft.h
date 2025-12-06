#pragma once
#include "game.h"

namespace Testing {

    // Runs a recursive perft calculation from the given game state
    long perft(Game& game, int depth);

    //Helper to print per-depth results
    void runPerftSuite(Game& game, int maxDepth);

    void perftDivide(Game& game, int depth); //debugging
    bool isPromotionMove(const Game& game, const Move& m);
}
