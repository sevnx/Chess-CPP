#ifndef CHESS_CPP_BOARD_H
#define CHESS_CPP_BOARD_H

#include <vector>
#include <map>
#include <memory>
#include "../pieces/Piece.h"
#include "../pieces/PieceFactory.hpp"
#include "Position.h"

enum class BoardType {
    DEFAULT_CHESS_BOARD,
    EMPTY_BOARD
};

class Board {
private:
    std::map<Position, std::unique_ptr<Piece>> pieces;
    Board();
    void populateDefaultChessBoard();
    std::unique_ptr<Piece> movePiecePointerAtPosition(int x, int y);
    void movePiece(int pieceX, int pieceY, int newX, int newY);
    void addPiece(std::unique_ptr<Piece> piece, int x, int y);
public:
    explicit Board(BoardType type);
    void removePieceAt(int x, int y);
    bool isPositionOccupied(int x, int y);
    Piece& getPieceAt(int x, int y);
    ~Board() = default;
};

#endif //CHESS_CPP_BOARD_H
