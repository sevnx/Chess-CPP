#ifndef CHESS_CPP_KNIGHT_HPP
#define CHESS_CPP_KNIGHT_HPP

#include <array>
#include "../Piece.h"

class Knight : public Piece {
private:
    enum {
        KNIGHT_VALUE = 3
    };
public:
    explicit Knight(Color color);
    bool isMoveValid(int fromX, int fromY, int toX, int toY) override;
    ~Knight() override = default;
};


#endif //CHESS_CPP_KNIGHT_HPP
