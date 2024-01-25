#include "MovePossibilityChecker.hpp"
#include "board/move-validation/MoveDirection.hpp"
#include <cmath>
using std::abs;

bool MovePossibilityChecker::isMovePossible(ChessBoard&board, int fromX, int fromY, const int toX, const int toY) {
    Piece&pieceFrom = board.getPieceAt({fromX, fromY});
    return MovePossibleWithBoardStateChecker::isMoveLegal(board, fromX, fromY, toX, toY)
           && (CorrectMoveForPieceChecker::isMoveCorrect(pieceFrom, fromX, fromY, toX, toY) ||
               ExistingMoveChecker::getMoveType(board, fromX, fromY, toX, toY) == MoveType::CASTLING);
}

// MovePossibleWithBoardStateChecker

MovePossibleWithBoardStateChecker::MovePossibleWithBoardStateChecker(ChessBoard&board, int fromX, int fromY,
                                                                     const int toX, const int toY): board(board),
    from(fromX, fromY), to(toX, toY), pieceFrom(board.getPieceAt({fromX, fromY})),
    moveType(ExistingMoveChecker::getMoveType(board, fromX, fromY, toX, toY)), boardPositionGetter(board) {
}

bool MovePossibleWithBoardStateChecker::isMoveLegal() {
    switch (moveType) {
        case MoveType::EN_PASSANT:
            return isMoveLegalForEnPassant();
        case MoveType::CASTLING:
            return isMoveLegalForCastling();
        case MoveType::NORMAL:
            return isMoveLegalForNormalPieceMove() && isMoveLegalForAnyMove();
    }
    return false;
}

bool MovePossibleWithBoardStateChecker::isMoveLegalForNormalPieceMove() {
    switch (pieceFrom.getType()) {
        case PieceType::PAWN:
            return isMoveLegalForPawn();
        case PieceType::KNIGHT:
            return isMoveLegalForKnight();
        case PieceType::BISHOP_WHITE:
        case PieceType::BISHOP_BLACK:
            return isMoveLegalForBishop();
        case PieceType::ROOK:
            return isMoveLegalForRook();
        case PieceType::QUEEN:
            return isMoveLegalForQueen();
        case PieceType::KING:
            return isMoveLegalForKing();
        case PieceType::NONE:
            break;
    }
    return false;
}


bool MovePossibleWithBoardStateChecker::isMoveLegalForPawn() {
    constexpr unsigned int MAX_PAWN_MOVE_Y = 2, MAX_PAWN_MOVE_X = 1;
    const unsigned int distanceX = abs(from.x - to.x), distanceY = abs(from.y - to.y);
    if (distanceX > MAX_PAWN_MOVE_X)
        return false;
    if (distanceY > MAX_PAWN_MOVE_Y)
        return false;
    if (distanceX == 0 && distanceY == MAX_PAWN_MOVE_Y) {
        return pieceFrom.getMoveCount() == 0
               && !board.isPositionOccupied({to.x, to.y})
               && !areTherePiecesBetween(ExistingMoves::STRAIGHT);
    }
    if (distanceX == 1 && distanceY == 1) {
        return board.isPositionOccupied(to) && pieceFrom.getColor() != board.getPieceAt(to).getColor();
    }
    return !board.isPositionOccupied(to);
}

bool MovePossibleWithBoardStateChecker::isMoveLegalForKnight() {
    return true;
}

bool MovePossibleWithBoardStateChecker::isMoveLegalForBishop() const {
    return !areTherePiecesBetween(ExistingMoves::DIAGONAL);
}

bool MovePossibleWithBoardStateChecker::isMoveLegalForRook() const {
    return !areTherePiecesBetween(ExistingMoves::STRAIGHT);
}

bool MovePossibleWithBoardStateChecker::isMoveLegalForQueen() const {
    if (from.x != to.x && from.y != to.y)
        return !areTherePiecesBetween(ExistingMoves::DIAGONAL);
    return !areTherePiecesBetween(ExistingMoves::STRAIGHT);
}

