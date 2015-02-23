#include "Deck.hh"
#include <iostream>

Deck::Deck(Engine *e) : _engine(e)
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

Deck::~Deck()
{

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
  _cards.push_back(new Valet (_engine, c));
  _cards.push_back(new Valet (_engine, c));
  _cards.push_back(new Foo   (_engine, c));
  _cards.push_back(new Foo   (_engine, c));
  _cards.push_back(new Foo   (_engine, c));
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
  for (unsigned int i = 0; i < _cards.size(); i++)
    _cards[i]->setPosition(_x, _y);
}

bool			Deck::clickOn(std::size_t x, std::size_t y)
{
  if (isEmpty())
    return (false);
  return (_cards[_cards.size() - 1]->clickOn(x, y));
}
