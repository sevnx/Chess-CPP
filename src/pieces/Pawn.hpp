//
// Created by SeV on 02.10.2023.
//

#ifndef CHESS_CPP_PAWN_HPP
#define CHESS_CPP_PAWN_HPP


#include "../Piece.h"

class Pawn : public Piece {
public:
    Pawn(Color color, Position position);
    bool isValidMove(Position newPosition) override;
};


#endif //CHESS_CPP_PAWN_HPP
