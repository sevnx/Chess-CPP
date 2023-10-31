#include "PositionAttackChecker.hpp"

PositionAttackChecker::PositionAttackChecker(Board &board, PieceColor ourColor)
        : board(board), ourColor(ourColor), positionAttacked() {}

bool PositionAttackChecker::isPositionAttacked(int x, int y) {
    if (positionAttacked.find(Position(x, y)) != positionAttacked.end())
        return positionAttacked[Position(x, y)];
    for (int i = 0; i < Position::MAX_POSITION; i++) {
        for (int j = 0; j < Position::MAX_POSITION; j++) {
            if (board.getPieceAt(i, j).getColor() == ourColor)
                continue;
            // Check if piece can move while not leaving king in check

        }
    }
    positionAttacked[Position(x, y)] = false;
    return false;
}

bool PositionAttackChecker::arePositionsAttacked(const std::vector<Position> &positions) {
    for (const Position &position: positions) {
        if (isPositionAttacked(position.x, position.y))
            return true;
    }
    return false;
}

bool PositionAttackChecker::isPositionAttacked(Position position) {
    return isPositionAttacked(position.x, position.y);
};


