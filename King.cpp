#include "King.hh"
#include "Engine.hh"

King::King(Engine *engine, Clan clan) : Card(engine, clan)
{
  _name = "Roi des " + getClanName();
  _picture = _engine->getSources()->getSprite(1);
}

King::~King()
{
}
