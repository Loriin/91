#include "Field.hh"

Field::~Field(int nb_card)
{
  _card_tab = new Card[nb_card];
  _alignment = NEUTRAL;
  _is_empty = false;
}

Field::~Field()
{
  delete[] _card_tab;
}
