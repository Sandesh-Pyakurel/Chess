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
        _player2 = std::make_unique<Player>( _data, false, false );

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

            if ( sf::Mouse::isButtonPressed( sf::Mouse::Left ) )
            {
                int mouse_x = sf::Mouse::getPosition( _data->window ).x;
                int mouse_y = sf::Mouse::getPosition( _data->window ).y;

                if(((mouse_x >= BOARD_POSITION_X) && (mouse_x <= BOARD_POSITION_X + 8*BLOCK_SIZE )) && ( (mouse_y >= BOARD_POSITION_Y) && (mouse_y <= BOARD_POSITION_Y + 8*BLOCK_SIZE )))
                {
                    struct Cordinate cord;
                                                                               
                    cord.x =(( mouse_x - BOARD_POSITION_X ) / BLOCK_SIZE) * BLOCK_SIZE + BOARD_POSITION_X;
                    cord.y =(( mouse_y - BOARD_POSITION_Y ) / BLOCK_SIZE) * BLOCK_SIZE + BOARD_POSITION_Y;

                    if ( _clickedPiece )
                    {
                        _clickedPiece->setCordinate( cord );
                        _clickedPiece = nullptr;
                    }
                    else
                    {
                         if ( _isWhiteTurn )
                         {
                             _clickedPiece = _player1->pieceClicked( cord );
                         }
                         else
                         {
                             _clickedPiece = _player2->pieceClicked( cord );
                         }
                         if( _clickedPiece )
                         {

                         }
                    
                    }
                }
            }
        }
    }

    void GameState::Update(  )
    {
        _player1->Update(  );
        _player2->Update(  );
    }

    void GameState::Draw(  )
    {
        _data->window.clear(  );

        _board->DrawBoard(  );
        _player1->Draw(  );
        _player2->Draw(  );
        
        _data->window.display(  );
    }
}
