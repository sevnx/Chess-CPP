#include "GamePlay.hpp"
#include <iostream>

#include <move-validation/MoveEndGameChecker.hpp>

GamePlay::GamePlay(): board(BoardType::DEFAULT_CHESS_BOARD), turnColor(PieceColor::WHITE) {}

void GamePlay::startGame() {
    GamePlay game;
    while (!game.isGameOver()) {
        game.turn();
        game.nextTurn();
    }
}

GamePlay::GameState GamePlay::getGameState() {
    if (MoveEndGameChecker::isCheckmate(board, turnColor)) {
        return GameState::CHECKMATE;
    } if (MoveEndGameChecker::isStalemate(board, turnColor)) {
        return GameState::STALEMATE;
    } if (MoveEndGameChecker::isDraw(board)) {
        return GameState::DRAW;
    }
    return GameState::IN_PROGRESS;
}

void GamePlay::turn() {

}

bool GamePlay::isGameOver() {
    return getGameState() != GameState::IN_PROGRESS;
}

void GamePlay::nextTurn() {
    turnColor = turnColor == PieceColor::WHITE ? PieceColor::BLACK : PieceColor::WHITE;
}
