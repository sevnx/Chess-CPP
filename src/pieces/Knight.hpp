#ifndef CHESS_CPP_KNIGHT_HPP
#define CHESS_CPP_KNIGHT_HPP

#include "Piece.h"

class Knight : public Piece {
private:
    enum {
        KNIGHT_VALUE = 3
    };
public:
    explicit Knight(Color color);
    bool canMove(unsigned int fromX, unsigned int fromY, unsigned int toX, unsigned int toY) override;
    ~Knight() override = default;
};


#endif //CHESS_CPP_KNIGHT_HPP
