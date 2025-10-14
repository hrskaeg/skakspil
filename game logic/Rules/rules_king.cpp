#include "rules.h"
#include <cmath>


bool Rules::King::isValidMove(const Board& board, const Move& move) {
const Piece& piece = board.getPiece(move.from.row, move.from.col);
const Piece& targetsquare = board.getPiece(move.to.row, move.to.col);
if (piece.type != Piecetype::King) //safety check that piece is king
{
    return false; 
}

//calculate move length
int dRow = move.to.row - move.from.row;
int dCol = move.to.col - move.from.col;

if (abs(dRow) > 1 || abs(dCol) > 1) // check if movement length is greater than 1 in either direction
{
    return false;
}

//Missing castling, and check for whether square is threatened

//destination must be empty or contain enemy
return  Rules::isEnemyPiece(board,move) ||
        targetsquare.type == Piecetype::None;
}