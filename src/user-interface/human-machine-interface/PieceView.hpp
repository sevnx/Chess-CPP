#ifndef CHESS_CPP_PIECEVIEW_HPP
#define CHESS_CPP_PIECEVIEW_HPP

#include "pieces/Piece.hpp"

class PieceView {
    PieceType pieceType;

    public:
        explicit PieceView(const Piece& piece);

        virtual void drawPiece() = 0;

        virtual ~PieceView() = default;
};


#endif //CHESS_CPP_PIECEVIEW_HPP
