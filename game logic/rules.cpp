#include "rules.h"
#include "board.h"
#include "piece.h"


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


//Dummy definitions of piece rules
bool Rules::Pawn::isValidMove(const Board& board, const Move& move) {
    return true;
}

bool Rules::Rook::isValidMove(const Board& board, const Move& move) {
    return true;
}

bool Rules::Knight::isValidMove(const Board& board, const Move& move) {
    return true;
}

bool Rules::Bishop::isValidMove(const Board& board, const Move& move) {
    return true;
}

bool Rules::Queen::isValidMove(const Board& board, const Move& move) {
    return true;
}

bool Rules::King::isValidMove(const Board& board, const Move& move) {
    return true;
}




