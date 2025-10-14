# 🎮 Tic-Tac-Toe with Unbeatable AI

<div align="center">

![Python](https://img.shields.io/badge/Python-3.x-blue?style=for-the-badge&logo=python&logoColor=white)
![C++](https://img.shields.io/badge/C++-17-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)
![License](https://img.shields.io/badge/License-MIT-green?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Complete-success?style=for-the-badge)

**An advanced Tic-Tac-Toe game featuring an unbeatable AI powered by the Minimax algorithm.**

*A demonstration of multi-language software architecture combining C++ performance with Python AI intelligence.*

[Features](#-features) • [Installation](#-installation--running) • [How It Works](#-how-it-works) • [Documentation](#-detailed-documentation) • [License](#-license)

</div>

---

## 📋 Table of Contents

- [Overview](#-overview)
- [Features](#-features)
- [Technologies Used](#️-technologies-used)
- [Prerequisites](#-prerequisites)
- [Installation & Running](#-installation--running)
- [How to Play](#-how-to-play)
- [How It Works](#-how-it-works)
- [Detailed Documentation](#-detailed-documentation)
- [Project Structure](#-project-structure)
- [Algorithm Explanation](#-algorithm-explanation)
- [Technical Implementation](#-technical-implementation)
- [Performance Analysis](#-performance-analysis)
- [Code Examples](#-code-examples)
- [What I Learned](#-what-i-learned)
- [Challenges & Solutions](#-challenges--solutions)
- [Future Enhancements](#-future-enhancements)
- [Contributing](#-contributing)
- [License](#-license)
- [Author](#-author)
- [Acknowledgments](#-acknowledgments)

---

## 🌟 Overview

This project implements a **Tic-Tac-Toe game** where a human player competes against an **AI that never loses**. The AI is powered by the classic **Minimax algorithm** from game theory, ensuring optimal decision-making at every move.

The project showcases:
- **Multi-language integration**: C++ handles the game engine for performance, while Python implements the AI logic for clarity and ease of implementation
- **Algorithm implementation**: Full Minimax algorithm built from scratch without external AI libraries
- **Clean architecture**: Separation of concerns between game logic, AI engine, and user interface
- **Real-world application**: Demonstrates how different programming languages can work together in a single project

### Why This Project?

This isn't just a simple game—it's a demonstration of:
1. **Algorithm mastery**: Understanding and implementing game theory algorithms
2. **System design**: Building a multi-component system with clear interfaces
3. **Language integration**: Making C++ and Python communicate effectively
4. **Problem-solving**: Creating an AI that plays perfectly without machine learning

---

## 🌟 Features

- ✨ **Unbeatable AI** - Uses the Minimax algorithm to play optimally; will never lose
- ⚡ **High Performance** - C++ game engine ensures fast, responsive gameplay
- 🧠 **Intelligent Decision-Making** - Python AI evaluates all possible game states
- 🎯 **Clean Terminal UI** - Beautiful ASCII art interface with clear visual feedback
- 🔗 **Inter-Language Communication** - Seamless data exchange between C++ and Python
- 📊 **Optimal Play** - AI chooses moves that lead to fastest wins or prevent losses
- 🎮 **Interactive Gameplay** - Easy-to-use interface with input validation
- 💪 **Robust Error Handling** - Comprehensive validation and error messages
- 🔄 **Replayable** - Quick restarts for multiple games
- 📝 **Well-Documented Code** - Clean, readable code structure

---

## 🛠️ Technologies Used

### Languages
- **C++17** - Game logic, user interface, and main game loop
- **Python 3.x** - AI engine and Minimax algorithm implementation

### Algorithm
- **Minimax** - Game theory algorithm for optimal decision-making
- **Recursive tree search** - Explores all possible game states
- **Depth-based scoring** - Prioritizes faster wins and delayed losses

### Tools
- **Make** - Build automation
- **Git** - Version control
- **Inter-process communication** - C++ ↔ Python data exchange via command-line arguments

---

## 📋 Prerequisites

Before running this project, ensure you have:

### Required
- **C++ Compiler** (g++ 7.0+ or clang++ 5.0+)
  - Must support C++17 features (structured bindings)
- **Python 3.x** (3.6 or higher)
  - Only uses standard library (no external packages needed)

### Optional
- **Make** - For easier compilation (can compile manually without it)
- **Git** - For cloning the repository

### Platform Support
- ✅ **Linux** (Tested on Ubuntu 20.04+)
- ✅ **macOS** (Tested on macOS 11+)
- ✅ **Windows** (WSL, MinGW, or Cygwin)

---

## 🚀 Installation & Running

### Quick Start

```bash
# 1. Clone the repository
git clone https://github.com/MagnusArcher/tic-tac-toe-ai.git
cd tic-tac-toe-ai

# 2. Navigate to C++ directory
cd cpp

# 3. Compile the game
make

# 4. Run the game
./tic_tac_toe
