#ifndef QUEEN_HH_
#define QUEEN_HH_

#include <string>
#include "Card.hh"

class Engine;

class Queen : public Card
{
public:
  Queen(Engine*, Clan = None);
  ~Queen();
};

#endif
