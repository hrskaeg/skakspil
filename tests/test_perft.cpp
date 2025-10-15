#include "perft.h"
#include "game.h"
#include "fen.h"
#include <iostream>



int main() {
    std::string fen;
    int depth;

    std::cout << "Enter FEN string: ";
    std::getline(std::cin, fen);

    std::cout << "Enter perft depth: ";
    std::cin >> depth;

    Game game;
    FEN::loadPosition(game, fen);


    

    std::cout << "\nFEN: " << fen << std::endl;
    Testing::perftDivide(game, depth);

    return 0;
}