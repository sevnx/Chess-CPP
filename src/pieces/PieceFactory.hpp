#ifndef CHESS_CPP_PIECEFACTORY_HPP
#define CHESS_CPP_PIECEFACTORY_HPP

#include <memory>
#include "Piece.hpp"

class PieceFactory {
public:

    static std::unique_ptr<Piece> createPiece(PieceType type, PieceColor color);
};

#endif //CHESS_CPP_PIECEFACTORY_HPP
