#include "piece.h"

class Board {
    private:
        Piece squares[7][7];    //internal board representation
    public:
    Board();                                        //Constructor (Sets up a new board)
    void setupDefault();                            //Sets up all pieces to start position
    const Piece& getPiece(int row, int col) const;         //Read-only access to a piece on an index
    void setPiece(int row, int col, Piece piece);   //replace or place a piece
    void movePiece(int fromRow, int fromCol, int toRow, int toCol);     //Move logic (no validation
};
