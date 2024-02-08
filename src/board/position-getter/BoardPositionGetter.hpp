#ifndef CHESS_CPP_BOARDPOSITIONGETTER_HPP
#define CHESS_CPP_BOARDPOSITIONGETTER_HPP

#include <optional>

#include "board/ChessBoard.hpp"
#include "board/Position.hpp"
#include "board/move-validation/MoveTypes.hpp"

class BoardPositionGetter {
    const ChessBoard &board;

    static void populatePositionsInBetween(std::vector<Position> &positions,
                                           const std::pair<Position, Position> &fromTo,
                                           const std::pair<int, int> &direction);

public:
    explicit BoardPositionGetter(const ChessBoard &board);

    [[nodiscard]] std::optional<Position> getFirstPiecePosition(PieceColor color, PieceType type) const;

    [[nodiscard]] std::vector<Position> getPiecesPositions(PieceColor color, PieceType type) const;

    [[nodiscard]] std::vector<Position> getPiecesPositions(PieceColor color) const;

    static std::vector<Position> getPositionsInBetween(ExistingMoves moveType, const std::pair<Position, Position>&fromTo);
};

#endif //CHESS_CPP_BOARDPOSITIONGETTER_HPP
