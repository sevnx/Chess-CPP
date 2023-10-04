//
// Created by sev on 04/10/2023.
//


#include "PieceFactory.hpp"

std::shared_ptr<Piece> PieceFactory::createPiece(PieceType type, Color color) {
    switch (type) {
        case PAWN:
            return std::make_shared<Pawn>(Pawn(color));
        case ROOK:
            return std::make_shared<Rook>(Rook(color));
        case KNIGHT:
            return std::make_shared<Knight>(Knight(color));
        case BISHOP:
            return std::make_shared<Bishop>(Bishop(color));
        case QUEEN:
            return std::make_shared<Queen>(Queen(color));
        case KING:
            return std::make_shared<King>(King(color));
    }
    return nullptr;
}
