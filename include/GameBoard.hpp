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
        void compBlackProm();
        void compWhiteProm();

        void Update(  );
        void DrawBoard(  );

    private:
        GameDataRef _data;
        int _highsize;

        bool _isBlackProm = false;
        bool _isWhiteProm = false;

        sf::RectangleShape _boxes[8][8];
        sf::RectangleShape _highlights[28]; 
        sf::RectangleShape _blackPromotion[4];
        sf::RectangleShape _whitePromotion[4];

        sf::Sprite _bpromotionPieces[4];
        sf::Sprite _wpromotionPieces[4];

    };
}
