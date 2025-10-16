#include "include/rules.h"
#include "include/piece.h"
#include "game.h"
#include <cmath>
#include <iostream>




bool Rules::pathIsClear(const Board& board, const Move& move){
//compute direction between start and end position (deltaRow, deltaCol)
int dRow = move.to.row - move.from.row;
int dCol = move.to.col - move.from.col;

// quick exit for |1| size movements, where no path checks are required.
if (abs(dRow) <= 1 && abs(dCol) <= 1) {
        return true;
    }

//Provide direction for pieces along each axis, with 'steps' for row and col. Direction can never change with piece moves.
//Checks if dRow is none, negative or positive. If negative, each 'step' is -1, if positivie 1. Same for dCol
int stepRow;
    if (dRow == 0) {
        stepRow = 0;
    }
    else if (dRow > 0) {
        stepRow = 1;
    }
    else {
        stepRow = -1;
    }

int stepCol;
    if (dCol == 0) {
        stepCol = 0;
    }
    else if (dCol > 0) {
        stepCol = 1;
    }
    else {
        stepCol = -1;
    }
//Iterates through each 'step' on the board, and returns false if blocked. Loop stops 1 short of destination square
int r = move.from.row + stepRow, c = move.from.col + stepCol;
while (r != move.to.row || c != move.to.col) {
    const Piece& piece = board.getPiece(r, c);
    if (piece.type != Piecetype::None) return false;
    r += stepRow; c += stepCol;
}
return true; //reached destination without any pieces blocking
}

//Checks if given position contains enemy unit.
bool Rules::isEnemyPiece(const Board& board, const Move& move){
Piece fromPiece = board.getPiece(move.from.row, move.from.col);
Piece toPiece = board.getPiece(move.to.row, move.to.col);


if (toPiece.color == Color::None) //if empty return false
{
    return false;
}else if (toPiece.color != fromPiece.color){ //if not same color, return true
    return true;
}else{              //else return false (same color)
    return false;
}



}

Position Rules::findKing(const Board& board, Color color){
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

//checks kingsafety post move is executed. Can't check own king by moving piece
bool Rules::isKingSafePostMove(const Board& board, const Move& move){
    Color pieceColor = board.getPiece(move.from.row,move.from.col).color;
    Board tempBoard = board;    //temp board to simulate king safety after move is executed.
    tempBoard.executeMove(move);

    
    Position kingPos = findKing(tempBoard,pieceColor);
    Color enemyColor = (pieceColor == Color::White) ? Color::Black : Color::White; //Finds enemyColor
    if(Rules::isSquareAttacked(tempBoard,kingPos,enemyColor)){   //Checks if kingPos is attacked after move executed
    return false;
}
else{return true;} //if not, king is safe post move.
}

bool Rules::isValidMove(const Board& board, const Move& move){
    const Piece& piece = board.getPiece(move.from.row, move.from.col);


    switch (piece.type)
    {
    case Piecetype::Pawn:   return Rules::Pawn::isValidMove(board, move);
    case Piecetype::Rook:   return Rules::Rook::isValidMove(board, move);
    case Piecetype::Knight: return Rules::Knight::isValidMove(board, move);
    case Piecetype::Bishop: return Rules::Bishop::isValidMove(board, move);
    case Piecetype::Queen:  return Rules::Queen::isValidMove(board, move);
    case Piecetype::King:   return Rules::King::isValidMove(board, move);
    
    default:
        return false;
    }
}

//position is position to be checked for threats. byColor is the color that we want to see if threatens square
bool Rules::isSquareAttacked(const Board& board, const Position& position, const Color& byColor){
for (int r = 0; r < 8; r++){ //Iterates through all rows
    for (int c = 0; c < 8; c++){ //combined with iterating through all columns = iterates all squares on board.
        const Piece& piece = board.getPiece(r,c); //gets piece of current square ite
        
        if (piece.type == Piecetype::None ){continue;} //If current square is empty, skip to next iteration
        if (piece.color != byColor) {continue;} //If current piece is not of color we're checking, skip to next iteration
        
        //Simulates current ite' piece, movement to position we're checking. If the move is legal, meaning square is attacked, return true 
        Move simulateMove{{r,c}, position};
        if (Rules::isValidMove(board, simulateMove)){
            return true;
        }
    }
    
}

return false;

}


