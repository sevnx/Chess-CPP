#include "MoveTypes.hpp"

ExistingMoveChecker::ExistingMoveChecker(ChessBoard& board, int fromX, int fromY, int toX, int toY):
    board(board), pieceFrom(board.getPieceAt({fromX, fromY})), from(fromX, fromY), to(toX, toY),
    pieceTo(board.getPieceAt({toX, toY})) {}

bool ExistingMoveChecker::isMoveEnPassant() const {
    const Piece& pieceTakenByEnPassant = board.getPieceAt({to.x, from.y});
    if (pieceFrom.getType() != PieceType::PAWN)
        return false;
    if (board.isPositionOccupied(to))
        return false;
    if (!board.isPositionOccupied({to.x, from.y}))
        return false;
    if (pieceTakenByEnPassant.getType() != PieceType::PAWN)
        return false;
    if (pieceTakenByEnPassant.getColor() == pieceFrom.getColor())
        return false;
    return true;
}

bool ExistingMoveChecker::isMoveCastling() const {
    PieceType pieceFromType = pieceFrom.getType();
    PieceType pieceToType = pieceTo.getType();
    if (pieceFromType < pieceToType)
        std::swap(pieceFromType, pieceToType);
    if (pieceFromType != PieceType::KING || pieceToType != PieceType::ROOK)
        return false;
    return true;
}

MoveType ExistingMoveChecker::getMoveType(ChessBoard& board, const int fromX, const int fromY, const int toX, const int toY) {
    const ExistingMoveChecker checker(board, fromX, fromY, toX, toY);
    if (checker.isMoveEnPassant())
        return MoveType::EN_PASSANT;
    if (checker.isMoveCastling())
        return MoveType::CASTLING;
    return MoveType::NORMAL;
}