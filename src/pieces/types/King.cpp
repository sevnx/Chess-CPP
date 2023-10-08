#include "King.hpp"

King::King(Color color): Piece(color,KING_CHECK_VALUE){}

bool King::isMoveValid(int fromX, int fromY, int toX, int toY) {
    return MoveValidator::isMoveValid(fromX, fromY, toX, toY, getColor(), PieceType::KING);
}

PieceType King::getType() {
    return KING;
}
