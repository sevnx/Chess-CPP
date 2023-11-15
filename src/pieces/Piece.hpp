#ifndef CHESS_CPP_PIECE_H
#define CHESS_CPP_PIECE_H

enum class PieceColor {
    BLACK, WHITE
};

enum class PieceType {
    PAWN, ROOK, KNIGHT, BISHOP_BLACK, BISHOP_WHITE, QUEEN, KING, NONE
};

class Piece {
private:
    PieceColor color;
    PieceType type;
    unsigned int value;
    unsigned int moveCount;
protected:
    Piece(PieceColor color, PieceType type, unsigned int value);

public:
    [[nodiscard]] PieceColor getColor() const;

    [[nodiscard]] PieceType getType() const;

    [[nodiscard]] unsigned int getValue() const;

    [[nodiscard]] unsigned int getMoveCount() const;

    [[nodiscard]] bool isFirstMove() const;

    void incrementMoveCount();

    virtual bool operator==(const Piece &other) const;

    virtual ~Piece() = default;
};

#endif //CHESS_CPP_PIECE_H
