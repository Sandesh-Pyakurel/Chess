#pragma once

#include "State.hpp"
#include "Game.hpp"
#include "GameBoard.hpp"
#include "Player.hpp"
#include "Piece.hpp"

namespace Chess
{
    class GameState : public State
    {
    public:
        GameState( GameDataRef data );
        
        void Init(  );

        void HandleInput(  );

        void Update(  );
        void Draw(  );

    private:
        GameDataRef _data;

        std::unique_ptr<GameBoard> _board;
        
        std::unique_ptr<Player> _player1;
        std::unique_ptr<Player> _player2;

        Piece* _clickedPiece = nullptr;

        bool _isWhiteTurn = true;
   };
}
