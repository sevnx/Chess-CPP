#include "PlayerStupidAI.hpp"
#include <random>

#include "move-getter/BoardPossibleMoveGetter.hpp"

PlayerStupidAI::PlayerStupidAI(ChessBoard& board, const PieceColor color) : board(board), color(color) {}

std::pair<Position, Position> PlayerStupidAI::getMove() {
    auto move = BoardPossibleMoveGetter::getPossibleMoves(board, color);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, move.size() - 1);
    return move[dis(gen)];
}

PieceType PlayerStupidAI::getPiecePromotionType() {
    return PieceType::QUEEN;
}