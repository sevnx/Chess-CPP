#ifndef CHESS_CPP_MOVECHECKER_HPP
#define CHESS_CPP_MOVECHECKER_HPP

#include "MoveValidityChecker.hpp"
#include "MoveLegalityChecker.hpp"

namespace MoveChecker {
    bool canMove(Board &board, int fromX, int fromY, int toX, int toY);
};

#endif //CHESS_CPP_MOVECHECKER_HPP
