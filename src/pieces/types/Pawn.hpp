#ifndef CHESS_CPP_PAWN_HPP
#define CHESS_CPP_PAWN_HPP

#include "../Piece.hpp"

class Pawn final : public Piece {
    enum {
        PAWN_VALUE = 1,
    };
public:
    explicit Pawn(PieceColor color);

    ~Pawn() override = default;
};

#endif //CHESS_CPP_PAWN_HPP
