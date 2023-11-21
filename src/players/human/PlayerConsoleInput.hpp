#ifndef CHESSBOARDPLAYERINTERFACETEXTBASED_HPP
#define CHESSBOARDPLAYERINTERFACETEXTBASED_HPP

#include <iostream>
#include <algorithm>
#include <array>
#include <../../game/Player.hpp>

class PlayerConsoleInput final : public Player {
    constexpr static char MIN_POSITION_CHAR = 'A';
    constexpr static char MAX_POSITION_CHAR = 'H';
    constexpr static char MIN_POSITION_NUM = '1';
    constexpr static char MAX_POSITION_NUM = '8';
    std::istream&inputStream;
    std::ostream&outputStream;

    static bool canParsePosition(const std::string&positionString);

    static bool canParsePieceType(const std::string&pieceTypeString);

    static PieceType parsePieceType(const std::string&pieceTypeString);

    static Position parsePosition(const std::string&positionString);

public:
    std::pair<Position, Position> getMove() override;

    PieceType getPiecePromotionType() override;

    explicit PlayerConsoleInput(std::istream&inputStream = std::cin, std::ostream&outputStream = std::cout);
};

#endif //CHESSBOARDPLAYERINTERFACETEXTBASED_HPP
