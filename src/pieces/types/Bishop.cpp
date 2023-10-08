#include "Bishop.hpp"

Bishop::Bishop(Color color): Piece(color,BISHOP_VALUE){}

bool Bishop::isMoveValid(int fromX, int fromY, int toX, int toY) {
    return MoveValidator::isMoveValid(fromX, fromY, toX, toY, getColor(), PieceType::BISHOP);
}

PieceType Bishop::getType() {
    return BISHOP;
}
