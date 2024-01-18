#ifndef MOVEDIRECTION_HPP
#define MOVEDIRECTION_HPP

enum class MoveDirection {
    FROM_WHITE_TO_BLACK,
    FROM_BLACK_TO_WHITE
};

MoveDirection getMoveDirection(int fromY, int toY);

#endif //MOVEDIRECTION_HPP
