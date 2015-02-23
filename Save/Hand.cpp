#include "Hand.hh"
#include <iostream>

Hand::Hand() : _card(0)
{

}

Hand::~Hand()
{
  
}

void		Hand::setPosition(size_t x, size_t y)
{
  _x = x;
  _y = y;
  if (_card)
    _card->setPosition(_x, _y);
}

void		Hand::takeCard(Card *card)
{
  if (_card)
    return;
  _card = card;
  _card->flip(true);
  std::cout << "Vous piochez la carte " << card->getName() << std::endl;
}

Card		*Hand::giveCard()
{
  Card		*card = _card;

  if (!_card)
    return (0);
  _card = 0;
  return (card);
}

void		Hand::drawHand()
{
  if (_card)
    _card->drawCard();
}

bool		Hand::isEmpty()
{
  return (_card == 0);
}
