#ifndef PIECECONSOLEVIEW_HPP
#define PIECECONSOLEVIEW_HPP
#include "user-interface/human-machine-interface/PieceView.hpp"
#include <iostream>
#include "../lib/termcolor.hpp"

class PieceConsoleView final : public PieceView {
    [[nodiscard]] char getPieceSymbol() const;
public:
    explicit PieceConsoleView(const Piece& piece);

    void drawPiece() override;

    ~PieceConsoleView() override = default;
};



#endif //PIECECONSOLEVIEW_HPP
