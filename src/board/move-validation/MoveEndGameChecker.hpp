#ifndef MOVEENDGAMECHECKER_HPP
#define MOVEENDGAMECHECKER_HPP

#include "PositionAttackChecker.hpp"

class MoveEndGameChecker {
public:
    static bool isCheck(ChessBoard& board, PieceColor color);
    static bool isCheckAfterMove(ChessBoard board, PieceColor color, int fromX, int fromY, int toX, int toY);
    static bool isCheckmate(ChessBoard &board, PieceColor color);
    static bool isStalemate(const ChessBoard&board, PieceColor color);

    // Checks for draw by insufficient material
    static bool isDraw(const ChessBoard &board);
};

#endif //MOVEENDGAMECHECKER_HPP
