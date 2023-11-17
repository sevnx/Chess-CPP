#include "BoardPositionGetter.hpp"

BoardPositionGetter::BoardPositionGetter(const ChessBoard &board) : board(board) {}

Position BoardPositionGetter::getFirstPiecePosition(const PieceColor color, const PieceType type) const {
    for (int i = 0; i < Position::MAX_POSITION; i++)
        for (int j = 0; j < Position::MAX_POSITION; j++) {
            if (board.isPositionOccupied({i, j}) && board.getPieceAt({i, j}).getType() == type &&
                board.getPieceAt({i, j}).getColor() == color)
                return {i, j};
        }
    return {-1, -1};
}

std::vector<Position> BoardPositionGetter::getPiecesPositions(const PieceColor color) const {
    std::vector<Position> positions;
    for (int i = 0; i < Position::MAX_POSITION; i++)
        for (int j = 0; j < Position::MAX_POSITION; j++)
            if (board.isPositionOccupied({i,j}) && board.getPieceAt({i, j}).getColor() == color)
                positions.emplace_back(i, j);
    return positions;
}

std::vector<Position> BoardPositionGetter::getPiecesPositions(const PieceColor color, const PieceType type) const {
    std::vector<Position> positions;
    for (int i = 0; i < Position::MAX_POSITION; i++)
        for (int j = 0; j < Position::MAX_POSITION; j++) {
            if (auto& piece = board.getPieceAt({i, j}); piece.getType() == type && piece.getColor() == color)
                positions.emplace_back(i, j);
        }
    return positions;
}

void BoardPositionGetter::populatePositionsInBetweenDiagonally(std::vector<Position> &positions,
                                                               const std::pair<Position, Position> &fromTo) {
    int fromX = fromTo.first.x, fromY = fromTo.first.y;
    while (fromX != fromTo.second.x && fromY != fromTo.second.y) {
        if (fromX < fromTo.second.x)
            fromX++, fromY++;
        else
            fromX--, fromY--;
        positions.emplace_back(fromX, fromY);
    }
}

void BoardPositionGetter::populatePositionsInBetweenInStraightLine(std::vector<Position> &positions,
                                                                   const std::pair<Position, Position> &fromTo) {
    int fromX = fromTo.first.x, fromY = fromTo.first.y;
    while (fromX != fromTo.second.x && fromY != fromTo.second.y) {
        if (fromX < fromTo.second.x)
            fromX++;
        else if (fromX > fromTo.second.x)
            fromX--;
        else if (fromY < fromTo.second.y)
            fromY++;
        else
            fromY--;
        positions.emplace_back(fromX, fromY);
    }
}

std::vector<Position>
BoardPositionGetter::getPositionsInBetween(const ExistingMoves moveType, const std::pair<Position, Position>&fromTo) {
    std::vector<Position> positions;
    switch (moveType) {
        case ExistingMoves::STRAIGHT:
            populatePositionsInBetweenInStraightLine(positions, fromTo);
            break;
        case ExistingMoves::DIAGONAL:
            populatePositionsInBetweenDiagonally(positions, fromTo);
            break;
        default:
            break;
    }
    return positions;
}
