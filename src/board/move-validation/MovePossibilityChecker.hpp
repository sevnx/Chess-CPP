#ifndef MOVEPOSSIBILITYCHECKER_HPP
#define MOVEPOSSIBILITYCHECKER_HPP

#include "board/ChessBoard.hpp"
#include "position-getter/BoardPositionGetter.hpp"

/**
 * \brief Checks if a move is possible
 * Possibility != legality
 * Possibility does not take into account check, checkmate, stalemate
 * For legality, see
 */
class MovePossibilityChecker {
public:
    static bool isMovePossible(const ChessBoard &board, int fromX, int fromY, int toX, int toY);
};

/**
 * \brief Checks if a move is possible for a piece with the current board state
 * Does not take into account move correctness
 * Basically checks if there is no piece on the way, and if the piece can move to the destination etc.
 */
class MovePossibleWithBoardStateChecker {
    const ChessBoard &board;
    Position from;
    Position to;
    Piece &pieceFrom;
    MoveType moveType;
    BoardPositionGetter boardPositionGetter;

    MovePossibleWithBoardStateChecker(const ChessBoard &board, int fromX, int fromY, int toX, int toY);

    bool isMoveLegal();

    bool isMoveLegalForNormalPieceMove();

    [[nodiscard]] bool isMoveLegalForAnyMove() const;

    bool isMoveLegalForPawn();

    static bool isMoveLegalForKnight();

    [[nodiscard]] bool isMoveLegalForBishop() const;

    [[nodiscard]] bool isMoveLegalForRook() const;

    [[nodiscard]] bool isMoveLegalForQueen() const;

    static bool isMoveLegalForKing();

    // Special moves accounted before everything else
    [[nodiscard]] bool isMoveLegalForCastling() const;

    [[nodiscard]] bool isMoveLegalForEnPassant() const;

    // Pieces between
    [[nodiscard]] bool areTherePiecesBetween(ExistingMoves moveType) const;

    [[nodiscard]] bool areTherePiecesBetweenDiagonally() const;

    [[nodiscard]] bool areTherePiecesBetweenInStraightLine() const;

public:
    static bool isMoveLegal(const ChessBoard &board, int fromX, int fromY, int toX, int toY);
};

/**
 * \brief Checks if a move is correct for a piece
 * Correct != legality
 * Correctness means that the move is possible for the piece (does not account the board state)
 */
class CorrectMoveForPieceChecker {
    Piece &pieceFrom;
    Position from;
    Position to;

    CorrectMoveForPieceChecker(Piece &piece, int fromX, int fromY, int toX, int toY);

    [[nodiscard]] bool isMoveNull() const;

    [[nodiscard]] bool isMoveInStraightLine() const;

    [[nodiscard]] bool isMoveInDiagonalLine() const;

    [[nodiscard]] bool isMoveInForLShape() const;

    [[nodiscard]] bool isMoveInOneByOneBox() const;

    [[nodiscard]] bool isMoveForwardsOrSidewaysByOneCase() const;

    [[nodiscard]] bool isMoveForwardsByAtMostTwoCases() const;

    [[nodiscard]] bool isMoveCorrectForPawn() const;

    [[nodiscard]] bool isMoveCorrectForRook() const;

    [[nodiscard]] bool isMoveCorrectForKnight() const;

    [[nodiscard]] bool isMoveCorrectForBishop() const;

    [[nodiscard]] bool isMoveCorrectForQueen() const;

    [[nodiscard]] bool isMoveCorrectForKing() const;

    [[nodiscard]] bool isMoveCorrectForPiece() const;

    ~CorrectMoveForPieceChecker() = default;

public:
    static bool isMoveCorrect(Piece &piece, int fromX, int fromY, int toX, int toY);
};



#endif //MOVEPOSSIBILITYCHECKER_HPP
