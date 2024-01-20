#include "MoveEndGameChecker.hpp"


bool MoveEndGameChecker::isCheck(ChessBoard& board, const PieceColor color) {
    const BoardPositionGetter positionGetter(board);
    const PositionAttackChecker attackedPositionChecker(board, color);
    const Position kingPosition = positionGetter.getFirstPiecePosition(color, PieceType::KING);
    return attackedPositionChecker.isPositionAttacked(kingPosition);
}

bool MoveEndGameChecker::isCheckAfterMove(const ChessBoard& board, const PieceColor color, int fromX, int fromY, int toX, int toY) {
    ChessBoard boardCopy = board;
    boardCopy.movePiece({fromX, fromY}, {toX, toY});
    return isCheck(boardCopy, color);
}

bool MoveEndGameChecker::isCheckmate(ChessBoard& board, const PieceColor color) {
    if (!isCheck(board, color))
        return false;
    const auto possibleMoves = BoardPossibleMoveGetter::getPossibleMoves(board, color);
    for (auto& [from, to]: possibleMoves)
        if (!isCheckAfterMove(board, color, from.x, from.y, to.x, to.y))
            return true;
    return false;
}

bool MoveEndGameChecker::isCheckmateAfterMove(const ChessBoard& board, const PieceColor color, int fromX, int fromY, int toX, int toY) {
    ChessBoard boardCopy = board;
    boardCopy.movePiece({fromX, fromY}, {toX, toY});
    return isCheckmate(boardCopy, color);
}

bool MoveEndGameChecker::isStalemate(const ChessBoard& board, const PieceColor color) {
    const auto possibleMoves = BoardPossibleMoveGetter::getPossibleMoves(board, color);
    for (auto& [from, to] : possibleMoves) {
        if (!isCheckAfterMove(board, color, from.x, from.y, to.x, to.y)) {
            return false;
        }
    }
    return true;
}

bool MoveEndGameChecker::isDraw(ChessBoard& board) {
    return false;
}
