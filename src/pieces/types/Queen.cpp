#include "Queen.hpp"

Queen::Queen(Color color): Piece(color,QUEEN_VALUE){}

bool Queen::isMoveValid(int fromX, int fromY, int toX, int toY) {
    return MoveValidator::isMoveValid(fromX, fromY, toX, toY, getColor(), PieceType::QUEEN);
}

PieceType Queen::getType() {
    return QUEEN;
};