#include "MoveLegalityCheck.hpp"

bool MoveLegalityCheck::isMoveLegal(Board &board, int fromX, int fromY, int toX, int toY) {
    MoveLegalityCheck check(board, fromX, fromY, toX, toY);
    return check.isMoveLegal();
}

MoveLegalityCheck::MoveLegalityCheck(Board &board, int fromX, int fromY, int toX, int toY):
board(board), from(fromX, fromY), to(toX, toY),
pieceFrom(board.getPieceAt(from.x, from.y)), pieceTo(board.getPieceAt(to.x, to.y)) {}

bool MoveLegalityCheck::isMoveLegal() {
    if (isMoveLegalForEnPassant() || isMoveLegalForCastling())
        return true;
    if (isMoveLegalForAnyPiece())
        return false;
    switch (pieceFrom.getType()){
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

bool MoveLegalityCheck::isMoveLegalForPawn() {
    return false;
}

bool MoveLegalityCheck::isMoveLegalForKnight() {
    return false;
}

bool MoveLegalityCheck::isMoveLegalForBishop() {
    return false;
}

bool MoveLegalityCheck::isMoveLegalForRook() {
    return false;
}

bool MoveLegalityCheck::isMoveLegalForQueen() {
    return false;
}

bool MoveLegalityCheck::isMoveLegalForKing() {
    return false;
}

bool MoveLegalityCheck::isMoveLegalForAnyPiece() {
    return (pieceFrom.getColor() != pieceTo.getColor()) && !isKingChecked();
}

bool MoveLegalityCheck::isMoveLegalForCastling() {
    PieceType pieceFromType = pieceFrom.getType();
    PieceType pieceToType = pieceTo.getType();
    if (pieceFromType < pieceToType)
        std::swap(pieceFromType, pieceToType);
    return (pieceFromType == PieceType::KING && pieceToType == PieceType::ROOK)
    && !isKingChecked()
    && !areTherePiecesBetween(ExistingMoves::STRAIGHT) && !isKingCheckedAfterMove()
    && !arePositionsAttacked(getPositionsInBetween(ExistingMoves::STRAIGHT), ExistingMoves::STRAIGHT);
}

bool MoveLegalityCheck::isMoveLegalForEnPassant() {
    return false;
}

Position MoveLegalityCheck::getKingPosition(PieceColor color) {
    for (int i = 0; i < Position::MAX_POSITION; i++)
        for (int j = 0; j < Position::MAX_POSITION; j++)
            if (board.getPieceAt(i, j).getType() == PieceType::KING && board.getPieceAt(i, j).getColor() == color)
                return {i, j};
}

bool MoveLegalityCheck::isKingChecked(PieceColor color) {
    Position kingPosition = getKingPosition(color);
    return isPositionAttacked(kingPosition.x, kingPosition.y);
}

bool MoveLegalityCheck::isKingCheckedAfterMove() {
    return false;
}

bool MoveLegalityCheck::isPositionAttacked(int x, int y, PieceColor color) {

}

bool MoveLegalityCheck::areTherePiecesBetween(ExistingMoves moveType) {
    switch (moveType){
        case ExistingMoves::STRAIGHT:
            return areTherePiecesBetweenInStraightLine();
        case ExistingMoves::DIAGONAL:
            return areTherePiecesBetweenDiagonally();
        default:
            return false;
    }
}

bool MoveLegalityCheck::areTherePiecesBetweenDiagonally() {
    int x = from.x, y = from.y;
    while (x != to.x && y != to.y){
        if (board.isPositionOccupied(x, y))
            return true;
        if (x < to.x)
            x++, y++;
        else
            x--, y--;
    }
    return false;
}

bool MoveLegalityCheck::areTherePiecesBetweenInStraightLine() {
    int x = from.x, y = from.y;
    while (x != to.x && y != to.y){
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

bool MoveLegalityCheck::arePositionsAttacked(const std::vector<Position>& positions, ExistingMoves moveType) {
    switch (moveType){
        case ExistingMoves::STRAIGHT:
            return areTherePiecesBetweenInStraightLine();
        default:
            return false;
    }
}

bool MoveLegalityCheck::arePositionsAttackedInDiagonal(const std::vector<Position>& positions) {
    for (auto& position: positions){
        if (isPositionAttacked(position.x, position.y))
            return true;
    }
}

std::vector<Position> MoveLegalityCheck::getPositionsInBetween(ExistingMoves moveType) {
    std::vector<Position> positions;
    switch (moveType){
        case ExistingMoves::STRAIGHT:
            populatePositionsInBetweenInStraightLine(positions);
            break;
        case ExistingMoves::DIAGONAL:
            populatePositionsInBetweenDiagonally(positions);
            break;
        default:
            break;
    }
    return positions;
}

void MoveLegalityCheck::populatePositionsInBetweenDiagonally(std::vector<Position> &positions) const {
int fromX = from.x, fromY = from.y;
    while (fromX != to.x && fromY != to.y){
        if (fromX < to.x)
            fromX++, fromY++;
        else
            fromX--, fromY--;
        positions.emplace_back(fromX, fromY);
    }
}

void MoveLegalityCheck::populatePositionsInBetweenInStraightLine(std::vector<Position> &positions) const {
    int fromX = from.x, fromY = from.y;
    while (fromX != to.x && fromY != to.y){
        if (fromX < to.x)
            fromX++;
        else if (fromX > to.x)
            fromX--;
        else if (fromY < to.y)
            fromY++;
        else
            fromY--;
        positions.emplace_back(fromX, fromY);
    }
}


