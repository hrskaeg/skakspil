#include "piece.h"

class Board {
    private:
        Piece squares[8][8];    //internal board representation
    public:
    Board();                                        //Constructor (Sets up a new board)
    void setupDefault();                            //Sets up all pieces to start position
    const getpiece(int row, int col) const;         //Read-only access to a square
    void setPiece(int row, int col, Piece piece);   //replace or place a piece
    void movePiece(int fromRow, int fromCol, int toRow, int toCol);     //Move logic (no validation
};
