#include "Piece.hpp"

namespace Chess
{
    Piece::Piece( GameDataRef data, int pieceId, bool isWhite, std::string name, int x, int y ): _data( data ),  _pieceId( pieceId ), _isWhite( isWhite )
    {
        this->_cord.x = x;
        this->_cord.y = y;
        this->_piece.setTexture( this->_data->assets.GetTexture( name ) );  
        this->_piece.setPosition( sf::Vector2f( _cord.x, _cord.y ) );
    }

    void Piece::Draw(  )
    {
        this->_data->window.draw( this->_piece );
    }
}
