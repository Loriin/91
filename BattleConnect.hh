#ifndef BATTLECONNECT_HH_
#define BATTLECONNECT_HH_

#include <string>
#include <SFML/Network.hpp>
#include "Module.hh"
#include "Deck.hh"
#include "Hand.hh"

class Well;
class Field;
class Engine;
class Server;

class BattleConnect : public Module
{
public:
  // Enum
  typedef enum	eBattlePhase
    {
      DrawPhase,
      MainPhase,
      EndPhase,
      ServerPhase
    }		BattlePhase;

  typedef enum	eConnect
    {
      Disconnected,
      Wait,
      Start,
      Run,
      Exit,
      Stop
    }		Connect;

public:
  // Constructeur
  BattleConnect(Engine *, unsigned int = 0, unsigned int = 0);
  ~BattleConnect();
public:
  // Module
  void drawModule();
  void eventModule();
  void updateModule();
  void closeModule();
  void openModule();
  void setPosition(int, int);

public:
  // Indispensable
  bool drawEvent();
  bool mainEvent();
  void textEvent();
  Deck &getDeck();
  void setPhase(BattlePhase);
  BattlePhase getPhase();

public:
  // Network
  void moveOpponent(std::size_t, std::size_t);
  void dropCard(Card::CardType, Card::Clan, bool = false);
  void dropWell(std::size_t, bool = false);
  void dropBoard(std::size_t, std::size_t, bool = false);
  void putWell(std::size_t, bool = false);
  void putBoard(std::size_t, bool = false);

private:
  // Indispensable
  Deck		_deck;
  Hand		_hand;
  Hand		_handE;

  sf::Text	_txt;
  sf::Font	_font;

private:
  // Zone
  std::vector<sf::RectangleShape*> _toto;
  Field		*_fields[3];
  Field		*_fieldsE[3];
  Well		*_well;
  BattlePhase	_phase;

private:
  std::string			_ip;
  Server			*_server;
};

#endif
