#ifndef CHESS_CPP_MOVEVALIDATOR_HPP
#define CHESS_CPP_MOVEVALIDATOR_HPP

#include "MovePossibilityChecker.hpp"
#include "PositionAttackChecker.hpp"

class MoveChecker {
public:
        static bool canMove(ChessBoard& board, int fromX, int fromY, int toX, int toY, PieceColor currentTurn);
};

#endif //CHESS_CPP_MOVEVALIDATOR_HPP
