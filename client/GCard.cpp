#include "GCard.hh"
#include "Engine.hh"

GCard::GCard(Engine *e, Card::TYPE t, Card::FACTION f,
	     std::size_t vu, std::size_t vg) : Card(t, f, vu, vg), _engine(e), _img(0)
{
  // penser à set img
}

GCard::GCard(Engine *e, const Card &c) : Card(c), _engine(e)
{

}

GCard::~GCard()
{
  delete (_img);
}

void		GCard::drawCard()
{
  if (_img)
    _engine->getRender()->draw(*_img);
}
