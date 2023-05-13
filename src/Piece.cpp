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

    struct Cordinate Piece::getCordinate(  )
    {
        return this->_cord;
    }

    void Piece::setCordinate( struct Cordinate cord )
    {
       this->_cord = cord;
    }

    bool Piece::isCaptured( ) 
    {
        return this->_isCaptured;
    }

    void Piece::setCaptured(  )
    {
        this->_isCaptured = true;
    }

    void Piece::setUnCaputred( )
    {
        this->_isCaptured = false;
    }

    int Piece::getPieceId(  )
    {
        return _pieceId; 
    }

    bool Piece::isWhite(  )
    {
        return _isWhite;
    }

    void Piece::Update(  )
    {
        this->_piece.setPosition( sf::Vector2f( _cord.x, _cord.y ) );
    }

    void Piece::Draw(  )
    {
        if ( !_isCaptured )
        {
            this->_data->window.draw( this->_piece );
        }
    }
}
