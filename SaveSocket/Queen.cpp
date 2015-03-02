#include "Queen.hh"
#include "Engine.hh"

Queen::Queen(Engine *engine, Clan clan) : Card(engine, clan)
{
  _name = "Reine des " + getClanName();
  _picture = _engine->getSources()->getSprite(2);
}

Queen::~Queen()
{
}
