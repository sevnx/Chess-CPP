#include "Board.h"

Board::Board() {
   std::map<Position, std::unique_ptr<Piece>>();
}

Board::Board(BoardType type): Board() {
    switch (type) {
        case BoardType::DEFAULT_CHESS_BOARD:
            populateDefaultChessBoard();
            break;
        case BoardType::EMPTY_BOARD:
            break;
    }
}

void Board::addPiece(std::unique_ptr<Piece> piece, int x, int y) {
    if (isPositionOccupied(x, y))
        throw std::invalid_argument("Position is already occupied");
    pieces[Position(x, y)] = std::move(piece);
}

void Board::removePieceAt(int x, int y) {
    pieces.erase(Position(x, y));
}

std::unique_ptr<Piece> Board::movePiecePointerAtPosition(int x, int y) {
    return std::move(pieces[Position(x, y)]);
}

void Board::movePiece(int pieceX, int pieceY, int newX, int newY) {
    if (true) {
        throw std::invalid_argument("Piece cannot be moved to this position");
    } else {
        std::unique_ptr<Piece> movedPiece = movePiecePointerAtPosition(pieceX, pieceY);
        removePieceAt(pieceX, pieceY);
        addPiece(std::move(movedPiece), newX, newY);
    }
}

bool Board::isPositionOccupied(int x, int y) {
    return pieces.find(Position(x, y)) != pieces.end();
}

void Board::populateDefaultChessBoard() {
    const unsigned int PAWN_ROW = 1, WHITE_PIECES_ROW = 0, BLACK_PIECES_ROW = 7, BLACK_PAWN_ROW = 6;
    std::vector<PieceType> defaultPiecesOrder = {PieceType::ROOK,
                                                 PieceType::KNIGHT,
                                                 PieceType::BISHOP,
                                                 PieceType::QUEEN,
                                                 PieceType::KING,
                                                 PieceType::BISHOP,
                                                 PieceType::KNIGHT,
                                                 PieceType::ROOK};
    auto iter = defaultPiecesOrder.begin();

    for (int i = 0 ; i < Position::MAX_POSITION && iter != defaultPiecesOrder.end(); i++, iter++) {
        addPiece(PieceFactory::createPiece(*iter, PieceColor::WHITE), i, WHITE_PIECES_ROW);
        addPiece(PieceFactory::createPiece(*iter, PieceColor::BLACK), i, BLACK_PIECES_ROW);
        addPiece(PieceFactory::createPiece(PieceType::PAWN, PieceColor::WHITE), i, PAWN_ROW);
        addPiece(PieceFactory::createPiece(PieceType::PAWN, PieceColor::BLACK), i, BLACK_PAWN_ROW);
    }
}

Piece &Board::getPieceAt(int x, int y) {
    return *pieces[Position(x, y)];
}
