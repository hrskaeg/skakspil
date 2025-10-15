#include "rules.h"
#include <cmath>

bool Rules::Knight::isValidMove(const Board& board, const Move& move) {
const Piece& piece = board.getPiece(move.from.row, move.from.col);
const Piece& targetsquare = board.getPiece(move.to.row, move.to.col);

if (piece.type != Piecetype::Knight) //safety check that piece is Knight
{
    return false; 
}

//calculate move length
int dRow = abs(move.to.row - move.from.row);
int dCol = abs(move.to.col - move.from.col);

if(!((abs(dRow) == 2 && abs(dCol) == 1) || (abs(dCol) == 2 && abs(dRow) == 1))) //knight strictly moves 2,1 either vertically or horizontally (L shape)
{
    return false;
}

//missing check for, if currently blocking threat to king

//destination must be empty or contain enemy
return  Rules::isEnemyPiece(board,move) ||
        targetsquare.type == Piecetype::None;
}