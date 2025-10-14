#include "game.h"
#include "rules.h"
#include <vector>
#include <iostream>


bool Game::tryMove(const Move& move){
const Piece& piece = board.getPiece(move.from.row, move.from.col);

//validates if turn
if (piece.color != getTurn())
{
    std::cout << "Not your turn!" << std::endl;
    return false;
}

//validates if legal
if (!Rules::isValidMove(board,move))
{
    std::cout << "Illegal move!" << std::endl;
    return false;
}
//Performs move
moveHistory.push_back({
    move.from,
    move.to,
    piece,
    board.getPiece(move.to.row, move.to.col)

});

board.movePiece(move.from.row, move.from.col, move.to.row,move.to.col);
switchTurn();
return true;
}   

void Game::switchTurn(){
    currentTurn = (currentTurn == Color::White) ? Color::Black : Color::White;

    std::cout << "Turn switched. " << ((currentTurn == Color::White) ? "White" : "Black") << " to move" << std::endl;
}                          

void printBoard()const{

}
                 
const Board& getBoard() const{

}

Color Game::getTurn() const{                      //Returns color of current turn
const Move& lastmove = moveHistory.back();  //readonly of moveHistory vector, saves latest entry in lastmove
    if (lastmove.movedPiece.color == Color::White){     //checks latest entry for movedpiece.color
        return Color::Black;
    }
    else if (lastmove.movedPiece.color == Color::Black){
        return Color::White;
    }
    else
    return Color::White;
}