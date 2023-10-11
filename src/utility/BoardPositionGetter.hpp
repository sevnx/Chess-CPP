#ifndef CHESS_CPP_BOARDPOSITIONGETTER_HPP
#define CHESS_CPP_BOARDPOSITIONGETTER_HPP

#include "../board/Board.hpp"
#include "MoveTypes.hpp"

class BoardPositionGetter {
private:
    Board &board;

    static void populatePositionsInBetweenDiagonally(std::vector<Position> &positions,
                                                     const std::pair<Position, Position> &fromTo);

    static void populatePositionsInBetweenInStraightLine(std::vector<Position> &positions,
                                                         const std::pair<Position, Position> &fromTo);

public:
    explicit BoardPositionGetter(Board &board);

    Position getFirstPiecePosition(PieceColor color, PieceType type);

    std::vector<Position> getPiecesPositions(PieceColor color, PieceType type);

    std::vector<Position> getPiecesPositions(PieceColor color);

    static std::vector<Position> getPositionsInBetween(ExistingMoves moveType, std::pair<Position, Position> fromTo);
};


#endif //CHESS_CPP_BOARDPOSITIONGETTER_HPP
