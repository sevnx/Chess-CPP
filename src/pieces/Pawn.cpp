#include "Pawn.hpp"

Pawn::Pawn(Color color): Piece(color,PAWN_VALUE){}

bool Pawn::canMove(unsigned int fromX, unsigned int fromY, unsigned int toX, unsigned int toY) {
    return false;
};
