#pragma once
#include "board.h"
#include "piece.h"
#include "move.h"
#include <vector>

class Game{
private:
    Board board;
    Color currentTurn = Color::White;
    std::vector<Move> moveHistory;
public:
    Game();                                     //constructor, initialises board and turn
    bool tryMove(const Move& move);   //Attempts move, (validates, and applies if legal)
    void switchTurn();                          //switches from white to black
    void printBoard()const;
    Color getTurn() const;                      //Returns color of current turn
    const Board& getBoard() const;              //rendering access
};