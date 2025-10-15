#include "rules.h"
#include <cmath>


Rules::Pawn::MoveType Rules::Pawn::classifyMove(const Piece& piece, int dRow, int dCol){

//Checks piece color, direction negative if black, positive if white
int direction = (piece.color == Color::White) ? 1: -1;



//assignt movetype based on move directions
if(dCol == 0 && dRow == direction){
    return MoveType::ForwardOne;
}else if (dCol == 0 && dRow == 2*direction && !piece.hasMoved){
    return MoveType::ForwardTwo;
}else if(abs(dCol) == 1 && dRow == direction){
    return MoveType::DiagonalCapture;
}
return MoveType::None;
}

bool Rules::Pawn::isValidMove(const Board& board, const Move& move) {
const Piece& piece = board.getPiece(move.from.row, move.from.col);
const Piece& targetsquare = board.getPiece(move.to.row, move.to.col);

if (piece.type != Piecetype::Pawn) //safety check that piece is pawn
{
    return false; 
}
//calculate move length
int dRow = move.to.row - move.from.row;
int dCol = move.to.col - move.from.col;

auto moveType = classifyMove(piece, dRow, dCol);

//missing check for, if currently blocking threat to king

switch (moveType)
{
    case MoveType::ForwardOne:
        return targetsquare.type == Piecetype::None; //gets destinationsquare, and checks for empty. returns true if true
    
    case MoveType::ForwardTwo: {
        bool valid = !piece.hasMoved &&
                 Rules::pathIsClear(board, move) &&
                 targetsquare.type == Piecetype::None; //checks if pawn has moved AND if path is clear AND if destination square is empty
        if (valid){
            //mark en passant target square halfway between start and end
            const_cast<Board&>(board).setEnPassantTarget({
                (move.from.row + move.to.row) / 2, move.from.col
            });
        }else{const_cast<Board&>(board).clearEnPassantTarget();
        }
    return valid;
    }
        
    
    case MoveType::DiagonalCapture:{
        //normal capture
        if(Rules::isEnemyPiece(board, move)){ //Checks destinationsquare for enemypiece
        return true; 
        }
        
        //en passant capture
        Position ep = board.getEnPassantTarget();
        if (ep.row == move.to.row && ep.col == move.to.col)
            return true;
        }
    default:
        return false;
}



}