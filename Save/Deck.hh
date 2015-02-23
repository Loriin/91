#ifndef DECK_HH_
#define DECK_HH_

#include <string>
#include "King.hh"
#include "Queen.hh"
#include "Knight.hh"
#include "Valet.hh"
#include "Foo.hh"
#include "Noble.hh"
#include "Mage.hh"
#include <cstdlib>
#include <ctime>

class Deck
{
public:
  Deck(Engine *);
  ~Deck();
  bool	isEmpty();
  Card	*draw();
  void	check();
  void	drawDeck();
  void	addCard(Card::Clan);
  void	setPosition(std::size_t, std::size_t);
  bool  clickOn(std::size_t, std::size_t);
private:
  std::vector<Card*>	_cards;
  Engine		*_engine;
  std::size_t		_x;
  std::size_t		_y;
};

#endif
