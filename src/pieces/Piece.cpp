#include "Piece.h"

Piece::Piece(Color color,  unsigned int value): color(color), value(value){}

Color Piece::getColor() const {
    return color;
}

unsigned int Piece::getValue() const {
    return value;
}