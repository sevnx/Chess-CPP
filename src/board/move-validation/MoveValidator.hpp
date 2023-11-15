#ifndef CHESS_CPP_MOVEVALIDATOR_HPP
#define CHESS_CPP_MOVEVALIDATOR_HPP

#include "MoveValidityChecker.hpp"
#include "MoveLegalityChecker.hpp"

namespace MoveChecker {
    bool canMove(ChessBoard &board, int fromX, int fromY, int toX, int toY);
};

#endif //CHESS_CPP_MOVEVALIDATOR_HPP
