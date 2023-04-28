#pragma once

#include "DEFINITIONS.hpp"
#include "Game.hpp"

#include "SFML/Graphics.hpp"

namespace Chess
{
    class GameBoard
    {
    public:

        GameBoard( GameDataRef data );

        void DrawBoard(  );

    private:
        GameDataRef _data;

        sf::RectangleShape _boxes[8][8];
    };
}
