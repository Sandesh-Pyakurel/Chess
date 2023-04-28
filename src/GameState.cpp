#include "GameState.hpp"
#include <iostream>

namespace Chess
{
    GameState::GameState( GameDataRef data ): _data( data )
    {

    }

    void GameState::Init(  )
    {
        _board = std::make_unique<GameBoard>( _data ); 
    }

    void GameState::HandleInput(  )
    {
        sf::Event event;

        while( this->_data->window.pollEvent( event ) )
        {
            if ( sf::Event::Closed == event.type )
            {
                this->_data->window.close(  );  
            }
        }
    }

    void GameState::Update(  )
    {

    }

    void GameState::Draw(  )
    {
        _data->window.clear(  );

        _board->DrawBoard(  );
        
        _data->window.display(  );
    }
}
