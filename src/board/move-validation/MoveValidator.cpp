#include "MoveValidator.hpp"

bool MoveChecker::canMove(ChessBoard& board, const int fromX, const int fromY, const int toX, const int toY, const PieceColor currentTurn) {
    return board.isPositionOccupied({fromX, fromY})
           && board.getPieceAt({fromX, fromY}).getColor() == currentTurn
           && (MovePossibilityChecker::isMovePossible(board, fromX, fromY, toX, toY)
           || ExistingMoveChecker::getMoveType(board, fromX, fromY, toX, toY) != MoveType::NORMAL);
}
