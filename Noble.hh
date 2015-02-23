#ifndef NOBLE_HH_
#define NOBLE_HH_

#include <string>
#include "Card.hh"

class Engine;

class Noble : public Card
{
public:
  Noble(Engine*, Clan = None);
  ~Noble();
};

#endif
