#include "Player.hpp"

namespace Chess
{
    std::vector<Piece*> _pieces;
    
    Player::Player(GameDataRef data, bool engine, bool isWhite) : _data(data), _engine(engine), _isWhite(isWhite)
    {
        if (isWhite)
        {
            _pieces.push_back(new Piece(_data, Pieces::Rook, true, "White Rook", BOARD_POSITION_X, BOARD_POSITION_Y + 7 * BLOCK_SIZE));
            _pieces.push_back(new Piece(_data, Pieces::Knight, true, "White Knight", BOARD_POSITION_X + 1 * BLOCK_SIZE, BOARD_POSITION_Y + 7 * BLOCK_SIZE));
            _pieces.push_back(new Piece(_data, Pieces::Bishop, true, "White Bishop", BOARD_POSITION_X + 2 * BLOCK_SIZE, BOARD_POSITION_Y + 7 * BLOCK_SIZE));
            _pieces.push_back(new Piece(_data, Pieces::Queen, true, "White Queen", BOARD_POSITION_X + 3 * BLOCK_SIZE, BOARD_POSITION_Y + 7 * BLOCK_SIZE));
            _pieces.push_back(new Piece(_data, Pieces::King, true, "White King", BOARD_POSITION_X + 4 * BLOCK_SIZE, BOARD_POSITION_Y + 7 * BLOCK_SIZE));
            _pieces.push_back(new Piece(_data, Pieces::Bishop, true, "White Bishop", BOARD_POSITION_X + 5 * BLOCK_SIZE, BOARD_POSITION_Y + 7 * BLOCK_SIZE));
            _pieces.push_back(new Piece(_data, Pieces::Knight, true, "White Knight", BOARD_POSITION_X + 6 * BLOCK_SIZE, BOARD_POSITION_Y + 7 * BLOCK_SIZE));
            _pieces.push_back(new Piece(_data, Pieces::Rook, true, "White Rook", BOARD_POSITION_X + 7 * BLOCK_SIZE, BOARD_POSITION_Y + 7 * BLOCK_SIZE));

            for (int i = 0; i < 8; i++)
            {

                _pieces.push_back(new Piece(_data, Pieces::Pawn, true, "White Pawn", BOARD_POSITION_X + i * BLOCK_SIZE, BOARD_POSITION_Y + 6 * BLOCK_SIZE));
            }
        }
        else
        {
            _pieces.push_back(new Piece(_data, Pieces::Rook, false, "Black Rook", BOARD_POSITION_X, BOARD_POSITION_Y + 0 * BLOCK_SIZE));
            _pieces.push_back(new Piece(_data, Pieces::Knight, false, "Black Knight", BOARD_POSITION_X + 1 * BLOCK_SIZE, BOARD_POSITION_Y + 0 * BLOCK_SIZE));
            _pieces.push_back(new Piece(_data, Pieces::Bishop, false, "Black Bishop", BOARD_POSITION_X + 2 * BLOCK_SIZE, BOARD_POSITION_Y + 0 * BLOCK_SIZE));
            _pieces.push_back(new Piece(_data, Pieces::Queen, false, "Black Queen", BOARD_POSITION_X + 3 * BLOCK_SIZE, BOARD_POSITION_Y + 0 * BLOCK_SIZE));
            _pieces.push_back(new Piece(_data, Pieces::King, false, "Black King", BOARD_POSITION_X + 4 * BLOCK_SIZE, BOARD_POSITION_Y + 0 * BLOCK_SIZE));
            _pieces.push_back(new Piece(_data, Pieces::Bishop, false, "Black Bishop", BOARD_POSITION_X + 5 * BLOCK_SIZE, BOARD_POSITION_Y + 0 * BLOCK_SIZE));
            _pieces.push_back(new Piece(_data, Pieces::Knight, false, "Black Knight", BOARD_POSITION_X + 6 * BLOCK_SIZE, BOARD_POSITION_Y + 0 * BLOCK_SIZE));
            _pieces.push_back(new Piece(_data, Pieces::Rook, false, "Black Rook", BOARD_POSITION_X + 7 * BLOCK_SIZE, BOARD_POSITION_Y + 0 * BLOCK_SIZE));

            for (int i = 0; i < 8; i++)
            {

                _pieces.push_back(new Piece(_data, Pieces::Pawn, false, "Black Pawn", BOARD_POSITION_X + i * BLOCK_SIZE, BOARD_POSITION_Y + 1 * BLOCK_SIZE));
            }
        }
    }

    Piece *Player::pieceClickedWhite(struct Cordinate cord)
    {
        for (int i = 0; i < _pieces.size(); i++)
        {
            if ((_pieces.at(i)->getCordinate() == cord) && _pieces.at( i )->isWhite(  ) )
            {
                return _pieces.at(i);
            }
        }
        return nullptr;
    }

