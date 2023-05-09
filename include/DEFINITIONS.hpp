#pragma once

#define SCREEN_WIDTH 1168
#define SCREEN_HEIGHT 980 

#define FPS 30

#define BLOCK_SIZE 100
#define BOARD_POSITION_X (SCREEN_WIDTH - 8 * BLOCK_SIZE) / 2
#define BOARD_POSITION_Y BLOCK_SIZE

#define SPLASH_STATE_SHOW_TIME 0.5

#define SPLASH_SCENE_BACKGROUND_FILEPATH "Resources/img/SplashScreen.png" 

#define MAIN_MENU_BACKGROUND_FILEPATH "Resources/img/SplashScreen.png"

#define MAIN_MENU_TITLE_PATH "Resources/img/GameTitle.png"

#define MAIN_MENU_PLAY_HUMAN_BUTTON_PATH "Resources/img/PlayHuman10.png"

#define MAIN_MENU_PLAY_COMPUTER_BUTTON_PATH "Resources/img/PlayComputer.png"

#define BLACK_ROOK_FILEPATH "Resources/img/rook.png"
#define BLACK_KNIGHT_FILEPATH "Resources/img/knight.png"
#define BLACK_PAWN_FILEPATH "Resources/img/pawn.png"
#define BLACK_KING_FILEPATH "Resources/img/king.png"
#define BLACK_QUEEN_FILEPATH "Resources/img/queen.png"
#define BLACK_BISHOP_FILEPATH "Resources/img/bishop.png"

#define WHITE_ROOK_FILEPATH "Resources/img/wrook.png"
#define WHITE_KNIGHT_FILEPATH "Resources/img/wknight.png"
#define WHITE_PAWN_FILEPATH "Resources/img/wpawn.png"
#define WHITE_KING_FILEPATH "Resources/img/wking.png"
#define WHITE_QUEEN_FILEPATH "Resources/img/wqueen.png"
#define WHITE_BISHOP_FILEPATH "Resources/img/wbishop.png"


enum Pieces
{
    None = 0,
    King = 1,
    Pawn = 2,
    Knight = 3,
    Bishop = 4,
    Rook = 5,
    Queen = 6,

    White = 8,
    Black = 16

};
