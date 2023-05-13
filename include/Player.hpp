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

        Piece* pieceClickedWhite( struct Cordinate cord );
        Piece* pieceClickedBlack( struct Cordinate cord );
        bool canMove( Cordinate cord );
        void removeMoves(  );
        void generateMoves( Piece* clickedPiece );
        void filterLegalMoves( Piece* clickedPiece );
        std::vector<Cordinate>* getMoves(  );
        bool isPieceAtWhite( Cordinate cord );
        bool isPieceAtBlack( Cordinate cord );
        void setIsWhite( );

        void Update(  );
        void Draw(  );
    private:
        bool _engine;
        bool _isWhite;
        bool _removeCaptured;
        Piece* _tempPiece;
        GameDataRef _data;

        std::vector<Cordinate> _moves;
        std::vector<Cordinate> _tempmoves;

        void pawnMoves( Piece* clickedPiece );
        void bishopMoves( Piece* clickedPiece );
        void rookMoves( Piece* clickedPiece );
        void KnightMoves( Piece* clickedPiece );
        void kingMoves( Piece* clickedPiece );

        void removePiece( Piece* piece );
        void restorePiece(  );

        Cordinate getKingPosition( );
        

        bool isAtCheck( Cordinate kingcord );
    };
}
