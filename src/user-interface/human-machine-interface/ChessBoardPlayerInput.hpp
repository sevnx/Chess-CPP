#ifndef CHESSBOARDPLAYERINTERFACE_HPP
#define CHESSBOARDPLAYERINTERFACE_HPP

#include <Piece.hpp>
#include <Position.hpp>

class ChessBoardPlayerInput {
    public:
        virtual ~ChessBoardPlayerInput() = default;

        virtual Position getCurrentPlayerMove() = 0;

        virtual PieceType getPromotionPieceType() = 0;
};

#endif //CHESSBOARDPLAYERINTERFACE_HPP
