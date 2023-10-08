#ifndef CHESS_CPP_PIECE_H
#define CHESS_CPP_PIECE_H

#include "../board/Position.h"

typedef enum {
    BLACK, WHITE
} Color;

typedef enum {
    PAWN, ROOK, KNIGHT, BISHOP, QUEEN, KING
} PieceType;

class Piece {
private:
    Color color;
    unsigned int value;
protected:
    Piece(Color color, unsigned int value);
public:
    [[nodiscard]] Color getColor() const;
    [[nodiscard]] unsigned int getValue() const;
    virtual bool isMoveValid(int fromX, int fromY, int toX, int toY) = 0;
    virtual PieceType getType() = 0;
    virtual ~Piece() = default;
};

#endif //CHESS_CPP_PIECE_H
