#include "GamePlay.hpp"

#include "../board/move-validation/MoveStatusChecker.hpp"
#include "move-validation/MoveTypes.hpp"
#include "move-validation/MoveValidator.hpp"
#include "players/ai/PlayerSmartAI.hpp"
#include "players/ai/PlayerStupidAI.hpp"
#include "players/human/PlayerConsoleInput.hpp"

GamePlay::GamePlay(): board(BoardType::DEFAULT_CHESS_BOARD)
                      , boardView(std::make_unique<ChessBoardConsoleView>(board))
                      , whitePlayer(std::make_unique<PlayerSmartAI>(board, PieceColor::WHITE))
                      , blackPlayer(std::make_unique<PlayerStupidAI>(board, PieceColor::BLACK))
                      , turnColor(STARTING_TURN_COLOR) {
}

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

GamePlay::GameState GamePlay::getGameState() const {
    if (MoveStatusChecker::isCheckmate(board, turnColor)) {
        return GameState::CHECKMATE;
    }
    if (MoveStatusChecker::isStalemate(board, turnColor)) {
        return GameState::STALEMATE;
    }
    if (MoveStatusChecker::isDraw(board)) {
        return GameState::DRAW;
    }
    return GameState::IN_PROGRESS;
}

void GamePlay::turn() {
    std::cout << "Turn: " << (turnColor == PieceColor::WHITE ? "White" : "Black") << std::endl;
    boardView->drawBoard();
    const auto&currentPlayer = turnColor == PieceColor::WHITE ? whitePlayer : blackPlayer;
    std::pair<Position, Position> move;
    bool isMoveValid = false;
    while (!isMoveValid) {
        move = currentPlayer->getMove();
        const MoveStatus moveStatus = MoveChecker::canMove(board, move.first.x, move.first.y, move.second.x,
                                                           move.second.y, turnColor);
        boardView->displayMoveStatus(moveStatus);
        isMoveValid = moveStatus == MoveStatus::VALID;
    }
    executeMove(move);
}

void GamePlay::executeMove(const std::pair<Position, Position>&move) {
    const int castlingOffset = move.second.x > move.first.x ? -1 : 1;
    switch (ExistingMoveChecker::getMoveType(board, move.first.x, move.first.y, move.second.x, move.second.y)) {
        case MoveType::EN_PASSANT:
            board.removePieceAt({move.second.x, move.first.y});
            board.movePiece(move.first, move.second);
            break;
        case MoveType::CASTLING:
            board.movePiece({move.second.x == 0 ? 0 : 7, move.first.y}, {move.second.x == 0 ? 3 : 5, move.first.y});
            board.movePiece(move.first, {move.second.x + castlingOffset, move.second.y});
            break;
        case MoveType::NORMAL:
            board.movePiece(move.first, move.second);
            break;
    }
    if (canPromotePawn(turnColor)) {
        const auto pieceType = (turnColor == PieceColor::WHITE ? whitePlayer : blackPlayer)->getPiecePromotionType();
        board.promotePawnTo(pieceType, move.second);
    }
}

bool GamePlay::isGameOver() const {
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
