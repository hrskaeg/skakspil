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
};