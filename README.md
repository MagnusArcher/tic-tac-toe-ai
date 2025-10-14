```markdown
# 🎮 Tic-Tac-Toe with Unbeatable AI

<div align="center">

![Python](https://img.shields.io/badge/Python-3.x-blue?style=for-the-badge&logo=python&logoColor=white)
![C++](https://img.shields.io/badge/C++-17-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)
![License](https://img.shields.io/badge/License-MIT-green?style=for-the-badge)

**Unbeatable Tic-Tac-Toe AI using Minimax algorithm**

*C++ game engine + Python AI intelligence*

</div>

---

## 📋 Overview

A Tic-Tac-Toe game where you compete against an **AI that never loses**. The AI uses the **Minimax algorithm** to play optimally, demonstrating:

- ✅ Algorithm implementation from scratch
- ✅ Multi-language integration (C++ ↔ Python)
- ✅ Game theory application
- ✅ Clean software architecture

---

## 🌟 Features

- ✨ **Unbeatable AI** - Minimax algorithm ensures perfect play
- ⚡ **High Performance** - C++ for speed, Python for AI
- 🎯 **Clean UI** - ASCII art terminal interface
- 💪 **Robust** - Input validation and error handling

---

## 🚀 Installation

### Prerequisites
- C++ compiler (g++ 7.0+)
- Python 3.6+
- Make (optional)

### Quick Start

```bash
git clone https://github.com/MagnusArcher/tic-tac-toe-ai.git
cd tic-tac-toe-ai/cpp
make
./tic_tac_toe
```

### Manual Compilation

```bash
cd cpp
g++ -std=c++17 -o tic_tac_toe game.cpp
./tic_tac_toe
```

---

## 🎯 How to Play

- **You**: Play as **O** (first move)
- **AI**: Plays as **X**
- **Goal**: Get 3 in a row
- **Input**: Enter row and column (0-2)

```
  === TIC TAC TOE ===
     0   1   2
   +---+---+---+
 0 |   |   |   |
   +---+---+---+
 1 |   | O |   |
   +---+---+---+
 2 |   |   |   |
   +---+---+---+

Your turn (O)! Enter row and column (0-2): 
```

---

## 🧠 How It Works

### Architecture

```
C++ Game Engine          Python AI Engine
├─ Board display         ├─ Minimax algorithm
├─ User input       ←──→ ├─ State evaluation
├─ Game logic            └─ Best move calculation
└─ Win detection
```

### Communication

**C++ → Python:**
```cpp
// Send board state as string: "XO  O X  "
python3 ai_engine.py "XO  O X  "
```

**Python → C++:**
```python
# Return best move: "1,2"
print(f"{row},{col}")
```

---

## 📂 Project Structure

```
tic-tac-toe-ai/
├── README.md
├── LICENSE
├── .gitignore
├── python/
│   └── ai_engine.py       # Minimax AI (150 lines)
└── cpp/
    ├── game.h             # Class declaration (30 lines)
    ├── game.cpp           # Game implementation (250 lines)
    └── Makefile           # Build config
```

---

## 🎓 Minimax Algorithm

**How it works:**
1. Assumes both players play optimally
2. Explores all possible game states
3. Maximizes AI score, minimizes human score
4. Returns best move

**Pseudocode:**
```
function MINIMAX(board, depth, isMaximizing):
    if game over:
        return score
    
    if AI's turn:
        try all moves
        return maximum score
    else:
        try all moves
        return minimum score
```

**Complexity:**
- Time: O(9!) ≈ 362,880 states
- Space: O(9) recursion depth
- Real performance: 50-200ms per move

---

## 📊 Performance

| Metric | Value |
|--------|-------|
| Average response | 50-100ms |
| Empty board | ~200ms |
| Endgame | <10ms |
| Memory | <1MB |

---

## 💻 Code Example

```python
# Python: Find best move
board = [
    ['X', 'O', ' '],
    [' ', 'X', ' '],
    [' ', ' ', ' ']
]

row, col = ai.find_best_move(board)
# Returns: (2, 2) - completes diagonal
```

```cpp
// C++: Validate move
bool TicTacToe::makeMove(int row, int col, char player) {
    if(row < 0 || row > 2 || col < 0 || col > 2)
        return false;
    if(board[row][col] != EMPTY)
        return false;
    board[row][col] = player;
    return true;
}
```

---

## 🎓 What I Learned

- ✅ Implementing Minimax algorithm from scratch
- ✅ C++ and Python inter-process communication
- ✅ Game theory and optimal decision-making
- ✅ Clean code architecture
- ✅ Error handling and input validation

---

## 🔧 Challenges Solved

1. **Inter-language communication** - Used command-line arguments
2. **Performance** - Depth-based scoring for efficiency
3. **Input validation** - Comprehensive error handling
4. **Cross-platform** - Standard C++17 and Python 3

---

## 🔮 Future Enhancements

- [ ] Difficulty levels (Easy, Medium, Hard)
- [ ] GUI using SDL2 or Qt
- [ ] Alpha-Beta pruning optimization
- [ ] Statistics tracking
- [ ] Unit tests

---

## 🤝 Contributing

Contributions welcome! Feel free to:
- Report bugs
- Suggest features
- Submit pull requests

```bash
git clone https://github.com/YOUR_USERNAME/tic-tac-toe-ai.git
git checkout -b feature/new-feature
# Make changes
git commit -m "Add feature"
git push origin feature/new-feature
```

---

## 📝 License

MIT License - Copyright (c) 2025 Magnus Archer

See [LICENSE](LICENSE) for details.

---

## 👤 Author

**Magnus Archer**

- GitHub: [@MagnusArcher](https://github.com/MagnusArcher)
- Telegram: [@MagnusArcher](https://t.me/MagnusArcher)

*Computer Science Student | Python & C++ Developer | AI Enthusiast*

---

## 🙏 Acknowledgments

- Minimax algorithm from game theory
- Inspired by classic AI algorithms
- [GeeksforGeeks: Minimax](https://www.geeksforgeeks.org/minimax-algorithm-in-game-theory/)

---

<div align="center">

**⭐ Star this project if you found it interesting!**

*Can you beat the unbeatable AI?* 🎮

![Views](https://komarev.com/ghpvc/?username=MagnusArcher&color=58a6ff&style=flat-square)

</div>
```
