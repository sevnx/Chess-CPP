#include "MoveChecker.hpp"

bool MoveChecker::canMove(Board &board, int fromX, int fromY, int toX, int toY) {
    return MoveValidityCheck::isMoveValid(board.getPieceAt(fromX, fromY), fromX, fromY, toX, toY) &&
           MoveLegalityCheck::isMoveLegal(board, fromX, fromY, toX, toY);
}