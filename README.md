# Chess in C++

## Description  
This project has been started as a way for me to learn and practice C++ and OOP.

The end goal is to have a fully functional chess game with a GUI (for now I am focusing on game logic
and for that making the game playable in the terminal is way easier, as I do not have
any experience with GUIs in C++).

It is written in C++17 and will use most likely, the [SFML](https://www.sfml-dev.org/) library for the GUI.

## Known Issues

- Castling implementation can be improved (check in King class), hard coded scenario that doesn't reflect the game

## Roadmap

✅ - Done

🟡 - In progress

❌ - Not started

## Overview

- ✅ Board creation and display in terminal
- ✅ Game logic (turns, etc.)
- ✅ Piece movement
- ✅ Game checks (check, checkmate, etc.)
- ❌ Game saving and loading
- ❌ Move logging
- ❌ GUI
- 🟡 AI <- Start of implementation (see [AI Roadmap](#ai-roadmap))

### AI Roadmap

- ✅ Basic AI that moves a random piece
- ✅ AI that moves a random piece that doesn't put the king in check
- ✅ AI that moves a piece after evaluating the possible moves and choosing the best one (takes into account if the move puts opponent in check, if the move captures a piece, etc.)
- ❌ Moves based on value (e.g. currently the AI captures the first piece it encounters (if other checks fail))
- ❌ Moves that aren't worth it (e.g. capturing pawn with queen, then queen can be captured by another piece)
- 🟡 AI that can play a full game (bugs sometimes)