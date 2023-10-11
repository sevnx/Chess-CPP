#include "MoveLegalityChecker.hpp"

bool MoveLegalityChecker::isMoveLegal(Board &board, int fromX, int fromY, int toX, int toY) {
    MoveLegalityChecker check(board, fromX, fromY, toX, toY);
    return check.isMoveLegal();
}

MoveLegalityChecker::MoveLegalityChecker(Board &board, int fromX, int fromY, int toX, int toY) :
        board(board), from(fromX, fromY), to(toX, toY),
        pieceFrom(board.getPieceAt(from.x, from.y)), pieceTo(board.getPieceAt(to.x, to.y)),
        boardPositionGetter(board), positionAttackChecker(board, pieceFrom.getColor()) {}

bool MoveLegalityChecker::isMoveLegal() {
    if (isMoveLegalForEnPassant() || isMoveLegalForCastling())
        return true;
    if (isMoveLegalForAnyPiece())
        return false;
    switch (pieceFrom.getType()) {
        case PieceType::PAWN:
            return isMoveLegalForPawn();
        case PieceType::KNIGHT:
            return isMoveLegalForKnight();
        case PieceType::BISHOP:
            return isMoveLegalForBishop();
        case PieceType::ROOK:
            return isMoveLegalForRook();
        case PieceType::QUEEN:
            return isMoveLegalForQueen();
        case PieceType::KING:
            return isMoveLegalForKing();
    }
    return false;
}

bool MoveLegalityChecker::isMoveLegalForPawn() {
    const unsigned int MAX_PAWN_MOVE_Y = 2, MAX_PAWN_MOVE_X = 1;
    const unsigned int distanceX = abs(from.x - to.x), distanceY = abs(from.y - to.y);
    if (distanceX > MAX_PAWN_MOVE_X)
        return false;
    if (distanceY > MAX_PAWN_MOVE_Y)
        return false;
    if (distanceX == 0 && distanceY == MAX_PAWN_MOVE_Y) {
        return pieceFrom.getMoveCount() == 0
               && !board.isPositionOccupied(to.x, to.y)
               && !areTherePiecesBetween(ExistingMoves::STRAIGHT);
    }
    if (distanceX == 1 && distanceY == 1) {
        return board.isPositionOccupied(to.x, to.y)
               && pieceFrom.getColor() != pieceTo.getColor();
    }
    return false;
}

bool MoveLegalityChecker::isMoveLegalForKnight() {
    return true;
}

bool MoveLegalityChecker::isMoveLegalForBishop() {
    return areTherePiecesBetween(ExistingMoves::DIAGONAL);
}

bool MoveLegalityChecker::isMoveLegalForRook() {
    return false;
}

bool MoveLegalityChecker::isMoveLegalForQueen() {
    return false;
}

bool MoveLegalityChecker::isMoveLegalForKing() {
    return true;
}

bool MoveLegalityChecker::isMoveLegalForAnyPiece() {
    return (pieceFrom.getColor() != pieceTo.getColor()) &&
           positionAttackChecker.isPositionAttacked(
                   boardPositionGetter.getFirstPiecePosition(pieceFrom.getColor(), PieceType::KING));
}

bool MoveLegalityChecker::isMoveLegalForCastling() {
    PieceType pieceFromType = pieceFrom.getType();
    PieceType pieceToType = pieceTo.getType();
    if (pieceFromType < pieceToType)
        std::swap(pieceFromType, pieceToType);
    return true;
}

bool MoveLegalityChecker::isMoveLegalForEnPassant() {
    Piece &pieceTakenByEnPassant = board.getPieceAt(to.x, from.y);
    return pieceFrom.getType() == PieceType::PAWN
           && !board.isPositionOccupied(to.x, to.y)
           && board.isPositionOccupied(to.x, from.y)
           && pieceTakenByEnPassant.getType() == PieceType::PAWN
           && pieceTakenByEnPassant.getColor() != pieceFrom.getColor()
           && pieceTakenByEnPassant.getMoveCount() == 1;
    // TODO: Check if the piece has just moved
}

bool MoveLegalityChecker::areTherePiecesBetween(ExistingMoves moveType) {
    switch (moveType) {
        case ExistingMoves::STRAIGHT:
            return areTherePiecesBetweenInStraightLine();
        case ExistingMoves::DIAGONAL:
            return areTherePiecesBetweenDiagonally();
        default:
            return false;
    }
}

bool MoveLegalityChecker::areTherePiecesBetweenDiagonally() {
    int x = from.x, y = from.y;
    while (x != to.x && y != to.y) {
        if (board.isPositionOccupied(x, y))
            return true;
        if (x < to.x)
            x++, y++;
        else
            x--, y--;
    }
    return false;
}

bool MoveLegalityChecker::areTherePiecesBetweenInStraightLine() {
    int x = from.x, y = from.y;
    while (x != to.x && y != to.y) {
        if (board.isPositionOccupied(x, y))
            return true;
        if (x < to.x)
            x++;
        else if (x > to.x)
            x--;
        else if (y < to.y)
            y++;
        else
            y--;
    }
    return false;
}

