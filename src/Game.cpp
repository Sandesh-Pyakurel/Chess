#include "Game.hpp"
#include "SplashState.hpp"

namespace Chess
{
    Game::Game( int width, int height, std::string title )
    {
        _data->window.create( sf::VideoMode( width, height ), title, sf::Style::Close | sf::Style::Titlebar );

        _data->machine.AddState( StateRef( new SplashState( this->_data ) ) );

        this->Run(  );

    }

    void Game::Run(  )
    {
        while( this->_data->window.isOpen(  ) )
        {
            this->_data->machine.ProcessingStateChanges(  );
            
            this->_data->machine.GetActiveState(  )->HandleInput(  );
            this->_data->machine.GetActiveState(  )->Update(  );

            this->_data->machine.GetActiveState(  )->Draw(  ); 
        }
    }

}
