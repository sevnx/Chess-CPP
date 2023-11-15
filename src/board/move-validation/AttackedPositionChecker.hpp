#ifndef CHESS_CPP_POSITIONATTACKCHECKER_HPP
#define CHESS_CPP_POSITIONATTACKCHECKER_HPP

#include "board/move-checking/MoveChecker.hpp"
#include <algorithm>

class PositionAttackChecker {
private:
    std::map<Position, bool> positionAttacked;
    Board &board;
    PieceColor ourColor;
public:
    PositionAttackChecker(Board &board, PieceColor ourColor);

    bool isPositionAttacked(int x, int y);

    bool isPositionAttacked(Position position);

    bool arePositionsAttacked(const std::vector<Position> &positions);
};


#endif //CHESS_CPP_POSITIONATTACKCHECKER_HPP
