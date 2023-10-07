#ifndef CHESS_CPP_BISHOP_HPP
#define CHESS_CPP_BISHOP_HPP

#include <array>
#include "../Piece.h"
#include <algorithm>

class Bishop : public Piece {
private:
    enum {
        BISHOP_VALUE = 3
    };
public:
    explicit Bishop(Color color);
    bool isMoveValid(int fromX, int fromY, int toX, int toY) override;
    ~Bishop() override = default;
};


#endif //CHESS_CPP_BISHOP_HPP
