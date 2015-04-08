#ifndef DECK_HH_
#define DECK_HH_

#include <string>
#include <vector>

#include "Card.hh"
#include "Randomer.hh"

class Deck
{
public:
  Deck();
  ~Deck();
  bool			isEmpty();
  Card			drawCard();
  void			melt();

protected:
  Card			createCard(Card::TYPE, Card::FACTION, std::size_t);
  void			createPage(Card::FACTION);
  std::vector<Card>	_deck;
  std::size_t		_value[6][2];
};

#endif
