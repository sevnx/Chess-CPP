#include "MovePossibilityChecker.hpp"

bool MovePossibilityChecker::isMovePossible(ChessBoard &board, int fromX, int fromY, const int toX, const int toY) {
    Piece &pieceFrom = board.getPieceAt({fromX, fromY});
    return MovePossibleWithBoardStateChecker::isMoveLegal(board, fromX, fromY, toX, toY)
    && CorrectMoveForPieceChecker::isMoveCorrect(pieceFrom, fromX, fromY, toX, toY);
}

// MovePossibleWithBoardStateChecker
#include <iostream>

MovePossibleWithBoardStateChecker::MovePossibleWithBoardStateChecker(ChessBoard &board, int fromX, int fromY, const int toX, const int toY):
    board(board), pieceFrom(board.getPieceAt({fromX, fromY})), from(fromX, fromY), to(toX, toY),
    boardPositionGetter(board), moveType(ExistingMoveChecker::getMoveType(board, fromX, fromY, toX, toY)) {
}


bool MovePossibleWithBoardStateChecker::isMoveLegal() {
    if (!isMoveLegalForAnyMove())
        return false;
    switch (moveType) {
        case MoveType::EN_PASSANT:
            return isMoveLegalForEnPassant();
        case MoveType::CASTLING:
            return isMoveLegalForCastling();
        case MoveType::NORMAL:
            return isMoveLegalForNormalPieceMove();
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
    if (distanceX == 0 && distanceY == 1) {
        return !board.isPositionOccupied(to);
    }
    return false;
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
    return !areTherePiecesBetween(ExistingMoves::STRAIGHT) || !areTherePiecesBetween(ExistingMoves::DIAGONAL);
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
    if (areTherePiecesBetween(ExistingMoves::STRAIGHT))
        return false;
    return true;
}

bool MovePossibleWithBoardStateChecker::isMoveLegalForEnPassant() const {
    const Position enPassantPosition = {to.x, from.y};
    if (!board.isPositionOccupied(enPassantPosition))
        return false;
    const Piece &pieceTakenByEnPassant = board.getPieceAt(enPassantPosition);
    return pieceTakenByEnPassant.getMoveCount() == 1
           && board.getLastPositionMovedTo(pieceTakenByEnPassant.getColor()) == Position(to.x, from.y);
}

bool MovePossibleWithBoardStateChecker::areTherePiecesBetween(const ExistingMoves moveType) const {
    switch (moveType) {
        case ExistingMoves::STRAIGHT:
            return areTherePiecesBetweenInStraightLine();
        case ExistingMoves::DIAGONAL:
            return areTherePiecesBetweenDiagonally();
        default:
            return false;
    }
}

bool MovePossibleWithBoardStateChecker::areTherePiecesBetweenDiagonally() const {
    int x = from.x + 1, y = from.y + 1;
    const int xDirection = to.y > from.y ? 1 : -1;
    const int yDirection = to.x > from.x ? 1 : -1;
    while (x != to.x && y != to.y) {
        if (!Position::isPositionValid(x, y))
            return false;
        if (board.isPositionOccupied({x, y}))
            return true;
        x += xDirection;
        y += yDirection;
    }
    return false;
}

bool MovePossibleWithBoardStateChecker::areTherePiecesBetweenInStraightLine() const {
    int x = from.x, y = from.y;
    while (x != to.x && y != to.y) {
        if (board.isPositionOccupied({x, y}))
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

bool MovePossibleWithBoardStateChecker::isMoveLegal(ChessBoard &board, const int fromX, const int fromY, const int toX, int toY) {
    MovePossibleWithBoardStateChecker check(board, fromX, fromY, toX, toY);
    return check.isMoveLegal();
}

// CorrectMoveForPieceChecker

CorrectMoveForPieceChecker::CorrectMoveForPieceChecker(Piece &piece, const int fromX, const int fromY, const int toX, const int toY) :
        pieceFrom(piece), from(fromX, fromY), to(toX, toY) {}

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
    const int distanceX = std::abs(from.x - to.x);
    const int distanceY = pieceFrom.getColor() == PieceColor::WHITE ? from.y - to.y : to.y - from.y;
    return distanceY == maxDistance && distanceX <= maxDistance;
}

bool CorrectMoveForPieceChecker::isMoveForwardsByAtMostTwoCases() const {
    constexpr unsigned int maxDistance = 2;
    const int distanceX = std::abs(from.x - to.x);
    const int distanceY = pieceFrom.getColor() == PieceColor::WHITE ? from.y - to.y : to.y - from.y;
    return distanceX == 0 && distanceY <= maxDistance && distanceY > 0;
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
    if (isMoveForwardsOrSidewaysByOneCase())
        return true;
    if (pieceFrom.isFirstMove())
        return isMoveForwardsByAtMostTwoCases();
    return false;
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

bool CorrectMoveForPieceChecker::isMoveCorrect(Piece &piece, const int fromX, const int fromY, const int toX, const int toY) {
    const CorrectMoveForPieceChecker moveValidator(piece, fromX, fromY, toX, toY);
    const bool isMoveNotNull = !moveValidator.isMoveNull();
    const bool isPositionValid = Position::isPositionValid(toX, toY);
    return isMoveNotNull && isPositionValid && moveValidator.isMoveCorrectForPiece();
}

