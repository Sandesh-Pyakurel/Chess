#include "Player.hpp"

namespace Chess
{
    std::vector<Piece *> _pieces;

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

        _removeCaptured = true;
        _tempPiece = nullptr;
    }

    // To get clicked piece's pointer if it is white.
    Piece *Player::pieceClickedWhite(struct Cordinate cord)
    {
        for (int i = 0; i < _pieces.size(); i++)
        {
            if ((_pieces.at(i)->getCordinate() == cord) && _pieces.at(i)->isWhite())
            {
                return _pieces.at(i);
            }
        }
        return nullptr;
    }

    // To get clicked piece's pointer if it is white.
    Piece *Player::pieceClickedBlack(struct Cordinate cord)
    {
        for (int i = 0; i < _pieces.size(); i++)
        {
            if ((_pieces.at(i)->getCordinate() == cord) && !_pieces.at(i)->isWhite())
            {
                return _pieces.at(i);
            }
        }
        return nullptr;
    }

    // To check if user's input move is possible.
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

    // To get moves available for the clicked piece.
    std::vector<Cordinate> *Player::getMoves()
    {
        return &_moves;
    }

    // To remove all the moves.
    void Player::removeMoves()
    {
        _moves.clear();
    }

    bool Player::checkPromotion( Piece* clickedPiece )
    {
        if ( clickedPiece->getPieceId() == Pieces::Pawn && (clickedPiece->getCordinate().y == BOARD_POSITION_Y + 7 * BLOCK_SIZE  ||   clickedPiece->getCordinate().y == BOARD_POSITION_Y + 0 * BLOCK_SIZE) ) 
        {
            clickedPiece->setCaptured();
            return true;
        }
    }

    void Player::handlePiecePromotion( int promoted_piece )
    {
        if ( _isWhite )
        {
            if ( promoted_piece == 0 )
            {
                _pieces.push_back(new Piece(_data, Pieces::Queen, true, "White Queen", coord.x, coord.y));
            }
            if ( promoted_piece == 1 )
            {
                _pieces.push_back(new Piece(_data, Pieces::Rook, true, "White Rook", coord.x, coord.y));
            }
            if ( promoted_piece == 2 )
            {
                _pieces.push_back(new Piece(_data, Pieces::Bishop, true, "White Bishop", coord.x, coord.y));
            }
            if ( promoted_piece == 3 )
            {
                _pieces.push_back(new Piece(_data, Pieces::Knight, true, "White Knight", coord.x, coord.y));
            }
        }
        else 
        {
            if ( promoted_piece == 0 )
            {
                _pieces.push_back(new Piece(_data, Pieces::Queen, false, "Black Queen", coord.x, coord.y));
            }
            if ( promoted_piece == 1 )
            {
                _pieces.push_back(new Piece(_data, Pieces::Rook, false, "Black Rook", coord.x, coord.y));
            }
            if ( promoted_piece == 2 )
            {
                _pieces.push_back(new Piece(_data, Pieces::Bishop, false, "Black Bishop", coord.x, coord.y));
            }
            if ( promoted_piece == 3 )
            {
                _pieces.push_back(new Piece(_data, Pieces::Knight, false, "Black Knight", coord.x, coord.y));
            }
        }
    }

    // Helper function for simulating moves looking for check.
    void Player::setIsWhite( )
    {
        if ( _isWhite )
            _isWhite = false;
        else
            _isWhite = true;
    }

    // Helper function for simulating moves looking for check.
    void Player::removePiece( Piece* piece )
    {
        for ( int i = 0; i < _pieces.size(  ); i++ )
        {
            if ( _pieces.at( i ) == piece )
            {
                _tempPiece = _pieces.at( i );
                _pieces.erase( _pieces.begin(  ) + i );
            }
        }
    }

    // Helper function for simulating moves looking for check.
    void Player::restorePiece(  )
    {
        _pieces.push_back( _tempPiece );
        _tempPiece = nullptr;
    }

    // To remove moves that causes check on own's king.
    void Player::filterLegalMoves( Piece* clickedPiece )
    {
        for ( int i = 0; i < _moves.size( );i++ )
        {
            _tempmoves.push_back( _moves.at( i ) );
        }
        removeMoves();
        
        Cordinate tempcord = clickedPiece->getCordinate(  );

        _removeCaptured = false;

        for ( int i = 0; i < _tempmoves.size( ); i++ )
        {
            Piece* temppiece = nullptr;
            if ( isPieceAtBlack(_tempmoves.at(i)))
            {
                temppiece = pieceClickedBlack( _tempmoves.at(i));
                temppiece->setCaptured( );
                removePiece( temppiece );
            }
            else if ( isPieceAtWhite(_tempmoves.at(i)))
            {
                temppiece = pieceClickedWhite( _tempmoves.at(i));
                temppiece->setCaptured( );
                removePiece( temppiece );
            }

            clickedPiece->setCordinate( _tempmoves.at( i ) );
            Cordinate kingcord = getKingPosition(  );

            if ( isAtCheck( kingcord ) )
            {
                _tempmoves.erase( _tempmoves.begin( ) + i );
                i--;
            }
            if ( temppiece )
            {
                temppiece->setUnCaputred( );
                restorePiece(  );
            }
        }
        clickedPiece->setCordinate( tempcord );
        
        removeMoves( );

        _removeCaptured = true;

        // check for castling move.
        Cordinate cord1, cord2, cord3;
        cord1.x = BOARD_POSITION_X + 1 * BLOCK_SIZE;
        cord1.y = BOARD_POSITION_Y + 7 * BLOCK_SIZE;

        cord3 = cord1;
        cord3.x += 2 * BLOCK_SIZE;
        cord2 = cord1;
        cord2.x += BLOCK_SIZE;


        if ( clickedPiece->getPieceId() == Pieces::King )
        {
            if ( _isWhite )
            {
                if ( _castleLeftPotential )
                {
                    if ( !(isPieceAtBlack(cord1) || isPieceAtWhite(cord1)) && !(isPieceAtBlack(cord2) || isPieceAtWhite(cord2)) && !(isPieceAtBlack(cord3) || isPieceAtWhite(cord3)) )
                    {
                        if ( !isAtCheck(cord1) && !isAtCheck(cord2) && !isAtCheck(cord3) )
                        {
                            _tempmoves.push_back( cord2 );
                            _castleLeftNow = true;
                        }
                    }
                }

                if ( _castleRightPotential )
                {

                    cord1.x += 4 * BLOCK_SIZE;
                    cord2.x += 4 * BLOCK_SIZE;

                    if ( !(isPieceAtBlack(cord1) || isPieceAtWhite(cord1)) && !(isPieceAtBlack(cord2) || isPieceAtWhite(cord2)) )
                    {
                        if ( !isAtCheck(cord1) && !isAtCheck(cord2) )
                        {
                            _tempmoves.push_back( cord2 );
                            _castleRightNow = true;
                        }
                    }
                }
            }
            else
            {
                cord1.x = BOARD_POSITION_X + 1 * BLOCK_SIZE;
                cord1.y = BOARD_POSITION_Y; 

                cord3 = cord1;
                cord3.x += 2 * BLOCK_SIZE;
                cord2 = cord1;
                cord2.x += BLOCK_SIZE;

                if ( _castleLeftPotential )
                {
                    if ( !(isPieceAtBlack(cord1) || isPieceAtWhite(cord1)) && !(isPieceAtBlack(cord2) || isPieceAtWhite(cord2)) && !(isPieceAtBlack(cord3) || isPieceAtWhite(cord3)) )
                    {
                        if ( !isAtCheck(cord1) && !isAtCheck(cord2) && !isAtCheck(cord3) )
                        {
                            _tempmoves.push_back( cord2 );
                            _castleLeftNow = true;
                        }
                    }
                }

                if ( _castleRightPotential )
                {

                    cord1.x += 4 * BLOCK_SIZE;
                    cord2.x += 4 * BLOCK_SIZE;

                    if ( !(isPieceAtBlack(cord1) || isPieceAtWhite(cord1)) && !(isPieceAtBlack(cord2) || isPieceAtWhite(cord2)) )
                    {
                        if ( !isAtCheck(cord1) && !isAtCheck(cord2) )
                        {
                            _tempmoves.push_back( cord2 );
                            _castleRightNow = true;
                        }
                    }
                }
            }
 
        }

        for ( int i = 0; i < _tempmoves.size( );i++ )
        {
            _moves.push_back( _tempmoves.at( i ) );
        }
        _tempmoves.clear( );


    }

    // To generate pseudolegal moves according to clicked piece.
    void Player::generateMoves(Piece *clickedPiece)
    {
        if (clickedPiece->getPieceId() == Pieces::Pawn)
        {
            pawnMoves(clickedPiece);
        }
        else if (clickedPiece->getPieceId() == Pieces::Bishop)
        {
            bishopMoves(clickedPiece);
        }
        else if (clickedPiece->getPieceId() == Pieces::Rook)
        {
            rookMoves(clickedPiece);
        }
        else if (clickedPiece->getPieceId() == Pieces::Queen)
        {
            bishopMoves(clickedPiece);
            rookMoves(clickedPiece);
        }
        else if ( clickedPiece->getPieceId(  ) == Pieces::Knight )
        {
            KnightMoves( clickedPiece );
        }
        else if ( clickedPiece->getPieceId( ) == Pieces::King )
        {
            kingMoves( clickedPiece );
        }
    }

    // To check if there is white piece at the given cordinate.
    bool Player::isPieceAtWhite(Cordinate cord)
    {
        for (int i = 0; i < _pieces.size(); i++)
        {
            if (cord == _pieces.at(i)->getCordinate() && _pieces.at(i)->isWhite())
            {
                return true;
            }
        }
        return false;
    }

    // To check if there is black piece at the given cordinate.
    bool Player::isPieceAtBlack(Cordinate cord)
    {
        for (int i = 0; i < _pieces.size(); i++)
        {
            if (cord == _pieces.at(i)->getCordinate() && !_pieces.at(i)->isWhite())
            {
                return true;
            }
        }
        return false;
    }

    // To get king's cordinate to look for check.
    Cordinate Player::getKingPosition( )
    {
        for ( int i = 0; i < _pieces.size( ); i++ )
        {
            if ( _pieces.at( i)->getPieceId( ) == Pieces::King && _pieces.at( i )->isWhite( ) == _isWhite )
            {
                return _pieces.at( i)->getCordinate( );
            }
        }
    }

    // Function to generate pseudolegal moves for pawn.
    void Player::pawnMoves(Piece *clickedPiece)
    {
        if (_isWhite)
        {
            Cordinate cord = clickedPiece->getCordinate();
            cord.y -= 1 * BLOCK_SIZE;
            Cordinate cord1 = cord, cord2 = cord, cord3 = cord;
            cord1.x += 1 * BLOCK_SIZE; // it store the capturing position in right side.
            cord2.x -= 1 * BLOCK_SIZE; // it store the capturing position in left side.
            cord3.y -= 1 * BLOCK_SIZE; // it stors the position for two block movement if it is first move of the pawn.
            int flag = 0;
            int flag1 = 1;
            for (int i = 0; i < _pieces.size(); i++)
            {
                if (cord == _pieces.at(i)->getCordinate())
                {
                    flag = 1; // flag = 1 represents there is same color piece in the one block forward.
                }
                if (clickedPiece->getCordinate().y == BOARD_POSITION_Y + 6 * BLOCK_SIZE)
                {
                    if (cord3 == _pieces.at(i)->getCordinate() ||cord == _pieces.at(i)->getCordinate())
                    {
                        flag1 = 0; // flag1 = 0 means two block movement is not possible.
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
                if (clickedPiece->getCordinate().y == BOARD_POSITION_Y + 1 * BLOCK_SIZE)
                {
                    if (cord3 == _pieces.at(i)->getCordinate() || cord == _pieces.at(i)->getCordinate())
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

    // Function to generate pseudolegal moves for bishop.
    void Player::bishopMoves(Piece *clickedPiece)
    {
        Cordinate cord = clickedPiece->getCordinate();
        Cordinate cord1 = cord;

        for (int i = 1; i < 8; i++)
        {
            cord1.y -= 1 * BLOCK_SIZE;
            cord1.x += 1 * BLOCK_SIZE;

            if (_isWhite)
            {
                if (isPieceAtWhite(cord1))
                {
                    break;
                }
                else if (isPieceAtBlack(cord1))
                {
                    _moves.push_back(cord1);
                    break;
                }
                else if (cord1.x > BOARD_POSITION_X + 7 * BLOCK_SIZE || cord1.y < BOARD_POSITION_Y)
                {
                    break;
                }
                else
                {
                    _moves.push_back(cord1);
                }
            }
            else
            {
                if (isPieceAtBlack(cord1))
                {
                    break;
                }
                else if (isPieceAtWhite(cord1))
                {
                    _moves.push_back(cord1);
                    break;
                }
                else if (cord1.x > BOARD_POSITION_X + 7 * BLOCK_SIZE || cord1.y < BOARD_POSITION_Y)
                {
                    break;
                }
                else
                {
                    _moves.push_back(cord1);
                }
            }
        }
        cord1 = cord;
        for (int i = 1; i < 8; i++)
        {
            cord1.y -= 1 * BLOCK_SIZE;
            cord1.x -= 1 * BLOCK_SIZE;

            if (_isWhite)
            {
                if (isPieceAtWhite(cord1))
                {
                    break;
                }
                else if (isPieceAtBlack(cord1))
                {
                    _moves.push_back(cord1);
                    break;
                }
                else if (cord1.x < BOARD_POSITION_X || cord1.y < BOARD_POSITION_Y)
                {
                    break;
                }
                else
                {
                    _moves.push_back(cord1);
                }
            }
            else
            {
                if (isPieceAtBlack(cord1))
                {
                    break;
                }
                else if (isPieceAtWhite(cord1))
                {
                    _moves.push_back(cord1);
                    break;
                }
                else if (cord1.x < BOARD_POSITION_X || cord1.y < BOARD_POSITION_Y)
                {
                    break;
                }
                else
                {
                    _moves.push_back(cord1);
                }
            }
        }
        cord1 = cord;
        for (int i = 1; i < 8; i++)
        {
            cord1.y += 1 * BLOCK_SIZE;
            cord1.x += 1 * BLOCK_SIZE;

            if (_isWhite)
            {
                if (isPieceAtWhite(cord1))
                {
                    break;
                }
                else if (isPieceAtBlack(cord1))
                {
                    _moves.push_back(cord1);
                    break;
                }
                else if (cord1.x > BOARD_POSITION_X + 7 * BLOCK_SIZE || cord1.y > BOARD_POSITION_Y + 7 * BLOCK_SIZE)
                {
                    break;
                }
                else
                {
                    _moves.push_back(cord1);
                }
            }
            else
            {
                if (isPieceAtBlack(cord1))
                {
                    break;
                }
                else if (isPieceAtWhite(cord1))
                {
                    _moves.push_back(cord1);
                    break;
                }
                else if (cord1.x > BOARD_POSITION_X + 7 * BLOCK_SIZE || cord1.y > BOARD_POSITION_Y + 7 * BLOCK_SIZE)
                {
                    break;
                }
                else
                {
                    _moves.push_back(cord1);
                }
            }
        }
        cord1 = cord;
        for (int i = 1; i < 8; i++)
        {
            cord1.y += 1 * BLOCK_SIZE;
            cord1.x -= 1 * BLOCK_SIZE;

            if (_isWhite)
            {
                if (isPieceAtWhite(cord1))
                {
                    break;
                }
                else if (isPieceAtBlack(cord1))
                {
                    _moves.push_back(cord1);
                    break;
                }
                else if (cord1.x < BOARD_POSITION_X || cord1.y > BOARD_POSITION_Y + 7 * BLOCK_SIZE)
                {
                    break;
                }
                else
                {
                    _moves.push_back(cord1);
                }
            }
            else
            {
                if (isPieceAtBlack(cord1))
                {
                    break;
                }
                else if (isPieceAtWhite(cord1))
                {
                    _moves.push_back(cord1);
                    break;
                }
                else if (cord1.x < BOARD_POSITION_X || cord1.y > BOARD_POSITION_Y + 7 * BLOCK_SIZE)
                {
                    break;
                }
                else
                {
                    _moves.push_back(cord1);
                }
            }
        }
    }

    // Function to generate pseudolegal moves for rook.
    void Player::rookMoves(Piece *clickedPiece)
    {
        Cordinate cord = clickedPiece->getCordinate();
        Cordinate cord1 = cord;

        for (int i = 1; i < 8; i++)
        {
            cord1.y -= 1 * BLOCK_SIZE;

            if (_isWhite)
            {
                if (isPieceAtWhite(cord1))
                {
                    break;
                }
                else if (isPieceAtBlack(cord1))
                {
                    _moves.push_back(cord1);
                    break;
                }
                else if (cord1.y < BOARD_POSITION_Y)
                {
                    break;
                }
                else
                {
                    _moves.push_back(cord1);
                }
            }
            else
            {
                if (isPieceAtBlack(cord1))
                {
                    break;
                }
                else if (isPieceAtWhite(cord1))
                {
                    _moves.push_back(cord1);
                    break;
                }
                else if (cord1.y < BOARD_POSITION_Y)
                {
                    break;
                }
                else
                {
                    _moves.push_back(cord1);
                }
            }
        }
        cord1 = cord;
        for (int i = 1; i < 8; i++)
        {
            cord1.y += 1 * BLOCK_SIZE;

            if (_isWhite)
            {
                if (isPieceAtWhite(cord1))
                {
                    break;
                }
                else if (isPieceAtBlack(cord1))
                {
                    _moves.push_back(cord1);
                    break;
                }
                else if (cord1.y > BOARD_POSITION_Y + 7 * BLOCK_SIZE)
                {
                    break;
                }
                else
                {
                    _moves.push_back(cord1);
                }
            }
            else
            {
                if (isPieceAtBlack(cord1))
                {
                    break;
                }
                else if (isPieceAtWhite(cord1))
                {
                    _moves.push_back(cord1);
                    break;
                }
                else if (cord1.y > BOARD_POSITION_Y + 7 * BLOCK_SIZE)
                {
                    break;
                }
                else
                {
                    _moves.push_back(cord1);
                }
            }
        }
        cord1 = cord;
        for (int i = 1; i < 8; i++)
        {
            cord1.x += 1 * BLOCK_SIZE;

            if (_isWhite)
            {
                if (isPieceAtWhite(cord1))
                {
                    break;
                }
                else if (isPieceAtBlack(cord1))
                {
                    _moves.push_back(cord1);
                    break;
                }
                else if (cord1.x > BOARD_POSITION_X + 7 * BLOCK_SIZE)
                {
                    break;
                }
                else
                {
                    _moves.push_back(cord1);
                }
            }
            else
            {
                if (isPieceAtBlack(cord1))
                {
                    break;
                }
                else if (isPieceAtWhite(cord1))
                {
                    _moves.push_back(cord1);
                    break;
                }
                else if (cord1.x > BOARD_POSITION_X + 7 * BLOCK_SIZE)
                {
                    break;
                }
                else
                {
                    _moves.push_back(cord1);
                }
            }
        }
        cord1 = cord;
        for (int i = 1; i < 8; i++)
        {
            cord1.x -= 1 * BLOCK_SIZE;

            if (_isWhite)
            {
                if (isPieceAtWhite(cord1))
                {
                    break;
                }
                else if (isPieceAtBlack(cord1))
                {
                    _moves.push_back(cord1);
                    break;
                }
                else if (cord1.x < BOARD_POSITION_X)
                {
                    break;
                }
                else
                {
                    _moves.push_back(cord1);
                }
            }
            else
            {
                if (isPieceAtBlack(cord1))
                {
                    break;
                }
                else if (isPieceAtWhite(cord1))
                {
                    _moves.push_back(cord1);
                    break;
                }
                else if (cord1.x < BOARD_POSITION_X)
                {
                    break;
                }
                else
                {
                    _moves.push_back(cord1);
                }
            }
        }
    }

    // Function to generate pseudolegal moves for knight.
    void Player::KnightMoves(Piece *clickedPiece)
    {
        Cordinate cord = clickedPiece->getCordinate();
        Cordinate cord1 = cord, cord2 = cord;

        cord1.y -= 2 * BLOCK_SIZE;
        cord1.x -= 1 * BLOCK_SIZE;

        cord2.y -= 2 * BLOCK_SIZE;
        cord2.x += 1 * BLOCK_SIZE;

        if (_isWhite)
        {
            if (isPieceAtBlack(cord1))
            {
                _moves.push_back(cord1);
            }
            else if (!isPieceAtWhite( cord1 ) && !( cord1.y < BOARD_POSITION_Y) && !(cord1.x < BOARD_POSITION_X) )
            {
                _moves.push_back(cord1);
            }
            if (isPieceAtBlack(cord2))
            {
                _moves.push_back(cord2);
            }
            else if (!isPieceAtWhite( cord2 ) && !( cord2.y < BOARD_POSITION_Y) && !(cord2.x > BOARD_POSITION_X + 7 * BLOCK_SIZE) )
            {
                _moves.push_back(cord2);
            }
        }
        else
        {
            if (isPieceAtWhite(cord1))
            {
                _moves.push_back(cord1);
            }
            else if (!isPieceAtBlack( cord1 ) && !( cord1.y < BOARD_POSITION_Y) && !(cord1.x < BOARD_POSITION_X) )
            {
                _moves.push_back(cord1);
            }
            if (isPieceAtWhite(cord2))
            {
                _moves.push_back(cord2);
            }
            else if (!isPieceAtBlack( cord2 ) && !( cord2.y < BOARD_POSITION_Y) && !(cord2.x > BOARD_POSITION_X + 7 * BLOCK_SIZE) )
            {
                _moves.push_back(cord2);
            }
        }

        cord1.y += 4 * BLOCK_SIZE;
        cord2.y += 4 * BLOCK_SIZE;

        if (_isWhite)
        {
            if (isPieceAtBlack(cord1))
            {
                _moves.push_back(cord1);
            }
            else if (!isPieceAtWhite( cord1 ) && !( cord1.y > BOARD_POSITION_Y + 7 * BLOCK_SIZE) && !(cord1.x < BOARD_POSITION_X) )
            {
                _moves.push_back(cord1);
            }
            if (isPieceAtBlack(cord2))
            {
                _moves.push_back(cord2);
            }
            else if (!isPieceAtWhite( cord2 ) && !( cord2.y > BOARD_POSITION_Y + 7 * BLOCK_SIZE) && !(cord2.x > BOARD_POSITION_X + 7 * BLOCK_SIZE) )
            {
                _moves.push_back(cord2);
            }
        }
        else
        {
            if (isPieceAtWhite(cord1))
            {
                _moves.push_back(cord1);
            }
            else if (!isPieceAtBlack( cord1 ) && !( cord1.y > BOARD_POSITION_Y + 7 * BLOCK_SIZE) && !(cord1.x < BOARD_POSITION_X) )
            {
                _moves.push_back(cord1);
            }
            if (isPieceAtWhite(cord2))
            {
                _moves.push_back(cord2);
            }
            else if (!isPieceAtBlack( cord2 ) && !( cord2.y > BOARD_POSITION_Y + 7 * BLOCK_SIZE) && !(cord2.x > BOARD_POSITION_X + 7 * BLOCK_SIZE) )
            {
                _moves.push_back(cord2);
            }
        }

        cord1.y -= 3 * BLOCK_SIZE;
        cord2.y -= 1 * BLOCK_SIZE;

        cord1.x  += 3 * BLOCK_SIZE;
        cord2.x += 1 * BLOCK_SIZE;

        if (_isWhite)
        {
            if (isPieceAtBlack(cord1))
            {
                _moves.push_back(cord1);
            }
            else if (!isPieceAtWhite( cord1 ) && !( cord1.x > BOARD_POSITION_X + 7 * BLOCK_SIZE) && !(cord1.y < BOARD_POSITION_Y) )
            {
                _moves.push_back(cord1);
            }
            if (isPieceAtBlack(cord2))
            {
                _moves.push_back(cord2);
            }
            else if (!isPieceAtWhite( cord2 ) && !( cord2.x > BOARD_POSITION_X + 7 * BLOCK_SIZE) && !(cord2.y > BOARD_POSITION_Y + 7 * BLOCK_SIZE) )
            {
                _moves.push_back(cord2);
            }
        }
        else
        {
            if (isPieceAtWhite(cord1))
            {
                _moves.push_back(cord1);
            }
            else if (!isPieceAtBlack( cord1 ) && !( cord1.x > BOARD_POSITION_X + 7 * BLOCK_SIZE) && !(cord1.y < BOARD_POSITION_Y) )
            {
                _moves.push_back(cord1);
            }
            if (isPieceAtWhite(cord2))
            {
                _moves.push_back(cord2);
            }
            else if (!isPieceAtBlack( cord2 ) && !( cord2.x > BOARD_POSITION_X + 7 * BLOCK_SIZE) && !(cord2.y > BOARD_POSITION_Y + 7 * BLOCK_SIZE) )
            {
                _moves.push_back(cord2);
            }
        }

        cord1.x -= 4 * BLOCK_SIZE;
        cord2.x -= 4 * BLOCK_SIZE;

        if (_isWhite)
        {
            if (isPieceAtBlack(cord1))
            {
                _moves.push_back(cord1);
            }
            else if (!isPieceAtWhite( cord1 ) && !( cord1.x < BOARD_POSITION_X ) && !(cord1.y < BOARD_POSITION_Y) )
            {
                _moves.push_back(cord1);
            }
            if (isPieceAtBlack(cord2))
            {
                _moves.push_back(cord2);
            }
            else if (!isPieceAtWhite( cord2 ) && !( cord2.x < BOARD_POSITION_X ) && !(cord2.y > BOARD_POSITION_Y + 7 * BLOCK_SIZE) )
            {
                _moves.push_back(cord2);
            }
        }
        else
        {
            if (isPieceAtWhite(cord1))
            {
                _moves.push_back(cord1);
            }
            else if (!isPieceAtBlack( cord1 ) && !( cord1.x < BOARD_POSITION_X ) && !(cord1.y < BOARD_POSITION_Y) )
            {
                _moves.push_back(cord1);
            }
            if (isPieceAtWhite(cord2))
            {
                _moves.push_back(cord2);
            }
            else if (!isPieceAtBlack( cord2 ) && !( cord2.x < BOARD_POSITION_X)  && !(cord2.y > BOARD_POSITION_Y + 7 * BLOCK_SIZE) )
            {
                _moves.push_back(cord2);
            }
        }
    }

    // Function to generate pseudolegal moves for king.
    void Player::kingMoves(Piece *clickedPiece)
    {
        Cordinate cord = clickedPiece->getCordinate( );

        Cordinate cord1 = cord;

        cord1.y -= 1 * BLOCK_SIZE;
        cord1.x -= 2 * BLOCK_SIZE;

        for ( int i = 0; i < 3; i++ )
        {
            cord1.x += 1 * BLOCK_SIZE;

            if ( _isWhite )
            {
                if ( isPieceAtWhite( cord1 ) )
                {
                    continue;
                }
                else if ( isPieceAtBlack( cord1 ) )
                {
                    _moves.push_back( cord1 );
                }
                else if ( cord1.y < BOARD_POSITION_Y || cord1.x < BOARD_POSITION_X || cord1.x > BOARD_POSITION_X + 7 * BLOCK_SIZE )
                {
                    continue;
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
                    continue;
                }
                else if ( isPieceAtWhite( cord1 ) )
                {
                    _moves.push_back( cord1 );
                }
                else if ( cord1.y < BOARD_POSITION_Y || cord1.x < BOARD_POSITION_X || cord1.x > BOARD_POSITION_X + 7 * BLOCK_SIZE )
                {
                    continue;
                }
                else
                {
                    _moves.push_back( cord1 );
                }
            }
        }

        cord1.y += 2 * BLOCK_SIZE;
        cord1.x -= 3 * BLOCK_SIZE;

        for ( int i = 0; i < 3; i++ )
        {
            cord1.x += 1 * BLOCK_SIZE;

            if ( _isWhite )
            {
                if ( isPieceAtWhite( cord1 ) )
                {
                    continue;
                }
                else if ( isPieceAtBlack( cord1 ) )
                {
                    _moves.push_back( cord1 );
                }
                else if ( cord1.y > BOARD_POSITION_Y + 7 * BLOCK_SIZE || cord1.x < BOARD_POSITION_X || cord1.x > BOARD_POSITION_X + 7 * BLOCK_SIZE )
                {
                    continue;
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
                    continue;
                }
                else if ( isPieceAtWhite( cord1 ) )
                {
                    _moves.push_back( cord1 );
                }
                else if ( cord1.y < BOARD_POSITION_Y || cord1.x < BOARD_POSITION_X || cord1.x > BOARD_POSITION_X + 7 * BLOCK_SIZE )
                {
                    continue;
                }
                else
                {
                    _moves.push_back( cord1 );
                }
            }
        }

        cord1.y -= 1 * BLOCK_SIZE;
        cord1.x -= 4 * BLOCK_SIZE;

        for ( int i = 0; i < 2; i++ )
        {
            cord1.x += 2 * BLOCK_SIZE;

            if ( _isWhite )
            {
                if ( isPieceAtWhite( cord1 ) )
                {
                    continue;
                }
                else if ( isPieceAtBlack( cord1 ) )
                {
                    _moves.push_back( cord1 );
                }
                else if ( cord1.x < BOARD_POSITION_X || cord1.x > BOARD_POSITION_X + 7 * BLOCK_SIZE )
                {
                    continue;
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
                    continue;
                }
                else if ( isPieceAtWhite( cord1 ) )
                {
                    _moves.push_back( cord1 );
                }
                else if ( cord1.x < BOARD_POSITION_X || cord1.x > BOARD_POSITION_X + 7 * BLOCK_SIZE )
                {
                    continue;
                }
                else
                {
                    _moves.push_back( cord1 );
                }
            }
        }
    }

    // Function to check weather king is at check at current position.
    bool Player::isAtCheck( Cordinate kingcord )
    {
        if ( _isWhite )
        {
            setIsWhite( );
            for ( int i = 0; i < _pieces.size(  ); i++ )
            {
                if ( !_pieces.at( i )->isWhite(  ) )
                {
                    generateMoves( _pieces.at( i ));
                    for ( int i = 0; i < _moves.size( ); i++ )
                    {
                        
                        if ( kingcord == _moves.at( i ) )
                        {
                            removeMoves( );
                            setIsWhite( );
                            return true;
                        }
                    }
                    removeMoves( );
                }
            }
            removeMoves( );
            setIsWhite( );
            return false;
        }
        else
        {
            setIsWhite( );
            for ( int i = 0; i < _pieces.size(  ); i++ )
            {
                if ( _pieces.at( i )->isWhite(  ) )
                {
                    generateMoves( _pieces.at( i ));

                    for ( int i = 0; i < _moves.size( ); i++ )
                    {
                        if ( kingcord == _moves.at( i ) )
                        {
                            removeMoves( );
                            setIsWhite( );
                            return true;
                        }
                    }
                    removeMoves( );
                }
            }
            removeMoves( );
            setIsWhite( );
            return false;
        }
    }

    // Function to update the player.
    void Player::Update()
    {
        for (int i = 0; i < _pieces.size(); i++)
        {
            _pieces.at(i)->Update();

            if ( _removeCaptured )
            {
                if (_pieces.at(i)->isCaptured())
                {
                    _pieces.erase(_pieces.begin() + i);
                }
            }
        }
        if ( _lastMovedPiece != nullptr )
        {

            if ( _lastMovedPiece->getPieceId() == Pieces::King && ( _castleLeftPotential && _castleRightPotential ) )
            {
                _castleLeftPotential = false;
                _castleRightPotential = false;
            }

            if ( _lastMovedPiece->getPieceId() == Pieces::Rook )
            {
                if ( _lastMovedPiece->getCordinate( ).x == BOARD_POSITION_X && _castleLeftPotential )
                {
                    _castleLeftPotential = false;
                } 
                if ( _lastMovedPiece->getCordinate().x == BOARD_POSITION_X + 7 * BLOCK_SIZE && _castleRightPotential )
                {
                    _castleRightPotential = false;
                }
            }
        }

        Cordinate cord, cord1;
        cord.x = BOARD_POSITION_X;
        cord.y = BOARD_POSITION_Y + 7 * BLOCK_SIZE;
        cord1 = cord;
        cord1.x += 3 * BLOCK_SIZE;
        if ( _isWhite )
        {
            if ( _castleLeftNow && _lastMovedPiece->getPieceId() == Pieces::King && kingCastle.x == BOARD_POSITION_X + 2 * BLOCK_SIZE )
            {
                pieceClickedWhite(cord)->setCordinate(cord1);
                _castleLeftNow = false;
                _castleRightNow = false;
                _castleLeftPotential = false;
                _castleRightPotential = false;
            }
            else if ( _castleRightNow && _lastMovedPiece->getPieceId() == Pieces::King && kingCastle.x == BOARD_POSITION_X + 6 * BLOCK_SIZE )
            {
                cord.x += 7 * BLOCK_SIZE;
                cord1.x += 2 * BLOCK_SIZE;

                pieceClickedWhite(cord)->setCordinate(cord1);
                _castleLeftNow = false;
                _castleRightNow = false;
                _castleLeftPotential = false;
                _castleRightPotential = false;
            }
        }
        else
        {
            cord.x = BOARD_POSITION_X;
            cord.y = BOARD_POSITION_Y;
            cord1 = cord;
            cord1.x += 3 * BLOCK_SIZE;
            if ( _castleLeftNow && _lastMovedPiece->getPieceId() == Pieces::King  && kingCastle.x == BOARD_POSITION_X + 2 * BLOCK_SIZE )
            {
                pieceClickedBlack(cord)->setCordinate(cord1);
                _castleLeftNow = false;
                _castleRightNow = false;
                _castleLeftPotential = false;
                _castleRightPotential = false;
            }
            else if ( _castleRightNow && _lastMovedPiece->getPieceId() == Pieces::King  && kingCastle.x == BOARD_POSITION_X + 6 * BLOCK_SIZE )
            {
                cord.x += 7 * BLOCK_SIZE;
                cord1.x += 2 * BLOCK_SIZE;

                pieceClickedBlack(cord)->setCordinate(cord1);
                _castleLeftNow = false;
                _castleRightNow = false;
                _castleLeftPotential = false;
                _castleRightPotential = false;
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
