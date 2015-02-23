#include "Knight.hh"
#include "Engine.hh"

Knight::Knight(Engine *engine, Clan clan) : Card(engine, clan)
{
  _name = "Chevalier du roi " + getClanName();
  _picture = _engine->getSources()->getSprite(3);
}

Knight::~Knight()
{
}
