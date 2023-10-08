#ifndef CHESS_CPP_KING_HPP
#define CHESS_CPP_KING_HPP

#include "../Piece.h"
#include "../../utility/MoveValidator.hpp"

class King : public Piece {
private:
    enum {
        KING_CHECK_VALUE = 0
    };
public:
    explicit King(Color color);
    bool isMoveValid(int fromX, int fromY, int toX, int toY) override;
    PieceType getType() override;
    ~King() override = default;
};


#endif //CHESS_CPP_KING_HPP
