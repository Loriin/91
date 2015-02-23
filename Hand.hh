#ifndef HAND_HH_
#define HAND_HH_

#include <string>
#include "Card.hh"

class Hand
{
public:
  Hand();
  ~Hand();
  void		setPosition(size_t, size_t);
  void		takeCard(Card*);
  Card		*giveCard();
  void		drawHand();
  bool		isEmpty();
private:
  size_t	_x;
  size_t	_y;
  Card		*_card;
};

#endif
