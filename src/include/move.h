#pragma once
#include "piece.h"

struct Position {int row; int col;};

struct Move{
    Position from;
    Position to;
    Piece movedPiece;
    Piece capturedPiece;
};

