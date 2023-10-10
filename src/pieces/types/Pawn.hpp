#ifndef CHESS_CPP_PAWN_HPP
#define CHESS_CPP_PAWN_HPP

#include "../Piece.h"

class Pawn : public Piece {
private:
    enum {
        PAWN_VALUE = 1,
    };
public:
    explicit Pawn(PieceColor color);
    ~Pawn() override = default;
};

#endif //CHESS_CPP_PAWN_HPP
