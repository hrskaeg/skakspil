#include "board.h"
#include "piece.h"

Board::Board() {
    setupDefault();
}

//Board startposition
void Board::setupDefault(){
//White backrank
squares[0][0] = {Piecetype::Rook,   Color::White};
squares[0][1] = {Piecetype::Knight, Color::White};
squares[0][2] = {Piecetype::Bishop, Color::White};
squares[0][3] = {Piecetype::Queen,  Color::White};
squares[0][4] = {Piecetype::King,   Color::White};
squares[0][5] = {Piecetype::Bishop, Color::White};
squares[0][6] = {Piecetype::Knight, Color::White};
squares[0][7] = {Piecetype::Rook,   Color::White};

//white pawns
for (int col = 0; col < 8; col++)
{
    squares[1][col] = {Piecetype::Pawn, Color::White};
}


//Black backrank
squares[7][0] = {Piecetype::Rook,   Color::Black};
squares[7][1] = {Piecetype::Knight, Color::Black};
squares[7][2] = {Piecetype::Bishop, Color::Black};
squares[7][3] = {Piecetype::Queen,  Color::Black};
squares[7][4] = {Piecetype::King,   Color::Black};
squares[7][5] = {Piecetype::Bishop, Color::Black};
squares[7][6] = {Piecetype::Knight, Color::Black};
squares[7][7] = {Piecetype::Rook,   Color::Black};

//Black pawns
for (int col = 0; col < 8; col++)
{
    squares[6][col] = {Piecetype::Pawn, Color::Black};
}

//empty squares
for (int row = 2; row < 6; row++)
    for (int col = 0; col < 8; col++)
    {
        squares[row][col] = {Piecetype::None, Color::None};
    }
}

const Piece& Board::getPiece(int row, int col) const{
    
}

void setPiece(int row, int col, Piece piece){}
void movePiece(int fromRow, int fromCol, int toRow, int toCol){}

