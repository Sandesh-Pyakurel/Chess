#pragma once

#include "State.hpp"
#include "Game.hpp"
#include "GameBoard.hpp"

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
   };
}
