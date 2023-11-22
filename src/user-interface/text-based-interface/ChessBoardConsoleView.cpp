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

void printOutEmptyLine() {
    printOutNewLine();
}
void printOutEmptyPiece() {
    std::cout << "x";
}

void printOutSpaces(const int numberOfSpaces) {
    for (int i = 0; i < numberOfSpaces; ++i) {
        printOutSpace();
    }
}

void printOutHeader() {
    printOutSpaces(4);
    for (unsigned char i = 0; i < Position::MAX_POSITION; ++i) {
        char letter = 'A' + i;
        std::cout << letter << " ";
    }
    printOutNewLine();
}

void ChessBoardConsoleView::drawBoard() {
    printOutHeader();
    printOutEmptyLine();
    for (int y = 0; y < Position::MAX_POSITION; ++y) {
        std::cout << Position::MAX_POSITION - y << " ";
        printOutSpaces(2);
        for (int x = 0; x < Position::MAX_POSITION; ++x) {
            if (chessBoard.isPositionOccupied(Position(x, y))) {
                auto&piece = chessBoard.getPieceAt(Position(x, y));
                PieceConsoleView pieceView(piece);
                pieceView.drawPiece();
            }
            else {
                printOutEmptyPiece();
            }
            printOutSpace();
        }
        printOutNewLine();
    }
    printOutEmptyLine();
    printOutHeader();
}
