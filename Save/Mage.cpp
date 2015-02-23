#include "Mage.hh"
#include "Engine.hh"

Mage::Mage(Engine *engine, Clan clan) : Card(engine, clan)
{
  _name = "Grand mage incontesté !";
  _picture = _engine->getSources()->getSprite(7);
}

Mage::~Mage()
{
  delete (_picture);
}
