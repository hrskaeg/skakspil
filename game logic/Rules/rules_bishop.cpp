#include "rules.h"
#include <cmath>

bool Rules::Bishop::isValidMove(const Board& board, const Move& move) {
const Piece& piece = board.getPiece(move.from.row, move.from.col);
const Piece& TargetSquare = board.getPiece(move.to.row, move.to.col);

if (piece.type != Piecetype::Bishop) //safety check that piece is bishop
{
    return false; 
}
//calculate move length
int dRow = abs(move.to.row - move.from.row);
int dCol = abs(move.to.col - move.from.col);

if(dRow != dCol) //Only diagonal movement. so it must travel the same columns as rows.
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
        TargetSquare.type == Piecetype::None;
}