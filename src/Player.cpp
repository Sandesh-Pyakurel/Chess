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

    Piece *Player::pieceClicked(struct Cordinate cord)
    {
        for (int i = 0; i < _pieces.size(); i++)
        {
            if ((_pieces.at(i)->getCordinate() == cord))
            {
                return _pieces.at(i);
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
            int flag1 = 0;
            for (int i = 0; i < _pieces.size(); i++)
            {
                if (cord == _pieces.at(i)->getCordinate())
                {
                    std::cout<<"hello.\n";
                    flag = 1;
                }
                if ( clickedPiece->getCordinate().y == BOARD_POSITION_Y + 6 * BLOCK_SIZE)
                {
                    if (!(cord3 == _pieces.at(i)->getCordinate()))
                    {
                        flag1 = 1;
                    }
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
            int flag1 = 0;
            for (int i = 0; i < _pieces.size(); i++)
            {
                if (cord == _pieces.at(i)->getCordinate())
                {
                    flag = 1;
                }
                if ( clickedPiece->getCordinate(  ).y == BOARD_POSITION_Y + 1 * BLOCK_SIZE)
                {
                    if (!(cord3 == _pieces.at(i)->getCordinate()))
                    {
                        flag1 = 1;
                    }
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
