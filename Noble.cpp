#include "Noble.hh"
#include "Engine.hh"

Noble::Noble(Engine *engine, Clan clan) : Card(engine, clan)
{
  _name = "Noble " + getClanName();
  _picture = _engine->getSources()->getSprite(6);
}

Noble::~Noble()
{
}
