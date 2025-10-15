// src/include/fen.h
#pragma once
#include "board.h"
#include "game.h"
#include <string>

namespace FEN {
    void loadPosition(Game& game, const std::string& fen);
}
