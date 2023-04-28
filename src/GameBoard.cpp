#include "GameBoard.hpp"
#include "DEFINITIONS.hpp"


namespace Chess
{
    GameBoard::GameBoard( GameDataRef data ): _data( data )
    {
        for ( int rank = 0; rank < 8; rank++ )
        {
            for ( int file = 0; file < 8; file++ )
            {
                _boxes[rank][file].setSize( sf::Vector2f( BLOCK_SIZE, BLOCK_SIZE ) );
                _boxes[rank][file].setPosition( BOARD_POSITION_X + file * BLOCK_SIZE, BOARD_POSITION_Y + rank * BLOCK_SIZE );

                if ( ( rank + file ) % 2 == 0 )
                {
                    _boxes[rank][file].setFillColor( sf::Color::White ); 
                }
                else
                {
                    _boxes[rank][file].setFillColor( sf::Color::Green );
                }
            }
        }
    }

    void GameBoard::DrawBoard(  )
    {
        for ( int rank = 0; rank < 8; rank++ )
        {
            for ( int file = 0; file < 8; file++ )
            {
                _data->window.draw( _boxes[rank][file] ); 
            }
        }
    }
}
