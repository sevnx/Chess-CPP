#include "MoveValidityCheck.hpp"

MoveValidityCheck::MoveValidityCheck(Piece& piece, int fromX, int fromY, int toX, int toY) :
        pieceFrom(piece), from(fromX, fromY), to(toX, toY) {}

bool MoveValidityCheck::isMoveNull() const {
    return from.x == to.x && from.y == to.y;
}

bool MoveValidityCheck::isMoveInStraightLine() const {
    return from.x == to.x || from.y == to.y;
}

bool MoveValidityCheck::isMoveInDiagonalLine() const {
    return std::abs(from.x - to.x) == std::abs(from.y - to.y);
}

bool MoveValidityCheck::isMoveInForLShape() const {
    std::pair<int,int> move = std::make_pair(abs(from.x - to.x),abs(from.y - to.y));
    const unsigned int firstDirectionDistance = 2;
    const unsigned int secondDirectionDistance = 1;

    return (move.first == firstDirectionDistance && move.second == secondDirectionDistance) ||
           (move.first == secondDirectionDistance && move.second == firstDirectionDistance);
}

bool MoveValidityCheck::isMoveInOneByOneBox() const {
    const unsigned int maxDistance = 1;
    return std::abs(from.x - to.x) <= maxDistance && std::abs(from.y - to.y) <= maxDistance;
}

bool MoveValidityCheck::isMoveForwardsOrSidewaysByOneCase() const {
    const unsigned int maxDistance = 1;
    switch (pieceFrom.getColor()) {
        case PieceColor::WHITE:
            return isMoveInOneByOneBox() && to.y - from.y == maxDistance;
        case PieceColor::BLACK:
            return isMoveInOneByOneBox() && from.y - to.y == maxDistance;
    }
    return false;
}

bool MoveValidityCheck::isMoveForwardsByAtMostTwoCases() const {
    const unsigned int maxDistance = 2;
    switch (pieceFrom.getColor()) {
        case PieceColor::WHITE:
            return isMoveInOneByOneBox() && to.y - from.y <= maxDistance;
        case PieceColor::BLACK:
            return isMoveInOneByOneBox() && from.y - to.y <= maxDistance;
    }
    return false;
}

bool MoveValidityCheck::isMoveValidForPiece() {
    switch (pieceFrom.getType()) {
        case PieceType::PAWN:
            return isMoveValidForPawn(pieceFrom.isFirstMove());
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


bool MoveValidityCheck::isMoveValidForPawn(bool firstMove) {
    if (firstMove)
        return isMoveForwardsByAtMostTwoCases() || isMoveForwardsOrSidewaysByOneCase();
    else
        return isMoveForwardsOrSidewaysByOneCase();
}

bool MoveValidityCheck::isMoveValidForRook() {
    return isMoveInStraightLine();
}

bool MoveValidityCheck::isMoveValidForKnight() {
    return isMoveInForLShape();
}

bool MoveValidityCheck::isMoveValidForBishop() {
    return isMoveInDiagonalLine();
}

bool MoveValidityCheck::isMoveValidForQueen() {
    return isMoveInStraightLine() || isMoveInDiagonalLine();
}

bool MoveValidityCheck::isMoveValidForKing() {
    return isMoveInOneByOneBox();
}

bool MoveValidityCheck::isMoveValid(Piece &piece, int fromX, int fromY, int toX, int toY) {
    MoveValidityCheck moveValidator(piece, fromX, fromY, toX, toY);
    bool isMoveNotNull = !moveValidator.isMoveNull();
    bool isPositionValid = Position::isPositionValid(toX, toY);
    return isMoveNotNull && isPositionValid && moveValidator.isMoveValidForPiece();
}