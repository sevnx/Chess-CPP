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
    const BoardPositionGetter positionGetter(board);
    const Position kingPosition = positionGetter.getFirstPiecePosition(color, PieceType::KING);
    const std::vector<Position> kingPossibleMove = BoardPossibleMoveGetter::getPossibleMoveForKing
            (board, kingPosition.x, kingPosition.y, board.getPieceAt(kingPosition));
    if (!isCheck(board, color))
        return false;
    for (auto& move : kingPossibleMove)
        if (!isCheckAfterMove(board, color, kingPosition.x, kingPosition.y, move.x, move.y))
            return true;
    return false;
}

bool MoveEndGameChecker::isCheckmateAfterMove(const ChessBoard& board, const PieceColor color, int fromX, int fromY, int toX, int toY) {
    ChessBoard boardCopy = board;
    boardCopy.movePiece({fromX, fromY}, {toX, toY});
    return isCheckmate(boardCopy, color);
}

bool MoveEndGameChecker::isStalemate(const ChessBoard& board, const PieceColor color) {
    const std::vector<std::pair<Position, Position>> possibleMoves = BoardPossibleMoveGetter::getPossibleMoves(board, color);
    for (auto& [from, to] : possibleMoves) {
        if (!isCheckAfterMove(board, color, from.x, from.y, to.x, to.y)) {
            return false;
        }
    }
    return true;
}

bool MoveEndGameChecker::isDraw(ChessBoard& board) {
    // TODO: Implement this
    return false;
}
