#include "PieceConsoleView.hpp"

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

PieceConsoleView::PieceConsoleView(const Piece&piece) : PieceView(piece) {
}

void PieceConsoleView::drawPiece() {
    std::cout << getPieceSymbol();
}


