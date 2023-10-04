//
// Created by sev on 04/10/2023.
//

#include "Bishop.hpp"

Bishop::Bishop(Color color): Piece(color,BISHOP_VALUE){}

bool Bishop::canMove(unsigned int fromX, unsigned int fromY, unsigned int toX, unsigned int toY) {
    return false;
};
