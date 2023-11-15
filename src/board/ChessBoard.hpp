#ifndef CHESS_CPP_BOARD_H
#define CHESS_CPP_BOARD_H

#include <vector>
#include <map>
#include <memory>

#include "../pieces/PieceFactory.hpp"
#include "Position.hpp"

enum class BoardType {
    DEFAULT_CHESS_BOARD,
    EMPTY_BOARD
};

class ChessBoard {
    std::map<Position, std::unique_ptr<Piece>> pieces;

    std::map<PieceColor, Position> lastPositionMovedTo;

    ChessBoard();

    void populateDefaultChessBoard();
public:
    explicit ChessBoard(BoardType type);

    bool isPositionOccupied(Position position);

    [[nodiscard]] Piece &getPieceAt(Position position) const;

    [[nodiscard]] Position getLastPositionMovedTo(PieceColor color) const;

    void addPiece(std::unique_ptr<Piece> piece, Position position);

    void removePieceAt(Position position);

    void movePiece(Position oldPosition, Position newPosition);

    [[nodiscard]] std::vector<PieceType> getPiecesOnBoard(PieceColor color) const;

    ChessBoard(const ChessBoard &other);

    ChessBoard &operator=(const ChessBoard &other);

    ~ChessBoard() = default;
};

#endif //CHESS_CPP_BOARD_H
