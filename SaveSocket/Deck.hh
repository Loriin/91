#ifndef DECK_HH_
#define DECK_HH_

#include <string>
#include "King.hh"
#include "Queen.hh"
#include "Knight.hh"
#include "Valet.hh"
#include "Clerc.hh"
#include "Noble.hh"
#include "Mage.hh"
#include <cstdlib>
#include <ctime>

class Deck
{

public:
  Deck(Engine *);
  ~Deck();

public:
  bool	isEmpty();
  Card	*draw();
  void	check();
  void	drawDeck();
  void	addCard(Card::Clan);
  void	setPosition(std::size_t, std::size_t);
  bool  clickOn(std::size_t, std::size_t, bool = false);
  void	initialize();
  Card	*makeCard(Card::CardType, Card::Clan);

public:
  Card	*makeKing(Card::Clan);
  Card	*makeQueen(Card::Clan);
  Card	*makeKnigth(Card::Clan);
  Card	*makeClerc(Card::Clan);
  Card	*makeValet(Card::Clan);
  Card	*makeNoble(Card::Clan);

public:
  Card::CardType	gType(sf::Uint32);
  Card::Clan		gClan(sf::Uint32);
private:
  std::vector<Card*>	_cards;
  Engine		*_engine;
  std::size_t		_x;
  std::size_t		_y;
  Mage			_ref;
private:
  Card		*(Deck::*_make[6])(Card::Clan);
};

#endif
