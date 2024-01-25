#include <iostream>
#include "board/ChessBoard.hpp"
#include "pieces/PieceFactory.hpp"
#include "board/move-validation/MoveEndGameChecker.hpp"
#include <cassert>

bool verifyDrawCases() {
    const std::vector<std::pair<std::string, std::vector<PieceType>>> equalDrawScenarios = {
        {"King only", {PieceType::KING}},
        {"King and black bishop equal", {PieceType::KING, PieceType::BISHOP_BLACK}},
        {"King and white bishop equal", {PieceType::KING, PieceType::BISHOP_WHITE}},
    };

    const std::vector<std::pair<std::string, std::vector<PieceType>>> scenariosOnlyComparableToKing = {
        {"King and black bishop compare king", {PieceType::KING, PieceType::BISHOP_BLACK}},
        {"King and white bishop compare king", {PieceType::KING, PieceType::BISHOP_WHITE}},
        {"King and knight compare king", {PieceType::KING, PieceType::KNIGHT}}
    };

    for (const auto& [fst, snd]: equalDrawScenarios) {
        const auto& scenario = snd;
        ChessBoard board(BoardType::EMPTY_BOARD);
        auto positionWhite = Position(0, 0);
        auto positionBlack = Position(7, 7);
        for (const auto& piece: scenario) {
            board.addPiece(PieceFactory::createPiece(piece, PieceColor::WHITE), positionWhite);
            board.addPiece(PieceFactory::createPiece(piece, PieceColor::BLACK), positionBlack);
            positionWhite.x++;
            positionBlack.x--;
        }
        if (!MoveEndGameChecker::isDraw(board)) {
            std::cout << "Failed to detect draw for scenario: " << fst << std::endl;
            return false;
        }
    }
    for (const auto& [fst, snd]: scenariosOnlyComparableToKing) {
        const auto& scenario = snd;
        ChessBoard board(BoardType::EMPTY_BOARD);
        auto positionWhite = Position(0, 0);
        board.addPiece(PieceFactory::createPiece(PieceType::KING, PieceColor::BLACK), Position(7, 7));
        for (const auto& piece: scenario) {
            board.addPiece(PieceFactory::createPiece(piece, PieceColor::WHITE), positionWhite);
            positionWhite.x++;
        }
        if (!MoveEndGameChecker::isDraw(board)) {
            std::cout << "Failed to detect draw for scenario: " << fst << std::endl;
            return false;
        }
    }
    return true;
}

bool verifyNotDrawDefault() {
    const ChessBoard board(BoardType::DEFAULT_CHESS_BOARD);
    return !MoveEndGameChecker::isDraw(board);
}

int main() {
    assert(verifyDrawCases());
    assert(verifyNotDrawDefault());
}