#ifndef KNIGHT_HH_
#define KNIGHT_HH_

#include <string>
#include "Card.hh"

class Engine;

class Knight : public Card
{
public:
  Knight(Engine*, Clan = None);
  ~Knight();
};

#endif
