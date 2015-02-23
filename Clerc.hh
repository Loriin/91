#ifndef CLERC_HH_
#define CLERC_HH_

#include <string>
#include "Card.hh"

class Engine;

class Clerc : public Card
{
public:
  Clerc(Engine*, Clan = None);
  ~Clerc();
};

#endif
