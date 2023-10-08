#include <iostream>
#include "src/board/Board.h"

int main(){
    Board board(DEFAULT_CHESS_BOARD);
    for (int i = 0; i<8; i++){
        for (int j = 0; j<8; j++){
            std::cout << board.isPositionOccupied(j, i) << " ";
        }
        std::cout << std::endl;
    }
}
 