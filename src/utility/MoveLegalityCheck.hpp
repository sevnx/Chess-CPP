#ifndef CHESS_CPP_MOVELEGALITYCHECK_HPP
#define CHESS_CPP_MOVELEGALITYCHECK_HPP

#include "../board/Board.h"
#include "./Moves.hpp"

class MoveLegalityCheck {
private:
    Board &board;
    Position from;
    Position to;
    Piece& pieceFrom;
    Piece& pieceTo;
    MoveLegalityCheck(Board &board, int fromX, int fromY, int toX, int toY);
    bool isMoveLegal();
    bool isMoveLegalForAnyPiece();
    bool isMoveLegalForPawn();
    bool isMoveLegalForKnight();
    bool isMoveLegalForBishop();
    bool isMoveLegalForRook();
    bool isMoveLegalForQueen();
    bool isMoveLegalForKing();
    // Special moves accounted before everything else
    bool isMoveLegalForCastling();
    bool isMoveLegalForEnPassant();
    // Other methods
    Position getKingPosition(PieceColor color);
    bool isKingChecked(PieceColor color);
    bool isKingCheckedAfterMove();
    // Positions attacked
    bool isPositionAttacked(int x, int y, PieceColor color);
    bool arePositionsAttacked(const std::vector<Position>& positions, ExistingMoves moveType);
    bool arePositionsAttackedInDiagonal(const std::vector<Position>& positions);
    // Positions in between
    std::vector<Position> getPositionsInBetween(ExistingMoves moveType);
    void populatePositionsInBetweenDiagonally(std::vector<Position>& positions) const;
    void populatePositionsInBetweenInStraightLine(std::vector<Position>& positions) const;
    // Pieces between
    bool areTherePiecesBetween(ExistingMoves moveType);
    bool areTherePiecesBetweenDiagonally();
    bool areTherePiecesBetweenInStraightLine();
public:
    static bool isMoveLegal(Board &board, int fromX, int fromY, int toX, int toY);
};


#endif //CHESS_CPP_MOVELEGALITYCHECK_HPP
