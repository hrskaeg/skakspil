#include "rules.h"
#include <cmath>

bool Rules::Queen::isValidMove(const Board& board, const Move& move) {
const Piece& piece = board.getPiece(move.from.row, move.from.col);
const Piece& targetsquare = board.getPiece(move.to.row, move.to.col);

if (piece.type != Piecetype::Queen) //safety check that piece is Queen
{
    return false; 
}

//calculate move length
int dRow = abs(move.to.row - move.from.row);
int dCol = abs(move.to.col - move.from.col);

if(!(dRow == 0 || dCol == 0 || abs(dCol) == abs(dRow))) //Queen either moves: vertically (dRow=0), horizontally (dCol=0), or diagonally (abs(dRow) == abs(dCol))
{
    return false;
}

if(!Rules::pathIsClear(board,move)) //path must be clear (not counting destination)
{
    return false;
}

//missing check for, if currently blocking threat to king

//destination must be empty or contain enemy
return  Rules::isEnemyPiece(board,move) ||
        targetsquare.type == Piecetype::None;
}