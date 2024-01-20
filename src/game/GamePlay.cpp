#include "GamePlay.hpp"

#include "move-validation/MoveEndGameChecker.hpp"
#include "move-validation/MoveTypes.hpp"
#include "move-validation/MoveValidator.hpp"
#include "players/human/PlayerConsoleInput.hpp"

GamePlay::GamePlay(): board(BoardType::DEFAULT_CHESS_BOARD), whitePlayer(std::make_unique<PlayerConsoleInput>()), blackPlayer(std::make_unique<PlayerConsoleInput>()), turnColor(STARTING_TURN_COLOR),
boardView(std::make_unique<ChessBoardConsoleView>(board)) {}

void GamePlay::startGame() {
    GamePlay game;
    while (!game.isGameOver()) {
        game.turn();
        game.nextTurn();
    }
    game.boardView->drawBoard();
    switch (game.getGameState()) {
        case GameState::CHECKMATE:
            std::cout << "Checkmate" << std::endl;
            break;
        case GameState::STALEMATE:
            std::cout << "Stalemate" << std::endl;
            break;
        case GameState::DRAW:
            std::cout << "Draw" << std::endl;
            break;
        default:
            break;
    }
}

GamePlay::GameState GamePlay::getGameState() {
    if (MoveEndGameChecker::isCheckmate(board, turnColor)) {
        return GameState::CHECKMATE;
    }
    if (MoveEndGameChecker::isStalemate(board, turnColor)) {
        return GameState::STALEMATE;
    }
    if (MoveEndGameChecker::isDraw(board)) {
        return GameState::DRAW;
    }
    return GameState::IN_PROGRESS;
}

void GamePlay::turn() {
    std::cout << "Turn: " << (turnColor == PieceColor::WHITE ? "White" : "Black") << std::endl;
    boardView->drawBoard();
    const auto& currentPlayer = turnColor == PieceColor::WHITE ? whitePlayer : blackPlayer;
    std::pair<Position, Position> move;
    bool isMoveValid = false;
    while (!isMoveValid) {
        move = currentPlayer->getMove();
        isMoveValid = MoveChecker::canMove(board, move.first.x, move.first.y, move.second.x, move.second.y, turnColor);
        if (!isMoveValid)
            std::cout << "Invalid move" << std::endl;
    }
    switch (getMoveType(board, move.first.x, move.first.y, move.second.x, move.second.y)) {
        case MoveType::EN_PASSANT:
            board.removePieceAt({move.second.x, move.first.y});
            board.movePiece(move.first, move.second);
            break;
        case MoveType::CASTLING:
            if (move.second.x == 2) {
                board.movePiece({0, move.first.y}, {3, move.first.y});
            } else if (move.second.x == 6) {
                board.movePiece({7, move.first.y}, {5, move.first.y});
            }
            board.movePiece(move.first, move.second);
            break;
        case MoveType::NORMAL:
            board.movePiece(move.first, move.second);
    }
    board.movePiece(move.first, move.second);
    if (canPromotePawn(turnColor)) {
        const auto pieceType = currentPlayer->getPiecePromotionType();
        board.promotePawnTo(pieceType, move.second);
    }
}

bool GamePlay::isGameOver() {
    return getGameState() != GameState::IN_PROGRESS;
}

bool GamePlay::canPromotePawn(const PieceColor color) const {
    int promotionRow = color == PieceColor::WHITE ? ChessBoard::BLACK_PIECES_ROW : ChessBoard::WHITE_PIECES_ROW;
    for (int i = 0; i < Position::MAX_POSITION; ++i) {
        if (board.isPositionOccupied({i, promotionRow})
            && board.getPieceAt({i, promotionRow}).getType() == PieceType::PAWN) {
            return true;
        }
    }
    return false;
}

void GamePlay::nextTurn() {
    turnColor = turnColor == PieceColor::WHITE ? PieceColor::BLACK : PieceColor::WHITE;
}
