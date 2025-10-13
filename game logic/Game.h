#include "board.h"
#include "rules.h"
#include <vector>

class Game{
private:
    Board board;
    Color currentTurn;
    std::vector<Move> moveHistory;
public:
    Game();                                     //constructor, initialises board and turn
    bool tryMove(Position from, Position to);   //Attempts move, (validates, and applies if legal)
    void switchTurn();                          //switches from white to black
    Color getTurn() const;                      //Returns color of current turn
    const Board& getBoard() const;              //rendering access
};