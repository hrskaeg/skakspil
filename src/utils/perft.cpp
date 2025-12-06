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




bool isPromotionMove(const Game& game, const Move& m) {
    const Piece& p = game.getBoard().getPiece(m.from.row, m.from.col);
    if (p.type != Piecetype::Pawn) return false;

    int tr = m.to.row;
    return (tr == 0 || tr == 7);  // last rank for either side
}


void runPerftSuite(Game& game, int maxDepth) {
    for (int d = 1; d <= maxDepth; ++d) {
        long n = perft(game, d);
        std::cout << "Perft(" << d << ") = " << n << "\n";
    }
}

void perftDivide(Game& game, int depth) {
    auto moves = game.generateAllMoves(game.getTurn());
    //all promotion pieces available
    const Piecetype promotionPieces[] = {
        Piecetype::Queen,
        Piecetype::Rook,
        Piecetype::Bishop,
        Piecetype::Knight
    };

    for (const auto& m : moves) {
        int nodesForThisMove = 0;
        if (isPromotionMove(game, m)) {
            // Handle all promotion types
            for (const auto& promoType : promotionPieces) {
                Game next = game;
                auto res = next.tryMove(m, promoType);
                if (res == MoveStatus::Success) {
                    nodesForThisMove += perft(next, depth - 1);
                }
            }
        } else {
        Game next = game;
        auto res = next.tryMove(m, Piecetype::None);
        if (res == MoveStatus::Success) {
            nodesForThisMove += Testing::perft(next, depth - 1);
        }
    }
    std::cout << m.toString() << ": " << nodesForThisMove << "\n";
}

} // namespace Testing
}
