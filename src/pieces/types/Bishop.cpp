#include "Bishop.hpp"

Bishop::Bishop(PieceColor color, BishopColor bishopColor) : Piece(color, bishopColor == PieceColor::WHITE
? PieceType::BISHOP_WHITE : PieceType::BISHOP_BLACK, BISHOP_VALUE), bishopColor(bishopColor) {}