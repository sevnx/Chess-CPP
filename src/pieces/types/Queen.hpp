#ifndef CHESS_CPP_QUEEN_HPP
#define CHESS_CPP_QUEEN_HPP

#include "../Piece.hpp"

class Queen : public Piece {
private:
    enum {
        QUEEN_VALUE = 9
    };
public:
    explicit Queen(PieceColor color);

    ~Queen() override = default;
};

#endif //CHESS_CPP_QUEEN_HPP
