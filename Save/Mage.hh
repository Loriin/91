#ifndef MAGE_HH_
#define MAGE_HH_

#include <string>
#include "Card.hh"

class Engine;

class Mage : public Card
{
public:
  Mage(Engine*, Clan = None);
  ~Mage();
};

#endif
