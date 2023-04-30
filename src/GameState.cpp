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

        this->_data->assets.LoadTexture( "Black Pawn", BLACK_PAWN_FILEPATH );
        this->_data->assets.LoadTexture( "Black Rook", BLACK_ROOK_FILEPATH );
        this->_data->assets.LoadTexture( "Black Bishop", BLACK_BISHOP_FILEPATH );
        this->_data->assets.LoadTexture( "Black Knight", BLACK_KNIGHT_FILEPATH );
        this->_data->assets.LoadTexture( "Black King", BLACK_KING_FILEPATH );
        this->_data->assets.LoadTexture( "Black Queen", BLACK_QUEEN_FILEPATH );

                
        this->_data->assets.LoadTexture( "White Pawn", WHITE_PAWN_FILEPATH );
        this->_data->assets.LoadTexture( "White Rook", WHITE_ROOK_FILEPATH );
        this->_data->assets.LoadTexture( "White Bishop", WHITE_BISHOP_FILEPATH );
        this->_data->assets.LoadTexture( "White Knight", WHITE_KNIGHT_FILEPATH );
        this->_data->assets.LoadTexture( "White King", WHITE_KING_FILEPATH );
        this->_data->assets.LoadTexture( "White Queen", WHITE_QUEEN_FILEPATH );

       _player1 = std::make_unique<Player>( _data, false, true ); 

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
        _player1->Draw(  );
        
        _data->window.display(  );
    }
}
