#include "board.h"
#include "piece.h"
#include "move.h"
#pragma once

namespace Rules {

    bool isValidMove(const Board& board, const Move& move);

    namespace Pawn {
        bool isValidMove(const Board& board, const Move& move);
    }

    namespace Rook {
        bool isValidMove(const Board& board, const Move& move);
    }

    namespace Knight {
        bool isValidMove(const Board& board, const Move& move);
    }

    namespace Bishop {
        bool isValidMove(const Board& board, const Move& move);
    }

    namespace Queen {
        bool isValidMove(const Board& board, const Move& move);
    }

    namespace King {
        bool isValidMove(const Board& board, const Move& move);
    }
}
