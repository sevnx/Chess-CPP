//
// Created by sev on 04/10/2023.
//

#include "Queen.hpp"

Queen::Queen(Color color): Piece(color,QUEEN_VALUE){}

bool Queen::canMove(unsigned int fromX, unsigned int fromY, unsigned int toX, unsigned int toY) {
    return false;
};