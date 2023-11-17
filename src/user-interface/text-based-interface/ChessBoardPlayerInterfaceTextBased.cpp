#include "ChessBoardPlayerInterfaceTextBased.hpp"

bool ChessBoardPlayerInterface_TextBased::canParsePosition(const std::string& positionString) {
    if (positionString.length() != 2)
        return false;
    if (positionString[0] < MIN_POSITION_CHAR || positionString[0] > MAX_POSITION_CHAR)
        return false;
    if (positionString[1] < MIN_POSITION_NUM || positionString[1] > MAX_POSITION_NUM)
        return false;
    return true;
}

bool ChessBoardPlayerInterface_TextBased::canParsePieceType(const std::string& pieceTypeString) {
    constexpr int NUMBER_OF_PIECE_TYPES = 4, LENGTH_OF_PIECE_TYPE_STRING = 1;
    if (pieceTypeString.length() != LENGTH_OF_PIECE_TYPE_STRING)
        return false;
    std::array<char, NUMBER_OF_PIECE_TYPES> validPieceTypes = {'Q', 'R', 'B', 'N'};
    return std::any_of(validPieceTypes.begin(), validPieceTypes.end(), [&] (const char pieceType) {
        return pieceType == pieceTypeString[0];
    });
}

PieceType ChessBoardPlayerInterface_TextBased::parsePieceType(const std::string& pieceTypeString) {
    switch (pieceTypeString[0]) {
        case 'Q':
            return PieceType::QUEEN;
        case 'R':
            return PieceType::ROOK;
        case 'B':
            return PieceType::BISHOP_WHITE;
        case 'N':
            return PieceType::KNIGHT;
        default:
            throw std::invalid_argument("Invalid piece type");
    }
}

Position ChessBoardPlayerInterface_TextBased::getCurrentPlayerMove() {
    std::string positionFrom, positionTo;
    outputStream << "Enter position to move from and to (e.g. A1 A2): ";
    inputStream >> positionFrom >> positionTo;
    while (!canParsePosition(positionFrom) || !canParsePosition(positionTo)) {
        outputStream << "Invalid input. Try again: ";
        inputStream >> positionFrom >> positionTo;
    }
    outputStream << std::endl << "Input accepted" << std::endl;
    return {positionFrom[0] - 'A', positionFrom[1] - '1'};
}

PieceType ChessBoardPlayerInterface_TextBased::getPromotionPieceType() {
    std::string pieceTypeString;
    outputStream << "Enter piece type to promote to (Q (Queen), R (Rook), B (Bishop), N (Knight)): ";
    inputStream >> pieceTypeString;
    while (!canParsePieceType(pieceTypeString)) {
        outputStream << "Invalid input. Try again: ";
        inputStream >> pieceTypeString;
    }
    outputStream << std::endl << "Input accepted" << std::endl;
    return parsePieceType(pieceTypeString);
}

ChessBoardPlayerInterface_TextBased::ChessBoardPlayerInterface_TextBased(std::istream& inputStream, std::ostream& outputStream)
    : inputStream(inputStream),
      outputStream(outputStream) {}