    Piece *Player::pieceClickedBlack( struct Cordinate cord )
    {
        for ( int i = 0; i < _pieces.size(  ); i++ )
        {
            if ( ( _pieces.at( i )->getCordinate(  ) == cord ) && !_pieces.at( i )->isWhite(  ) )
            {
                return _pieces.at( i );
            }
        }
        return nullptr;
    }

    bool Player::canMove(Cordinate cord)
    {
        for (int i = 0; i < _moves.size(); i++)
        {
            if (cord == _moves.at(i))
            {
                return true;
            }
        }
        return false;
    }

    std::vector<Cordinate>* Player::getMoves(  )
    {
        return &_moves;
    }

    void Player::removeMoves()
    {
        _moves.clear();
    }

    void Player::generateMoves(Piece *clickedPiece)
    {
        if (clickedPiece->getPieceId() == Pieces::Pawn)
        {
            pawnMoves( clickedPiece );
        }
        else if ( clickedPiece->getPieceId(  ) == Pieces::Bishop )
        {
            bishopMoves( clickedPiece );
        }
        else if ( clickedPiece->getPieceId(  ) == Pieces::Rook )
        {
            rookMoves( clickedPiece );
        }
        else if ( clickedPiece->getPieceId(  ) == Pieces::Queen )
        {
            bishopMoves( clickedPiece );
            rookMoves( clickedPiece );
        }
    }

    bool Player::isPieceAtWhite( Cordinate cord )
    {
        for ( int i = 0; i < _pieces.size(  ); i++ )
        {
            if ( cord == _pieces.at( i )->getCordinate(  ) && _pieces.at( i )->isWhite(  ) )
            {
                return true;
            }
        }
        return false;
    }

    bool Player::isPieceAtBlack( Cordinate cord )
    {
        for ( int i = 0; i < _pieces.size(  ); i++ )
        {
            if ( cord == _pieces.at( i )->getCordinate(  ) && !_pieces.at( i )->isWhite(  ) )
            {
                return true;
            }
        }
        return false;
    }

    void Player::pawnMoves(Piece *clickedPiece)
    {
        if (_isWhite)
        {
            Cordinate cord = clickedPiece->getCordinate();
            cord.y -= 1 * BLOCK_SIZE;
            Cordinate cord1 = cord, cord2 = cord, cord3 = cord;
            cord1.x += 1 * BLOCK_SIZE;
            cord2.x -= 1 * BLOCK_SIZE;
            cord3.y -= 1 * BLOCK_SIZE;
            int flag = 0;
            int flag1 = 1;
            for (int i = 0; i < _pieces.size(); i++)
            {
                if (cord == _pieces.at(i)->getCordinate())
                {
                    flag = 1;
                }
                if ( clickedPiece->getCordinate().y == BOARD_POSITION_Y + 6 * BLOCK_SIZE)
                {
                    if (cord3 == _pieces.at(i)->getCordinate())
                    {
                        flag1 = 0;
                    }
                }
                else
                {
                    flag1 = 0;
                }
                if ((cord1 == _pieces.at(i)->getCordinate()) && !_pieces.at(i)->isWhite())
                {
                    _moves.push_back(cord1);
                }
                if (cord2 == _pieces.at(i)->getCordinate() && !_pieces.at(i)->isWhite())
                {
                    _moves.push_back(cord2);
                }
            }
            if (!flag)
            {
                _moves.push_back(cord);
            }
            if (flag1)
            {
                _moves.push_back(cord3);
            }
        }
        else
        {
            Cordinate cord = clickedPiece->getCordinate();
            cord.y += 1 * BLOCK_SIZE;
            Cordinate cord1 = cord, cord2 = cord, cord3 = cord;
            cord1.x += 1 * BLOCK_SIZE;
            cord2.x -= 1 * BLOCK_SIZE;
            cord3.y += 1 * BLOCK_SIZE;
            int flag = 0;
            int flag1 = 1;
            for (int i = 0; i < _pieces.size(); i++)
            {
                if (cord == _pieces.at(i)->getCordinate())
                {
                    flag = 1;
                }
                if ( clickedPiece->getCordinate(  ).y == BOARD_POSITION_Y + 1 * BLOCK_SIZE)
                {
                    if (cord3 == _pieces.at(i)->getCordinate())
                    {
                        flag1 = 0;
                    }
                }
                else
                {
                    flag1 = 0;
                }
                if ((cord1 == _pieces.at(i)->getCordinate()) && _pieces.at(i)->isWhite())
                {
                    _moves.push_back(cord1);
                }
                if (cord2 == _pieces.at(i)->getCordinate() && _pieces.at(i)->isWhite())
                {
                    _moves.push_back(cord2);
                }
            }
            if (!flag)
            {
                _moves.push_back(cord);
            }
            if (flag1)
            {
                _moves.push_back(cord3);
            }
        }
    }

