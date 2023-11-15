#ifndef CHESS_CPP_ROOK_HPP
#define CHESS_CPP_ROOK_HPP

#include "../Piece.hpp"

class Rook final : public Piece {
    enum {
        ROOK_VALUE = 5
    };
public:
    explicit Rook(PieceColor color);

    ~Rook() override = default;
};

#endif //CHESS_CPP_ROOK_HPP
