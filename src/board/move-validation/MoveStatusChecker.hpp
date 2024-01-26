#ifndef MOVEENDGAMECHECKER_HPP
#define MOVEENDGAMECHECKER_HPP

#include "PositionAttackChecker.hpp"

class MoveStatusChecker {
public:
    static bool isCapture(const ChessBoard& board, int fromX, int fromY, int toX, int toY);
    static bool isCheck(const ChessBoard& board, PieceColor color);
    static bool isCheckAfterMove(ChessBoard board, PieceColor color, int fromX, int fromY, int toX, int toY);
    static bool isCheckmate(const ChessBoard &board, PieceColor color);
    static bool isCheckMateAfterMove(ChessBoard board, PieceColor color, int fromX, int fromY, int toX, int toY);
    static bool isStalemate(const ChessBoard&board, PieceColor color);

    // Checks for draw by insufficient material only
    static bool isDraw(const ChessBoard &board);
};

#endif //MOVEENDGAMECHECKER_HPP
