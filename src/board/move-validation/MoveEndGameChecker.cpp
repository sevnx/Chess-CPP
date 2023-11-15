#include "MoveEndGameChecker.hpp"

#include "PositionAttackChecker.hpp"


bool MoveEndGameChecker::isCheck(ChessBoard& board, PieceColor color) {
    const BoardPositionGetter positionGetter(board);
    const PositionAttackChecker attackedPositionChecker(board, color);
    const Position kingPosition = positionGetter.getFirstPiecePosition(color, PieceType::KING);
    return attackedPositionChecker.isPositionAttacked(kingPosition);
}

bool MoveEndGameChecker::isCheckAfterMove(ChessBoard& board, PieceColor color, int fromX, int fromY, int toX, int toY) {
    ChessBoard boardCopy = board;
    boardCopy.movePiece({fromX, fromY}, {toX, toY});
    return isCheck(boardCopy, color);
}

bool MoveEndGameChecker::isCheckmate(ChessBoard& board, PieceColor color) {
    // TODO: implement
}

bool MoveEndGameChecker::isCheckmateAfterMove(ChessBoard& board, PieceColor color, int fromX, int fromY, int toX,
    int toY) {
    ChessBoard boardCopy = board;
    boardCopy.movePiece({fromX, fromY}, {toX, toY});
    return isCheckmate(boardCopy, color);
}

bool MoveEndGameChecker::isStalemate(ChessBoard& board, PieceColor color) {
}

bool MoveEndGameChecker::isDraw(ChessBoard& board) {
}
