#include "BoardPlayer.hh"
#include "BoardGame.hh"

BoardPlayer::BoardPlayer(int nb_card = 7) :
  _tab_fields(nb_card),
  _score(0),
  _hand(false)
{
}

BoardPlayer::~BoardPlayer()
{
}
