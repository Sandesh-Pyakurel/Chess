#pragma once

#include "Game.hpp"
#include "DEFINITIONS.hpp"
#include "Piece.hpp"

namespace Chess
{
    class Player
    {
    public:
        Player( GameDataRef data, bool engine, bool isWhite );

        void Draw(  );
    private:
        bool _engine;
        bool _isWhite;
        GameDataRef _data;

        std::vector<Piece*> _pieces;
    };
}
