#ifndef MOVEPOSSIBILITYCHECKER_HPP
#define MOVEPOSSIBILITYCHECKER_HPP

#include "board/ChessBoard.hpp"

/**
 * \brief Checks if a move is possible
 * Possbility != legality
 * Possibility does not take into account check, checkmate, stalemate
 * For legality, see
 */
class MovePossibilityChecker {

};

/**
 * \brief
 */
class MoveValidityChecker {
    Piece &pieceFrom;
    Position from;
    Position to;

    MoveValidityChecker(Piece &piece, int fromX, int fromY, int toX, int toY);

    [[nodiscard]] bool isMoveNull() const;

    [[nodiscard]] bool isMoveInStraightLine() const;

    [[nodiscard]] bool isMoveInDiagonalLine() const;

    [[nodiscard]] bool isMoveInForLShape() const;

    [[nodiscard]] bool isMoveInOneByOneBox() const;

    [[nodiscard]] bool isMoveForwardsOrSidewaysByOneCase() const;

    [[nodiscard]] bool isMoveForwardsByAtMostTwoCases() const;

    [[nodiscard]] bool isMoveValidForPawn() const;

    [[nodiscard]] bool isMoveValidForRook() const;

    [[nodiscard]] bool isMoveValidForKnight() const;

    [[nodiscard]] bool isMoveValidForBishop() const;

    [[nodiscard]] bool isMoveValidForQueen() const;

    [[nodiscard]] bool isMoveValidForKing() const;

    [[nodiscard]] bool isMoveValidForPiece() const;

    ~MoveValidityChecker() = default;

public:
    static bool isMoveValid(Piece &piece, int fromX, int fromY, int toX, int toY);
};



#endif //MOVEPOSSIBILITYCHECKER_HPP
