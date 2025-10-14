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
- ✅ User-friendly interface with comprehensive error handling

---

## 🌟 Features

- ✨ **Unbeatable AI** - Minimax algorithm ensures perfect play
- ⚡ **High Performance** - C++ for speed, Python for AI
- 🎯 **Clean UI** - ASCII art terminal interface with clear instructions
- 💪 **Robust** - Comprehensive input validation and error handling
- 🎮 **User-Friendly** - Intuitive 1-3 numbering system

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
g++ -std=c++17 -o tic_tac_toe game.cpp
./tic_tac_toe
```

### For Windows

```cmd
cd tic-tac-toe-ai\cpp
g++ -std=c++17 -o tic_tac_toe.exe game.cpp
tic_tac_toe.exe
```

---

## 🎯 How to Play

- **You**: Play as **O** (first move)
- **AI**: Plays as **X**
- **Goal**: Get 3 in a row
- **Input**: Enter row and column (1-3) separated by space

### Input Format

```
Your turn (O)! Enter row and column (1-3): 2 2
```

- First number: Row (1-3)
- Second number: Column (1-3)
- Separate with space

### Example Gameplay

```
╔════════════════════════════════════════╗
║   TIC TAC TOE - AI CHALLENGE          ║
║                                        ║
║   You: O  |  AI: X                    ║
║   Can you beat the unbeatable AI?     ║
╚════════════════════════════════════════╝

💡 Instructions:
   - Enter row and column as two numbers (1-3)
   - Example: Type '1 2' and press Enter
   - Row first, then column

  === TIC TAC TOE ===
     1   2   3
   +---+---+---+
 1 |   |   |   |
   +---+---+---+
 2 |   |   |   |
   +---+---+---+
 3 |   |   |   |
   +---+---+---+

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
Your turn (O)! Enter row and column (1-3): 2 2

✓ You played: (2, 2)

  === TIC TAC TOE ===
     1   2   3
   +---+---+---+
 1 |   |   |   |
   +---+---+---+
 2 |   | O |   |
   +---+---+---+
 3 |   |   |   |
   +---+---+---+

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
🤖 AI is thinking...
🤖 AI played: (1, 1)
```

### Error Handling

The game handles various input errors:

```
❌ Error: No input provided
❌ Error: Invalid input format
❌ Error: Too many inputs
❌ Error: Numbers must be between 1 and 3
❌ Error: Cell is already occupied
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
system("python ai_engine.py \"XO  O X  \" > ai_output.txt");
```

**Python → C++:**
```python
print(f"{row},{col}")
```

The C++ program reads the AI's move from a temporary file (`ai_output.txt`) which is automatically deleted after reading.

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
    ├── game.cpp           # Game implementation (300 lines)
    └── Makefile           # Build config
```

---

## 🎓 Minimax Algorithm

**How it works:**
1. Assumes both players play optimally
2. Explores all possible game states
3. Maximizes AI score, minimizes human score
4. Returns best move

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

## 💻 Technical Implementation

### Input Validation

Uses `std::getline` and `std::stringstream` for robust input parsing:

```cpp
std::getline(std::cin, input);
std::stringstream ss(input);

if(!(ss >> row >> col)) {
    // Handle invalid format
}

if(ss >> extra) {
    // Handle too many inputs
}
```

### Cross-Platform Compatibility

Uses `system()` with temporary file for Windows/Linux/Mac compatibility:

```cpp
system("python ai_engine.py \"...\" > ai_output.txt");
std::ifstream inputFile("ai_output.txt");
remove("ai_output.txt");
```

---

## 🎓 What I Learned

- ✅ Implementing Minimax algorithm from scratch
- ✅ C++ and Python inter-process communication
- ✅ Game theory and optimal decision-making
- ✅ Clean code architecture
- ✅ Comprehensive error handling and input validation
- ✅ Cross-platform development (Windows/Linux/Mac)
- ✅ User experience design in CLI applications

---

## 🔧 Challenges Solved

1. **Inter-language communication** - Used system() with temporary files
2. **Performance** - Depth-based scoring for efficiency
3. **Input validation** - Comprehensive error handling for all edge cases
4. **Cross-platform** - Compatible with MinGW, GCC, and Clang
5. **User experience** - Intuitive 1-3 numbering with clear error messages

---

## 🔮 Future Enhancements

- [ ] Difficulty levels (Easy, Medium, Hard)
- [ ] GUI using SDL2 or Qt
- [ ] Alpha-Beta pruning optimization
- [ ] Undo/Redo functionality
- [ ] Game statistics and history
- [ ] Network multiplayer
- [ ] Save/Load game state

---

## 🤝 Contributing

Contributions welcome! Feel free to:
- Report bugs
- Suggest features
- Submit pull requests

```bash
git clone https://github.com/YOUR_USERNAME/tic-tac-toe-ai.git
git checkout -b feature/new-feature
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
- [GeeksforGeeks: Minimax](https://www.geeksforgeeks.org/artificial-intelligence/mini-max-algorithm-in-artificial-intelligence/)

---

<div align="center">

**⭐ Star this project if you found it interesting!**

*Can you beat the unbeatable AI?* 🎮

![Views](https://komarev.com/ghpvc/?username=MagnusArcher&color=58a6ff&style=flat-square)

</div>
