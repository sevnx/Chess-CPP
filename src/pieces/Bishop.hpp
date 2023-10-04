#ifndef CHESS_CPP_BISHOP_HPP
#define CHESS_CPP_BISHOP_HPP

#include "Piece.h"

class Bishop : public Piece {
private:
    enum {
        BISHOP_VALUE = 3
    };
public:
    explicit Bishop(Color color);
    bool canMove(unsigned int fromX, unsigned int fromY, unsigned int toX, unsigned int toY) override;
    ~Bishop() override = default;
};


#endif //CHESS_CPP_BISHOP_HPP
