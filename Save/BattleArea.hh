#ifndef BATTLEAREA_HH_
#define BATTLEAREA_HH_

#include <string>
#include "Module.hh"
#include "Deck.hh"
#include "Hand.hh"

class Well;
class Field;
class Engine;

class BattleArea : public Module
{
public:

  typedef enum	eBattlePhase
    {
      DrawPhase,
      MainPhase,
      EndPhase,
      ServerPhase
    }		BattlePhase;

public:
  BattleArea(Engine *, unsigned int = 0, unsigned int = 0);
  ~BattleArea();
  void drawModule();
  void eventModule();
  void updateModule();
  void closeModule();
  void openModule();
  bool drawEvent();
  bool mainEvent();
private:
  Deck		_deck;
  Hand		_hand;
private:
  std::vector<sf::RectangleShape*> _toto;
  Field		*_fields[3];
  Well		*_well;
  BattlePhase	_phase;
};

#endif
