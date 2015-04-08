#ifndef GCARD_HH_
#define GCARD_HH_

#include <string>
#include <SFML/Graphics.hpp>

#include "../common/Card.hh"

class Engine;

class GCard : public Card
{
public:
  GCard(Engine*, TYPE, FACTION, std::size_t = 0, std::size_t = 0);
  GCard(Engine*, const Card &c);
  ~GCard();
  void drawCard();
private:
  Engine	*_engine;
  sf::Sprite	*_img;
};

#endif
