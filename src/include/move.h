#pragma once
#include "piece.h"
#include <string>

struct Position {int row; int col;};

struct Move{
    Position from;
    Position to;
    Piece movedPiece;
    Piece capturedPiece;

     std::string toString() const;
};

