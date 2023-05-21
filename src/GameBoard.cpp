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

        _wpromotionPieces[0].setTexture(_data->assets.GetTexture("White Queen"));
        _wpromotionPieces[1].setTexture(_data->assets.GetTexture("White Rook"));
        _wpromotionPieces[2].setTexture(_data->assets.GetTexture("White Bishop"));
        _wpromotionPieces[3].setTexture(_data->assets.GetTexture("White Knight"));

        for (int i = 0; i < 4; i++)
        {
            sf::RectangleShape ret;
            ret.setSize( sf::Vector2f( 0.6 * BLOCK_SIZE, 0.6 * BLOCK_SIZE));
            ret.setFillColor( sf::Color(240, 222, 232));
            ret.setPosition(sf::Vector2f(BOARD_POSITION_X + (8 * BLOCK_SIZE - 4 * 0.6 * BLOCK_SIZE) / 2 + i * 0.6 * BLOCK_SIZE, BOARD_POSITION_Y - ret.getGlobalBounds().height * 1.2));
            _wpromotionPieces[i].setPosition(sf::Vector2f(BOARD_POSITION_X + (8 * BLOCK_SIZE - 4 * 0.6 * BLOCK_SIZE) / 2 + i * 0.6 * BLOCK_SIZE, BOARD_POSITION_Y - ret.getGlobalBounds().height * 1.2));
            _wpromotionPieces[i].scale(sf::Vector2f(0.6, 0.6));
            _whitePromotion[i] = ret;
        }

        _bpromotionPieces[0].setTexture(_data->assets.GetTexture("Black Queen"));
        _bpromotionPieces[1].setTexture(_data->assets.GetTexture("Black Rook"));
        _bpromotionPieces[2].setTexture(_data->assets.GetTexture("Black Bishop"));
        _bpromotionPieces[3].setTexture(_data->assets.GetTexture("Black Knight"));


        for (int i = 0; i < 4; i++)
        {
            sf::RectangleShape ret;
            ret.setSize( sf::Vector2f( 0.6 * BLOCK_SIZE, 0.6 * BLOCK_SIZE));
            ret.setFillColor( sf::Color(240, 222, 232));
            ret.setPosition(sf::Vector2f(BOARD_POSITION_X + (8 * BLOCK_SIZE - 4 * 0.6 * BLOCK_SIZE) / 2 + i * 0.6 * BLOCK_SIZE, BOARD_POSITION_Y + 8 * BLOCK_SIZE + ret.getGlobalBounds().height * 0.2));
            _bpromotionPieces[i].setPosition(sf::Vector2f(BOARD_POSITION_X + (8 * BLOCK_SIZE - 4 * 0.6 * BLOCK_SIZE) / 2 + i * 0.6 * BLOCK_SIZE, BOARD_POSITION_Y + 8 * BLOCK_SIZE + ret.getGlobalBounds().height * 0.2));
            _bpromotionPieces[i].scale(sf::Vector2f(0.6, 0.6));
            _blackPromotion[i] = ret;
        }
 
    }
    
    void GameBoard::compBlackProm()
    {
        this->_isBlackProm = !_isBlackProm;
    }
    void GameBoard::compWhiteProm()
    {
        this->_isWhiteProm = !_isWhiteProm;
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

        if (_isWhiteProm)
        {
            for (int i = 0; i < 4; i++)
            {
                _data->window.draw(_whitePromotion[i]);
                _data->window.draw(_wpromotionPieces[i]);
            }
        }
        if (_isBlackProm)
        {
            for (int i = 0; i < 4; i++)
            {
                _data->window.draw(_blackPromotion[i]);
                _data->window.draw(_bpromotionPieces[i]);
            }
        }
 
    }
}
