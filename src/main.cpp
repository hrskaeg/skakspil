#include <iostream>
#include <string>
#include "game.h"
#include "board.h"
#include "move.h"
#include "piece.h"
#include "rules.h"

int main(){
    Game game;

    std::cout << "Welcome to Skakspil (CLI Chess)\n";
    std::cout << "---------------------------------\n";
    std::cout << "Type moves in coordinate form (e.g., e2e4)\n";
    std::cout << "Type 'quit' or 'exit' to end the game.\n\n";
    std::cout << "Type 'show' to view board.\n";

    // Print the initial board
    game.getBoard().printBoard();

    while(true){
        std::string input;
        std::cout << ((game.getTurn()== Color::White) ? "White" : "Black") << " to move:";
        std::cin >> input;

        //handle exit
        if (input == "quit" || input == "exit"){
            std::cout << "exitting game...\n";
            break;
        }
        if (input == "show"){
            std::cout << "\nCurrent board: "; 
            game.getBoard().printBoard();
        }

        //input validation
         if (input.size() != 4 ||
            input[0] < 'a' || input[0] > 'h' ||
            input[2] < 'a' || input[2] > 'h' ||
            input[1] < '1' || input[1] > '8' ||
            input[3] < '1' || input[3] > '8'){
            std::cout << "Invalid move format. Use e.g., e2e4.\n";
            continue;
        }
        
        //convert algebraic chess notation to indices usable by program
        Position from, to;
        from.col = input[0] - 'a'; //ASCII value of a is 97, for input: a-a, takes col 0(a)
        from.row = input[1] - '1'; //ASCII value of 1 is is 49. for input: 1-1 takes row 0(1)
        to.col   = input[2] - 'a';
        to.row   = input[3] - '1';

        Move move{from,to};

        MoveStatus resultMove = game.tryMove(move);

        switch (resultMove)
        {
        case MoveStatus::IllegalMove :
            std::cout << "Illegal Move! \n";
            break;

        case MoveStatus::NotYourTurn :
            std::cout << "Not your turn! Current turn is: " << ((game.getTurn() == Color::White) ? "White" : "Black") << " to move" << std::endl;
            break;
        case MoveStatus::MovingEmpty :
            std::cout << "No piece selected";
            break;
        case MoveStatus::Success :
            std::cout << input << std::endl;;
            game.getBoard().printBoard();
            break;

        default:
            std::cout << "Movestatus error!!";
            break;
        }
        

        //switch turn and saving moves happens in trymove
    }
    std::cout << "game ended";
    return 0;


}