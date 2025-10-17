#pragma once
#include "piece.h"
#include "move.h"

class Board {
    private:
        Piece squares[8][8];    //internal board representation
        char pieceToChar(const Piece& p) const;
        Position enPassantTarget = {-1,1};
    public:
    Board();                                        //Constructor (Sets up a new board)
    void setupDefault();                            //Sets up all pieces to start position
    Piece& getPiece(int row, int col);    
    const Piece& getPiece(int row, int col) const;         //Read-only access to a piece on an index
    void setPiece(int row, int col, Piece piece);   //replace or place a piece
    void executeMove(const Move& move);     //Move logic (no validation
    void printBoard()const;
    void setEnPassantTarget(Position pos) { enPassantTarget = pos; }
    void clearEnPassantTarget() { enPassantTarget = {-1,-1}; }
    Position getEnPassantTarget() const {return enPassantTarget; }
    void handleCastling(const Move& move);

};
