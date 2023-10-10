#ifndef CHESS_CPP_KING_HPP
#define CHESS_CPP_KING_HPP

#include "../Piece.h"

class King : public Piece {
private:
    enum {
        KING_VALUE = 0
    };
public:
    explicit King(PieceColor color);
    ~King() override = default;
};

#endif //CHESS_CPP_KING_HPP
