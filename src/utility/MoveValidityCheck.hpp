#ifndef CHESS_CPP_MOVEVALIDITYCHECK_HPP
#define CHESS_CPP_MOVEVALIDITYCHECK_HPP

#include "../board/Position.h"
#include "../pieces/Piece.h"

class MoveValidityCheck {
private:
    Piece& pieceFrom;
    Position from;
    Position to;
    MoveValidityCheck(Piece& piece, int fromX, int fromY, int toX, int toY);
    [[nodiscard]] bool isMoveNull() const;
    [[nodiscard]] bool isMoveInStraightLine() const;
    [[nodiscard]] bool isMoveInDiagonalLine() const;
    [[nodiscard]] bool isMoveInForLShape() const;
    [[nodiscard]] bool isMoveInOneByOneBox() const;
    [[nodiscard]] bool isMoveForwardsOrSidewaysByOneCase() const;
    [[nodiscard]] bool isMoveForwardsByAtMostTwoCases() const;
    bool isMoveValidForPawn(bool firstMove);
    bool isMoveValidForRook();
    bool isMoveValidForKnight();
    bool isMoveValidForBishop();
    bool isMoveValidForQueen();
    bool isMoveValidForKing();
    bool isMoveValidForPiece();
    ~MoveValidityCheck() = default;
public:
    static bool isMoveValid(Piece& piece, int fromX, int fromY, int toX, int toY);
};

#endif //CHESS_CPP_MOVEVALIDITYCHECK_HPP
