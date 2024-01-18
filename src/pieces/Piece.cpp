#include "Piece.hpp"

Piece::Piece(const PieceColor color, const PieceType type, const unsigned int value) :
        color(color), type(type), value(value), moveCount(0) {}

PieceColor Piece::getColor() const {
    return color;
}

unsigned int Piece::getValue() const {
    return value;
}

unsigned int Piece::getMoveCount() const {
    return moveCount;
}

void Piece::incrementMoveCount() {
    moveCount++;
}

bool Piece::isFirstMove() const {
    return moveCount == 0;
}

PieceType Piece::getType() const {
    return type;
}

bool Piece::operator==(const Piece &other) const {
    return type == other.type;
}
