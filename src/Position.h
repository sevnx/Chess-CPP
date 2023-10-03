//
// Created by SeV on 02.10.2023.
//

#ifndef CHESS_CPP_POSITION_H
#define CHESS_CPP_POSITION_H
#include <stdexcept>

struct Position {
    const unsigned int MAX_POSITION = 8;
    unsigned int x;
    unsigned int y;
    Position(unsigned int x, unsigned int y);
};


#endif //CHESS_CPP_POSITION_H
