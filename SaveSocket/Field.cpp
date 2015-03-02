#include "Field.hh"

Field::Field(Engine *e) : _engine(e), _backField(0), _score(0)
{
  _backField = new Stikers(_engine->getRender(), 0, 0, 0, 560, 300);
}

Field::~Field()
{
  delete (_backField);
}

void		Field::addCard(Card *c)
{
  if (isFull())
    return;
  c->setPosition(_x + (_pile.size() * 60), _y);
  _pile.push_back(c);
  //organizedCard();
}

bool		Field::isFull()
{
  return (_pile.size() == 7);
}

bool		Field::isEmpty()
{
  return (_pile.size() == 0);
}

Card		*Field::drop(size_t pos)
{
  if (pos >= _pile.size())
    return (0);
  Card	*ret = _pile[_pile.size() - 1];
  _pile.pop_back();
  //organizedCard();
  return (ret);
}

void		Field::setPosition(std::size_t x, std::size_t y)
{
  _x = x;
  _y = y;
  _backField->setPosition(_x, _y);
  for (size_t i = 0; i < _pile.size(); i++)
    _pile[i]->setPosition(_x + (i * 60), _y);
}

void		Field::drawField(std::size_t n)
{
  Card	*c = 0;

  if (n != 7 && _pile.size() > n)
    c = _pile[n];
  for (std::size_t i = 0; i < _pile.size(); i++)
    if (_pile[i] != c)
      _pile[i]->drawCard();
  if (c)
    c->drawCard();
}

std::size_t	Field::hoverCard(std::size_t x, std::size_t y) const
{
  std::size_t	max = _pile.size();

  for (std::size_t i = 0; i < max; i++)
    if (_pile[max - i - 1]->clickOn(x, y))
      return (max - i - 1);
  if (_backField->isClicked(x, y))
    return (7);
  return (8);
}

void		Field::organizedCard()
{
  for (std::size_t i = 0; i < _pile.size(); i++)
    _pile[i]->setPosition(_x + (i*60), _y);
}

int		Field::getScore() const
{
  return (_score);
}
