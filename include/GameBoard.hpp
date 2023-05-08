#pragma once

#include "DEFINITIONS.hpp"
#include "Game.hpp"
#include "Piece.hpp"
#include <iostream>

#include "SFML/Graphics.hpp"

namespace Chess
{
    class GameBoard
    {
    public:

        GameBoard( GameDataRef data );
        void highlight( std::vector<Cordinate>* moves );
        void removeHighlight(  );

        void Update(  );
        void DrawBoard(  );

    private:
        GameDataRef _data;
        int _highsize;

        sf::RectangleShape _boxes[8][8];
        sf::RectangleShape _highlights[28]; 

    };
}
