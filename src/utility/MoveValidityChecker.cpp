#include "MoveValidityChecker.hpp"

MoveValidityChecker::MoveValidityChecker(Piece &piece, int fromX, int fromY, int toX, int toY) :
        pieceFrom(piece), from(fromX, fromY), to(toX, toY) {}

bool MoveValidityChecker::isMoveNull() const {
    return from.x == to.x && from.y == to.y;
}

bool MoveValidityChecker::isMoveInStraightLine() const {
    return from.x == to.x || from.y == to.y;
}

bool MoveValidityChecker::isMoveInDiagonalLine() const {
    return std::abs(from.x - to.x) == std::abs(from.y - to.y);
}

bool MoveValidityChecker::isMoveInForLShape() const {
    std::pair<int, int> move = std::make_pair(abs(from.x - to.x), abs(from.y - to.y));
    const unsigned int firstDirectionDistance = 2;
    const unsigned int secondDirectionDistance = 1;

    return (move.first == firstDirectionDistance && move.second == secondDirectionDistance) ||
           (move.first == secondDirectionDistance && move.second == firstDirectionDistance);
}

bool MoveValidityChecker::isMoveInOneByOneBox() const {
    const unsigned int maxDistance = 1;
    return std::abs(from.x - to.x) <= maxDistance && std::abs(from.y - to.y) <= maxDistance;
}

bool MoveValidityChecker::isMoveForwardsOrSidewaysByOneCase() const {
    const unsigned int maxDistance = 1;
    switch (pieceFrom.getColor()) {
        case PieceColor::WHITE:
            return isMoveInOneByOneBox() && to.y - from.y == maxDistance;
        case PieceColor::BLACK:
            return isMoveInOneByOneBox() && from.y - to.y == maxDistance;
    }
    return false;
}

bool MoveValidityChecker::isMoveForwardsByAtMostTwoCases() const {
    const unsigned int maxDistance = 2;
    switch (pieceFrom.getColor()) {
        case PieceColor::WHITE:
            return isMoveInOneByOneBox() && to.y - from.y <= maxDistance;
        case PieceColor::BLACK:
            return isMoveInOneByOneBox() && from.y - to.y <= maxDistance;
    }
    return false;
}

bool MoveValidityChecker::isMoveValidForPiece() {
    switch (pieceFrom.getType()) {
        case PieceType::PAWN:
            return isMoveValidForPawn();
        case PieceType::ROOK:
            return isMoveValidForRook();
        case PieceType::KNIGHT:
            return isMoveValidForKnight();
        case PieceType::BISHOP:
            return isMoveValidForBishop();
        case PieceType::QUEEN:
            return isMoveValidForQueen();
        case PieceType::KING:
            return isMoveValidForKing();
    }
    return false;
}


bool MoveValidityChecker::isMoveValidForPawn() {
    if (pieceFrom.isFirstMove())
        return isMoveForwardsByAtMostTwoCases() || isMoveForwardsOrSidewaysByOneCase();
    else
        return isMoveForwardsOrSidewaysByOneCase();
}

bool MoveValidityChecker::isMoveValidForRook() {
    return isMoveInStraightLine();
}

bool MoveValidityChecker::isMoveValidForKnight() {
    return isMoveInForLShape();
}

bool MoveValidityChecker::isMoveValidForBishop() {
    return isMoveInDiagonalLine();
}

bool MoveValidityChecker::isMoveValidForQueen() {
    return isMoveInStraightLine() || isMoveInDiagonalLine();
}

bool MoveValidityChecker::isMoveValidForKing() {
    return isMoveInOneByOneBox();
}

bool MoveValidityChecker::isMoveValid(Piece &piece, int fromX, int fromY, int toX, int toY) {
    MoveValidityChecker moveValidator(piece, fromX, fromY, toX, toY);
    bool isMoveNotNull = !moveValidator.isMoveNull();
    bool isPositionValid = Position::isPositionValid(toX, toY);
    return isMoveNotNull && isPositionValid && moveValidator.isMoveValidForPiece();
}