cmake_minimum_required(VERSION 3.26)
project(Chess_CPP)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)
include_directories(src/pieces)
include_directories(src/pieces/types)
include_directories(src/board)
include_directories(src/utility)

add_executable(Chess_CPP
        src/pieces/types/Bishop.hpp
        src/pieces/types/King.hpp
        src/pieces/types/Knight.hpp
        src/pieces/types/Pawn.hpp
        src/pieces/types/Queen.hpp
        src/pieces/types/Rook.hpp
        src/pieces/Piece.hpp
        src/pieces/PieceFactory.hpp
        src/board/Board.hpp
        src/board/Position.hpp
        src/utility/MoveChecker.hpp
        src/utility/MoveTypes.hpp
        src/utility/MoveValidityChecker.hpp
        src/utility/MoveLegalityChecker.hpp
        src/utility/PositionAttackChecker.hpp
        src/utility/BoardPositionGetter.hpp
        src/pieces/types/Bishop.cpp
        src/pieces/types/King.cpp
        src/pieces/types/Knight.cpp
        src/pieces/types/Pawn.cpp
        src/pieces/types/Queen.cpp
        src/pieces/types/Rook.cpp
        src/pieces/PieceFactory.cpp
        src/board/Board.cpp
        src/board/Position.cpp
        src/utility/MoveChecker.cpp
        src/utility/MoveValidityChecker.cpp
        src/utility/MoveLegalityChecker.cpp
        src/utility/PositionAttackChecker.cpp
        src/utility/BoardPositionGetter.cpp
        main.cpp
)

        
