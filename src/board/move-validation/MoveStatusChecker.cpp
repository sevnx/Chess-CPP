#include "MoveStatusChecker.hpp"
#include <algorithm>
#include <stdexcept>

#include "MoveValidator.hpp"
#include "../move-getter/BoardPossibleMoveGetter.hpp"

bool MoveStatusChecker::isCapture(const ChessBoard& board, int fromX, int fromY, int toX, int toY) {
    if (!board.isPositionOccupied({toX, toY}))
        return false;
    const auto fromPiece = board.getPieceAt({fromX, fromY});
    const auto toPiece = board.getPieceAt({toX, toY});
    return MoveChecker::canMove(board, fromX, fromY, toX, toY, fromPiece.getColor())==MoveStatus::VALID;
}

bool MoveStatusChecker::isCheck(const ChessBoard&board, const PieceColor color) {
    const Position kingPosition = BoardPositionGetter(board).getFirstPiecePosition(color, PieceType::KING);
    return PositionAttackChecker(board, color).isPositionAttacked(kingPosition);
}

bool MoveStatusChecker::isCheckAfterMove(ChessBoard board, const PieceColor color, int fromX, int fromY, int toX,
                                          int toY) {
    board.movePiece({fromX, fromY}, {toX, toY});
    return isCheck(board, color);
}

bool MoveStatusChecker::isCheckmate(const ChessBoard&board, const PieceColor color) {
    if (!isCheck(board, color))
        return false;
    for (const auto&[fst, snd]: BoardPossibleMoveGetter::getPossibleMoves(board, color)) {
        if (!isCheckAfterMove(board, color, fst.x, fst.y, snd.x, snd.y))
            return false;
    }
    return true;
}

bool MoveStatusChecker::isCheckMateAfterMove(ChessBoard board, const PieceColor color, int fromX, int fromY, int toX,
                                              int toY) {
    board.movePiece({fromX, fromY}, {toX, toY});
    return isCheckmate(board, color);
}

bool MoveStatusChecker::isStalemate(const ChessBoard&board, const PieceColor color) {
    return BoardPossibleMoveGetter::getPossibleMoves(board, color).empty();
}

bool contains(const std::vector<PieceType>&pieces, const PieceType type) {
    return std::find(pieces.begin(), pieces.end(), type) != pieces.end();
}

bool equals(const std::vector<PieceType>&first, const std::vector<PieceType>&second) {
    auto firstSorted = first;
    auto secondSorted = second;
    std::sort(firstSorted.begin(), firstSorted.end());
    std::sort(secondSorted.begin(), secondSorted.end());
    return std::equal(firstSorted.begin(), firstSorted.end(), secondSorted.begin(), secondSorted.end());
}


bool MoveStatusChecker::isDraw(const ChessBoard&board) {
    const auto whitePieces = board.getPiecesOnBoard(PieceColor::WHITE);
    const auto blackPieces = board.getPiecesOnBoard(PieceColor::BLACK);

    if (!contains(whitePieces, PieceType::KING) || !contains(blackPieces, PieceType::KING))
        throw std::runtime_error("No kings on board");

    const std::vector<std::vector<PieceType>> equalDrawScenarios = {
        {PieceType::KING},
        {PieceType::KING, PieceType::BISHOP_BLACK},
        {PieceType::KING, PieceType::BISHOP_WHITE},
    };

    const std::vector<std::vector<PieceType>> scenariosOnlyComparableToKing = {
        {PieceType::KING, PieceType::BISHOP_BLACK},
        {PieceType::KING, PieceType::BISHOP_WHITE},
        {PieceType::KING, PieceType::KNIGHT}
    };

    for (const auto&scenario: equalDrawScenarios) {
        if (equals(whitePieces, scenario) && equals(blackPieces, scenario)) return true;
    }

    for (const auto&scenario: scenariosOnlyComparableToKing) {
        if ((equals(whitePieces, scenario) && equals(blackPieces, {PieceType::KING})) ||
            (equals(whitePieces, {PieceType::KING}) && equals(blackPieces, scenario)))
            return true;
    }

    return false;
}
