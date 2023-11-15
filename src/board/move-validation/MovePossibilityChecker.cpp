#include "MovePossibilityChecker.hpp"



// MoveValidityChecker

MoveValidityChecker::MoveValidityChecker(Piece &piece, const int fromX, const int fromY, const int toX, const int toY) :
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
    const auto [fst, snd] = std::make_pair(abs(from.x - to.x), abs(from.y - to.y));
    constexpr unsigned int firstDirectionDistance = 2;
    constexpr unsigned int secondDirectionDistance = 1;

    return (fst == firstDirectionDistance && snd == secondDirectionDistance) ||
           (fst == secondDirectionDistance && snd == firstDirectionDistance);
}

bool MoveValidityChecker::isMoveInOneByOneBox() const {
    constexpr unsigned int maxDistance = 1;
    return std::abs(from.x - to.x) <= maxDistance && std::abs(from.y - to.y) <= maxDistance;
}

bool MoveValidityChecker::isMoveForwardsOrSidewaysByOneCase() const {
    constexpr unsigned int maxDistance = 1;
    switch (pieceFrom.getColor()) {
        case PieceColor::WHITE:
            return isMoveInOneByOneBox() && to.y - from.y == maxDistance;
        case PieceColor::BLACK:
            return isMoveInOneByOneBox() && from.y - to.y == maxDistance;
    }
    return false;
}

bool MoveValidityChecker::isMoveForwardsByAtMostTwoCases() const {
    constexpr unsigned int maxDistance = 2;
    switch (pieceFrom.getColor()) {
        case PieceColor::WHITE:
            return isMoveInOneByOneBox() && to.y - from.y <= maxDistance;
        case PieceColor::BLACK:
            return isMoveInOneByOneBox() && from.y - to.y <= maxDistance;
    }
    return false;
}

bool MoveValidityChecker::isMoveValidForPiece() const {
    switch (pieceFrom.getType()) {
        case PieceType::PAWN:
            return isMoveValidForPawn();
        case PieceType::ROOK:
            return isMoveValidForRook();
        case PieceType::KNIGHT:
            return isMoveValidForKnight();
        case PieceType::BISHOP_BLACK:
        case PieceType::BISHOP_WHITE:
            return isMoveValidForBishop();
        case PieceType::QUEEN:
            return isMoveValidForQueen();
        case PieceType::KING:
            return isMoveValidForKing();
        case PieceType::NONE:
            break;
    }
    return false;
}


bool MoveValidityChecker::isMoveValidForPawn() const {
    if (pieceFrom.isFirstMove())
        return isMoveForwardsByAtMostTwoCases() || isMoveForwardsOrSidewaysByOneCase();
    return isMoveForwardsOrSidewaysByOneCase();
}

bool MoveValidityChecker::isMoveValidForRook() const {
    return isMoveInStraightLine();
}

bool MoveValidityChecker::isMoveValidForKnight() const {
    return isMoveInForLShape();
}

bool MoveValidityChecker::isMoveValidForBishop() const {
    return isMoveInDiagonalLine();
}

bool MoveValidityChecker::isMoveValidForQueen() const {
    return isMoveInStraightLine() || isMoveInDiagonalLine();
}

bool MoveValidityChecker::isMoveValidForKing() const {
    return isMoveInOneByOneBox();
}

bool MoveValidityChecker::isMoveValid(Piece &piece, const int fromX, const int fromY, const int toX, const int toY) {
    const MoveValidityChecker moveValidator(piece, fromX, fromY, toX, toY);
    const bool isMoveNotNull = !moveValidator.isMoveNull();
    const bool isPositionValid = Position::isPositionValid(toX, toY);
    return isMoveNotNull && isPositionValid && moveValidator.isMoveValidForPiece();
}
