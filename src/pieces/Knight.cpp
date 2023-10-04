//
// Created by sev on 04/10/2023.
//

#include "Knight.hpp"


Knight::Knight(Color color): Piece(color,KNIGHT_VALUE){}

bool Knight::canMove(unsigned int fromX, unsigned int fromY, unsigned int toX, unsigned int toY) {
    return false;
};