#ifndef CHESSBOARDPLAYERINTERFACETEXTBASED_HPP
#define CHESSBOARDPLAYERINTERFACETEXTBASED_HPP

#include <iostream>
#include <algorithm>
#include <array>
#include <user-interface/human-machine-interface/ChessBoardPlayerInput.hpp>

class ChessBoardPlayerInterface_TextBased final : public ChessBoardPlayerInput {
    constexpr static char MIN_POSITION_CHAR = 'A';
    constexpr static char MAX_POSITION_CHAR = 'H';
    constexpr static char MIN_POSITION_NUM = '1';
    constexpr static char MAX_POSITION_NUM = '8';
    std::istream& inputStream;
    std::ostream& outputStream;

    static bool canParsePosition(const std::string& positionString);

    static bool canParsePieceType(const std::string& pieceTypeString);

    static PieceType parsePieceType(const std::string& pieceTypeString);

    public:
        Position getCurrentPlayerMove() override;

        PieceType getPromotionPieceType() override;

        explicit ChessBoardPlayerInterface_TextBased(std::istream& inputStream = std::cin, std::ostream& outputStream = std::cout);
};

#endif //CHESSBOARDPLAYERINTERFACETEXTBASED_HPP
