cmake_minimum_required(VERSION 3.26)
project(Chess_CPP LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

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
        src/board/ChessBoard.hpp
        src/board/Position.hpp
        src/pieces/types/Bishop.cpp
        src/pieces/types/King.cpp
        src/pieces/types/Knight.cpp
        src/pieces/types/Pawn.cpp
        src/pieces/types/Queen.cpp
        src/pieces/types/Rook.cpp
        src/pieces/Piece.cpp
        src/pieces/PieceFactory.cpp
        src/board/ChessBoard.cpp
        src/board/Position.cpp
        main.cpp
        src/game/GamePlay.cpp
        src/game/GamePlay.hpp
        src/user-interface/human-machine-interface/PieceView.cpp
        src/user-interface/human-machine-interface/PieceView.hpp
        src/user-interface/human-machine-interface/ChessBoardView.cpp
        src/user-interface/human-machine-interface/ChessBoardView.hpp
        src/board/move-validation/MoveValidator.cpp
        src/board/move-validation/MoveValidator.hpp
        src/board/move-validation/MoveTypes.hpp
        src/board/move-validation/PositionAttackChecker.hpp
        src/board/move-validation/PositionAttackChecker.cpp
        src/board/position-getter/BoardPositionGetter.hpp
        src/board/position-getter/BoardPositionGetter.cpp
        src/board/move-validation/MovePossibilityChecker.cpp
        src/board/move-validation/MovePossibilityChecker.hpp
        src/board/move-validation/MoveTypes.cpp
        src/board/move-validation/MoveEndGameChecker.cpp
        src/board/move-validation/MoveEndGameChecker.hpp
        src/board/move-getter/BoardPossibleMoveGetter.cpp
        src/board/move-getter/BoardPossibleMoveGetter.hpp
        src/game/Player.hpp
        src/players/human/PlayerConsoleInput.cpp
        src/players/human/PlayerConsoleInput.hpp
        src/user-interface/text-based-interface/ChessBoardConsoleView.cpp
        src/user-interface/text-based-interface/ChessBoardConsoleView.hpp
        src/user-interface/text-based-interface/PieceConsoleView.cpp
        src/user-interface/text-based-interface/PieceConsoleView.hpp
        src/players/ai/PlayerStupidAI.cpp
        src/players/ai/PlayerStupidAI.hpp
        src/board/move-validation/MoveDirection.hpp
        src/board/move-validation/MoveDirection.cpp
        lib/termcolor/termcolor.hpp
        # test/DrawTest.cpp
)

target_link_libraries(Chess_CPP PRIVATE sfml-graphics)
target_compile_features(Chess_CPP PRIVATE cxx_std_17)

if(WIN32)
    add_custom_command(
            TARGET Chess_CPP
            COMMENT "Copy OpenAL DLL"
            PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:Chess_CPP>
            VERBATIM)
endif()
