#include "rules.h"
#include "board.h"
#include "piece.h"




bool pathIsClear(const Board& board, Position from, Position to){


}

//Checks if given position contains enemy unit.
bool isEnemyPiece(const Board& board, Position from, Position to){
Piece fromPiece = board.getPiece(from.row, from.col);
Piece toPiece = board.getPiece(to.row, to.col);


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


//Dummy definitions of piece rules
bool Rules::Pawn::isValidMove(const Board& board, const Move& move) {
    return true;
}

bool Rules::Rook::isValidMove(const Board& board, const Move& move) {

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




