#ifndef CHESS_CPP_POSITION_H
#define CHESS_CPP_POSITION_H

#include <stdexcept>

struct Position {
    enum {
        MAX_POSITION = 8
    };
    unsigned int x;
    unsigned int y;
    Position(unsigned int x, unsigned int y);
    static bool isPositionValid(unsigned int x,unsigned int y);
    bool operator==(const Position &other) const;
    bool operator!=(const Position &other) const;
    bool operator<(const Position &other) const;
    ~Position() = default;
};


#endif //CHESS_CPP_POSITION_H
