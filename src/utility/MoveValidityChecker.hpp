#ifndef CHESS_CPP_MOVEVALIDITYCHECKER_HPP
#define CHESS_CPP_MOVEVALIDITYCHECKER_HPP

#include "../board/Position.hpp"
#include "../pieces/Piece.hpp"

class MoveValidityChecker {
private:
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

    //
    bool isMoveValidForPawn();

    bool isMoveValidForRook();

    bool isMoveValidForKnight();

    bool isMoveValidForBishop();

    bool isMoveValidForQueen();

    bool isMoveValidForKing();

    bool isMoveValidForPiece();

    ~MoveValidityChecker() = default;

public:
    static bool isMoveValid(Piece &piece, int fromX, int fromY, int toX, int toY);
};

#endif //CHESS_CPP_MOVEVALIDITYCHECKER_HPP
