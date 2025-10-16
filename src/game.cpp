#include "include/game.h"
#include "include/rules.h"
#include <vector>
#include <iostream>

MoveStatus Game::tryMove(const Move& move){
const Piece& piece = board.getPiece(move.from.row, move.from.col);


//Validations
if (piece.color != getTurn()){return MoveStatus::NotYourTurn;}
if (!Rules::isValidMove(board,move)){return MoveStatus::IllegalMove;}
if (piece.type == Piecetype::None){return MoveStatus::MovingEmpty;}
if (!Rules::isKingSafePostMove(board,move)){return MoveStatus::KingThreatened;}

//Logs move in history
moveHistory.push_back({
    move.from,
    move.to,
    piece,
    board.getPiece(move.to.row, move.to.col)
});


//Performs move
board.executeMove(move);
    
handlePromotion(move);
switchTurn();
return MoveStatus::Success;
}

Game::Game()
    : board(), currentTurn(Color::White)
{
    //initializes starting position
    board.setupDefault();
}
void Game::switchTurn(){
    currentTurn = (currentTurn == Color::White) ? Color::Black : Color::White;

    //std::cout << "Turn switched. " << ((currentTurn == Color::White) ? "White" : "Black") << " to move" << std::endl;
}                          


                 
const Board& Game::getBoard()const{ return board;} //returns current board when called
Board& Game::getBoard() { return board; } 

void Game::setTurn(Color turn){
    currentTurn = turn;
}





Color Game::getTurn() const{return currentTurn;}            //Returns color of current turn


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
                    if (Rules::isValidMove(board,m)){
                        Board tempBoard = board;
                        tempBoard.executeMove(m);

                        //check kingsafety postmove
                        Position kingPos = Rules::findKing(tempBoard, color);
                        Color enemyColor = (color == Color::White) ? Color::Black : Color::White;

                        //only add move if king is safe after move
                        if (!Rules::isSquareAttacked(tempBoard, kingPos, enemyColor)){
                            moves.push_back(m);
                        }
                    }
                }
            }
        }
    }
    return moves;
}

//returns True if color passed is in check
bool Game::inCheck(const Color& color)const{ 
Position kingPos = Rules::findKing(board,color);
Color enemyColor = (color == Color::White) ? Color::Black : Color::White; //Finds enemyColor
return Rules::isSquareAttacked(board, kingPos, enemyColor);

}

//returns true if in stalemate
bool Game::inStalemate(Color color)const{
if (inCheck(color)) return false; //if king is in check, not stalemate

std::vector<Move> moves = generateAllMoves(color); //vector called 'moves' with all legal moves

for (const Move& m : moves) { //iterates through all moves in vector 'moves'
    Board tempBoard = board;
    tempBoard.executeMove(m); //executes current ite on tempboard

    Position kingPos = Rules::findKing(tempBoard,color);
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
    tempBoard.executeMove(m); //executes current ite on tempboard

    Position kingPos = Rules::findKing(tempBoard,color);
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
        (p.color == Color::Black && move.to.row == 0)){
            p.type = Piecetype::Queen;
            std::cout << "Pawn promoted to Queen!" << std::endl;
        }
}


}


