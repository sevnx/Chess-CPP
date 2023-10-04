#ifndef CHESS_CPP_QUEEN_HPP
#define CHESS_CPP_QUEEN_HPP

#include "Piece.h"

class Queen : public Piece {
private:
    enum {
        QUEEN_VALUE = 9
    };
public:
    explicit Queen(Color color);
    bool canMove(unsigned int fromX, unsigned int fromY, unsigned int toX, unsigned int toY) override;
    ~Queen() override = default;
};


#endif //CHESS_CPP_QUEEN_HPP
