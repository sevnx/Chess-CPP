#ifndef CHESS_CPP_ROOK_HPP
#define CHESS_CPP_ROOK_HPP

#include "../Piece.h"

class Rook : public Piece {
private:
    enum {
        ROOK_VALUE = 5
    };
public:
    explicit Rook(Color color);
    bool isMoveValid(int fromX, int fromY, int toX, int toY) override;
    ~Rook() override = default;
};


#endif //CHESS_CPP_ROOK_HPP
