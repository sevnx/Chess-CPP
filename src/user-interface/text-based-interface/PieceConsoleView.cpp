#include "PieceConsoleView.hpp"
#include <iostream>
#include "../../../lib/termcolor/termcolor.hpp"

char PieceConsoleView::getPieceSymbol() const {
    switch (pieceType) {
        case PieceType::PAWN:
            return 'P';
        case PieceType::ROOK:
            return 'R';
        case PieceType::KNIGHT:
            return 'N';
        case PieceType::BISHOP_BLACK:
        case PieceType::BISHOP_WHITE:
            return 'B';
        case PieceType::QUEEN:
            return 'Q';
        case PieceType::KING:
            return 'K';
        default:
            return ' ';
    }
}

PieceColor PieceConsoleView::getPieceColor() const {
    return pieceColor;
}

PieceConsoleView::PieceConsoleView(const Piece& piece) : PieceView(piece) {}

void PieceConsoleView::drawPiece() {
    if (getPieceColor() == PieceColor::WHITE)
        std::cout << termcolor::blue;
    else
        std::cout << termcolor::red;
    std::cout << getPieceSymbol() << termcolor::reset;
}
