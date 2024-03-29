#ifndef CHESS_CPP_MOVEVALIDATOR_HPP
#define CHESS_CPP_MOVEVALIDATOR_HPP

#include "MoveStatusChecker.hpp"

enum class MoveStatus {
        VALID,
        CHECK,
        INCORRECT_TURN,
        INCORRECT_POSITION,
        INCORRECT_MOVE,
};

class MoveChecker {
public:
        static MoveStatus canMove(const ChessBoard& board, int fromX, int fromY, int toX, int toY, PieceColor currentTurn);
};

#endif //CHESS_CPP_MOVEVALIDATOR_HPP
