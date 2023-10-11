#include "MoveChecker.hpp"

bool MoveChecker::canMove(Board &board, int fromX, int fromY, int toX, int toY) {
    return MoveValidityChecker::isMoveValid(board.getPieceAt(fromX, fromY), fromX, fromY, toX, toY) &&
           MoveLegalityChecker::isMoveLegal(board, fromX, fromY, toX, toY);
}