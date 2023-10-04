#ifndef CHESS_CPP_KING_HPP
#define CHESS_CPP_KING_HPP

#include "Piece.h"

class King : public Piece {
private:
    enum {
        KING_CHECK_VALUE = 0
    };
public:
    explicit King(Color color);
    bool canMove(unsigned int fromX, unsigned int fromY, unsigned int toX, unsigned int toY) override;
    ~King() override = default;
};


#endif //CHESS_CPP_KING_HPP
