#include "Bishop.hpp"

Bishop::Bishop(const PieceColor color, const BishopColor bishopColor) : Piece(color, bishopColor == PieceColor::WHITE
                                                                                         ? PieceType::BISHOP_WHITE : PieceType::BISHOP_BLACK, BISHOP_VALUE), bishopColor(bishopColor) {}