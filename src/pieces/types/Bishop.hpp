#ifndef CHESS_CPP_BISHOP_HPP
#define CHESS_CPP_BISHOP_HPP

#include "../Piece.hpp"

class Bishop : public Piece {
private:
    enum {
        BISHOP_VALUE = 3
    };
public:
    explicit Bishop(PieceColor color);

    ~Bishop() override = default;
};

#endif //CHESS_CPP_BISHOP_HPP
