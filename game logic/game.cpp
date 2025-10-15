#include "game.h"
#include "rules.h"
#include <vector>
#include <iostream>

bool Game::tryMove(const Move& move){
const Piece& piece = board.getPiece(move.from.row, move.from.col);

//validates if turn
if (piece.color != getTurn())
{
    std::cout << "Not your turn!" << std::endl;
    return false;
}

//validates if legal
if (!Rules::isValidMove(board,move))
{
    std::cout << "Illegal move!" << std::endl;
    return false;
}

//Below block checks kingsafety post move is executed. Can't check own king by moving piece
Board tempBoard = board;    //temp board to simulate king safety after move is executed.
tempBoard.movePiece(move.from.row, move.from.col, move.to.row, move.to.col);
Position kingPos = findKing(tempBoard,getTurn());
Color enemyColor = (getTurn() == Color::White) ? Color::Black : Color::White; //Finds enemyColor
if(Rules::isSquareAttacked(tempBoard,kingPos,enemyColor)){   //Checks if kingPos is attacked after move executed

    std::cout << "Move leaves own king in check!" << std::endl;
    return false;
}


//Logs move in history
moveHistory.push_back({
    move.from,
    move.to,
    piece,
    board.getPiece(move.to.row, move.to.col)

});
//Performs move
board.movePiece(move.from.row, move.from.col, move.to.row,move.to.col);
switchTurn();
return true;
}   

void Game::switchTurn(){
    currentTurn = (currentTurn == Color::White) ? Color::Black : Color::White;

    std::cout << "Turn switched. " << ((currentTurn == Color::White) ? "White" : "Black") << " to move" << std::endl;
}                          

void printBoard(){

}
                 
const Board& Game::getBoard()const{

}

Position Game::findKing(const Board& board, Color color) const{
for (int r = 0; r < 8; r++){ //Iterates through all rows
    for (int c = 0; c < 8; c++){ //combined with iterating through all columns = iterates all squares on board.
        const Piece& piece = board.getPiece(r,c); //gets piece of current square ite
        if (piece.type == Piecetype::King && piece.color == color)
        {
            return {r,c};
        }
}
}
//If no king found (should never happen)
return {-1,-1};
}

Color Game::getTurn() const{            //Returns color of current turn
const Move& lastmove = moveHistory.back();  //readonly of moveHistory vector, saves latest entry in lastmove
    if (lastmove.movedPiece.color == Color::White){     //checks latest entry for movedpiece.color
        return Color::Black;
    }
    else if (lastmove.movedPiece.color == Color::Black){
        return Color::White;
    }
    else
    return Color::White;
}


//returns vector with all possible moves for color provided
std::vector<Move> Game::generateAllMoves (Color color) const{
    std::vector<Move> moves;
    for (int r = 0; r < 8; r++){ //Iterates through all rows
        for (int c = 0; c < 8; c++){ //combined with iterating through all columns = iterates all squares on board.
            const Piece& piece = board.getPiece(r,c);
            if (piece.color != color || piece.type == Piecetype::None){ continue;} //checks if current ite piececolor is opposite, or if piece empty, goes next ite.

        
            for (int tr = 0; tr < 8; tr++){ //Iterates through all rows
                for (int tc = 0; tc < 8; tc++){ //combined with iterating through all columns = iterates all squares on board.
                    Move m{{r,c}, {tr,tc}}; //saves moveset as m
                    if (Rules::isValidMove(board,m))
                    moves.push_back(m); //saves move in vector
                }
            }
        }
    }
    return moves;
}

//returns True if color passed is in check
bool Game::inCheck(const Color& color)const{ 
Position kingPos = findKing(board,color);
Color enemyColor = (getTurn() == Color::White) ? Color::Black : Color::White; //Finds enemyColor
return Rules::isSquareAttacked(board, kingPos, enemyColor);

}

//returns true if in stalemate
bool Game::inStalemate(Color color)const{
if (inCheck(color)) return false; //if king is in check, not stalemate

std::vector<Move> moves = generateAllMoves(color); //vector called 'moves' with all legal moves

for (const Move& m : moves) { //iterates through all moves in vector 'moves'
    Board tempBoard = board;
    tempBoard.movePiece(m.from.row, m.from.col, m.to.row, m.to.col); //executes current ite on tempboard

    Position kingPos = findKing(tempBoard,color);
    Color enemyColor = (color == Color::White) ? Color::Black : Color::White; //finds king, sets enemyColor

        if (!Rules::isSquareAttacked(tempBoard, kingPos,enemyColor)){  
            return false; //if king is NOT attacked after move simulated -> found legal move, where king is not threatened
            }
 
}
return true;//No legal moves to avoid checkmate
}

//returns true if in checkmate
bool Game::inCheckmate(Color color)const{
if (!inCheck(color)) return false;


std::vector<Move> moves = generateAllMoves(color); //vector 'moves' with all legal moves

for (const Move& m : moves) { //iterates through all moves in vector 'moves'
    Board tempBoard = board;
    tempBoard.movePiece(m.from.row, m.from.col, m.to.row, m.to.col); //executes current ite on tempboard

    Position kingPos = findKing(tempBoard,color);
    Color enemyColor = (color == Color::White) ? Color::Black : Color::White; //finds king, sets enemyColor

        if (!Rules::isSquareAttacked(tempBoard, kingPos,enemyColor)){  
            return false; //if king is NOT attacked after move simulated -> found legal move, where king is not threatened
            }
 
}
return true;//No legal moves to avoid checkmate
}

//When called, swaps the pawn on the backrank to a queen
void Game::handlePromotion(const Move& move){
Piece& p = board.getPiece(move.to.row,move.to.col);
if (p.type == Piecetype::Pawn){
    if((p.color == Color::White && move.to.row == 7) ||
        p.color == Color::Black && move.to.row == 0){
            p.type = Piecetype::Queen;
            std::cout << "Pawn promoted to Queen!" << std::endl;
        }
}


}