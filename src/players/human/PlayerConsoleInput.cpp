#include "PlayerConsoleInput.hpp"

bool PlayerConsoleInput::canParsePosition(const std::string& positionString) {
    if (positionString.length() != 2)
        return false;
    if (positionString[0] < MIN_POSITION_CHAR || positionString[0] > MAX_POSITION_CHAR)
        return false;
    if (positionString[1] < MIN_POSITION_NUM || positionString[1] > MAX_POSITION_NUM)
        return false;
    return true;
}

bool PlayerConsoleInput::canParsePieceType(const std::string& pieceTypeString) {
    constexpr int NUMBER_OF_PIECE_TYPES = 4, LENGTH_OF_PIECE_TYPE_STRING = 1;
    if (pieceTypeString.length() != LENGTH_OF_PIECE_TYPE_STRING)
        return false;
    std::array<char, NUMBER_OF_PIECE_TYPES> validPieceTypes = {'Q', 'R', 'B', 'N'};
    return std::any_of(validPieceTypes.begin(), validPieceTypes.end(), [&] (const char pieceType) {
        return pieceType == pieceTypeString[0];
    });
}

PieceType PlayerConsoleInput::parsePieceType(const std::string& pieceTypeString) {
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

Position PlayerConsoleInput::parsePosition(const std::string& positionString) {
    return {positionString[0] - MIN_POSITION_CHAR, MAX_POSITION_NUM - positionString[1]};
}

std::pair<Position, Position> PlayerConsoleInput::getMove() {
    std::string positionFrom, positionTo;
    outputStream << "Your move (e.g. A1 A2): ";
    inputStream >> positionFrom >> positionTo;
    while (!canParsePosition(positionFrom) || !canParsePosition(positionTo)) {
        outputStream << "Invalid input. Try again: ";
        inputStream >> positionFrom >> positionTo;
    }
    return std::make_pair(parsePosition(positionFrom), parsePosition(positionTo));
}

PieceType PlayerConsoleInput::getPiecePromotionType() {
    std::string pieceTypeString;
    outputStream << "Promote piece to (Q (Queen), R (Rook), B (Bishop), N (Knight)): ";
    inputStream >> pieceTypeString;
    while (!canParsePieceType(pieceTypeString)) {
        outputStream << "Invalid input. Try again: ";
        inputStream >> pieceTypeString;
    }
    return parsePieceType(pieceTypeString);
}

PlayerConsoleInput::PlayerConsoleInput(std::istream& inputStream, std::ostream& outputStream)
    : inputStream(inputStream),
      outputStream(outputStream) {}