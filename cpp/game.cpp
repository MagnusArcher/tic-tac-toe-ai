#include "game.h"
#include <sstream>
#include <limits>
#include <cstdio>

TicTacToe::TicTacToe() {
    initBoard();
    currentPlayer = HUMAN;
}

void TicTacToe::initBoard() {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            board[i][j] = EMPTY;
        }
    }
}

void TicTacToe::displayBoard() {
    std::cout << "\n  === TIC TAC TOE ===" << std::endl;
    std::cout << "     0   1   2" << std::endl;
    std::cout << "   +---+---+---+" << std::endl;
    
    for(int i = 0; i < 3; i++) {
        std::cout << " " << i << " | ";
        for(int j = 0; j < 3; j++) {
            std::cout << board[i][j];
            if(j < 2) std::cout << " | ";
        }
        std::cout << " |" << std::endl;
        std::cout << "   +---+---+---+" << std::endl;
    }
    std::cout << std::endl;
}

bool TicTacToe::makeMove(int row, int col, char player) {
    if(row < 0 || row > 2 || col < 0 || col > 2) {
        return false;
    }
    
    if(board[row][col] != EMPTY) {
        return false;
    }
    
    board[row][col] = player;
    return true;
}

bool TicTacToe::checkWin(char player) {
    for(int i = 0; i < 3; i++) {
        if(board[i][0] == player && 
           board[i][1] == player && 
           board[i][2] == player) {
            return true;
        }
    }
    
    for(int i = 0; i < 3; i++) {
        if(board[0][i] == player && 
           board[1][i] == player && 
           board[2][i] == player) {
            return true;
        }
    }
    
    if(board[0][0] == player && 
       board[1][1] == player && 
       board[2][2] == player) {
        return true;
    }
    
    if(board[0][2] == player && 
       board[1][1] == player && 
       board[2][0] == player) {
        return true;
    }
    
    return false;
}

bool TicTacToe::isBoardFull() {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(board[i][j] == EMPTY) {
                return false;
            }
        }
    }
    return true;
}

std::string TicTacToe::getBoardString() {
    std::string result = "";
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            result += board[i][j];
        }
    }
    return result;
}

std::pair<int, int> TicTacToe::getAIMove() {
    std::string boardStr = getBoardString();
    std::string command = "python ../python/ai_engine.py \"" + boardStr + "\"";
    
    FILE* pipe = popen(command.c_str(), "r");
    
    if(!pipe) {
        std::cerr << "Error: Cannot execute Python AI engine!" << std::endl;
        return std::make_pair(-1, -1);
    }
    
    char buffer[128];
    std::string result = "";
    
    while(fgets(buffer, sizeof(buffer), pipe) != nullptr) {
        result += buffer;
    }
    
    pclose(pipe);
    
    int row, col;
    if(sscanf(result.c_str(), "%d,%d", &row, &col) != 2) {
        std::cerr << "Error: Invalid AI response!" << std::endl;
        return std::make_pair(-1, -1);
    }
    
    return std::make_pair(row, col);
}

std::pair<int, int> TicTacToe::getHumanMove() {
    int row, col;
    
    while(true) {
        std::cout << "Your turn (O)! Enter row and column (0-2): ";
        std::cin >> row >> col;
        
        if(std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input! Please enter numbers." << std::endl;
            continue;
        }
        
        if(row >= 0 && row <= 2 && col >= 0 && col <= 2 && board[row][col] == EMPTY) {
            return std::make_pair(row, col);
        }
        
        std::cout << "Invalid move! Cell must be empty and in range 0-2." << std::endl;
    }
}

void TicTacToe::playGame() {
    std::cout << "\n╔════════════════════════════════════════╗" << std::endl;
    std::cout << "║   TIC TAC TOE - AI CHALLENGE          ║" << std::endl;
    std::cout << "║                                        ║" << std::endl;
    std::cout << "║   You: O  |  AI: X                    ║" << std::endl;
    std::cout << "║   Can you beat the unbeatable AI?     ║" << std::endl;
    std::cout << "╚════════════════════════════════════════╝\n" << std::endl;
    
    displayBoard();
    
    while(true) {
        std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << std::endl;
        
        std::pair<int, int> humanMove = getHumanMove();
        int hRow = humanMove.first;
        int hCol = humanMove.second;
        
        makeMove(hRow, hCol, HUMAN);
        displayBoard();
        
        if(checkWin(HUMAN)) {
            std::cout << "🎉 Congratulations! You won!" << std::endl;
            std::cout << "   (This shouldn't happen...)" << std::endl;
            break;
        }
        
        if(isBoardFull()) {
            std::cout << "🤝 It's a tie! Well played!" << std::endl;
            break;
        }
        
        std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << std::endl;
        std::cout << "🤖 AI is thinking..." << std::endl;
        
        std::pair<int, int> aiMove = getAIMove();
        int aRow = aiMove.first;
        int aCol = aiMove.second;
        
        if(aRow == -1 || aCol == -1) {
            std::cerr << "Fatal error: AI failed to make a move!" << std::endl;
            break;
        }
        
        makeMove(aRow, aCol, AI);
        std::cout << "🤖 AI played: (" << aRow << ", " << aCol << ")" << std::endl;
        displayBoard();
        
        if(checkWin(AI)) {
            std::cout << "🤖 AI wins! Better luck next time!" << std::endl;
            break;
        }
        
        if(isBoardFull()) {
            std::cout << "🤝 It's a tie! Well played!" << std::endl;
            break;
        }
    }
    
    std::cout << "\nThanks for playing! 🎮\n" << std::endl;
}

int main() {
    TicTacToe game;
    game.playGame();
    return 0;
}
