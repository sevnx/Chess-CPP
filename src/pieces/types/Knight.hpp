#ifndef CHESS_CPP_KNIGHT_HPP
#define CHESS_CPP_KNIGHT_HPP

#include "../Piece.hpp"

class Knight final : public Piece {
    enum {
        KNIGHT_VALUE = 3
    };
public:
    explicit Knight(PieceColor color);

    ~Knight() override = default;
};

#endif //CHESS_CPP_KNIGHT_HPP
