//
// Created by SeV on 02.10.2023.
//

#include "Board.h"

Board::Board() {
   pieces = std::map<Position, std::unique_ptr<Piece>>();
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

void Board::addPiece(std::unique_ptr<Piece>& piece, unsigned int x, unsigned int y) {
    if (isPositionOccupied(x, y)) {
        throw std::invalid_argument("Position is already occupied");
    }
    pieces[Position(x, y)] = std::move(piece);
}

void Board::removePieceAt(unsigned int x, unsigned int y) {
    pieces.erase(Position(x, y));
}

void Board::movePiece(unsigned int pieceX, unsigned int pieceY, unsigned int newX, unsigned int newY) {
    std::unique_ptr<Piece> movedPiece = std::move(pieces.at(Position(pieceX, pieceY)));
    if (movedPiece->canMove(pieceX, pieceY, newX, newY)) {
        throw std::invalid_argument("Piece cannot be moved to this position");
    } else {
        removePieceAt(pieceX, pieceY);
        addPiece(movedPiece, newX, newY);
    }
}

bool Board::isPositionOccupied(unsigned int x, unsigned int y) {
    return pieces.find(Position(x, y)) != pieces.end();
}

void Board::populateDefaultChessBoard() {
    const unsigned int PAWN_ROW = 1, WHITE_PIECES_ROW = 0, BLACK_PIECES_ROW = 7, BLACK_PAWN_ROW = 6;
    std::vector<PieceType> defaultPiecesOrder = {ROOK, KNIGHT, BISHOP, QUEEN, KING, BISHOP, KNIGHT, ROOK};
    auto iter = defaultPiecesOrder.begin();

    for (int i = 0 ; i < Position::MAX_POSITION && iter != defaultPiecesOrder.end(); i++, iter++) {
        std::unique_ptr<Piece> whitePiece = PieceFactory::createPiece(*iter, WHITE);
        std::unique_ptr<Piece> blackPiece = PieceFactory::createPiece(*iter, BLACK);
        std::unique_ptr<Piece> whitePawn = PieceFactory::createPiece(PAWN, WHITE);
        std::unique_ptr<Piece> blackPawn = PieceFactory::createPiece(PAWN, BLACK);
        addPiece(whitePiece, i, WHITE_PIECES_ROW);
        addPiece(blackPiece, i, BLACK_PIECES_ROW);
        addPiece(whitePawn, i, PAWN_ROW);
        addPiece(blackPawn, i, BLACK_PAWN_ROW);
    }
}

std::vector<std::unique_ptr<Piece>>
Board::getPiecesInPath(PieceType type, unsigned int fromX, unsigned int fromY, unsigned int toX, unsigned int toY) {
    std::vector<std::unique_ptr<Piece>> piecesInPath = std::vector<std::unique_ptr<Piece>>();
    switch (type) {
        case BISHOP:
            break;
        default:
            for (unsigned int i = fromX, j = fromY; i < toX || j < toY;) {
                if (i < toX)
                    i++;
                if (j < toY)
                    j++;
            }
    }
    return piecesInPath;
}

bool Board::canMoveOnBoard(unsigned int fromX, unsigned int fromY, unsigned int toX, unsigned int toY) {
    return false;
}

std::unique_ptr<Piece> &Board::getPieceAtPosition(unsigned int x, unsigned int y) {
    return pieces.at(Position(x, y));
}
