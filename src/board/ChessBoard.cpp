#include "ChessBoard.hpp"

ChessBoard::ChessBoard() : pieces(), lastPositionMovedTo() {}

ChessBoard::ChessBoard(BoardType type) : ChessBoard() {
    switch (type) {
        case BoardType::DEFAULT_CHESS_BOARD:
            populateDefaultChessBoard();
            break;
        case BoardType::EMPTY_BOARD:
            break;
    }
}

void ChessBoard::addPiece(std::unique_ptr<Piece> piece, Position position) {
    pieces[position] = std::move(piece);
}

void ChessBoard::removePieceAt(Position position) {
    pieces.erase(position);
}

void ChessBoard::movePiece(Position oldPosition, Position newPosition) {
    if (!isPositionOccupied(oldPosition))
        throw std::invalid_argument("No piece at position");
    PieceColor pieceFromColor = pieces[oldPosition]->getColor();
    auto movedPiece = std::move(pieces[oldPosition]);
    removePieceAt(oldPosition);
    lastPositionMovedTo.emplace(pieceFromColor, newPosition);
    addPiece(std::move(movedPiece), newPosition);
}

bool ChessBoard::isPositionOccupied(Position position) {
    return pieces.find(position) != pieces.end();
}

void ChessBoard::populateDefaultChessBoard() {
    const unsigned int WHITE_PAWN_ROW = 1, WHITE_PIECES_ROW = 0, BLACK_PIECES_ROW = 7, BLACK_PAWN_ROW = 6;
    std::vector<PieceType> defaultPiecesOrderWhite = {PieceType::ROOK,
                                                 PieceType::KNIGHT,
                                                 PieceType::BISHOP_WHITE,
                                                 PieceType::QUEEN,
                                                 PieceType::KING,
                                                 PieceType::BISHOP_BLACK,
                                                 PieceType::KNIGHT,
                                                 PieceType::ROOK};
    std::vector<PieceType> defaultPiecesOrderBlack = {PieceType::ROOK,
                                                 PieceType::KNIGHT,
                                                 PieceType::BISHOP_BLACK,
                                                 PieceType::QUEEN,
                                                 PieceType::KING,
                                                 PieceType::BISHOP_WHITE,
                                                 PieceType::KNIGHT,
                                                 PieceType::ROOK};

    auto iterWhite = defaultPiecesOrderWhite.begin();
    auto iterBlack = defaultPiecesOrderBlack.begin();

    for (int i = 0; i < Position::MAX_POSITION && iterWhite != defaultPiecesOrderWhite.end() && iterBlack != defaultPiecesOrderBlack.end(); i++, iterWhite++, iterBlack++) {
        addPiece(PieceFactory::createPiece(*iterWhite, PieceColor::WHITE), {i, WHITE_PIECES_ROW});
        addPiece(PieceFactory::createPiece(*iterBlack, PieceColor::BLACK), {i, BLACK_PIECES_ROW});
        addPiece(PieceFactory::createPiece(PieceType::PAWN, PieceColor::WHITE), {i, WHITE_PAWN_ROW});
        addPiece(PieceFactory::createPiece(PieceType::PAWN, PieceColor::BLACK), {i, BLACK_PAWN_ROW});
    }
}

Piece &ChessBoard::getPieceAt(Position position) {
    return *pieces[position];
}

std::vector<PieceType> ChessBoard::getPiecesOnBoard(PieceColor color) {
    std::vector<PieceType> piecesOnBoard;
    for (auto &piece : pieces)
        if (piece.second->getColor() == color)
            piecesOnBoard.push_back(piece.second->getType());
    return piecesOnBoard;
}
