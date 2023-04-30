#pragma once

#include "Game.hpp"
#include "DEFINITIONS.hpp"

namespace Chess
{
    struct Cordinate
    {
        int x, y;
    };

    class Piece
    {
    public:
        Piece( GameDataRef data, int pieceId, bool isWhite, std::string name, int x, int y );

        void Draw(  );

    private:

        GameDataRef _data;
        int _pieceId;
        bool _isWhite;
        struct Cordinate _cord;
        bool _isCaptured = false;

        sf::Sprite _piece;
        
    };
}
