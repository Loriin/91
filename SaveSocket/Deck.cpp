#include "Deck.hh"
#include <iostream>

Deck::Deck(Engine *e) : _engine(e), _ref(e)
{
  _make[0] = &Deck::makeKing;
  _make[1] = &Deck::makeQueen;
  _make[2] = &Deck::makeKnigth;
  _make[3] = &Deck::makeClerc;
  _make[4] = &Deck::makeValet;
  _make[5] = &Deck::makeNoble;
}

Deck::~Deck()
{

}

void			Deck::initialize()
{
  addCard(Card::Igvar);
  addCard(Card::Shadow);
  addCard(Card::Krion);
  addCard(Card::Starn);
  addCard(Card::Zarron);
  _cards.push_back(new Mage(_engine));
  check();
  check();
  check();
}

bool			Deck::isEmpty()
{
  return (_cards.size() == 0);
}

Card			*Deck::draw()
{
  if (isEmpty())
    return (0);
  Card			*ret = _cards[_cards.size() - 1];
  _cards.pop_back();
  return (ret);
}

void			Deck::check()
{
  std::vector<Card*>	checker;
  Card			*card;
  size_t		rdm;

  while (!isEmpty())
    checker.push_back(draw());
  while (checker.size() > 0)
    {
      rdm = rand() % checker.size();
      card = checker[rdm];
      checker.erase(checker.begin() + rdm);
      _cards.push_back(card);
    }
}

void			Deck::drawDeck()
{
  if (_cards.size() > 0)
    _cards[_cards.size() - 1]->drawCard();
}

void			Deck::addCard(Card::Clan c)
{
  _cards.push_back(new King  (_engine, c));
  _cards.push_back(new Queen (_engine, c));
  _cards.push_back(new Knight(_engine, c));
  _cards.push_back(new Knight(_engine, c));
  _cards.push_back(new Clerc (_engine, c));
  _cards.push_back(new Clerc (_engine, c));
  _cards.push_back(new Valet (_engine, c));
  _cards.push_back(new Valet (_engine, c));
  _cards.push_back(new Valet (_engine, c));
  _cards.push_back(new Noble (_engine, c));
  _cards.push_back(new Noble (_engine, c));
  _cards.push_back(new Noble (_engine, c));
  _cards.push_back(new Noble (_engine, c));
  _cards.push_back(new Noble (_engine, c));
  _cards.push_back(new Noble (_engine, c));
  _cards.push_back(new Noble (_engine, c));
  _cards.push_back(new Noble (_engine, c));
  _cards.push_back(new Noble (_engine, c));
}

void			Deck::setPosition(std::size_t x, std::size_t y)
{
  _x = x;
  _y = y;

  _ref.setPosition(_x, _y);
  for (unsigned int i = 0; i < _cards.size(); i++)
    _cards[i]->setPosition(_x, _y);
}

bool			Deck::clickOn(std::size_t x, std::size_t y, bool verif)
{
  if (isEmpty() && verif)
    return (false);
  return (_ref.clickOn(x, y));
  //return (_cards[_cards.size() - 1]->clickOn(x, y));
}

Card			*Deck::makeCard(Card::CardType type, Card::Clan clan)
{
  if (type == Card::Mage)
    return (new Mage(_engine));
  return ((this->*_make[type])(clan));
}

Card			*Deck::makeKing(Card::Clan clan)
{
  return (new King(_engine, clan));
}

Card			*Deck::makeQueen(Card::Clan clan)
{
  return (new Queen(_engine, clan));
}

Card			*Deck::makeKnigth(Card::Clan clan)
{
  return (new Knight(_engine, clan));
}

Card			*Deck::makeClerc(Card::Clan clan)
{
  return (new Clerc(_engine, clan));
}

Card			*Deck::makeValet(Card::Clan clan)
{
  return (new Valet(_engine, clan));
}

Card			*Deck::makeNoble(Card::Clan clan)
{
  return (new Noble(_engine, clan));
}


Card::CardType		Deck::gType(sf::Uint32 type)
{
  if (type == 0)
    return (Card::King);
  else if (type == 1)
    return (Card::Queen);
  else if (type == 2)
    return (Card::Knigth);
  else if (type == 3)
    return (Card::Valet);
  else if (type == 4)
    return (Card::Valet);
  else if (type == 5)
    return (Card::Noble);
  else
    return (Card::Mage);
}

Card::Clan		Deck::gClan(sf::Uint32 clan)
{
  if (clan == 0)
    return (Card::Igvar);
  else if (clan == 1)
    return (Card::Shadow);
  else if (clan == 2)
    return (Card::Krion);
  else if (clan == 3)
    return (Card::Starn);
  else if (clan == 4)
    return (Card::Zarron);
  else
    return (Card::None);
}
