//
// Created by SeV on 02.10.2023.
//

#ifndef CHESS_CPP_BOARD_H
#define CHESS_CPP_BOARD_H

#include <vector>
#include <map>
#include <memory>
#include "Piece.h"
#include "PieceFactory.hpp"
#include "Position.h"

typedef enum {
    DEFAULT_CHESS_BOARD,
    EMPTY_BOARD
} BoardType;

class Board {
private:
    std::map<Position, std::unique_ptr<Piece>> pieces;
    void populateDefaultChessBoard();
    Board();
public:
    explicit Board(BoardType type);
    void addPiece(const std::unique_ptr<Piece>&, unsigned int x, unsigned int y);
    void removePieceAt(unsigned int x, unsigned int y);
    void movePiece(unsigned int pieceX, unsigned int pieceY, unsigned int newX, unsigned int newY);
    bool canMoveOnBoard(unsigned int fromX, unsigned int fromY, unsigned int toX, unsigned toY);
    std::vector<std::unique_ptr<Piece>> getPiecesInPath(PieceType type, unsigned int fromX, unsigned int fromY, unsigned int toX, unsigned int toY);
    bool isPositionOccupied(unsigned int x, unsigned int y);
    std::unique_ptr<Piece>& getPieceAtPosition(unsigned int x, unsigned int y);
    ~Board() = default;
};


#endif //CHESS_CPP_BOARD_H
