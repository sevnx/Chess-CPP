#include "Board.h"

Board::Board() {
   std::map<Position, std::unique_ptr<Piece>>();
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

void Board::addPiece(std::unique_ptr<Piece> piece, unsigned int x, unsigned int y) {
    if (isPositionOccupied(x, y))
        throw std::invalid_argument("Position is already occupied");
    pieces[Position(x, y)] = std::move(piece);
}

void Board::removePieceAt(unsigned int x, unsigned int y) {
    pieces.erase(Position(x, y));
}

void Board::movePiece(unsigned int pieceX, unsigned int pieceY, unsigned int newX, unsigned int newY) {
    std::unique_ptr<Piece> movedPiece = getPieceAtPosition(pieceX, pieceY);

    if (movedPiece->isMoveValid(pieceX, pieceY, newX, newY)) {
        throw std::invalid_argument("Piece cannot be moved to this position");
    } else {
        removePieceAt(pieceX, pieceY);
        addPiece(std::move(movedPiece), newX, newY);
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
        addPiece(PieceFactory::createPiece(*iter, WHITE), i, WHITE_PIECES_ROW);
        addPiece(PieceFactory::createPiece(*iter, BLACK), i, BLACK_PIECES_ROW);
        addPiece(PieceFactory::createPiece(PAWN, WHITE), i, PAWN_ROW);
        addPiece(PieceFactory::createPiece(PAWN, BLACK), i, BLACK_PAWN_ROW);
    }
}

std::unique_ptr<Piece> Board::getPieceAtPosition(unsigned int x, unsigned int y) {
    return std::move(pieces[Position(x, y)]);
}
