#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"
#include "GameState.hpp"

namespace Chess
{
    class MainMenuState : public State
    {
    public:
        MainMenuState( GameDataRef data );

        void Init(  );

        void HandleInput(  );

        void Update(  );

        void Draw(  );
    
    private:
        GameDataRef _data;

        sf::Sprite _background;
        sf::Sprite _playHuman10Button;
        sf::Sprite _playComputerButton;
        sf::Sprite _title;
    };
}
