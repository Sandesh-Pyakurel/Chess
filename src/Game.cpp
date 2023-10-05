#include "Game.hpp"
#include "SplashState.hpp"

namespace Chess
{
    // Window is created, inital state is added and main game loop is entered.
    Game::Game( int width, int height, std::string title )
    {
        _data->window.create( sf::VideoMode( width, height ), title, sf::Style::Close | sf::Style::Titlebar );

        _data->machine.AddState( StateRef( new SplashState( this->_data ) ) );

        _data->window.setFramerateLimit( FPS );

        this->Run(  );

    }

    // Main game loop, here state changes are processed, handleinput, update and draw of the active state is performed.
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
