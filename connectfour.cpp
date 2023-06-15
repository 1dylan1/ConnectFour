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
    //printWelcomeScreen();
    ConnectFour game;
    clearScreen();
    game.printBoard();
    while(game.getGameState() == -1) {
     cout << "Enter drop location:";
     int input;
     cin >> input;
     game.PlaceChecker(input-1);
     if(game.checkWin() != -1) break;
     game.changePlayerTurn();
     clearScreen();
     game.printBoard();
    }
    clearScreen();
    game.printBoard();
    cout << ANSI_COLOR_YELLOW << game.getGameState() << " wins!\n" << ANSI_COLOR_RESET; 
    return 0;
}