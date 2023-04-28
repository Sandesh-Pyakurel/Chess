#include "MainMenuState.hpp"
#include <sstream>
#include "DEFINITIONS.hpp"

#include <iostream>

namespace Chess
{
    MainMenuState::MainMenuState( GameDataRef data ): _data( data )
    {

    }

    void MainMenuState::Init(  )
    {
        this->_data->assets.LoadTexture( "Main Menu Background", MAIN_MENU_BACKGROUND_FILEPATH );
        this->_data->assets.LoadTexture( "Play 10", MAIN_MENU_PLAY_HUMAN_BUTTON_PATH );
        this->_data->assets.LoadTexture( "Play Computer", MAIN_MENU_PLAY_COMPUTER_BUTTON_PATH );
        this->_data->assets.LoadTexture( "Main Menu Title", MAIN_MENU_TITLE_PATH );


        this->_background.setTexture( this->_data->assets.GetTexture( "Main Menu Background" ) );
        this->_playHuman10Button.setTexture( this->_data->assets.GetTexture( "Play 10" ) );
        this->_playComputerButton.setTexture( this->_data->assets.GetTexture( "Play Computer" ) );
        this->_title.setTexture( this->_data->assets.GetTexture( "Main Menu Title" ) );


        this->_background.setPosition( this->_data->window.getSize(  ).x / 2 - _background.getLocalBounds(  ).width / 2, this->_data->window.getSize(  ).y / 2 - _background.getGlobalBounds(  ).height / 2 );
        this->_title.setPosition( SCREEN_WIDTH / 2 - this->_title.getGlobalBounds(  ).width / 2, 0 );
        this->_playComputerButton.setPosition( SCREEN_WIDTH / 2 - this->_playComputerButton.getGlobalBounds(  ).width / 2, SCREEN_HEIGHT / 2 + this->_playComputerButton.getGlobalBounds(  ).height / 2 );
        this->_playHuman10Button.setPosition( SCREEN_WIDTH / 2 - this->_playHuman10Button.getGlobalBounds(  ).width / 2, this->_playComputerButton.getPosition(  ).y + this->_playComputerButton.getGlobalBounds(  ).height + this->_playHuman10Button.getGlobalBounds(  ).height / 2 ); 
    }
    
    void MainMenuState::HandleInput(  )
    {
        sf::Event event;

        while( this->_data->window.pollEvent( event ) )
        {
            if ( sf::Event::Closed == event.type )
            {
                this->_data->window.close(  );
            }
            if ( this->_data->input.IsSpriteClicked( this->_playHuman10Button, sf::Mouse::Left, this->_data->window ) )
            {
                std::cout << "hello.\n"; 
                this->_data->machine.AddState( StateRef( new GameState( _data ) ), true ); 
            }
        }
    }

    void MainMenuState::Update(  )
    {

    }

    void MainMenuState::Draw(  )
    {
        this->_data->window.clear(  );
        
        this->_data->window.draw( this->_background );
        this->_data->window.draw( this->_title );
        this->_data->window.draw(this->_playComputerButton );
        this->_data->window.draw( this->_playHuman10Button );

        this->_data->window.display(  );
    }
}
