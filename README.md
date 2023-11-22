# Chess in C++

## Description  
This project has been started as a way for me to learn and practice C++ and OOP. \
The end goal is to have a fully functional chess game with a GUI (for now I am focusing on game logic
and for that making the game playable in the terminal is way easier, as I do not have
any experience with GUIs in C++). \
It is written in C++17 and most likely, the [SFML](https://www.sfml-dev.org/) library for the GUI.

## Roadmap

✅ - Done \
🟡 - In progress \
❌ - Not started

### Overview
- ✅ Board creation and display in terminal
- ✅ Game logic (turns, etc.)
- 🟡 Piece movement <- problem with diagonal movement in some cases, en passant, castling, promotion need checking
- 🟡 Game checks (check, checkmate, etc.) <- problem with either checkmate or stalemate (game ends preemptively)
- ❌ Game saving and loading
- ❌ Move logging
- ❌ GUI
- ❌ AI (maybe)