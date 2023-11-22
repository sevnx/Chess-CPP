#ifndef CHESS_CPP_MOVETYPES_HPP
#define CHESS_CPP_MOVETYPES_HPP

#include "ChessBoard.hpp"

enum class ExistingMoves {
    DIAGONAL,
    STRAIGHT,
    L_SHAPED,
    ONE_BY_ONE_BOX,
    ONE_STEP_FORWARD,
    ONE_OR_TWO_STEPS_FORWARD,
    ONE_STEP_FORWARD_DIAGONALLY
};

enum class MoveType {
    EN_PASSANT,
    CASTLING,
    NORMAL
};

class ExistingMoveChecker {
    const ChessBoard& board;
    Position from;
    Position to;
    Piece& pieceFrom;

    ExistingMoveChecker(const ChessBoard& board, int fromX, int fromY, int toX, int toY);

    [[nodiscard]] bool isMoveEnPassant() const;

    [[nodiscard]] bool isMoveCastling() const;

public:
        static MoveType getMoveType(const ChessBoard& board, int fromX, int fromY, int toX, int toY);
};

MoveType getMoveType(ChessBoard& board, int fromX, int fromY, int toX, int toY);

#endif //CHESS_CPP_MOVETYPES_HPP
