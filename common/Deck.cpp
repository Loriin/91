#include "Deck.hh"

Deck::Deck()
{
  _value[0][0] = 8;
  _value[0][1] = 10;

  _value[1][0] = 7;
  _value[1][1] = 9;

  _value[2][0] = 5;
  _value[2][1] = 6;

  _value[3][0] = 4;
  _value[3][1] = 6;

  _value[4][0] = 2;
  _value[4][1] = 3;

  _value[5][0] = 1;
  _value[5][1] = 2;

  createPage(Card::F1);
  melt();
  createPage(Card::F2);
  melt();
  createPage(Card::F3);
  melt();
  createPage(Card::F4);
  melt();
  createPage(Card::F5);
  melt();

  Card	mage(Card::MAGE, Card::NONE, 30, 0);
  _deck.push_back(mage);

  melt();
}

Deck::~Deck()
{

}

bool		Deck::isEmpty()
{
  return (_deck.size() == 0);
}

Card		Deck::drawCard()
{
  Card		card(_deck.back());

  _deck.pop_back();
  return (card);
}

void		Deck::melt()
{
  std::vector<Card>	tmp;
  std::size_t		rdm;

  while (!isEmpty())
    tmp.push_back(drawCard());
  while (tmp.size() > 0)
    {
      rdm = Randomer::random(tmp.size());
      _deck.push_back(tmp[rdm]);
      tmp.erase(tmp.begin() + rdm);
    }
}

Card		Deck::createCard(Card::TYPE t, Card::FACTION f, std::size_t i)
{
  Card		card(t, f, _value[i][0], _value[i][1]);;

  return (card);
}

void		Deck::createPage(Card::FACTION t)
{
  _deck.push_back(createCard(Card::KING, t, 0));
  _deck.push_back(createCard(Card::QUEEN, t, 1));

  _deck.push_back(createCard(Card::KNIGTH, t, 2));
  _deck.push_back(createCard(Card::KNIGTH, t, 2));

  _deck.push_back(createCard(Card::CLERC, t, 3));
  _deck.push_back(createCard(Card::CLERC, t, 3));

  _deck.push_back(createCard(Card::VALET, t, 4));
  _deck.push_back(createCard(Card::VALET, t, 4));
  _deck.push_back(createCard(Card::VALET, t, 4));

  for (std::size_t j = 0; j < 9; j++)
    _deck.push_back(createCard(Card::NOBLE, t, 5));
}
