#ifndef PIECECONSOLEVIEW_HPP
#define PIECECONSOLEVIEW_HPP
#include "user-interface/human-machine-interface/PieceView.hpp"
#include <iostream>

class PieceConsoleView final : public PieceView {
    [[nodiscard]] char getPieceSymbol() const;
public:
    explicit PieceConsoleView(const Piece& piece);

    void drawPiece() override;

    ~PieceConsoleView() override = default;
};



#endif //PIECECONSOLEVIEW_HPP
