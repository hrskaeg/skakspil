#include "include/board.h"
#include "include/piece.h"
#include "include/move.h"
#include <cctype>
#include <iostream>

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
return squares[row][col];


}

Piece& Board::getPiece(int row, int col){
return squares[row][col];

}

void Board::setPiece(int row, int col, Piece piece){
    squares[row][col] = piece;
}

//Returns lowercase letter for black, Uppercase for white
char Board::pieceToChar(const Piece& piece)const{
    char symbol;
    switch (piece.type)
    {
    case Piecetype::None : return '.';
    case Piecetype::King :   symbol = 'K'; break;
    case Piecetype::Queen :  symbol = 'Q'; break;
    case Piecetype::Rook :   symbol = 'R'; break;
    case Piecetype::Bishop : symbol = 'B'; break;
    case Piecetype::Knight : symbol = 'N'; break;
    case Piecetype::Pawn :   symbol = 'P'; break;
    default: return '?'; //Error output
    }
if(piece.color == Color::Black){
    symbol = std::tolower(symbol);
    }
return symbol;

}

void Board::printBoard()const{
std::cout << std::endl;

for (int r = 7; r >= 0; r--)
{
    std::cout << (r + 1) << " | ";
    for (int c = 0; c < 8; c++)
    {
        const Piece& piece = getPiece(r,c); //sets piecetype for current ite
        char symbol = pieceToChar(piece); //gets symbol for current piecetype
        std::cout << symbol << " ";

    }
    std::cout << std::endl;
}
std::cout << "    ---------------\n";
std::cout << "    a b c d e f g h\n"; //labels at bottom
}



void Board::executeMove(const Move& move){
    Piece movingPiece = squares[move.from.row][move.from.col];  //Copy piece to be moved

    //checks for castling, and handles rook movement if true
    if (movingPiece.type == Piecetype::King && abs(move.to.col - move.from.col) == 2){ //special case castling
    handleCastling(move);
    }
        
        //check for en passant
    if  (movingPiece.type == Piecetype::Pawn &&
        abs(move.to.col - move.from.col) == 1 &&
        getPiece(move.to.row,move.to.col).type == Piecetype::None &&
        getEnPassantTarget().row == move.to.row &&
        getEnPassantTarget().col == move.to.col)
        {
            //en passant capture -> remove pawn behind target square
            int capturedRow = (movingPiece.color == Color::White) ? move.to.row -1 : move.to.row +1;
            setPiece(capturedRow, move.to.col, Piece::makeEmpty());
            std::cout <<"en passant! Removing pawn at(" << capturedRow <<", " << move.to.col <<")\n";
        }

    squares[move.to.row][move.to.col] = movingPiece;            //Paste piece to destination

    squares[move.to.row][move.to.col].hasMoved = true;          //Marks piece as having moved

    squares[move.from.row][move.from.col] = { Piecetype::None, Color::None, false };    //clears previous square of piece

   


    //Handle new en passant target if pawn pushed 2
    if (movingPiece.type == Piecetype::Pawn && abs(move.to.row - move.from.row) == 2) {
        int midRow = (move.to.row + move.from.row) / 2;
        setEnPassantTarget({ midRow, move.from.col });
    }else{
        setEnPassantTarget({-1,-1});

    }
    }

void Board::handleCastling(const Move& move){
int row = move.from.row;
bool kingSide = (move.to.col > move.from.col); //The king on col 4 is castling kingside (short castles), if the rook square is less than king square. If rook square larger, its queenside castles(long)

//find rook's starting and ending position
int rookFrom = kingSide ? 7 : 0;
int rookTo = kingSide ? 5 : 3;    

//moves rook
Piece rook = getPiece(row, rookFrom);
rook.hasMoved = true;
setPiece(row, rookTo, rook);
setPiece(row, rookFrom, Piece::makeEmpty());
std::cout << (kingSide ? "Kingside" : "Queenside") << " Castling executed!" << std::endl;


}

