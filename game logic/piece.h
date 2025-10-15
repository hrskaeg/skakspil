#pragma once
#include <cstdint>

enum class Piecetype : uint8_t {
    None, Pawn, Rook, Knight, Bishop, Queen, King 
};

enum class Color : uint8_t {
    None, Black, White
};

struct Piece {
    Piecetype type;
    Color color;
    bool hasMoved = false; //2 row movement pawns, castling etc.
//clears square callable function
static Piece makeEmpty() {
    Piece p;
    p.type = Piecetype::None;
    p.color = Color::None;
    p.hasMoved = false;
    return p;
}

};
