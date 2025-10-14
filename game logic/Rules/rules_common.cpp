#include "rules.h"
#include "piece.h"
#include <cmath>




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
//Iterates through each 'step' on the board, and returns false if blocked. Loop stops 1 short of destination square (while statement)
for (
    int r = move.from.row + stepRow, c = move.from.col + stepCol;
    (r != move.to.row) || (c != move.to.col); //while r,c is both not equal to destination square   
    r += stepRow, c += stepCol
){
    const Piece& piece = board.getPiece(r, c);

    if (piece.type != Piecetype::None)
    {
        return false; //Blocked
    }
    
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




bool Rules::isValidMove(const Board& board, const Move& move){
    const Piece& piece = board.getPiece(move.from.row, move.from.col);

    switch (piece.type)
    {
    case Piecetype::Pawn:   return Rules::Pawn::isValidMove(board, move); break;
    case Piecetype::Rook:   return Rules::Rook::isValidMove(board, move); break;
    case Piecetype::Knight: return Rules::Knight::isValidMove(board, move); break;
    case Piecetype::Bishop: return Rules::Bishop::isValidMove(board, move); break;
    case Piecetype::Queen:  return Rules::Queen::isValidMove(board, move); break;
    case Piecetype::King:   return Rules::King::isValidMove(board, move); break;
    
    default:
        break;
    }
}




bool Rules::King::isValidMove(const Board& board, const Move& move) {
    return true;
}




