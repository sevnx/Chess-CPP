//
// Created by SeV on 02.10.2023.
//

#include "Board.h"

Board::Board() {
   pieces = std::map<Position, std::shared_ptr<Piece>>();
}

Board::Board(BoardType type): Board() {
    switch (type) {
        case DEFAULT_CHESS_BOARD:
            populateDefaultChessBoard();
            break;
        case EMPTY_BOARD:
            break;
    }
}

void Board::addPiece(Piece &piece, unsigned int x, unsigned int y) {
    pieces.emplace(Position(x, y), std::shared_ptr<Piece>(&piece));
}

void Board::removePieceAt(unsigned int x, unsigned int y) {
    pieces.erase(Position(x, y));
}

void Board::movePiece(unsigned int pieceX, unsigned int pieceY, unsigned int newX, unsigned int newY) {
    Piece &movedPiece = getPieceAtPosition(pieceX, pieceY);
    if (!movedPiece.canMove(pieceX, pieceY, newX, newY)) {
        throw std::invalid_argument("Piece cannot be moved to this position");
    } else {
        removePieceAt(pieceX, pieceY);
        addPiece(movedPiece, newX, newY);
    }
}

bool Board::isPositionOccupied(unsigned int x, unsigned int y) {
    return pieces.find(Position(x, y)) != pieces.end();
}

Piece &Board::getPieceAtPosition(unsigned int x, unsigned int y) {
    return *pieces[Position(x, y)];
}

void Board::populateDefaultChessBoard() {
    const unsigned int PAWN_ROW = 1, WHITE_PIECES_ROW = 0, BLACK_PIECES_ROW = 7, BLACK_PAWN_ROW = 6;
    std::vector<PieceType> defaultPiecesOrder = {ROOK, KNIGHT, BISHOP, QUEEN, KING, BISHOP, KNIGHT, ROOK};
    for (int i = 0; i < 8; i++) {
        pieces[Position(i, PAWN_ROW)] = PieceFactory::createPiece(PAWN, WHITE);
        pieces[Position(i, BLACK_PAWN_ROW)] = PieceFactory::createPiece(PAWN, BLACK);
    }
    int i = 0;
    for (PieceType type : defaultPiecesOrder) {
        pieces[Position(i, WHITE_PIECES_ROW)] = PieceFactory::createPiece(type, WHITE);
        pieces[Position(i++, BLACK_PIECES_ROW)] = PieceFactory::createPiece(type, BLACK);
    }
}
/*
bool Board::canMovePiece(unsigned int pieceX, unsigned int pieceY, unsigned int newX, unsigned int newY) {
    return false;
} */