#include "rules.h"
#include <cmath>


bool Rules::Rook::isValidMove(const Board& board, const Move& move) {
const Piece& piece = board.getPiece(move.from.row, move.from.col);
const Piece& targetsquare = board.getPiece(move.to.row, move.to.col);
if (piece.type != Piecetype::Rook) //safety check that piece is rook
{
    return false; 
}
//calculate move length
int dRow = move.to.row - move.from.row;
int dCol = move.to.col - move.from.col;

if(dRow != 0 && dCol != 0) //Strictly moves rows or columns
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