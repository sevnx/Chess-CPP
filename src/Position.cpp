#include "Position.h"

Position::Position(unsigned int x, unsigned int y): x(x), y(y) {
    if (x > MAX_POSITION || y > MAX_POSITION) {
        throw std::invalid_argument("Position out of bounds");
    }
}

bool Position::operator==(const Position &other) const {
    return this->x == other.x && this->y == other.y;
}

bool Position::operator!=(const Position &other) const {
    return !(*this == other);
}

bool Position::operator<(const Position &other) const {
    return this->x < other.x || (this->x == other.x && this->y < other.y);
}
