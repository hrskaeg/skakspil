#include "fen.h"
#include <sstream>
#include <cctype>


namespace FEN{

void loadPosition(Game& game, const std::string& fen){
    std::istringstream ss(fen);
    std::string boardpart, turnPart, castlingPart, ePart;
    int halfmove, fullmove;

    ss >> boardpart >> turnPart >> castlingPart >> ePart >> halfmove >> fullmove;

    int row = 7, col = 0;
    for (char c : boardpart)
    {
        if(c == '/'){
            row--;
            col = 0;
        }
        else if(isdigit(c)) {
            int empty = c -'0';
            for (int i = 0; i < empty; i++){
                game.getBoard().setPiece(row,col, Piece::makeEmpty());
                col++;
            }
        }else{
            Color color = isupper(c) ? Color::White : Color::Black;
            Piecetype type;

            switch (tolower(c)) {
        case 'k': type = Piecetype::King  ;  break;
        case 'q': type = Piecetype::Queen ;  break;
        case 'r': type = Piecetype::Rook  ;  break;
        case 'b': type = Piecetype::Bishop;  break;
        case 'n': type = Piecetype::Knight;  break;
        case 'p': type = Piecetype::Pawn  ;  break;
        default: type  = Piecetype::None  ;  break; 
        }

        game.getBoard().setPiece(row,col,Piece{type,color});
        col++;
        }
    }
game.setTurn(turnPart == "w" ? Color::White : Color::Black);

    // --- Castling rights ---
    // If you track them in your Game or Board, mark the rooks and king as having not moved.
    if (castlingPart.find('K') != std::string::npos)
        game.getBoard().getPiece(0, 4).hasMoved = false; // white king
    if (castlingPart.find('Q') != std::string::npos)
        game.getBoard().getPiece(0, 0).hasMoved = false; // white queenside rook
    if (castlingPart.find('k') != std::string::npos)
        game.getBoard().getPiece(7, 4).hasMoved = false; // black king
    if (castlingPart.find('q') != std::string::npos)
        game.getBoard().getPiece(7, 0).hasMoved = false; // black queenside rook

    // --- En passant target square ---
    if (ePart != "-") {
        int file = ePart[0] - 'a';
        int rank = ePart[1] - '1';
        game.getBoard().setEnPassantTarget({rank, file});
    } else {
        game.getBoard().setEnPassantTarget({-1, -1}); // no square
    }

    // (halfmove and fullmove are ignored for now)
}

} // namespace FEN