bool MovePossibleWithBoardStateChecker::isMoveLegalForKing() {
    return true;
}

bool MovePossibleWithBoardStateChecker::isMoveLegalForAnyMove() const {
    if (!board.isPositionOccupied(to))
        return true;
    return pieceFrom.getColor() != board.getPieceAt(to).getColor();
}

bool MovePossibleWithBoardStateChecker::isMoveLegalForCastling() const {
    if (!board.isPositionOccupied(to))
        return false;
    if (pieceFrom.getMoveCount() != 0 || board.getPieceAt(to).getMoveCount() != 0)
        return false;
    return !areTherePiecesBetween(ExistingMoves::STRAIGHT);
}

bool MovePossibleWithBoardStateChecker::isMoveLegalForEnPassant() const {
    const Position enPassantPosition = {to.x, from.y};
    if (!board.isPositionOccupied(enPassantPosition))
        return false;
    const Piece&pieceTakenByEnPassant = board.getPieceAt(enPassantPosition);
    const Position&lastPositionMovedTo = board.getLastPositionMovedTo(pieceTakenByEnPassant.getColor());
    return pieceTakenByEnPassant.getMoveCount() == 1
           && lastPositionMovedTo == enPassantPosition;
}

bool MovePossibleWithBoardStateChecker::areTherePiecesBetween(const ExistingMoves moveType) const {
    switch (moveType) {
        case ExistingMoves::STRAIGHT:
            return areTherePiecesBetweenInStraightLine();
        case ExistingMoves::DIAGONAL:
            return areTherePiecesBetweenDiagonally();
        default:
            break;
    }
    return false;
}

bool MovePossibleWithBoardStateChecker::areTherePiecesBetweenDiagonally() const {
    const int directionX = from.x < to.x ? 1 : -1;
    const int directionY = from.y < to.y ? 1 : -1;
    int x = from.x + directionX;
    int y = from.y + directionY;

    while (x != to.x && y != to.y) {
        if (!Position::isPositionValid(x, y))
            return false;
        if (board.isPositionOccupied({x, y}))
            return true;
        x += directionX;
        y += directionY;
    }
    return false;
}


bool MovePossibleWithBoardStateChecker::areTherePiecesBetweenInStraightLine() const {
    const int dx = to.x - from.x ? (to.x - from.x) / abs(to.x - from.x) : 0;
    const int dy = to.y - from.y ? (to.y - from.y) / abs(to.y - from.y) : 0;
    for (int x = from.x + dx, y = from.y + dy; x != to.x || y != to.y; x += dx, y += dy) {
        if (board.isPositionOccupied({x, y}))
            return true;
    }
    return false;
}


bool MovePossibleWithBoardStateChecker::isMoveLegal(ChessBoard&board, const int fromX, const int fromY, const int toX,
                                                    int toY) {
    MovePossibleWithBoardStateChecker check(board, fromX, fromY, toX, toY);
    return check.isMoveLegal();
}

// CorrectMoveForPieceChecker

CorrectMoveForPieceChecker::CorrectMoveForPieceChecker(Piece&piece, const int fromX, const int fromY, const int toX,
                                                       const int toY) : pieceFrom(piece), from(fromX, fromY),
                                                                        to(toX, toY) {
}

bool CorrectMoveForPieceChecker::isMoveNull() const {
    return from.x == to.x && from.y == to.y;
}

bool CorrectMoveForPieceChecker::isMoveInStraightLine() const {
    return from.x == to.x || from.y == to.y;
}

bool CorrectMoveForPieceChecker::isMoveInDiagonalLine() const {
    return std::abs(from.x - to.x) == std::abs(from.y - to.y);
}

