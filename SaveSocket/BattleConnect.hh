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
  // Indispensable
  BattleConnect(Engine *, unsigned int = 0, unsigned int = 0);
  ~BattleConnect();
  void drawModule();
  void eventModule();
  void updateModule();
  void closeModule();
  void openModule();
  bool drawEvent();
  bool mainEvent();
  void textEvent();
  Deck &getDeck();
  void setPhase(BattlePhase);
public:
  // Network
  void sendCommand(std::size_t, std::size_t = 0, std::size_t = 0);
  void listenSocket();
  void moveOpponent(sf::Packet &packet);
  void dropCard(sf::Packet &packet);
  void dropWell(sf::Packet &packet);
  void dropBoard(sf::Packet &packet);
  void putWell(sf::Packet &packet);
  void putBoard(sf::Packet &packet);
  bool receiveSpecial(sf::Packet&, sf::Uint32);

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
  void		(BattleConnect::*_execute[6])(sf::Packet&);
  Well		*_well;
  BattlePhase	_phase;

private:
  // NetWork
  std::vector<sf::Packet>	_cmd;
  sf::TcpSocket			_socket;
  sf::Thread			_th;
  Connect			_connect;
  std::string			_ip;
  Server			*_server;
};

#endif
