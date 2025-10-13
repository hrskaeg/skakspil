#include "game.h"
#include <vector>

Color Game::getTurn() const{                      //Returns color of current turn
const Move& lastmove = moveHistory.back(); //readonly of moveHistory vector, saves latest entry in lastmove
    if (lastmove.movedPiece.color == Color::White){ //checks latest entry for movedpiece.color
        return Color::Black;
    }
    else if (lastmove.movedPiece.color == Color::Black){
        return Color::White;
    }
    else
    return Color::White;
}