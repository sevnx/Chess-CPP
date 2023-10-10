#ifndef CHESS_CPP_MOVECHECKER_HPP
#define CHESS_CPP_MOVECHECKER_HPP

#include "MoveValidityCheck.hpp"
#include "MoveLegalityCheck.hpp"

namespace MoveChecker {
    static bool canMove(Board& board, int fromX, int fromY, int toX, int toY);
};

#endif //CHESS_CPP_MOVECHECKER_HPP
