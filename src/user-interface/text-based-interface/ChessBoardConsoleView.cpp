#include "ChessBoardConsoleView.hpp"
#include <iostream>
#include "PieceConsoleView.hpp"

ChessBoardConsoleView::ChessBoardConsoleView(ChessBoard& chessBoard): ChessBoardView(chessBoard) {}

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
    std::cout << " ";
    if (chessBoard.isPositionOccupied(Position(x, y))) {
        const auto& piece = chessBoard.getPieceAt(Position(x, y));
        PieceConsoleView pieceView(piece);
        pieceView.drawPiece();
    } else {
        std::cout << " ";
    }
    std::cout << " |";
}

void ChessBoardConsoleView::displayMoveStatus(const MoveStatus moveStatus) {
    switch (moveStatus) {
        case MoveStatus::INCORRECT_POSITION:
            std::cout << "No piece at this position" << std::endl;
            break;
        case MoveStatus::INCORRECT_TURN:
            std::cout << "Wrong piece color for this turn" << std::endl;
            break;
        case MoveStatus::INCORRECT_MOVE:
            std::cout << "Incorrect move for this piece" << std::endl;
            break;
        case MoveStatus::CHECK:
            std::cout << "Impossible move, you are in check" << std::endl;
            break;
        case MoveStatus::VALID:
            break;
    }
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
