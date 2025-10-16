// tests/ep_test_pin.cpp
#include <cassert>
#include <iostream>
#include "game.h"
#include "fen.h"

static bool hasMove(const std::vector<Move>& ms, Position f, Position t) {
    for (auto& m : ms) if (m.from.row==f.row && m.from.col==f.col &&
                           m.to.row==t.row && m.to.col==t.col) return true;
    return false;
}

int main() {
    Game g;
    // 4r3/8/8/3pK3/8/8/8/8 w - d6 0 1
    // rows: 7..0 = ranks 8..1
    FEN::loadPosition(g, "4r3/8/8/3pK3/8/8/8/8 w - d6 0 1");
    auto ms = g.generateAllMoves(Color::White);
    
    Position from = {4,4}, to = {5,3};
    assert(!hasMove(ms, from, to) && "EP capture must be illegal when it exposes king to check");
    std::cout << "[EP pin] OK\n";
    return 0;
}
