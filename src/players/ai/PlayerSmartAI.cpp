#include "PlayerSmartAI.hpp"
#include "move-getter/BoardPossibleMoveGetter.hpp"
#include "move-validation/MoveStatusChecker.hpp"
#include <random>

PlayerSmartAI::PlayerSmartAI(const ChessBoard&board, const PieceColor color) : board(board), color(color) {
}

PieceColor reverseColor(const PieceColor color) {
    return color == PieceColor::BLACK ? PieceColor::WHITE : PieceColor::BLACK;
}

std::pair<Position, Position> PlayerSmartAI::getMove() {
    const bool isCheck = MoveStatusChecker::isCheck(board, color);
    std::vector<std::pair<Position, Position>> moves;
    for (const auto&[fst, snd]: BoardPossibleMoveGetter::getPossibleMoves(board, color)) {
        if (MoveStatusChecker::isCheckAfterMove(board, color, fst.x, fst.y, snd.x, snd.y))
            continue;
        if (isCheck)
            return {fst, snd};
        if (MoveStatusChecker::isCheckMateAfterMove(board, reverseColor(color), fst.x, fst.y, snd.x, snd.y))
            return {fst, snd};
        if (MoveStatusChecker::isCheckAfterMove(board, reverseColor(color), fst.x, fst.y, snd.x, snd.y))
            return {fst, snd};
        if (MoveStatusChecker::isStalemate(board, reverseColor(color)))
            return {fst, snd};
        if (MoveStatusChecker::isDraw(board))
            return {fst, snd};
        if (MoveStatusChecker::isCapture(board, fst.x, fst.y, snd.x, snd.y))
            return {fst, snd};
        moves.emplace_back(fst, snd);
    }
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, moves.size() - 1);
    return moves[dis(gen)];
}

PieceType PlayerSmartAI::getPiecePromotionType() {
    return PieceType::QUEEN;
}
