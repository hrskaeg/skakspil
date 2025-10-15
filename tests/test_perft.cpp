#include "perft.h"
#include "game.h"
#include <iostream>


int main() {
    Game game;
    int depth = 4;
    long nodes = Testing::perft(game, depth);
    
    std::cout << "depth ("<< depth << ") returned: " << nodes << " moves" <<std::endl;

    return 0;
}