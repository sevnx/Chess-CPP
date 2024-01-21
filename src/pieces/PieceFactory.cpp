#include "PieceFactory.hpp"
#include <stdexcept>

#include "types/Bishop.hpp"
#include "types/King.hpp"
#include "types/Knight.hpp"
#include "types/Pawn.hpp"
#include "types/Queen.hpp"
#include "types/Rook.hpp"

std::unique_ptr<Piece> PieceFactory::createPiece(const PieceType type, const PieceColor color) {
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
        default:
            break;
    }
    throw std::invalid_argument("Invalid piece type");
}
