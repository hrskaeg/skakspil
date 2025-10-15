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

if(!piece.hasMoved && dRow == 0 && abs(dCol) == 2){ //Castling
    return Rules::King::canCastle(board,move);
}

if (abs(dRow) > 1 || abs(dCol) > 1) // check if movement length is greater than 1 in either direction
{
    return false;
}


//destination must be empty or contain enemy
return  Rules::isEnemyPiece(board,move) ||
        targetsquare.type == Piecetype::None;
}





bool Rules::King::canCastle(const Board& board, const Move& move){
const Piece& king = board.getPiece(move.from.row,move.from.col);
Color color = king.color;
if (king.type !=Piecetype::King ||king.hasMoved !=false ){ //First condition, has the king moved?
    return false;
    }

int row = move.from.row;
int direction = (move.to.col > move.from.col) ? 1 : -1; //+1 = kingside castle, -1 = queenside castle
int rookCol = (direction > 0) ? 7 : 0; //selects appropiate rook based on direction
const Piece& rook = board.getPiece(row,rookCol);
if (rook.type !=Piecetype::Rook || rook.color !=color || rook.hasMoved !=false ){ //second condition, has the rook moved?
    return false;
    }

if(!Rules::pathIsClear(board, {move.from, {row, rookCol}})){    //Third condition. Is the path clear between king and rook?
    return false;
    }

if (Rules::isSquareAttacked(board, {move.from.row, move.from.col}, (color == Color::White ? Color::Black : Color::White))){ //Fourth condition, is king currently checked?
    return false;
    }

for (int step = 0; step <=2; ++step){
    Position testPos{row, move.from.col + direction*step};
    if (Rules::isSquareAttacked(board, testPos,(color == Color::White ? Color::Black : Color::White))){ //fifth confition. Is squares between rook and king threatened?
        return false;
        
    }
}
//If all above checks are ok, return true -> castling valid.
return true;
    

}
