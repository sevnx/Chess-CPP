#include "Position.h"

Position::Position(unsigned int x, unsigned int y): x(x), y(y) {
    if (x > MAX_POSITION || y > MAX_POSITION) {
        throw std::invalid_argument("Position out of bounds");
    }
}
