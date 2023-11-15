#include "PieceFactory.hpp"

std::unique_ptr<Piece> PieceFactory::createPiece(PieceType type, PieceColor color) {
    switch (type) {
        case PieceType::PAWN:
            return std::make_unique<Pawn>(color);
        case PieceType::ROOK:
            return std::make_unique<Rook>(color);
        case PieceType::KNIGHT:
            return std::make_unique<Knight>(color);
        case PieceType::BISHOP_BLACK:
            return std::make_unique<Bishop>(color, BishopColor::BLACK);
        case PieceType::BISHOP_WHITE:
            return std::make_unique<Bishop>(color, BishopColor::WHITE);
        case PieceType::QUEEN:
            return std::make_unique<Queen>(color);
        case PieceType::KING:
            return std::make_unique<King>(color);
    }
    return nullptr;
}
