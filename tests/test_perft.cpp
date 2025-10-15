#include "perft.h"
#include "game.h"
#include <iostream>



int main() {
    Game g;
    std::cout << "==== DEPTH 1 ====\n";
    Testing::perftDivide(g, 1);
    std::cout << "\n==== DEPTH 2 ====\n";
    Testing::perftDivide(g, 2);
}