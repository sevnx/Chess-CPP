#ifndef CHESS_CPP_PIECEFACTORY_HPP
#define CHESS_CPP_PIECEFACTORY_HPP

#include "Piece.h"
#include <memory>

#include "pieces/Pawn.hpp"
#include "pieces/Rook.hpp"
#include "pieces/Knight.hpp"
#include "pieces/Bishop.hpp"
#include "pieces/Queen.hpp"
#include "pieces/King.hpp"

class PieceFactory {
public:
    static std::shared_ptr<Piece> createPiece(PieceType type, Color color);
};


#endif //CHESS_CPP_PIECEFACTORY_HPP
