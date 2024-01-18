#include "MoveDirection.hpp"

MoveDirection getMoveDirection(const int fromY, const int toY) {
    if (fromY < toY)
        return MoveDirection::FROM_BLACK_TO_WHITE;
    return MoveDirection::FROM_WHITE_TO_BLACK;
}