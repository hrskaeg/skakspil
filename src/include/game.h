#pragma once
#include "board.h"
#include "piece.h"
#include "move.h"
#include <vector>

enum class MoveStatus {
    Success,
    NotYourTurn,
    IllegalMove,
    MovingEmpty
};

class Game{
private:
    Board board;
    Color currentTurn = Color::White;
    std::vector<Move> moveHistory;
public:
    Game();                                                     //constructor, initialises board and turn
    MoveStatus tryMove(const Move& move);                             //Attempts move, (validates, and applies if legal)
    void switchTurn();                                          //switches from white to black
    Color getTurn() const;                                      //Returns color of current turn
    const Board& getBoard() const;   //rendering access
    Board& getBoard();    //nonconst reference
    void setTurn(Color turn); //sets turn
    std::vector<Move> generateAllMoves (Color color) const;     //outputs vector with all possible moves
    Position findKing(const Board& board, Color color) const;   //Returns king position based on color provided
    bool inCheck(const Color& color) const;                     //Checks if king is threatened
    bool inStalemate(Color color) const;                        //Checks if king is in stalemate
    bool inCheckmate(Color color) const;                        //Checks if king is in checkmate
    void handlePromotion(const Move& move);
    void handleCastling(const Move& move);
    void executeMove(const Move& move);
    void postMoveChecks(const Move& move);

    
};



