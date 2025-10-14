#!/usr/bin/env python3

import sys

class TicTacToeAI:
    def __init__(self):
        self.HUMAN = 'O'
        self.AI = 'X'
        self.EMPTY = ' '
        
    def evaluate(self, board):
        for row in range(3):
            if board[row][0] == board[row][1] == board[row][2]:
                if board[row][0] == self.AI:
                    return 10
                elif board[row][0] == self.HUMAN:
                    return -10
        
        for col in range(3):
            if board[0][col] == board[1][col] == board[2][col]:
                if board[0][col] == self.AI:
                    return 10
                elif board[0][col] == self.HUMAN:
                    return -10
        
        if board[0][0] == board[1][1] == board[2][2]:
            if board[0][0] == self.AI:
                return 10
            elif board[0][0] == self.HUMAN:
                return -10
        
        if board[0][2] == board[1][1] == board[2][0]:
            if board[0][2] == self.AI:
                return 10
            elif board[0][2] == self.HUMAN:
                return -10
        
        return 0
    
    def is_moves_left(self, board):
        for i in range(3):
            for j in range(3):
                if board[i][j] == self.EMPTY:
                    return True
        return False
    
    def minimax(self, board, depth, is_max):
        score = self.evaluate(board)
        
        if score == 10:
            return score - depth
        
        if score == -10:
            return score + depth
        
        if not self.is_moves_left(board):
            return 0
        
        if is_max:
            best = -1000
            
            for i in range(3):
                for j in range(3):
                    if board[i][j] == self.EMPTY:
                        board[i][j] = self.AI
                        best = max(best, self.minimax(board, depth + 1, False))
                        board[i][j] = self.EMPTY
            
            return best
        
        else:
            best = 1000
            
            for i in range(3):
                for j in range(3):
                    if board[i][j] == self.EMPTY:
                        board[i][j] = self.HUMAN
                        best = min(best, self.minimax(board, depth + 1, True))
                        board[i][j] = self.EMPTY
            
            return best
    
    def find_best_move(self, board):
        best_val = -1000
        best_row = -1
        best_col = -1
        
        for i in range(3):
            for j in range(3):
                if board[i][j] == self.EMPTY:
                    board[i][j] = self.AI
                    move_val = self.minimax(board, 0, False)
                    board[i][j] = self.EMPTY
                    
                    if move_val > best_val:
                        best_row = i
                        best_col = j
                        best_val = move_val
        
        return best_row, best_col

def main():
    if len(sys.argv) != 2:
        print("Error: Invalid arguments", file=sys.stderr)
        sys.exit(1)
    
    board_str = sys.argv[1]
    
    if len(board_str) != 9:
        print("Error: Invalid board state", file=sys.stderr)
        sys.exit(1)
    
    board = []
    for i in range(3):
        row = []
        for j in range(3):
            char = board_str[i * 3 + j]
            row.append(char)
        board.append(row)
    
    ai = TicTacToeAI()
    row, col = ai.find_best_move(board)
    
    print(f"{row},{col}")

if __name__ == "__main__":
    main()
