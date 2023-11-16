#include "BoardPossibleMoveGetter.hpp"

std::vector<Position> BoardPossibleMoveGetter::getPossibleMoveForPiece(const ChessBoard& board, const int x, const int y, const Piece& piece) {
    switch (piece.getType()) {
        case PieceType::PAWN:
            return getPossibleMoveForPawn(board, x, y, piece);
        case PieceType::ROOK:
            return getPossibleMoveForRook(board, x, y, piece);
        case PieceType::KNIGHT:
            return getPossibleMoveForKnight(board, x, y, piece);
        case PieceType::BISHOP_BLACK:
        case PieceType::BISHOP_WHITE:
            return getPossibleMoveForBishop(board, x, y, piece);
        case PieceType::QUEEN:
            return getPossibleMoveForQueen(board, x, y, piece);
        case PieceType::KING:
            return getPossibleMoveForKing(board, x, y, piece);
        default:
            throw std::runtime_error("Unknown piece type");
    }
}

std::vector<Position> BoardPossibleMoveGetter::getPossibleMoveForPawn(const ChessBoard &board, int x, int y, const Piece& piece) {
    std::vector<Position> possibleMoves;
    constexpr int DEFAULT_PAWN_MOVE = 1, PAWN_DOUBLE_MOVE = 2;
    const int direction = piece.getColor() == PieceColor::WHITE ? 1 : -1;
    if (!board.isPositionOccupied({x, y + direction}))
        possibleMoves.emplace_back(x, y + direction);
    if (board.isPositionOccupied({x + DEFAULT_PAWN_MOVE, y + direction}))
        possibleMoves.emplace_back(x + DEFAULT_PAWN_MOVE, y + direction);
    if (board.isPositionOccupied({x - DEFAULT_PAWN_MOVE, y + direction}))
        possibleMoves.emplace_back(x - DEFAULT_PAWN_MOVE, y + direction);
    if (piece.isFirstMove() && !board.isPositionOccupied({x, y + direction * PAWN_DOUBLE_MOVE}))
        possibleMoves.emplace_back(x, y + direction * PAWN_DOUBLE_MOVE);
    return possibleMoves;
}

std::vector<Position> BoardPossibleMoveGetter::getPossibleMoveForRook(const ChessBoard& board, int x, int y, const Piece& piece) {
    std::vector<Position> possibleMoves;
    for (int i = x; i < Position::MAX_POSITION; ++i) {
        if (board.isPositionOccupied({i, y})) {
            if (board.getPieceAt({i, y}).getColor() != piece.getColor())
                possibleMoves.emplace_back(i, y);
            break;
        }
        possibleMoves.emplace_back(i, y);
    }
    for (int i = x; i >= 0; --i) {
        if (board.isPositionOccupied({i, y})) {
            if (board.getPieceAt({i, y}).getColor() != piece.getColor())
                possibleMoves.emplace_back(i, y);
            break;
        }
        possibleMoves.emplace_back(i, y);
    }
    for (int i = y; i < Position::MAX_POSITION; ++i) {
        if (board.isPositionOccupied({x, i})) {
            if (board.getPieceAt({x, i}).getColor() != piece.getColor())
                possibleMoves.emplace_back(x, i);
            break;
        }
        possibleMoves.emplace_back(x, i);
    }
    for (int i = y; i >= 0; --i) {
        if (board.isPositionOccupied({x, i})) {
            if (board.getPieceAt({x, i}).getColor() != piece.getColor())
                possibleMoves.emplace_back(x, i);
            break;
        }
        possibleMoves.emplace_back(x, i);
    }
    return possibleMoves;
}

std::vector<Position> BoardPossibleMoveGetter::getPossibleMoveForKnight(const ChessBoard& board, int x, int y, const Piece& piece) {
    std::vector<Position> possibleMoves;
    std::array<std::pair<int, int>, 8> possibleMovesForKnight = {
            std::make_pair(1, 2),
            std::make_pair(2, 1),
            std::make_pair(2, -1),
            std::make_pair(1, -2),
            std::make_pair(-1, -2),
            std::make_pair(-2, -1),
            std::make_pair(-2, 1),
            std::make_pair(-1, 2)
    };
    for (const auto&[x,y] : possibleMovesForKnight) {
        if (Position::isPositionValid(x, y)) {
            if (board.isPositionOccupied({x, y})) {
                if (board.getPieceAt({x, y}).getColor() != piece.getColor())
                    possibleMoves.emplace_back(x, y);
            } else
                possibleMoves.emplace_back(x, y);
        }
    }
    return possibleMoves;
}

