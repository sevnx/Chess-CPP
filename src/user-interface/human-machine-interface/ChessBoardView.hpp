#ifndef CHESS_CPP_CHESSBOARDVIEW_HPP
#define CHESS_CPP_CHESSBOARDVIEW_HPP
#include <ChessBoard.hpp>

class ChessBoardView {
protected:
    ChessBoard& chessBoard;
public:
    explicit ChessBoardView(ChessBoard&chessBoard);

    virtual ~ChessBoardView() = default;

    virtual void drawBoard() = 0;
};


#endif //CHESS_CPP_CHESSBOARDVIEW_HPP
