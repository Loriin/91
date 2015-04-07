#ifndef CARD_HH_
#define CARD_HH_

#include <string>

class Card
{
public:
  enum TYPE
    {
      KING,
      QUEEN,
      KNIGTH,
      CLERC,
      VALET,
      NOBLE,
      MAGE
    };
  enum	FACTION
    {
      NONE = -1,
      F1 = 0,
      F2,
      F3,
      F4,
      F5
    };

public:
  Card(TYPE, FACTION, std::size_t = 0, std::size_t = 0);
  ~Card();
  std::size_t	getValue(bool = false);
  TYPE		getType();
  FACTION	getFaction();

protected:
  TYPE		_type;
  FACTION	_faction;
  std::size_t	_value[2];
};

#endif
