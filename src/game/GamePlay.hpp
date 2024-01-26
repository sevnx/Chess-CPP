#ifndef CHESS_CPP_GAMEPLAY_HPP
#define CHESS_CPP_GAMEPLAY_HPP

#include "Player.hpp"
#include "../board/ChessBoard.hpp"
#include "../user-interface/text-based-interface/ChessBoardConsoleView.hpp"

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

    std::unique_ptr<ChessBoardConsoleView> boardView;

    std::unique_ptr<Player> whitePlayer;

    std::unique_ptr<Player> blackPlayer;

    PieceColor turnColor;

    GameState getGameState() const;

    void nextTurn();

    void turn();

    void executeMove(const std::pair<Position, Position>& move);

    [[nodiscard]] bool isGameOver() const;

    [[nodiscard]] bool canPromotePawn(PieceColor color) const;

public:
    static void startGame();

    ~GamePlay() = default;
};

#endif //CHESS_CPP_GAMEPLAY_HPP
