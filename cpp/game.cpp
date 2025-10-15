#include "game.h"
#include <sstream>
#include <limits>
#include <fstream>
#include <cstdlib>

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
    std::cout << "     1   2   3" << std::endl;
    std::cout << "   +---+---+---+" << std::endl;
    
    for(int i = 0; i < 3; i++) {
        std::cout << " " << (i + 1) << " | ";
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
    std::string command = "python ../python/ai_engine.py \"" + boardStr + "\" > ai_output.txt";
    
    int result = system(command.c_str());
    
    if(result != 0) {
        std::cerr << "Error: Cannot execute Python AI engine!" << std::endl;
        return std::make_pair(-1, -1);
    }
    
    std::ifstream inputFile("ai_output.txt");
    if(!inputFile.is_open()) {
        std::cerr << "Error: Cannot read AI output!" << std::endl;
        return std::make_pair(-1, -1);
    }
    
    std::string line;
    std::getline(inputFile, line);
    inputFile.close();
    
    remove("ai_output.txt");
    
    int row, col;
    if(sscanf(line.c_str(), "%d,%d", &row, &col) != 2) {
        std::cerr << "Error: Invalid AI response!" << std::endl;
        return std::make_pair(-1, -1);
    }
    
    return std::make_pair(row, col);
}

std::pair<int, int> TicTacToe::getHumanMove() {
    int row, col;
    std::string input;
    
    while(true) {
        std::cout << "Your turn (O)! Enter row and column (1-3): ";
        
        std::getline(std::cin, input);
        
        if(input.empty()) {
            std::cout << "[ERROR] No input provided. Please enter two numbers (e.g., 1 2)" << std::endl;
            continue;
        }
        
        std::stringstream ss(input);
        
        if(!(ss >> row >> col)) {
            std::cout << "[ERROR] Invalid input format. Please enter two numbers separated by space (e.g., 1 2)" << std::endl;
            continue;
        }
        
        std::string extra;
        if(ss >> extra) {
            std::cout << "[ERROR] Too many inputs. Please enter exactly two numbers (e.g., 1 2)" << std::endl;
            continue;
        }
        
        if(row < 1 || row > 3 || col < 1 || col > 3) {
            std::cout << "[ERROR] Numbers must be between 1 and 3. Please try again." << std::endl;
            continue;
        }
        
        int actualRow = row - 1;
        int actualCol = col - 1;
        
        if(board[actualRow][actualCol] != EMPTY) {
            std::cout << "[ERROR] Cell (" << row << ", " << col << ") is already occupied. Choose another cell." << std::endl;
            continue;
        }
        
        return std::make_pair(actualRow, actualCol);
    }
}

void TicTacToe::playGame() {
    std::cout << "\n+==========================================+" << std::endl;
    std::cout << "|   TIC TAC TOE - AI CHALLENGE            |" << std::endl;
    std::cout << "|                                          |" << std::endl;
    std::cout << "|   You: O  |  AI: X                      |" << std::endl;
    std::cout << "|   Can you beat the unbeatable AI?       |" << std::endl;
    std::cout << "+==========================================+" << std::endl;
    std::cout << "\n[INFO] Instructions:" << std::endl;
    std::cout << "   - Enter row and column as two numbers (1-3)" << std::endl;
    std::cout << "   - Example: Type '1 2' and press Enter" << std::endl;
    std::cout << "   - Row first, then column\n" << std::endl;
    
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    displayBoard();
    
    while(true) {
        std::cout << "========================================" << std::endl;
        
        std::pair<int, int> humanMove = getHumanMove();
        int hRow = humanMove.first;
        int hCol = humanMove.second;
        
        makeMove(hRow, hCol, HUMAN);
        std::cout << "\n[OK] You played: (" << (hRow + 1) << ", " << (hCol + 1) << ")" << std::endl;
        displayBoard();
        
        if(checkWin(HUMAN)) {
            std::cout << "\n+==========================================+" << std::endl;
            std::cout << "|   CONGRATULATIONS! YOU WON!              |" << std::endl;
            std::cout << "|   (This shouldn't happen...)             |" << std::endl;
            std::cout << "+==========================================+\n" << std::endl;
            break;
        }
        
        if(isBoardFull()) {
            std::cout << "\n+==========================================+" << std::endl;
            std::cout << "|   IT'S A TIE! WELL PLAYED!               |" << std::endl;
            std::cout << "+==========================================+\n" << std::endl;
            break;
        }
        
        std::cout << "========================================" << std::endl;
        std::cout << "[AI] Thinking..." << std::endl;
        
        std::pair<int, int> aiMove = getAIMove();
        int aRow = aiMove.first;
        int aCol = aiMove.second;
        
        if(aRow == -1 || aCol == -1) {
            std::cerr << "\n[FATAL] AI failed to make a move!" << std::endl;
            break;
        }
        
        makeMove(aRow, aCol, AI);
        std::cout << "[AI] AI played: (" << (aRow + 1) << ", " << (aCol + 1) << ")" << std::endl;
        displayBoard();
        
        if(checkWin(AI)) {
            std::cout << "\n+==========================================+" << std::endl;
            std::cout << "|   AI WINS! BETTER LUCK NEXT TIME!        |" << std::endl;
            std::cout << "+==========================================+\n" << std::endl;
            break;
        }
        
        if(isBoardFull()) {
            std::cout << "\n+==========================================+" << std::endl;
            std::cout << "|   IT'S A TIE! WELL PLAYED!               |" << std::endl;
            std::cout << "+==========================================+\n" << std::endl;
            break;
        }
    }
    
    std::cout << "Thanks for playing!\n" << std::endl;
}

int main() {
    TicTacToe game;
    game.playGame();
    return 0;
}
