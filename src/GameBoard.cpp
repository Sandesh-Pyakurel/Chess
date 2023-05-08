#include "GameBoard.hpp"
#include "DEFINITIONS.hpp"


namespace Chess
{
    GameBoard::GameBoard( GameDataRef data ): _data( data )
    {
        _highsize = 0;
        for ( int rank = 0; rank < 8; rank++ )
        {
            for ( int file = 0; file < 8; file++ )
            {
                _boxes[rank][file].setSize( sf::Vector2f( BLOCK_SIZE, BLOCK_SIZE ) );
                _boxes[rank][file].setPosition( BOARD_POSITION_X + file * BLOCK_SIZE, BOARD_POSITION_Y + rank * BLOCK_SIZE );

                if ( ( rank + file ) % 2 == 0 )
                {
                    _boxes[rank][file].setFillColor( sf::Color{ 255, 240, 255 } ); 
                }
                else
                {
                    _boxes[rank][file].setFillColor( sf::Color{ 218, 160, 109 } );
                }
            }
        }
        
        for ( int i = 0; i < 28; i++ )
        {
            sf::RectangleShape ret;
            ret.setSize( sf::Vector2f( BLOCK_SIZE, BLOCK_SIZE ) );
            ret.setFillColor( sf::Color{ 240, 0, 0, 90 } );
            _highlights[i] = ret;
        }       
    }

    void GameBoard::highlight( std::vector<Cordinate>* moves )
    {
        _highsize = moves->size(  );
        for ( int i=0; i<moves->size(); i++ )
        {
            _highlights[i].setPosition( moves->at( i ).x, moves->at( i ).y );
        }
    }

    void GameBoard::removeHighlight(  )
    {
        _highsize = 0;   
    }

    void GameBoard::Update(  )
    {

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

        for ( int i = 0; i < _highsize; i++ )
        {
            _data->window.draw( _highlights[i] );
        }
    }
}
