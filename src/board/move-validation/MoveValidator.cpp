#include "MoveValidator.hpp"

bool MoveChecker::canMove(ChessBoard &board, const int fromX, const int fromY, const int toX, const int toY) {
    return MovePossibilityChecker::isMovePossible(board, fromX, fromY, toX, toY);
}