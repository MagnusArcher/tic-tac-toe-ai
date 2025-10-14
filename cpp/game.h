#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <cstdlib>

class TicTacToe {
private:
    char board[3][3];
    char currentPlayer;
    const char HUMAN = 'O';
    const char AI = 'X';
    const char EMPTY = ' ';
    
public:
    TicTacToe();
    void initBoard();
    void displayBoard();
    bool makeMove(int row, int col, char player);
    bool checkWin(char player);
    bool isBoardFull();
    void playGame();
    std::pair<int, int> getAIMove();
    std::pair<int, int> getHumanMove();
    std::string getBoardString();
};

#endif