std::vector<Position> BoardPossibleMoveGetter::getPossibleMoveForBishop(const ChessBoard& board, int x, int y, const Piece& piece) {
    std::vector<Position> possibleMoves;
    const int direction = piece.getColor() == PieceColor::WHITE ? 1 : -1;
    for (int i = x, j = y; i < Position::MAX_POSITION && j < Position::MAX_POSITION; ++i, ++j) {
        if (board.isPositionOccupied({i, j})) {
            if (board.getPieceAt({i, j}).getColor() != piece.getColor())
                possibleMoves.emplace_back(i, j);
            break;
        }
        possibleMoves.emplace_back(i, j);
    }
    for (int i = x, j = y; i >= 0 && j >= 0; --i, --j) {
        if (board.isPositionOccupied({i, j})) {
            if (board.getPieceAt({i, j}).getColor() != piece.getColor())
                possibleMoves.emplace_back(i, j);
            break;
        }
        possibleMoves.emplace_back(i, j);
    }
    for (int i = x, j = y; i >= 0 && j < Position::MAX_POSITION; --i, ++j) {
        if (board.isPositionOccupied({i, j})) {
            if (board.getPieceAt({i, j}).getColor() != piece.getColor())
                possibleMoves.emplace_back(i, j);
            break;
        }
        possibleMoves.emplace_back(i, j);
    }
    for (int i = x, j = y; i < Position::MAX_POSITION && j >= 0; ++i, --j) {
        if (board.isPositionOccupied({i, j})) {
            if (board.getPieceAt({i, j}).getColor() != piece.getColor())
                possibleMoves.emplace_back(i, j);
            break;
        }
        possibleMoves.emplace_back(i, j);
    }
    return possibleMoves;
}

std::vector<Position> BoardPossibleMoveGetter::getPossibleMoveForQueen(const ChessBoard& board, int x, int y, const Piece& piece) {
    auto moveForBishop = getPossibleMoveForBishop(board, x, y, piece);
    auto moveForRook = getPossibleMoveForRook(board, x, y, piece);
    auto moves = std::move(moveForBishop);
    moves.insert(moves.end(), moveForRook.begin(), moveForRook.end());
    return moveForBishop;
}

std::vector<Position> BoardPossibleMoveGetter::getPossibleMoveForKing(const ChessBoard& board, int x, int y, const Piece& piece) {
    std::vector<Position> possibleMoves;
    std::vector<std::pair<int,int>> possibleMovesKing;
    constexpr int KING_MOVE = 1;
    for (int i = -KING_MOVE; i <= KING_MOVE; ++i)
        for (int j = -KING_MOVE; j <= KING_MOVE; ++j)
            possibleMovesKing.emplace_back(i, j);

    for (auto& [x, y] : possibleMovesKing) {
        if (Position::isPositionValid(x, y)) {
            if (board.isPositionOccupied({x, y})) {
                if (board.getPieceAt({x, y}).getColor() != piece.getColor())
                    possibleMoves.emplace_back(x, y);
            } else
                possibleMoves.emplace_back(x, y);
        }
    }
    return possibleMoves;
}

std::vector<std::pair<Position, Position>> BoardPossibleMoveGetter::getPossibleMoves(const ChessBoard &board, const PieceColor color) {
    std::vector<std::pair<Position, Position>> possibleMoves;
    const BoardPositionGetter positionGetter(board);
    for (auto &piecePosition : positionGetter.getPiecesPositions(color))
        for (auto &move : getPossibleMoveForPiece(board, piecePosition.x, piecePosition.y))
            possibleMoves.emplace_back(piecePosition, move);
    return possibleMoves;
}

std::vector<Position> BoardPossibleMoveGetter::getPossibleMoveForPiece(const ChessBoard &board, int x, int y) {
    const Piece piece = board.getPieceAt({x, y});
    return getPossibleMoveForPiece(board, x, y, piece);
}
