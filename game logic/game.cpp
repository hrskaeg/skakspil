#include "game.h"
#include "rules.h"
#include "piece.h"
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

//Below block checks kingsafety post move is executed. Can't check own king by moving piece
Board tempBoard = board;    //temp board to simulate king safety after move is executed.
tempBoard.movePiece(move.from.row, move.from.col, move.to.row, move.to.col);
Position kingPos = findKing(tempBoard,getTurn());
Color enemyColor = (getTurn() == Color::White) ? Color::Black : Color::White; //Finds enemyColor
if(Rules::isSquareAttacked(tempBoard,kingPos,enemyColor)){   //Checks if kingPos is attacked after move executed

    std::cout << "Move checks own king!" << std::endl;
    return false;
}




//Logs move in history
moveHistory.push_back({
    move.from,
    move.to,
    piece,
    board.getPiece(move.to.row, move.to.col)

});
//Performs move
board.movePiece(move.from.row, move.from.col, move.to.row,move.to.col);
switchTurn();
return true;
}   

void Game::switchTurn(){
    currentTurn = (currentTurn == Color::White) ? Color::Black : Color::White;

    std::cout << "Turn switched. " << ((currentTurn == Color::White) ? "White" : "Black") << " to move" << std::endl;
}                          

void printBoard(){

}
                 
const Board& getBoard(){

}

Position findKing(const Board& board, Color color){
for (int r = 0; r < 8; r++){ //Iterates through all rows
    for (int c = 0; c < 8; c++){ //combined with iterating through all columns = iterates all squares on board.
        const Piece& piece = board.getPiece(r,c); //gets piece of current square ite
        if (piece.type == Piecetype::King && piece.color == color)
        {
            return {r,c};
        }
}
}
//If no king found (should never happen)
return {-1,-1};
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