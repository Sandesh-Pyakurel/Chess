#include <sstream>

#include "SplashState.hpp"

#include <iostream>

namespace Chess
{
    SplashState::SplashState( GameDataRef data ): _data( data )
    {

    }

    void SplashState::Init(  )
    {
        this->_data->assets.LoadTexture( "Splash State Background", SPLASH_SCENE_BACKGROUND_FILEPATH );

        _background.setTexture( this->_data->assets.GetTexture( "Splash State Background" ) );

        _background.setPosition( this->_data->window.getSize(  ).x / 2 - _background.getLocalBounds(  ).width / 2, this->_data->window.getSize(  ).y / 2 - _background.getGlobalBounds(  ).height / 2 );
    }

    void SplashState::HandleInput(  )
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

    void SplashState::Update(  )
    {
        if ( this->_clock.getElapsedTime(  ).asSeconds(  ) > SPLASH_STATE_SHOW_TIME )
        {
            // Switch to the Main Menu.
        }
    }

    void SplashState::Draw(  )
    {
        this->_data->window.clear( sf::Color::Black );

        this->_data->window.draw( this->_background );

        this->_data->window.display(  );
    }
}
