#include "GameState.hpp"
#include <iostream>

namespace Chess
{
    GameState::GameState( GameDataRef data ): _data( data )
    {

    }

    void GameState::Init(  )
    {
        // Initializing assets required for gamestate.

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

        _board = std::make_unique<GameBoard>( _data ); 
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

            // Handling mouse click event for piece movement.

            if ( sf::Event::MouseButtonPressed == event.type )
            {
                int mouse_x = sf::Mouse::getPosition( _data->window ).x;
                int mouse_y = sf::Mouse::getPosition( _data->window ).y;

                // processing white promotion if condition is true.
                if ( _board->isWhiteProm() )
                {
                    if ( (mouse_x >= _board->promotionPieceStartLocation().x && mouse_y >= _board->promotionPieceStartLocation().y) && (mouse_x <= _board->promotionPieceEndLocation().x && mouse_y <= _board->promotionPieceEndLocation().y) )
                    {
                        int promoted_piece = (mouse_x - _board->promotionPieceStartLocation().x) / (0.6 * BLOCK_SIZE);
                        _player1->handlePiecePromotion( promoted_piece );
                        _board->compWhiteProm();
                    }
                    break;
                }

                 if ( _board->isBlackProm() )
                {
                    if ( (mouse_x >= _board->promotionPieceStartLocation().x && mouse_y >= _board->promotionPieceStartLocation().y) && (mouse_x <= _board->promotionPieceEndLocation().x && mouse_y <= _board->promotionPieceEndLocation().y) )
                    {
                        int promoted_piece = (mouse_x - _board->promotionPieceStartLocation().x) / (0.6 * BLOCK_SIZE);
                        _player2->handlePiecePromotion( promoted_piece );
                        _board->compBlackProm();
                    }
                    break;
                }               

                // Checking if mouse coordinate is in the board. 

                if(((mouse_x >= BOARD_POSITION_X) && (mouse_x <= BOARD_POSITION_X + 8*BLOCK_SIZE )) && ( (mouse_y >= BOARD_POSITION_Y) && (mouse_y <= BOARD_POSITION_Y + 8*BLOCK_SIZE )))
                {
                    struct Cordinate cord;
                                                                               
                    // Substracting board offset form actual position to find index of box and add back to adjust real position.
                    cord.x =(( mouse_x - BOARD_POSITION_X ) / BLOCK_SIZE) * BLOCK_SIZE + BOARD_POSITION_X;
                    cord.y =(( mouse_y - BOARD_POSITION_Y ) / BLOCK_SIZE) * BLOCK_SIZE + BOARD_POSITION_Y;

                    // Handling the piece movement once it has been pressed.
                    if ( _clickedPiece )
                    {
                        if (! (_clickedPiece->getCordinate(  ) == cord ))
                        {
                            if ( _isWhiteTurn )
                            {
                                if ( _player1->canMove( cord ) )
                                {
                                    if ( _player2->pieceClickedBlack( cord ) )
                                    {
                                        _player2->pieceClickedBlack( cord )->setCaptured(  ); // deleting if captured.
                                    }

                                    _clickedPiece->setCordinate( cord ); // changing location if everything is valid.
                                    if ( _player1->checkPromotion( _clickedPiece ) ) // handling promotion condition for white piece.
                                    {
                                        _board->compWhiteProm();
                                        _player1->setCord( cord );
                                    }
                                    _clickedPiece = nullptr;
                                    _isWhiteTurn = !_isWhiteTurn;
                                    _player1->removeMoves( );
                                    _board->removeHighlight(  );
                                }    
                                else
                                {
                                    _clickedPiece = nullptr;
                                    _player1->removeMoves(  );
                                    _board->removeHighlight(  );
                                    break;
                                }
                            }
                            else
                            {
                                if ( _player2->canMove( cord ) )
                                {
                                    if ( _player1->pieceClickedWhite( cord ) )
                                    {
                                        _player1->pieceClickedWhite( cord )->setCaptured(  );
                                    }
                                    _clickedPiece->setCordinate( cord ); // changing location if everything is valid.
                                    if ( _player1->checkPromotion( _clickedPiece ) ) // handling promotion condition for black piece.
                                    {
                                        _board->compBlackProm();
                                        _player2->setCord( cord );
                                    }                       
                                    _clickedPiece = nullptr;
                                    _isWhiteTurn = !_isWhiteTurn;
                                    _player2->removeMoves( );
                                    _board->removeHighlight(  );
                                }
                                else
                                {
                                    _clickedPiece = nullptr;
                                    _player2->removeMoves(  );
                                    _board->removeHighlight(  );
                                    break;
                                }
                            }
                        }   
                        else
                        {
                            _clickedPiece = nullptr; // cannot move to the same location where clickedpiece is present.
                            _player1->removeMoves(  );
                            _player2->removeMoves(  );
                            _board->removeHighlight(  );                         
                        }
                    }
                    // checking if clicked location has any piece and Initializing _clickedPiece variable.
                    else
                    {
                         if ( _isWhiteTurn )
                         {
                             _clickedPiece = _player1->pieceClickedWhite( cord );
                            if ( _clickedPiece )
                            {
                                _player1->generateMoves( _clickedPiece );
                                _player1->filterLegalMoves( _clickedPiece );
                                _board->highlight( _player1->getMoves(  ) ); 
                            }
                         }
                         else
                         {
                             _clickedPiece = _player2->pieceClickedBlack( cord );
                            if ( _clickedPiece )
                            {
                                _player2->generateMoves( _clickedPiece );
                                _player2->filterLegalMoves( _clickedPiece );
                                _board->highlight( _player2->getMoves(  ) );
                            }
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
