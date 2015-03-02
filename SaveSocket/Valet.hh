#ifndef VALET_HH_
#define VALET_HH_

#include <string>
#include "Card.hh"

class Engine;

class Valet : public Card
{
public:
  Valet(Engine*, Clan = None);
  ~Valet();
};

#endif
