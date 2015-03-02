#include "Clerc.hh"
#include "Engine.hh"

Clerc::Clerc(Engine *engine, Clan clan) : Card(engine, clan)
{
  _name = "Clerc " + getClanName();
  _picture = _engine->getSources()->getSprite(5);
}

Clerc::~Clerc()
{
}
