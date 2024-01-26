#ifndef PLAYERSTUPIDAI_HPP
#define PLAYERSTUPIDAI_HPP
#include "ChessBoard.hpp"
#include "game/Player.hpp"

class PlayerStupidAI final : public Player {
    ChessBoard&board;
    PieceColor color;

public:
    PlayerStupidAI(ChessBoard&board, PieceColor color);

    std::pair<Position, Position> getMove() override;

    PieceType getPiecePromotionType() override;
};

#endif //PLAYERSTUPIDAI_HPP
