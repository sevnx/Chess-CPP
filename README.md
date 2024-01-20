# Chess in C++

## Description  
This project has been started as a way for me to learn and practice C++ and OOP.

The end goal is to have a fully functional chess game with a GUI (for now I am focusing on game logic
and for that making the game playable in the terminal is way easier, as I do not have
any experience with GUIs in C++).

It is written in C++17 and will use most likely, the [SFML](https://www.sfml-dev.org/) library for the GUI.

## Known Issues

- Castling implementation can be improved (check in King class), hard coded scenario that doesn't reflect the game
- Checkmate can be weird at times
- No tests

## Roadmap

✅ - Done

🟡 - In progress

❌ - Not started

### Overview

- ✅ Board creation and display in terminal
- ✅ Game logic (turns, etc.) <- Need to test promotion
- ✅ Piece movement
- 🟡 Game checks (check, checkmate, etc.) <- Testing needed
- ❌ Game saving and loading
- ❌ Move logging
- ❌ GUI
- ❌ AI (maybe)
