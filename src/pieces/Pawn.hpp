#ifndef CHESS_CPP_PAWN_HPP
#define CHESS_CPP_PAWN_HPP

#include "Piece.h"

class Pawn : public Piece {
private:
    enum {
        PAWN_VALUE = 1,
        MOVE_DISTANCE = 1,
        FIRST_MOVE_DISTANCE = 2
    };
    bool firstMove;
public:
    explicit Pawn(Color color);
    bool canMove(unsigned int fromX, unsigned int fromY, unsigned int toX, unsigned int toY) override;
    ~Pawn() override = default;
};


#endif //CHESS_CPP_PAWN_HPP
