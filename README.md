# Connect Four Game in C++

This is a console-based version of the classic game Connect Four. The game is implemented in C++ and can be played on a terminal.

## Description

The game features a standard Connect Four board (6 rows, 7 columns). Players take turns to drop their checkers into one of the columns. The first player to get four of their colored checkers in a row (horizontally, vertically, or diagonally) is the winner.

## Getting Started

### Dependencies

* GCC compiler
* Terminal that supports ANSI escape codes for color output
###### Alternatively, you can use the Dockerfile.

### Building and Running

#### Docker Container
If you don't have Docker already installed, you can find it [here](https://docs.docker.com/get-docker/). To build the Dockerfile, first run the command:

```bash
docker build -t connectfour .
```
then, to run our container:

```bash
docker run -it connectfour
```

#### C++ Compiler
To build the project with your CPP compiler, navigate to the project directory and run the following command:

```bash
g++ -o connectfour connectfour.cpp board.cpp
```

To run the game, use the following command:

```bash
./connectfour
```
## Gameplay

The game starts with an empty board. Player 1's pieces are denoted by 'X' (red), and Player 2's pieces are denoted by 'O' (blue). The current player is prompted to input the column number where they want to place their piece.

The game continues until one player gets four of their pieces in a line or the board is filled (a draw).

## Suggestions / Bugs / Comments
If you need to contact me for anything pertaining to this repository, you may do so at `asdjaksldjawdjwla@outlook.com`, please make sure your subject contains 'ConnectFour' so I know that it pertains to this repo before opening.