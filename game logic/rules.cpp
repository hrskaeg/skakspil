#include "rules.h"
#include "board.h"


bool Rules::isValidMove(const Board& board, const Move& move){
    const Piece& piece = board.getpiece(move.from.row, move.from.col);

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


