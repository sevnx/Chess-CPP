#ifndef CHESS_CPP_PIECEFACTORY_HPP
#define CHESS_CPP_PIECEFACTORY_HPP

#include "Piece.h"
#include <memory>

#include "types/Pawn.hpp"
#include "types/Rook.hpp"
#include "types/Knight.hpp"
#include "types/Bishop.hpp"
#include "types/Queen.hpp"
#include "types/King.hpp"

class PieceFactory {
public:
    static std::unique_ptr<Piece> createPiece(PieceType type, Color color);
};


#endif //CHESS_CPP_PIECEFACTORY_HPP
