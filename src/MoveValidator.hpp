#ifndef CHESS_CPP_MOVEVALIDATOR_HPP
#define CHESS_CPP_MOVEVALIDATOR_HPP

#include "Position.h"
#include "Piece.h"
#include "Board.h"

class MoveValidator {
private:
    int fromX, fromY, toX, toY;
    Color color;
    MoveValidator(int fromX, int fromY, int toX, int toY, Color color);
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
    ~MoveValidator() = default;
public:
    static bool isMoveValid(int fromX, int fromY, int toX, int toY, Color color, PieceType type, bool firstMove = false);
};

#endif //CHESS_CPP_MOVEVALIDATOR_HPP
