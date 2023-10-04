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

typedef enum {
    DEFAULT_CHESS_BOARD,
    EMPTY_BOARD
} BoardType;

class Board {
private:
    std::map<Position, std::shared_ptr<Piece>> pieces;
    void populateDefaultChessBoard();
    Board();
public:
    explicit Board(BoardType type);
    void addPiece(Piece &piece, unsigned int x, unsigned int y);
    void removePieceAt(unsigned int x, unsigned int y);
    // bool canMovePiece(unsigned int pieceX, unsigned int pieceY, unsigned int newX, unsigned int newY);
    void movePiece(unsigned int pieceX, unsigned int pieceY, unsigned int newX, unsigned int newY);
    bool isPositionOccupied(unsigned int x, unsigned int y);
    Piece& getPieceAtPosition(unsigned int x, unsigned int y);
    ~Board() = default;
};


#endif //CHESS_CPP_BOARD_H
