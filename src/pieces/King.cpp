//
// Created by sev on 04/10/2023.
//

#include "King.hpp"

King::King(Color color): Piece(color,KING_CHECK_VALUE){}

bool King::canMove(unsigned int fromX, unsigned int fromY, unsigned int toX, unsigned int toY) {
    return false;
}
