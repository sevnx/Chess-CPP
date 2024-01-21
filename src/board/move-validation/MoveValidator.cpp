#include "MoveValidator.hpp"

MoveStatus MoveChecker::canMove(ChessBoard& board, const int fromX, const int fromY, const int toX, const int toY, const PieceColor currentTurn) {
    if (!board.isPositionOccupied({fromX, fromY}))
        return MoveStatus::INCORRECT_POSITION;
    if (board.getPieceAt({fromX, fromY}).getColor() != currentTurn)
        return MoveStatus::INCORRECT_TURN;
    if (!MovePossibilityChecker::isMovePossible(board, fromX, fromY, toX, toY))
        return MoveStatus::INCORRECT_MOVE;
    if (MoveEndGameChecker::isCheckAfterMove(board, currentTurn, fromX, fromY, toX, toY))
        return MoveStatus::CHECK;
    return MoveStatus::VALID;
}
