//
// Created by sev on 04/10/2023.
//

#include "Rook.hpp"

Rook::Rook(Color color): Piece(color,ROOK_VALUE){}

bool Rook::canMove(unsigned int fromX, unsigned int fromY, unsigned int toX, unsigned int toY) {
    return false;
};
