#include "Player.hpp"

namespace Chess
{
    Player::Player( GameDataRef data, bool engine, bool isWhite ): _data( data ), _engine( engine ), _isWhite( isWhite )
    {
        if ( isWhite )
        {
            _pieces.push_back( new Piece( _data, Pieces::Rook, true, "White Rook", BOARD_POSITION_X, BOARD_POSITION_Y + 7*BLOCK_SIZE ) );
            _pieces.push_back( new Piece( _data, Pieces::Bishop, true, "White Bishop", BOARD_POSITION_X + 1*BLOCK_SIZE, BOARD_POSITION_Y + 7*BLOCK_SIZE ) );
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