bool CorrectMoveForPieceChecker::isMoveInForLShape() const {
    const auto [fst, snd] = std::make_pair(abs(from.x - to.x), abs(from.y - to.y));
    constexpr unsigned int firstDirectionDistance = 2;
    constexpr unsigned int secondDirectionDistance = 1;

    return (fst == firstDirectionDistance && snd == secondDirectionDistance) ||
           (fst == secondDirectionDistance && snd == firstDirectionDistance);
}

bool CorrectMoveForPieceChecker::isMoveInOneByOneBox() const {
    constexpr unsigned int maxDistance = 1;
    return std::abs(from.x - to.x) <= maxDistance && std::abs(from.y - to.y) <= maxDistance;
}

bool CorrectMoveForPieceChecker::isMoveForwardsOrSidewaysByOneCase() const {
    constexpr unsigned int maxDistance = 1;
    const auto direction = getMoveDirection(from.y, to.y);
    const int distance = std::abs(from.y - to.y);
    switch (pieceFrom.getColor()) {
        case PieceColor::WHITE:
            return isMoveInOneByOneBox() && distance == maxDistance && direction == MoveDirection::FROM_WHITE_TO_BLACK;
        case PieceColor::BLACK:
            return isMoveInOneByOneBox() && distance == maxDistance && direction == MoveDirection::FROM_BLACK_TO_WHITE;
    }
    return false;
}

bool CorrectMoveForPieceChecker::isMoveForwardsByAtMostTwoCases() const {
    constexpr unsigned int maxDistance = 2;
    const int distance = std::abs(from.y - to.y);
    const auto direction = getMoveDirection(from.y, to.y);
    switch (pieceFrom.getColor()) {
        case PieceColor::WHITE:
            return (isMoveInOneByOneBox() || distance <= maxDistance) && direction ==
                   MoveDirection::FROM_WHITE_TO_BLACK;
        case PieceColor::BLACK:
            return (isMoveInOneByOneBox() || distance <= maxDistance) && direction ==
                   MoveDirection::FROM_BLACK_TO_WHITE;
    }
    return false;
}

bool CorrectMoveForPieceChecker::isMoveCorrectForPiece() const {
    switch (pieceFrom.getType()) {
        case PieceType::PAWN:
            return isMoveCorrectForPawn();
        case PieceType::ROOK:
            return isMoveCorrectForRook();
        case PieceType::KNIGHT:
            return isMoveCorrectForKnight();
        case PieceType::BISHOP_BLACK:
        case PieceType::BISHOP_WHITE:
            return isMoveCorrectForBishop();
        case PieceType::QUEEN:
            return isMoveCorrectForQueen();
        case PieceType::KING:
            return isMoveCorrectForKing();
        case PieceType::NONE:
            break;
    }
    return false;
}


bool CorrectMoveForPieceChecker::isMoveCorrectForPawn() const {
    if (pieceFrom.isFirstMove())
        return isMoveForwardsByAtMostTwoCases() || isMoveForwardsOrSidewaysByOneCase();
    return isMoveForwardsOrSidewaysByOneCase();
}

bool CorrectMoveForPieceChecker::isMoveCorrectForRook() const {
    return isMoveInStraightLine();
}

bool CorrectMoveForPieceChecker::isMoveCorrectForKnight() const {
    return isMoveInForLShape();
}

bool CorrectMoveForPieceChecker::isMoveCorrectForBishop() const {
    return isMoveInDiagonalLine();
}

bool CorrectMoveForPieceChecker::isMoveCorrectForQueen() const {
    return isMoveInStraightLine() || isMoveInDiagonalLine();
}

bool CorrectMoveForPieceChecker::isMoveCorrectForKing() const {
    return isMoveInOneByOneBox();
}

bool CorrectMoveForPieceChecker::isMoveCorrect(Piece&piece, const int fromX, const int fromY, const int toX,
                                               const int toY) {
    const CorrectMoveForPieceChecker moveValidator(piece, fromX, fromY, toX, toY);
    return !moveValidator.isMoveNull() && Position::isPositionValid(toX, toY) && moveValidator.isMoveCorrectForPiece();
}
