#ifndef FOO_HH_
#define FOO_HH_

#include <string>
#include "Card.hh"

class Engine;

class Foo : public Card
{
public:
  Foo(Engine*, Clan = None);
  ~Foo();
};

#endif
