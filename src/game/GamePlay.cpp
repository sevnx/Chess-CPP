#include "GamePlay.hpp"

GamePlay::GamePlay(): board(BoardType::DEFAULT_CHESS_BOARD), turnColor(PieceColor::WHITE) {

}

void GamePlay::startGame() {
    GamePlay game;
    while (!game.isGameOver()) {
        game.turn();
    }
}

GamePlay::GameState GamePlay::getGameState() {
    return GamePlay::GameState::IN_PROGRESS;
}

void GamePlay::turn() {
    nextTurn();
}

bool GamePlay::isGameOver() {
    return getGameState() != GamePlay::GameState::IN_PROGRESS;
}

void GamePlay::nextTurn() {
    turnColor = turnColor == PieceColor::WHITE ? PieceColor::BLACK : PieceColor::WHITE;
}
