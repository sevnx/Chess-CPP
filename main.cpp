#include <iostream>
#include "Board.h"

/*
addPiece(PieceFactory::createPiece(*iter, WHITE), i, WHITE_PIECES_ROW);
addPiece(PieceFactory::createPiece(*iter, BLACK), i, BLACK_PIECES_ROW);
addPiece(PieceFactory::createPiece(PAWN, WHITE), i, PAWN_ROW);
addPiece(PieceFactory::createPiece(PAWN, BLACK), i, BLACK_PAWN_ROW);
removePieceAt(i, PAWN_ROW);
removePieceAt(i, BLACK_PAWN_ROW);
removePieceAt(i, WHITE_PIECES_ROW);
removePieceAt(i, BLACK_PIECES_ROW);
addPiece(PieceFactory::createPiece(*iter, WHITE), i, WHITE_PIECES_ROW);
addPiece(PieceFactory::createPiece(*iter, BLACK), i, BLACK_PIECES_ROW);
addPiece(PieceFactory::createPiece(PAWN, WHITE), i, PAWN_ROW);
addPiece(PieceFactory::createPiece(PAWN, BLACK), i, BLACK_PAWN_ROW);
movePiece(i, PAWN_ROW, i, PAWN_ROW);
movePiece(i, BLACK_PAWN_ROW, i, BLACK_PAWN_ROW);
movePiece(i, WHITE_PIECES_ROW, i, WHITE_PIECES_ROW);
movePiece(i, BLACK_PIECES_ROW, i, BLACK_PIECES_ROW);
 */

int main(){
    Board board(DEFAULT_CHESS_BOARD);
    for (int i = 0; i<8; i++){
        for (int j = 0; j<8; j++){
            std::cout << board.isPositionOccupied(j, i) << " ";
        }
        std::cout << std::endl;
    }
}
 