    void Player::bishopMoves( Piece* clickedPiece )
    {
        Cordinate cord = clickedPiece->getCordinate(  );
        Cordinate cord1 = cord;

        for ( int i = 1; i < 8 ; i++ )
        {
           cord1.y -= 1 * BLOCK_SIZE;
           cord1.x += 1 * BLOCK_SIZE;

            if ( _isWhite )
            {
                if ( isPieceAtWhite( cord1 ) )
                {
                    break;
                }
                else if ( isPieceAtBlack( cord1 ) )
                {
                    _moves.push_back( cord1 );
                    break;
                }
                else if ( cord1.x > BOARD_POSITION_X + 7 * BLOCK_SIZE || cord1.y < BOARD_POSITION_Y )
                {
                    break;
                }
                else 
                {
                    _moves.push_back( cord1 );
                }
            }
            else
            {
                if ( isPieceAtBlack( cord1 ) )
                {
                    break;
                }
                else if ( isPieceAtWhite( cord1 ) )
                {
                    _moves.push_back( cord1 );
                    break;
                }
                else if ( cord1.x > BOARD_POSITION_X + 7 * BLOCK_SIZE || cord1.y < BOARD_POSITION_Y )
                {
                    break;
                }
                else 
                {
                    _moves.push_back( cord1 );
                }

            }
        }
        cord1 = cord;
        for ( int i = 1; i < 8 ; i++ )
        {
           cord1.y -= 1 * BLOCK_SIZE;
           cord1.x -= 1 * BLOCK_SIZE;

            if ( _isWhite )
            {
                if ( isPieceAtWhite( cord1 ) )
                {
                    break;
                }
                else if ( isPieceAtBlack( cord1 ) )
                {
                    _moves.push_back( cord1 );
                    break;
                }
                else if ( cord1.x < BOARD_POSITION_X || cord1.y < BOARD_POSITION_Y )
                {
                    break;
                }
                else 
                {
                    _moves.push_back( cord1 );
                }
            }
            else
            {
                if ( isPieceAtBlack( cord1 ) )
                {
                    break;
                }
                else if ( isPieceAtWhite( cord1 ) )
                {
                    _moves.push_back( cord1 );
                    break;
                }
                else if ( cord1.x < BOARD_POSITION_X || cord1.y < BOARD_POSITION_Y )
                {
                    break;
                }
                else 
                {
                    _moves.push_back( cord1 );
                }

            }
        }
        cord1 = cord;
        for ( int i = 1; i < 8 ; i++ )
        {
           cord1.y += 1 * BLOCK_SIZE;
           cord1.x += 1 * BLOCK_SIZE;

            if ( _isWhite )
            {
                if ( isPieceAtWhite( cord1 ) )
                {
                    break;
                }
                else if ( isPieceAtBlack( cord1 ) )
                {
                    _moves.push_back( cord1 );
                    break;
                }
                else if ( cord1.x > BOARD_POSITION_X + 7 * BLOCK_SIZE || cord1.y > BOARD_POSITION_Y + 7 * BLOCK_SIZE )
                {
                    break;
                }
                else 
                {
                    _moves.push_back( cord1 );
                }
            }
            else
            {
                if ( isPieceAtBlack( cord1 ) )
                {
                    break;
                }
                else if ( isPieceAtWhite( cord1 ) )
                {
                    _moves.push_back( cord1 );
                    break;
                }
                else if ( cord1.x > BOARD_POSITION_X + 7 * BLOCK_SIZE || cord1.y > BOARD_POSITION_Y + 7 * BLOCK_SIZE )
                {
                    break;
                }
                else 
                {
                    _moves.push_back( cord1 );
                }

            }
        }
        cord1 = cord;
        for ( int i = 1; i < 8 ; i++ )
        {
           cord1.y += 1 * BLOCK_SIZE;
           cord1.x -= 1 * BLOCK_SIZE;

            if ( _isWhite )
            {
                if ( isPieceAtWhite( cord1 ) )
                {
                    break;
                }
                else if ( isPieceAtBlack( cord1 ) )
                {
                    _moves.push_back( cord1 );
                    break;
                }
                else if ( cord1.x < BOARD_POSITION_X || cord1.y > BOARD_POSITION_Y + 7 * BLOCK_SIZE )
                {
                    break;
                }
                else 
                {
                    _moves.push_back( cord1 );
                }
            }
            else
            {
                if ( isPieceAtBlack( cord1 ) )
                {
                    break;
                }
                else if ( isPieceAtWhite( cord1 ) )
                {
                    _moves.push_back( cord1 );
                    break;
                }
                else if ( cord1.x < BOARD_POSITION_X || cord1.y > BOARD_POSITION_Y + 7 * BLOCK_SIZE )
                {
                    break;
                }
                else 
                {
                    _moves.push_back( cord1 );
                }

            }
        }
    }

