//
// Created by SeV on 02.10.2023.
//

#ifndef CHESS_CPP_BOARD_H
#define CHESS_CPP_BOARD_H

#include <map>
#include "Piece.h"

class Board {
private:
    std::map<Position, Piece> pieces;
public:
    Board();
};


#endif //CHESS_CPP_BOARD_H
