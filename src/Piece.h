#ifndef CHESS_CPP_PIECE_H
#define CHESS_CPP_PIECE_H
#include "Position.h"

typedef enum {
    BLACK, WHITE
} Color;

class Piece {
private:
    Color color;
    unsigned int value;
protected:
    Piece(Color color, Position position, unsigned int value);
public:
    [[nodiscard]] Position getPosition() const;
    void setPosition(Position newPosition);
    virtual bool canMoveTo(Position position) = 0;
    virtual ~Piece() = default;
};


#endif //CHESS_CPP_PIECE_H
