#include "board.h"
#include <iostream>
#include <vector>

using namespace std;

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_RESET   "\x1b[0m"


enum GameState {NoWin = -1, Player1Win = 1, Player2Win = 2};

ConnectFour::ConnectFour() {
    board = createBoard();
    playerTurn = 0;
}

vector<vector<char>> ConnectFour::createBoard() {
    vector<vector<char>> newBoard(6, vector<char>(7, ' '));
    return newBoard;
}

void ConnectFour::printBoard() {
    cout << "  1   2   3   4   5   6   7\n";
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            cout << "║ ";
            if (board[i][j] == 'X') {  // player 1's pieces are red
                cout << ANSI_COLOR_RED << board[i][j] << ANSI_COLOR_RESET;
            } else if (board[i][j] == 'O') {  // player 2's pieces are blue
                cout << ANSI_COLOR_BLUE << board[i][j] << ANSI_COLOR_RESET;
            } else {
                cout << board[i][j];
            }
            cout << " ";
        }
        cout << "║\n";
        
        if (i < board.size() - 1) {
            cout << "╠═══╬═══╬═══╬═══╬═══╬═══╬═══╣\n";
        }
    }
    cout << "╚═══╩═══╩═══╩═══╩═══╩═══╩═══╝\n";
    cout << R"(
+--------------+
|Player Turn: )" << getCurrentTurn()+1 << R"(|
+--------------+
)";

}

void ConnectFour::changePlayerTurn() {
    playerTurn = !playerTurn;
}

int ConnectFour::getCurrentTurn() {
    return playerTurn;
}

bool ConnectFour::PlaceChecker(int columnIndex) {
    if(columnIndex >= board[0].size() || columnIndex < 0 || board[0][columnIndex] != ' ') return false;
    
    char checkerPiece = getCurrentTurn() ? 'X' : 'O';
    for (int rowIndex = board.size() - 1; rowIndex >= 0; --rowIndex) {
        if (board[rowIndex][columnIndex] == ' ') {
            board[rowIndex][columnIndex] = checkerPiece;
            return true;
        }
    }
    return false;
}

void ConnectFour::setGameState(int state) {
    gameState = state;
}

int ConnectFour::getGameState() {
    setGameState(checkWin());
    return gameState;
}

int ConnectFour::checkWin() {
    const int directions[4][2] = {{1, 0}, {0, 1}, {1, 1}, {1, -1}};  // horizontal, vertical, main diagonal, anti-diagonal
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            if (board[i][j] != ' ') {
                for (auto& dir : directions) {
                    int x = i, y = j;
                    int count = 0;
                    while (x >= 0 && y >= 0 && x < board.size() && y < board[i].size() && board[x][y] == board[i][j]) {
                        x += dir[0];
                        y += dir[1];
                        count++;
                    }
                    if (count >= 4) {
                        return board[i][j] == 'X' ? GameState::Player2Win : GameState::Player1Win;
                    }
                }
            }
        }
    }
    return NoWin;  // no win found
}

