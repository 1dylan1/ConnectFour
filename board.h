#include<vector>

using namespace std;

class ConnectFour {
    public:
        // The game board is a 2D vector of characters.
        vector<vector<char>> board;

        // Default constructor for the ConnectFour class.
        // Initializes the game board and sets the starting player.
        ConnectFour();

        // This function initializes and returns a 6x7 game board filled with empty spaces (' ').
        vector<vector<char>> createBoard();

        // This function prints the current state of the game board to the console.
        // It also displays which player's turn is next.
        void printBoard();

        // This function changes the turn to the other player.
        void changePlayerTurn();

        // This function returns the current player's turn.
        // 0 represents player 1 and 1 represents player 2.
        int getCurrentTurn();

        // This function places a checker in the specified column.
        // It returns true if the operation was successful and false otherwise.
        bool PlaceChecker(int columnIndex);

        // This function sets the current game state.
        // Game state can be -1 (game is ongoing), 1 (player 1 wins), or 2 (player 2 wins).
        void setGameState(int state);

        // This function returns the current game state.
        // It also updates the game state if a player has won.
        int getGameState();

        // This function checks if either player has won the game.
        // It returns -1 if no player has won, 1 if player 1 has won, and 2 if player 2 has won.
        int checkWin();

    private:
        // This variable keeps track of whose turn it is.
        // 0 represents player 1 and 1 represents player 2.
        int playerTurn;

        // This variable keeps track of the game state.
        // -1 represents an ongoing game, 1 represents a win for player 1, and 2 represents a win for player 2.
        int gameState = -1;
};
