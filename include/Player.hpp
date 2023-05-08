#pragma once

#include "Game.hpp"
#include "DEFINITIONS.hpp"
#include "Piece.hpp"

#include <iostream>

namespace Chess
{
    class Player
    {
    public:
        Player( GameDataRef data, bool engine, bool isWhite );

        Piece* pieceClicked( struct Cordinate cord );
        bool canMove( Cordinate cord );
        void removeMoves(  );
        void generateMoves( Piece* clickedPiece );
        std::vector<Cordinate>* getMoves(  );

        void Update(  );
        void Draw(  );
    private:
        bool _engine;
        bool _isWhite;
        GameDataRef _data;

        std::vector<Cordinate> _moves;


        void pawnMoves( Piece* clickedPiece );
    };
}
