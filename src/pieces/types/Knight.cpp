#include "Knight.hpp"


Knight::Knight(Color color): Piece(color,KNIGHT_VALUE){}

bool Knight::isMoveValid(int fromX, int fromY, int toX, int toY) {
    return MoveValidator::isMoveValid(fromX, fromY, toX, toY, getColor(), PieceType::KNIGHT);
}

PieceType Knight::getType() {
    return KNIGHT;
}
