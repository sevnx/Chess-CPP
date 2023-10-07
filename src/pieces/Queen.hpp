#ifndef CHESS_CPP_QUEEN_HPP
#define CHESS_CPP_QUEEN_HPP

#include "../Piece.h"

class Queen : public Piece {
private:
    enum {
        QUEEN_VALUE = 9
    };
public:
    explicit Queen(Color color);
    bool isMoveValid(int fromX, int fromY, int toX, int toY) override;
    ~Queen() override = default;
};


#endif //CHESS_CPP_QUEEN_HPP
