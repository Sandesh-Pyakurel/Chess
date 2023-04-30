#include "Player.hpp"

namespace Chess
{
    Player::Player( GameDataRef data, bool engine, bool isWhite ): _data( data ), _engine( engine ), _isWhite( isWhite )
    {
        if ( isWhite )
        {
            _pieces.push_back( new Piece( _data, Pieces::Rook, true, "White Rook", BOARD_POSITION_X, BOARD_POSITION_Y + 7*BLOCK_SIZE ) );
            _pieces.push_back( new Piece( _data, Pieces::Knight, true, "White Knight", BOARD_POSITION_X + 1*BLOCK_SIZE, BOARD_POSITION_Y + 7*BLOCK_SIZE ) );
            _pieces.push_back( new Piece( _data, Pieces::Bishop, true, "White Bishop", BOARD_POSITION_X + 2*BLOCK_SIZE, BOARD_POSITION_Y + 7*BLOCK_SIZE ) );
            _pieces.push_back( new Piece( _data, Pieces::Queen, true, "White Queen", BOARD_POSITION_X + 3*BLOCK_SIZE, BOARD_POSITION_Y + 7*BLOCK_SIZE ) );
            _pieces.push_back( new Piece( _data, Pieces::King, true, "White King", BOARD_POSITION_X + 4*BLOCK_SIZE, BOARD_POSITION_Y + 7*BLOCK_SIZE ) );
            _pieces.push_back( new Piece( _data, Pieces::Bishop, true, "White Bishop", BOARD_POSITION_X + 5*BLOCK_SIZE, BOARD_POSITION_Y + 7*BLOCK_SIZE ) );
            _pieces.push_back( new Piece( _data, Pieces::Knight, true, "White Knight", BOARD_POSITION_X + 6*BLOCK_SIZE, BOARD_POSITION_Y + 7*BLOCK_SIZE ) );
            _pieces.push_back( new Piece( _data, Pieces::Rook, true, "White Rook", BOARD_POSITION_X + 7*BLOCK_SIZE, BOARD_POSITION_Y + 7*BLOCK_SIZE ) );


            for ( int i = 0;i < 8;i++ )
            {

                _pieces.push_back( new Piece( _data, Pieces::Pawn, true, "White Pawn", BOARD_POSITION_X + i*BLOCK_SIZE, BOARD_POSITION_Y + 6*BLOCK_SIZE ) );

            }



        }
        else
        {
                _pieces.push_back( new Piece( _data, Pieces::Rook, false, "Black Rook", BOARD_POSITION_X, BOARD_POSITION_Y + 0*BLOCK_SIZE ) );
                _pieces.push_back( new Piece( _data, Pieces::Knight, false, "Black Knight", BOARD_POSITION_X + 1*BLOCK_SIZE, BOARD_POSITION_Y + 0*BLOCK_SIZE ) );
                _pieces.push_back( new Piece( _data, Pieces::Bishop, false, "Black Bishop", BOARD_POSITION_X + 2*BLOCK_SIZE, BOARD_POSITION_Y + 0*BLOCK_SIZE ) );
                _pieces.push_back( new Piece( _data, Pieces::Queen, false, "Black Queen", BOARD_POSITION_X + 3*BLOCK_SIZE, BOARD_POSITION_Y + 0*BLOCK_SIZE ) );
                _pieces.push_back( new Piece( _data, Pieces::King, false, "Black King", BOARD_POSITION_X + 4*BLOCK_SIZE, BOARD_POSITION_Y + 0*BLOCK_SIZE ) );
                _pieces.push_back( new Piece( _data, Pieces::Bishop, false, "Black Bishop", BOARD_POSITION_X + 5*BLOCK_SIZE, BOARD_POSITION_Y + 0*BLOCK_SIZE ) );
                _pieces.push_back( new Piece( _data, Pieces::Knight, false, "Black Knight", BOARD_POSITION_X + 6*BLOCK_SIZE, BOARD_POSITION_Y + 0*BLOCK_SIZE ) );
                _pieces.push_back( new Piece( _data, Pieces::Rook, false, "Black Rook", BOARD_POSITION_X + 7*BLOCK_SIZE, BOARD_POSITION_Y + 0*BLOCK_SIZE ) );
    
    
                for ( int i = 0;i < 8;i++ )
                {
    
                    _pieces.push_back( new Piece( _data, Pieces::Pawn, false, "Black Pawn", BOARD_POSITION_X + i*BLOCK_SIZE, BOARD_POSITION_Y + 1*BLOCK_SIZE ) );
    
                }
        }
    }

    Piece* Player::pieceClicked( struct Cordinate cord )
    {
        for ( int i = 0; i < _pieces.size(  ); i++ )
        {
            if ( ( _pieces.at( i )->getCordinate(  ) == cord ) )
            {
                return _pieces.at( i );
            }
        }
        return nullptr;
    }

    void Player::Update(  )
    {
        for ( int i = 0; i < _pieces.size(  ); i++ )
        {
            _pieces.at( i )->Update(  );
        }
    }

    void Player::Draw(  )
    {
        for ( int i = 0; i < _pieces.size(  ); i++ )
        {
            _pieces.at( i )->Draw(  );
        }
    }
}
