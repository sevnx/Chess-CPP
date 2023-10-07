#include "PieceFactory.hpp"

std::unique_ptr<Piece> PieceFactory::createPiece(PieceType type, Color color) {
    switch (type) {
        case PAWN:
            return std::make_unique<Pawn>(color);
        case ROOK:
            return std::make_unique<Rook>(color);
        case KNIGHT:
            return std::make_unique<Knight>(color);
        case BISHOP:
            return std::make_unique<Bishop>(color);
        case QUEEN:
            return std::make_unique<Queen>(color);
        case KING:
            return std::make_unique<King>(color);
    }
}
