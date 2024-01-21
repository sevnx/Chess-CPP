#include "BoardPossibleMoveGetter.hpp"

std::vector<Position> BoardPossibleMoveGetter::getPossibleMoveForPiece(const ChessBoard& board,
                                                                       const int x,
                                                                       const int y
) {
    switch (const Piece& piece = board.getPieceAt({x, y}); piece.getType()) {
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

std::vector<Position> BoardPossibleMoveGetter::getPossibleMoveForPawn(const ChessBoard& board,
                                                                      const int x,
                                                                      const int y,
                                                                      const Piece& piece
) {
    std::vector<Position> possibleMoves;
    constexpr int DEFAULT_PAWN_MOVE = 1, PAWN_DOUBLE_MOVE = 2;
    const int direction = piece.getColor() == PieceColor::BLACK ? 1 : -1;

    if (Position::isPositionValid(x, y + direction) && !board.isPositionOccupied({x, y + direction}))
        possibleMoves.emplace_back(x, y + direction);
    if (Position::isPositionValid(x + DEFAULT_PAWN_MOVE, y + direction) && board.isPositionOccupied({
            x + DEFAULT_PAWN_MOVE,
            y + direction
        }) && board.getPieceAt({x + DEFAULT_PAWN_MOVE, y + direction}).getColor() != piece.getColor())
        possibleMoves.emplace_back(x + DEFAULT_PAWN_MOVE, y + direction);
    if (Position::isPositionValid(x - DEFAULT_PAWN_MOVE, y + direction) && board.isPositionOccupied({
            x - DEFAULT_PAWN_MOVE,
            y + direction
        }) && board.getPieceAt({x - DEFAULT_PAWN_MOVE, y + direction}).getColor() != piece.getColor())
        possibleMoves.emplace_back(x - DEFAULT_PAWN_MOVE, y + direction);
    if (piece.isFirstMove() && !board.isPositionOccupied({x, y + direction * PAWN_DOUBLE_MOVE}))
        possibleMoves.emplace_back(x, y + direction * PAWN_DOUBLE_MOVE);

    return possibleMoves;
}

std::vector<Position> getPossibleMovesForDirections(const ChessBoard& board,
                                                    int x,
                                                    int y,
                                                    const std::vector<std::pair<int, int>>& directions,
                                                    const Piece& piece
) {
    std::vector<Position> possibleMoves;

    for (auto& [dx, dy] : directions) {
        if (Position::isPositionValid(x + dx, y + dy) && (!board.isPositionOccupied({x + dx, y + dy})
                                                          || board.getPieceAt({x + dx, y + dy}).getColor() != piece.
                                                          getColor())) {
            possibleMoves.emplace_back(x + dx, y + dy);
        }
    }

    return possibleMoves;
}

std::vector<Position> BoardPossibleMoveGetter::getPossibleMoveForRook(const ChessBoard& board,
                                                                      int x,
                                                                      int y,
                                                                      const Piece& piece
) {
    std::vector<Position> possibleMoves;
    const std::vector<std::pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    return getPossibleMovesForDirections(board, x, y, directions, piece);
}

std::vector<Position> BoardPossibleMoveGetter::getPossibleMoveForKnight(const ChessBoard& board,
                                                                        int x,
                                                                        int y,
                                                                        const Piece& piece
) {
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

    for (const auto& [dx,dy] : possibleMovesForKnight) {
        if (Position::isPositionValid(x + dx, y + dy) && (!board.isPositionOccupied({x + dx, y + dy})
                                                          || board.getPieceAt({x + dx, y + dy}).getColor() != piece.
                                                          getColor())) {
            possibleMoves.emplace_back(x + dx, y + dy);
        }
    }

    return possibleMoves;
}

std::vector<Position> BoardPossibleMoveGetter::getPossibleMoveForBishop(const ChessBoard& board,
                                                                        int x,
                                                                        int y,
                                                                        const Piece& piece
) {
    std::vector<Position> possibleMoves;
    const std::vector<std::pair<int, int>> directions = {{1, 1}, {-1, -1}, {-1, 1}, {1, -1}};

    return getPossibleMovesForDirections(board, x, y, directions, piece);
}

std::vector<Position> BoardPossibleMoveGetter::getPossibleMoveForQueen(const ChessBoard& board,
                                                                       int x,
                                                                       int y,
                                                                       const Piece& piece
) {
    auto moveForBishop = getPossibleMoveForBishop(board, x, y, piece);
    auto moveForRook = getPossibleMoveForRook(board, x, y, piece);

    moveForBishop.insert(moveForBishop.end(), moveForRook.begin(), moveForRook.end());

    return moveForBishop;
}

std::vector<Position> BoardPossibleMoveGetter::getPossibleMoveForKing(const ChessBoard& board,
                                                                      int x,
                                                                      int y,
                                                                      const Piece& piece
) {
    std::vector<Position> possibleMoves;
    std::vector<std::pair<int, int>> possibleMovesKing;
    constexpr int KING_MOVE = 1;

    for (int i = -KING_MOVE + x; i <= KING_MOVE + x; ++i) {
        for (int j = -KING_MOVE + y; j <= KING_MOVE + y; ++j)
            possibleMovesKing.emplace_back(i, j);
    }

    for (auto& [x, y] : possibleMovesKing) {
        if (Position::isPositionValid(x, y) &&
            (!board.isPositionOccupied({x, y}) || board.getPieceAt({x, y}).getColor() != piece.getColor()))
            possibleMoves.emplace_back(x, y);
    }

    return possibleMoves;
}

std::vector<std::pair<Position, Position>> BoardPossibleMoveGetter::getPossibleMoves(
    const ChessBoard& board,
    const PieceColor color
) {
    std::vector<std::pair<Position, Position>> possibleMoves;
    const BoardPositionGetter positionGetter(board);

    for (auto& piecePosition : positionGetter.getPiecesPositions(color)) {
        for (auto& move : getPossibleMoveForPiece(board, piecePosition.x, piecePosition.y))
            possibleMoves.emplace_back(piecePosition, move);
    }

    return possibleMoves;
}
