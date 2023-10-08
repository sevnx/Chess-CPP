#include "Pawn.hpp"

Pawn::Pawn(Color color): Piece(color,PAWN_VALUE){
    firstMove = true;
}

bool Pawn::isMoveValid(int fromX, int fromY, int toX, int toY) {
    return MoveValidator::isMoveValid(fromX, fromY, toX, toY, getColor(), PieceType::PAWN, firstMove);
}

PieceType Pawn::getType() {
    return PAWN;
};
