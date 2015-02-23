#include "Foo.hh"
#include "Engine.hh"

Foo::Foo(Engine *engine, Clan clan) : Card(engine, clan)
{
  _name = "Fou " + getClanName();
  _picture = _engine->getSources()->getSprite(5);
}

Foo::~Foo()
{
  delete (_picture);
}
