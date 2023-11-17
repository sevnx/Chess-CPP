#ifndef CHESS_CPP_GAMEPLAY_HPP
#define CHESS_CPP_GAMEPLAY_HPP

#include "../board/ChessBoard.hpp"
#include "../user-interface/human-machine-interface/ChessBoardPlayerInput.hpp"
#include "../board/move-validation/MoveEndGameChecker.hpp"

class GamePlay {
    enum class GameState {
        IN_PROGRESS,
        CHECKMATE,
        STALEMATE,
        DRAW
    };

    static constexpr PieceColor STARTING_TURN_COLOR = PieceColor::WHITE;

    GamePlay();

    ChessBoard board;

    PieceColor turnColor = STARTING_TURN_COLOR;

    GameState getGameState();

    void nextTurn();

    void turn();

    bool isGameOver();
public:
    static void startGame();

    ~GamePlay() = default;
};

#endif //CHESS_CPP_GAMEPLAY_HPP