    void Player::rookMoves( Piece* clickedPiece )
    {
        Cordinate cord = clickedPiece->getCordinate(  );
        Cordinate cord1 = cord;

        for ( int i = 1; i < 8 ; i++ )
        {
           cord1.y -= 1 * BLOCK_SIZE;

            if ( _isWhite )
            {
                if ( isPieceAtWhite( cord1 ) )
                {
                    break;
                }
                else if ( isPieceAtBlack( cord1 ) )
                {
                    _moves.push_back( cord1 );
                    break;
                }
                else if ( cord1.y < BOARD_POSITION_Y )
                {
                    break;
                }
                else 
                {
                    _moves.push_back( cord1 );
                }
            }
            else
            {
                if ( isPieceAtBlack( cord1 ) )
                {
                    break;
                }
                else if ( isPieceAtWhite( cord1 ) )
                {
                    _moves.push_back( cord1 );
                    break;
                }
                else if ( cord1.y < BOARD_POSITION_Y )
                {
                    break;
                }
                else 
                {
                    _moves.push_back( cord1 );
                }

            }
        }
        cord1 = cord;
        for ( int i = 1; i < 8 ; i++ )
        {
           cord1.y += 1 * BLOCK_SIZE;

            if ( _isWhite )
            {
                if ( isPieceAtWhite( cord1 ) )
                {
                    break;
                }
                else if ( isPieceAtBlack( cord1 ) )
                {
                    _moves.push_back( cord1 );
                    break;
                }
                else if ( cord1.y > BOARD_POSITION_Y + 7 * BLOCK_SIZE )
                {
                    break;
                }
                else 
                {
                    _moves.push_back( cord1 );
                }
            }
            else
            {
                if ( isPieceAtBlack( cord1 ) )
                {
                    break;
                }
                else if ( isPieceAtWhite( cord1 ) )
                {
                    _moves.push_back( cord1 );
                    break;
                }
                else if ( cord1.y > BOARD_POSITION_Y + 7 * BLOCK_SIZE )
                {
                    break;
                }
                else 
                {
                    _moves.push_back( cord1 );
                }

            }
        }
        cord1 = cord;
        for ( int i = 1; i < 8 ; i++ )
        {
           cord1.x += 1 * BLOCK_SIZE;

            if ( _isWhite )
            {
                if ( isPieceAtWhite( cord1 ) )
                {
                    break;
                }
                else if ( isPieceAtBlack( cord1 ) )
                {
                    _moves.push_back( cord1 );
                    break;
                }
                else if ( cord1.x > BOARD_POSITION_X + 7 * BLOCK_SIZE )
                {
                    break;
                }
                else 
                {
                    _moves.push_back( cord1 );
                }
            }
            else
            {
                if ( isPieceAtBlack( cord1 ) )
                {
                    break;
                }
                else if ( isPieceAtWhite( cord1 ) )
                {
                    _moves.push_back( cord1 );
                    break;
                }
                else if ( cord1.x > BOARD_POSITION_X + 7 * BLOCK_SIZE )
                {
                    break;
                }
                else 
                {
                    _moves.push_back( cord1 );
                }

            }
        }
        cord1 = cord;
        for ( int i = 1; i < 8 ; i++ )
        {
           cord1.x -= 1 * BLOCK_SIZE;

            if ( _isWhite )
            {
                if ( isPieceAtWhite( cord1 ) )
                {
                    break;
                }
                else if ( isPieceAtBlack( cord1 ) )
                {
                    _moves.push_back( cord1 );
                    break;
                }
                else if ( cord1.x < BOARD_POSITION_X )
                {
                    break;
                }
                else 
                {
                    _moves.push_back( cord1 );
                }
            }
            else
            {
                if ( isPieceAtBlack( cord1 ) )
                {
                    break;
                }
                else if ( isPieceAtWhite( cord1 ) )
                {
                    _moves.push_back( cord1 );
                    break;
                }
                else if ( cord1.x < BOARD_POSITION_X )
                {
                    break;
                }
                else 
                {
                    _moves.push_back( cord1 );
                }

            }
        }
    }

    void Player::KnightMoves( Piece* clickedPiece )
    {

    }

    void Player::kingMoves( Piece* clickedPiece )
    {

    }

    void Player::Update()
    {
        for (int i = 0; i < _pieces.size(); i++)
        {
            _pieces.at(i)->Update();

            if (_pieces.at(i)->isCaptured())
            {
                _pieces.erase(_pieces.begin() + i);
            }
        }
    }

    void Player::Draw()
    {
        for (int i = 0; i < _pieces.size(); i++)
        {
            _pieces.at(i)->Draw();
        }
    }
}
