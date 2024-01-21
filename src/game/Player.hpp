#ifndef CHESSBOARDPLAYERINTERFACE_HPP
#define CHESSBOARDPLAYERINTERFACE_HPP

#include <../board/Position.hpp>
#include <../pieces/Piece.hpp>

class Player {
public:

    virtual ~Player() = default;

    virtual std::pair<Position, Position> getMove() = 0;

    virtual PieceType getPiecePromotionType() = 0;
};

#endif //CHESSBOARDPLAYERINTERFACE_HPP
