#ifndef CHESS_CPP_GAMEPLAY_HPP
#define CHESS_CPP_GAMEPLAY_HPP

#include "../board/ChessBoard.hpp"
#include "../gui/ChessBoardView.hpp"
#include "../gui/PieceView.hpp"

class GamePlay {
private:
    enum class GameState {
        IN_PROGRESS,
        CHECKMATE,
        STALEMATE,
        DRAW
    };
    const static PieceColor STARTING_TURN_COLOR = PieceColor::WHITE;

    GamePlay();

    ChessBoard board;

    PieceColor turnColor = STARTING_TURN_COLOR;

    ChessBoardView boardView;

    GameState getGameState();

    void nextTurn();

    void turn();

    bool isGameOver();
public:
    static void startGame();

    ~GamePlay() = default;
};

#endif //CHESS_CPP_GAMEPLAY_HPP
