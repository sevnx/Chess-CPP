#include "MoveValidator.hpp"

MoveValidator::MoveValidator(int fromX, int fromY, int toX, int toY, Color color)
    : fromX(fromX), fromY(fromY), toX(toX), toY(toY), color(color) {}

bool MoveValidator::isMoveNull() const {
    return fromX == toX && fromY == toY;
}

bool MoveValidator::isMoveInStraightLine() const {
    return fromX == toX || fromY == toY;
}

bool MoveValidator::isMoveInDiagonalLine() const {
    return std::abs(fromX - toX) == std::abs(fromY - toY);
}

bool MoveValidator::isMoveInForLShape() const {
    std::pair<int,int> move = std::make_pair(abs(fromX - toX),abs(fromY - toY));
    const unsigned int firstDirectionDistance = 2;
    const unsigned int secondDirectionDistance = 1;

    return (move.first == firstDirectionDistance && move.second == secondDirectionDistance) ||
           (move.first == secondDirectionDistance && move.second == firstDirectionDistance);
}

bool MoveValidator::isMoveInOneByOneBox() const {
    const unsigned int maxDistance = 1;
    return std::abs(fromX - toX) <= maxDistance && std::abs(fromY - toY) <= maxDistance;
}

bool MoveValidator::isMoveForwardsOrSidewaysByOneCase() const {
    const unsigned int maxDistance = 1;
    switch (color) {
        case Color::WHITE:
            return isMoveInOneByOneBox() && toY - fromY == maxDistance;
        case Color::BLACK:
            return isMoveInOneByOneBox() && fromY - toY == maxDistance;
    }
    return false;
}

bool MoveValidator::isMoveForwardsByAtMostTwoCases() const {
    const unsigned int maxDistance = 2;
    switch (color) {
        case Color::WHITE:
            return isMoveInOneByOneBox() && toY - fromY <= maxDistance;
        case Color::BLACK:
            return isMoveInOneByOneBox() && fromY - toY <= maxDistance;
    }
    return false;
}

bool MoveValidator::isMoveValid(int fromX, int fromY, int toX, int toY, Color color, PieceType type, bool firstMove) {
    MoveValidator moveValidator(fromX, fromY, toX, toY, color);
    bool isMoveNotNull = !moveValidator.isMoveNull();
    bool isPositionValid = Position::isPositionValid(toX, toY);
    switch (type) {
        case PieceType::PAWN:
            return isMoveNotNull && isPositionValid && moveValidator.isMoveValidForPawn(firstMove);
        case PieceType::ROOK:
            return isMoveNotNull && isPositionValid && moveValidator.isMoveValidForRook();
        case PieceType::KNIGHT:
            return isMoveNotNull && isPositionValid && moveValidator.isMoveValidForKnight();
        case PieceType::BISHOP:
            return isMoveNotNull && isPositionValid && moveValidator.isMoveValidForBishop();
        case PieceType::QUEEN:
            return isMoveNotNull && isPositionValid && moveValidator.isMoveValidForQueen();
        case PieceType::KING:
            return isMoveNotNull && isPositionValid && moveValidator.isMoveValidForKing();
    }
    return false;
}

bool MoveValidator::isMoveValidForPawn(bool firstMove) {
    if (firstMove)
        return isMoveForwardsByAtMostTwoCases() || isMoveForwardsOrSidewaysByOneCase();
    else
        return isMoveForwardsOrSidewaysByOneCase();
}

bool MoveValidator::isMoveValidForRook() {
    return isMoveInStraightLine();
}

bool MoveValidator::isMoveValidForKnight() {
    return isMoveInForLShape();
}

bool MoveValidator::isMoveValidForBishop() {
    return isMoveInDiagonalLine();
}

bool MoveValidator::isMoveValidForQueen() {
    return isMoveInStraightLine() || isMoveInDiagonalLine();
}

bool MoveValidator::isMoveValidForKing() {
    return isMoveInOneByOneBox();
}

