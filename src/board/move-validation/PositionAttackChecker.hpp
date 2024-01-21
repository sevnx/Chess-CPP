#ifndef CHESS_CPP_POSITIONATTACKCHECKER_HPP
#define CHESS_CPP_POSITIONATTACKCHECKER_HPP

#include "MovePossibilityChecker.hpp"
#include "../ChessBoard.hpp"

/**
 * Checks if a position is attacked by any piece of the opposite color
 */
class PositionAttackChecker {
    ChessBoard& board;
    PieceColor ourColor;

public:

    PositionAttackChecker(ChessBoard& board, PieceColor ourColor);

    [[nodiscard]] bool isPositionAttacked(int x, int y) const;

    [[nodiscard]] bool isPositionAttacked(Position position) const;

    [[nodiscard]] bool arePositionsAttacked(const std::vector<Position>& positions) const;
};

#endif //CHESS_CPP_POSITIONATTACKCHECKER_HPP
