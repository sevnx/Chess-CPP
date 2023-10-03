#include "Piece.h"

Position Piece::getPosition() const {
    return {this->position.x, this->position.y};
}

void Piece::setPosition(Position newPosition) {
    this->position.x = newPosition.x;
    this->position.y = newPosition.y;
}

Piece::Piece(Color color, Position position, unsigned int value): color(color), position(position), value(value){}
