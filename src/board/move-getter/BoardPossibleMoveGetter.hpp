#ifndef BOARDMOVEGETTER_HPP
#define BOARDMOVEGETTER_HPP

#include "../ChessBoard.hpp"
#include "../position-getter/BoardPositionGetter.hpp"

class BoardPossibleMoveGetter {
    public:
        static std::vector<Position> getPossibleMoveForPawn(const ChessBoard& board, int x, int y, const Piece& piece);

        static std::vector<Position> getPossibleMoveForRook(const ChessBoard& board, int x, int y, const Piece& piece);

        static std::vector<Position> getPossibleMoveForKnight(const ChessBoard& board, int x, int y, const Piece& piece);

        static std::vector<Position> getPossibleMoveForBishop(const ChessBoard& board, int x, int y, const Piece& piece);

        static std::vector<Position> getPossibleMoveForQueen(const ChessBoard& board, int x, int y, const Piece& piece);

        static std::vector<Position> getPossibleMoveForKing(const ChessBoard& board, int x, int y, const Piece& piece);

        static std::vector<std::pair<Position, Position>> getPossibleMoves(const ChessBoard& board, PieceColor color);

        static std::vector<Position> getPossibleMoveForPiece(const ChessBoard& board, int x, int y);
};

#endif //BOARDMOVEGETTER_HPP
