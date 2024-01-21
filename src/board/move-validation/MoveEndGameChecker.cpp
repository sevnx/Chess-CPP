#include "MoveEndGameChecker.hpp"

bool MoveEndGameChecker::isCheck(ChessBoard&board, const PieceColor color) {
    const Position kingPosition = BoardPositionGetter(board).getFirstPiecePosition(color, PieceType::KING);
    return PositionAttackChecker(board, color).isPositionAttacked(kingPosition);
}

bool MoveEndGameChecker::isCheckAfterMove(ChessBoard board, const PieceColor color, int fromX, int fromY, int toX,
                                          int toY) {
    board.movePiece({fromX, fromY}, {toX, toY});
    return isCheck(board, color);
}

bool MoveEndGameChecker::isCheckmate(ChessBoard&board, const PieceColor color) {
    if (!isCheck(board, color))
        return false;
    for (const auto&[fst, snd]: BoardPossibleMoveGetter::getPossibleMoves(board, color)) {
        if (!isCheckAfterMove(board, color, fst.x, fst.y, snd.x, snd.y))
            return false;
    }
    return true;
}

bool MoveEndGameChecker::isStalemate(const ChessBoard&board, const PieceColor color) {
    return BoardPossibleMoveGetter::getPossibleMoves(board, color).empty();
}

bool MoveEndGameChecker::isDraw(ChessBoard&board) {
    return false;
}
