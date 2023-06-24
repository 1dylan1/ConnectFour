#include<iostream>
#include<stdlib.h>
#include<vector>
#include "board.h"

using namespace std;

#define ANSI_COLOR_RESET   "\x1b[0m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"

void clearScreen() {
    #ifdef WINDOWS
        system("CLS");
    #else
        // Assume POSIX
        system("clear");
    #endif
}


int main() {
    char playAgain = 'y';
    while (playAgain == 'y' || playAgain == 'Y') {
        ConnectFour game;
        clearScreen();
        game.printBoard();

        while (game.getGameState() == GameState::NoWin) {
            int input;
            bool validMove;
            do {
                cout << "Enter drop location: ";
                cin >> input;
                validMove = game.PlaceChecker(input-1);
                if(!validMove) {
                    cout << "Invalid move, please try again." << endl;
                }
            } while (!validMove);
    
            if(game.checkWin() != GameState::NoWin) break;

            game.changePlayerTurn();
            clearScreen();
            game.printBoard();
        }
        
        clearScreen();
        game.printBoard();

        switch (game.getGameState()) {
            case GameState::Player1Win:
                cout << ANSI_COLOR_YELLOW << "Player 1 wins!\n" << ANSI_COLOR_RESET;
                break;
            case GameState::Player2Win:
                cout << ANSI_COLOR_YELLOW << "Player 2 wins!\n" << ANSI_COLOR_RESET;
                break;
            case GameState::Draw:
                cout << ANSI_COLOR_YELLOW << "It's a draw!\n" << ANSI_COLOR_RESET;
                break;
            default:
                cout << ANSI_COLOR_YELLOW << "Unexpected game state!\n" << ANSI_COLOR_RESET;
        }

        cout << "Do you want to play again? (Y/N): ";
        cin >> playAgain;
    }
    return 0;
}