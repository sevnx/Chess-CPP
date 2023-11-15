#include "MoveValidator.hpp"

bool MoveChecker::canMove(ChessBoard &board, const int fromX, const int fromY, const int toX, const int toY) {
    return MoveValidityChecker::isMoveValid(board.getPieceAt({fromX, fromY}), fromX, fromY, toX, toY) &&
           MoveLegalityChecker::isMoveLegal(board, fromX, fromY, toX, toY);
}