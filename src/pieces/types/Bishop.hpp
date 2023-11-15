#ifndef CHESS_CPP_BISHOP_HPP
#define CHESS_CPP_BISHOP_HPP

#include "../Piece.hpp"

typedef PieceColor BishopColor;

class Bishop final : public Piece {
    enum {
        BISHOP_VALUE = 3
    };
    BishopColor bishopColor;
public:
    explicit Bishop(PieceColor color, BishopColor bishopColor);

    ~Bishop() override = default;
};

#endif //CHESS_CPP_BISHOP_HPP
