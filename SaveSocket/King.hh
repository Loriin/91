#ifndef KING_HH_
#define KING_HH_

#include <string>
#include "Card.hh"

class Engine;

class King : public Card
{
public:
  King(Engine*, Clan = None);
  ~King();
};

#endif
