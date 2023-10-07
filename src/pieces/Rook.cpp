#include "Rook.hpp"

Rook::Rook(Color color): Piece(color,ROOK_VALUE){}

bool Rook::isMoveValid(int fromX, int fromY, int toX, int toY) {
    return MoveValidator::isMoveValid(fromX, fromY, toX, toY, getColor(), PieceType::ROOK);
};
