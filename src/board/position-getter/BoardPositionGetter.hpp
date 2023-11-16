#ifndef CHESS_CPP_BOARDPOSITIONGETTER_HPP
#define CHESS_CPP_BOARDPOSITIONGETTER_HPP

#include "board/ChessBoard.hpp"
#include "board/Position.hpp"
#include "board/move-validation/MoveTypes.hpp"

class BoardPositionGetter {
    const ChessBoard &board;

    static void populatePositionsInBetweenDiagonally(std::vector<Position> &positions,
                                                     const std::pair<Position, Position> &fromTo);

    static void populatePositionsInBetweenInStraightLine(std::vector<Position> &positions,
                                                         const std::pair<Position, Position> &fromTo);

public:
    explicit BoardPositionGetter(const ChessBoard &board);

    [[nodiscard]] Position getFirstPiecePosition(PieceColor color, PieceType type) const;

    [[nodiscard]] std::vector<Position> getPiecesPositions(PieceColor color, PieceType type) const;

    [[nodiscard]] std::vector<Position> getPiecesPositions(PieceColor color) const;

    static std::vector<Position> getPositionsInBetween(ExistingMoves moveType, const std::pair<Position, Position>&fromTo);
};

#endif //CHESS_CPP_BOARDPOSITIONGETTER_HPP
