#ifndef PLAYERSMARTAI_HPP
#define PLAYERSMARTAI_HPP
#include "ChessBoard.hpp"
#include "game/Player.hpp"

class PlayerSmartAI final : public Player {
    const ChessBoard& board;
    PieceColor color;
public:
    PlayerSmartAI(const ChessBoard& board, PieceColor color);

    std::pair<Position, Position> getMove() override;

    PieceType getPiecePromotionType() override;
};



#endif //PLAYERSMARTAI_HPP
