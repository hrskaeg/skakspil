#include <iostream>
#include <cassert>
#include "fen.h"
#include "game.h"
#include "board.h"
#include "perft.h"

int main() {
    std::cout << "=== FEN Loader Test ===\n";

    // Test 1: Starting position
    {
        Game game;
        std::string startFEN = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
        FEN::loadPosition(game, startFEN);

        std::cout << "Loaded starting position:\n";
        game.getBoard().printBoard();

        // Optional sanity check: Perft(1) = 20, Perft(2) = 400
        long nodes = Testing::perft(game, 2);
        std::cout << "Perft(2) = " << nodes << std::endl;
        assert(nodes == 400 && "Starting FEN should produce 400 moves at depth 2");
    }

    // Test 2: Kiwipete position (used to validate castling + en passant later)
    {
        Game game;
        std::string kiwipete =
            "r3k2r/p1ppqpb1/bn2pnp1/3PN3/1p2P3/2N2Q1p/PPPBBPPP/R3K2R w KQkq - ";
        FEN::loadPosition(game, kiwipete);

        std::cout << "\nLoaded Kiwipete test position:\n";
        game.getBoard().printBoard();

        //Perfttest on kiwipete (reference: perft(1)=48, perft(2)=2039)
        long nodes = Testing::perft(game, 2);
        std::cout << "Perft(2) = " << nodes << std::endl;
    }

    std::cout << "\n=== FEN Loader Test Completed ===\n";
    return 0;
}
