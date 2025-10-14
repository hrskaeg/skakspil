#include "board.h"
#include "piece.h"
#include "move.h"
#pragma once

namespace Rules {
    bool pathIsClear(const Board& board, const Move& move);

    bool isEnemyPiece(const Board& board, const Move& move);

    bool isValidMove(const Board& board, const Move& move);

    bool isSquareAttacked(const Board& board, const Position& position, const Color& byColor);

    namespace Pawn {
        enum class MoveType {
            None,
            ForwardOne,
            ForwardTwo,
            DiagonalCapture
        };
        MoveType classifyMove(const Piece& piece, int dRow, int dCol);
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
