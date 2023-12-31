#ifndef MOVEENDGAMECHECKER_HPP
#define MOVEENDGAMECHECKER_HPP

#include "PositionAttackChecker.hpp"
#include "../move-getter/BoardPossibleMoveGetter.hpp"

class MoveEndGameChecker {
public:
    static bool isCheck(ChessBoard& board, PieceColor color);
    static bool isCheckAfterMove(const ChessBoard& board, PieceColor color, int fromX, int fromY, int toX, int toY);
    static bool isCheckmate(ChessBoard &board, PieceColor color);
    static bool isCheckmateAfterMove(const ChessBoard &board, PieceColor color, int fromX, int fromY, int toX, int toY);
    static bool isStalemate(const ChessBoard &board, PieceColor color);

    // Checks for draw by insufficient material
    static bool isDraw(ChessBoard &board);
};

#endif //MOVEENDGAMECHECKER_HPP
