#pragma once

#include "Game.hpp"
#include "DEFINITIONS.hpp"

namespace Chess
{
    struct Cordinate
    {
        int x, y;

        bool operator==( Cordinate c1 )
        {
            return ( x==c1.x && y==c1.y );
        }

        void operator=( Cordinate c1 )
        {
           x=c1.x;
           y=c1.y;
        }
    };

    class Piece
    {
    public:
        Piece( GameDataRef data, int pieceId, bool isWhite, std::string name, int x, int y );

        struct Cordinate getCordinate(  );

        void setCordinate( struct Cordinate cord );
        bool isCaptured(  );
        void setCaptured(  ); 
        void setUnCaputred( );
        int getPieceId(  );
        bool isWhite(  );

        void Update(  );
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
