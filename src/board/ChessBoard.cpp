#include "ChessBoard.hpp"
#include <stdexcept>
#include <string>

ChessBoard::ChessBoard() = default;

ChessBoard::ChessBoard(const BoardType type) : ChessBoard() {
    if (type == BoardType::DEFAULT_CHESS_BOARD)
        populateDefaultChessBoard();
}

void ChessBoard::addPiece(std::unique_ptr<Piece> piece, const Position position) {
    pieces[position] = std::move(piece);
}

void ChessBoard::removePieceAt(const Position position) {
    pieces.erase(position);
}

void ChessBoard::movePiece(const Position oldPosition, const Position newPosition) {
    if (!isPositionOccupied(oldPosition))
        throw std::invalid_argument("No piece at position");
    lastPositionMovedTo[pieces[oldPosition]->getColor()] = newPosition;
    auto movedPiece = std::move(pieces[oldPosition]);
    movedPiece->incrementMoveCount();
    removePieceAt(oldPosition);
    addPiece(std::move(movedPiece), newPosition);
}

void ChessBoard::promotePawnTo(const PieceType pieceType, const Position position) {
    if (!isPositionOccupied(position))
        throw std::invalid_argument("No piece at position");
    if (pieces.at(position)->getType() != PieceType::PAWN)
        throw std::invalid_argument("Piece at position is not a pawn");
    const PieceColor pieceColor = pieces.at(position)->getColor();
    removePieceAt(position);
    addPiece(PieceFactory::createPiece(pieceType, pieceColor), position);
}

bool ChessBoard::isPositionOccupied(const Position position) const {
    return pieces.find(position) != pieces.end();
}

void ChessBoard::populateDefaultChessBoard() {
    std::vector defaultPiecesOrderWhite = {
        PieceType::ROOK,
        PieceType::KNIGHT,
        PieceType::BISHOP_WHITE,
        PieceType::QUEEN,
        PieceType::KING,
        PieceType::BISHOP_BLACK,
        PieceType::KNIGHT,
        PieceType::ROOK
    };
    std::vector defaultPiecesOrderBlack = {
        PieceType::ROOK,
        PieceType::KNIGHT,
        PieceType::BISHOP_BLACK,
        PieceType::QUEEN,
        PieceType::KING,
        PieceType::BISHOP_WHITE,
        PieceType::KNIGHT,
        PieceType::ROOK
    };

    auto iterWhite = defaultPiecesOrderWhite.begin();
    auto iterBlack = defaultPiecesOrderBlack.begin();

    for (int i = 0; i < Position::MAX_POSITION && iterWhite != defaultPiecesOrderWhite.end() && iterBlack !=
                    defaultPiecesOrderBlack.end(); i++, ++iterWhite, ++iterBlack) {
        addPiece(PieceFactory::createPiece(*iterWhite, PieceColor::WHITE), {i, WHITE_PIECES_ROW});
        addPiece(PieceFactory::createPiece(*iterBlack, PieceColor::BLACK), {i, BLACK_PIECES_ROW});
        addPiece(PieceFactory::createPiece(PieceType::PAWN, PieceColor::WHITE), {i, WHITE_PAWN_ROW});
        addPiece(PieceFactory::createPiece(PieceType::PAWN, PieceColor::BLACK), {i, BLACK_PAWN_ROW});
    }
}

Piece& ChessBoard::getPieceAt(const Position position) const {
    if (!isPositionOccupied(position)) {
        throw std::invalid_argument("No piece at position "
                                    + std::to_string(position.x) + " "
                                    + std::to_string(position.y));
    }
    return *pieces.at(position);
}

std::vector<PieceType> ChessBoard::getPiecesOnBoard(const PieceColor color) const {
    std::vector<PieceType> piecesOnBoard;
    for (const auto& [position, piece] : pieces) {
        if (piece->getColor() == color)
            piecesOnBoard.push_back(piece->getType());
    }
    return piecesOnBoard;
}

ChessBoard::ChessBoard(const ChessBoard& other) {
    for (const auto& [position, piece] : other.pieces)
        pieces[position] = std::make_unique<Piece>(*piece);
    lastPositionMovedTo = other.lastPositionMovedTo;
}

ChessBoard& ChessBoard::operator=(const ChessBoard& other) {
    if (this == &other)
        return *this;
    pieces.clear();
    for (const auto& [position, piece] : other.pieces)
        pieces[position] = std::make_unique<Piece>(*piece);
    lastPositionMovedTo = other.lastPositionMovedTo;
    return *this;
}

Position ChessBoard::getLastPositionMovedTo(const PieceColor color) const {
    return lastPositionMovedTo.at(color);
}
