#include "Valet.hh"
#include "Engine.hh"

Valet::Valet(Engine *engine, Clan clan) : Card(engine, clan)
{
  _name = "Valet du clan " + getClanName();
  _picture = _engine->getSources()->getSprite(4);
}

Valet::~Valet()
{
}
