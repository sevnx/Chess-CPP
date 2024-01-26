#include "PositionAttackChecker.hpp"
#include <algorithm>

PositionAttackChecker::PositionAttackChecker(const ChessBoard& board, const PieceColor ourColor) : board(board)
  , ourColor(ourColor) {}

bool PositionAttackChecker::isPositionAttacked(const int x, const int y) const {
    for (int i = 0; i < Position::MAX_POSITION; i++) {
        for (int j = 0; j < Position::MAX_POSITION; j++) {
            if (!board.isPositionOccupied({i, j}))
                continue;
            if (board.getPieceAt({i, j}).getColor() == ourColor)
                continue;
            if (MovePossibilityChecker::isMovePossible(board, i, j, x, y)) {
                return true;
            }
        }
    }
    return false;
}

bool PositionAttackChecker::arePositionsAttacked(const std::vector<Position>& positions) const {
    std::any_of(positions.begin(), positions.end(), [&] (const Position position) {
        return isPositionAttacked(position);
    });
    return false;
}

bool PositionAttackChecker::isPositionAttacked(const Position position) const {
    return isPositionAttacked(position.x, position.y);
}



