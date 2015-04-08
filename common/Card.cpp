#include "Card.hh"

Card::Card(Card::TYPE type, Card::FACTION faction,
	   std::size_t s1, std::size_t s2) : _type(type), _faction(faction)
{
  _value[0] = s1;
  _value[1] = s2;
}

Card::Card(const Card &c) : _type(c._type), _faction(c._faction)
{
  _value[0] = c._value[0];
  _value[1] = c._value[1];
}

Card::~Card()
{

}

std::size_t	Card::getValue(bool group)
{
  if (group)
    return (_value[1]);
  return (_value[0]);
}

Card::TYPE	Card::getType()
{
  return (_type);
}

Card::FACTION	Card::getFaction()
{
  return (_faction);
}
