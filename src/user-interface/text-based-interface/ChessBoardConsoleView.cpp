#include "ChessBoardConsoleView.hpp"

#include "PieceConsoleView.hpp"

ChessBoardConsoleView::ChessBoardConsoleView(ChessBoard&chessBoard): ChessBoardView(chessBoard) {
}

void printOutSpace() {
    std::cout << " ";
}

void printOutNewLine() {
    std::cout << '\n';
}

void ChessBoardConsoleView::drawBoard() {
    for (int y = 0; y < Position::MAX_POSITION; ++y) {
        for (int x = 0; x < Position::MAX_POSITION; ++x) {
            if (chessBoard.isPositionOccupied(Position(x, y))) {
                auto&piece = chessBoard.getPieceAt(Position(x, y));
                PieceConsoleView pieceView(piece);
                pieceView.drawPiece();
            }
            else {
                printOutSpace();
            }
            printOutSpace();
        }
        printOutNewLine();
    }
}
