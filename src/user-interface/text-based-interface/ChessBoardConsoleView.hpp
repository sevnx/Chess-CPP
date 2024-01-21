#ifndef CHESSBOARDCONSOLEVIEW_HPP
#define CHESSBOARDCONSOLEVIEW_HPP
#include "user-interface/human-machine-interface/ChessBoardView.hpp"

class ChessBoardConsoleView final : ChessBoardView {
public:

    explicit ChessBoardConsoleView(ChessBoard& chessBoard);

    void drawBoard() override;

    static void printHorizontalLabels();

    void printRow(int y) const;

    void printSquare(int x, int y) const;

    void displayMoveStatus(MoveStatus moveStatus) override;

    ~ChessBoardConsoleView() override = default;
};

#endif //CHESSBOARDCONSOLEVIEW_HPP
