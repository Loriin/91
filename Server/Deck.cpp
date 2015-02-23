#include "Deck.hh"

Deck::Deck()
{
  Deck::Card mage;
  mage._type = Mage;
  mage._clan = Deck::NoClan;

  srand((int)time(NULL));
  addCard(Deck::Igvar);
  addCard(Deck::Shadow);
  addCard(Deck::Krion);
  addCard(Deck::Starn);
  addCard(Deck::Zarron);
  _cards.push_back(mage);
  check();
  check();
  check();
}

Deck::~Deck()
{

}

void		Deck::addCard(Deck::CardClan clan)
{
  if (_cards.size() == 0)
    _cards.push_back(makeCard(Deck::King, clan));
  else
    _cards.insert(_cards.begin() + (rand() % _cards.size()),
		  makeCard(Deck::King, clan));

  _cards.insert(_cards.begin() + (rand() % _cards.size()),
		makeCard(Deck::Queen, clan));
  
  _cards.insert(_cards.begin() + (rand() % _cards.size()),
		makeCard(Deck::Knigth, clan));
  _cards.insert(_cards.begin() + (rand() % _cards.size()),
		makeCard(Deck::Knigth, clan));

  _cards.insert(_cards.begin() + (rand() % _cards.size()),
		makeCard(Deck::Clerc, clan));
  _cards.insert(_cards.begin() + (rand() % _cards.size()),
		makeCard(Deck::Clerc, clan));
  
  _cards.insert(_cards.begin() + (rand() % _cards.size()),
		makeCard(Deck::Valet, clan));
  _cards.insert(_cards.begin() + (rand() % _cards.size()),
		makeCard(Deck::Valet, clan));
  _cards.insert(_cards.begin() + (rand() % _cards.size()),
		makeCard(Deck::Valet, clan));

  for (std::size_t i = 0; i < 9; i++)
    _cards.insert(_cards.begin() + rand() % _cards.size(),
		  makeCard(Deck::Noble, clan));

}

Deck::Card		Deck::makeCard(Deck::CardType type, Deck::CardClan clan)
{
  Deck::Card	c;

  c._type = type;
  c._clan = clan;
  return (c);
}

Deck::Card		Deck::popCard()
{
  Deck::Card		c;

  c = _cards.back();
  _cards.pop_back();
  return (c);
}

void			Deck::pushCard(Deck::Card c)
{
  _cards.insert(_cards.begin(), c);
}

void			Deck::check()
{
  std::vector<Deck::Card>	d;
  Deck::Card			u;
  std::size_t			r;

  while (_cards.size() > 0)
    {
      r = rand() % _cards.size();
      u = _cards[r];
      _cards.erase(_cards.begin() + r);
      d.push_back(u);
    }
  while (d.size() > 0)
    {
      r = rand() % d.size();
      u = d[r];
      d.erase(d.begin() + r);
      _cards.push_back(u);
    }
}

void			Deck::getCard(sf::Packet &packet)
{
  sf::Uint32		type;
  sf::Uint32		clan;
  Deck::Card		card;

  card = popCard();
  type = card._type;
  clan = card._clan;

  packet << 1 << type << clan;
}
