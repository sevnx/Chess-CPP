#ifndef CHESSBOARDCONSOLEVIEW_HPP
#define CHESSBOARDCONSOLEVIEW_HPP
#include "user-interface/human-machine-interface/ChessBoardView.hpp"


class ChessBoardConsoleView final : ChessBoardView {
public:
    explicit ChessBoardConsoleView(ChessBoard&chessBoard);

    void drawBoard() override;

    ~ChessBoardConsoleView() override = default;
};


#endif //CHESSBOARDCONSOLEVIEW_HPP
