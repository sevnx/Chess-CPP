#ifndef CHESS_CPP_MOVELEGALITYCHECKER_HPP
#define CHESS_CPP_MOVELEGALITYCHECKER_HPP

#include "MoveTypes.hpp"
#include "board/ChessBoard.hpp"
#include "position-getter/BoardPositionGetter.hpp"

class MoveLegalityChecker {
    ChessBoard &board;
    Position from;
    Position to;
    Piece &pieceFrom;
    Piece &pieceTo;
    BoardPositionGetter boardPositionGetter;

    MoveLegalityChecker(ChessBoard &board, int fromX, int fromY, int toX, int toY);

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

    // Pieces between
    bool areTherePiecesBetween(ExistingMoves moveType);

    bool areTherePiecesBetweenDiagonally();

    bool areTherePiecesBetweenInStraightLine();

public:
    static bool isMoveLegal(ChessBoard &board, int fromX, int fromY, int toX, int toY);
};


#endif //CHESS_CPP_MOVELEGALITYCHECKER_HPP
