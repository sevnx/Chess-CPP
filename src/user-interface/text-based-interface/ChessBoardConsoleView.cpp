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

void ChessBoardConsoleView::printHorizontalLabels() {
    std::cout << "   A   B   C   D   E   F   G   H\n";
}

void ChessBoardConsoleView::printSquare(const int x, const int y) const {
    std::cout << " "; // print vertical line
    if (chessBoard.isPositionOccupied(Position(x, y))) {
        const auto& piece = chessBoard.getPieceAt(Position(x, y));
        PieceConsoleView pieceView(piece);
        pieceView.drawPiece();
    } else {
        std::cout << " ";
    }
    std::cout << " |"; // print vertical line
}

void ChessBoardConsoleView::printRow(const int y) const {
    std::cout << Position::MAX_POSITION - y << " ";
    for (int x = 0; x < Position::MAX_POSITION; ++x) {
        printSquare(x, y);
    }
    std::cout << " " << Position::MAX_POSITION - y << '\n';
}

void ChessBoardConsoleView::drawBoard() {
    printHorizontalLabels();
    for (int y = 0; y < Position::MAX_POSITION; ++y) {
        printRow(y);
    }
    printHorizontalLabels();
}
