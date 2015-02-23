#include "Well.hh"

Well::Well(Engine *e) : _engine(e), _backWell(e->getRender(), 0, 0, 0, 650, 300), _x(0), _y(0)
{
  for (std::size_t i = 0; i < 3; i++)
    {
      _well[i].width = 200;
      _well[i].height = 300;
    }
}

Well::~Well()
{

}

bool		Well::isEmpty(std::size_t n)
{
  if (n >= 3)
    return (true);
  return (_pile[n].size() == 0);
}

bool		Well::isFull(std::size_t n)
{
  if (n >= 3)
    return (true);
  return (_pile[n].size() == 5);
}

void		Well::setPosition(std::size_t x, std::size_t y)
{
  _x = x;
  _y = y;
  _backWell.setPosition(x, y);
  for (std::size_t i = 0; i < 3; i++)
    {
      _well[i].left = 15 + x + (i*210);
      _well[i].top = y;
    }
}

std::size_t	Well::hoverCard(std::size_t x, std::size_t y)
{
  for (std::size_t i = 0; i < 3; i++)
    if (_well[i].contains(x, y))
      return (i);
  if (_backWell.isClicked(x, y))
    return (Well::IsIn);
  return (Well::IsOut);
}

void		Well::addCard(Card *c, std::size_t n)
{
  if (n >= 3)
    return;
  c->setPosition(_x + 15 + (n * 210), _y);
  _pile[n].push_front(c);
}

Card		*Well::popCard(std::size_t n)
{
  Card		*c;

  if (n >= 3 || isEmpty(n))
    return (0);
  c = _pile[n].front();
  _pile[n].pop_front();
  return (c);
}

void		Well::drawWell()
{
  for (std::size_t i = 0; i < 3; i++)
    if (_pile[i].size() > 0)
      _pile[i].front()->drawCard();
}
