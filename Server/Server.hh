#ifndef SERVER_HH_
#define SERVER_HH_

#include <string>
#include <SFML/Network.hpp>
#include <iostream>
#include "Deck.hh"

class Server
{
public:

  typedef struct	sPlayer
  {
    sf::Packet		_packet;
    sf::TcpSocket	_socket;
    std::string		_name;
    int			_score;
  }			Player;

  typedef enum		ePhase
    {
      DrawPhase = 300,
      MainPhase = 301,
      EndPhase = 302,
      ServerPhase = 303
    }			Phase;

public:
  Server();
  ~Server();
  void start();
  void sendSocket(sf::TcpSocket&, sf::Packet&, bool);
  void sendPhase(Player&, Phase);
  void game();
  void deletePlayer(Player&);
  void sendReverse(Player&, Player&);
  void changePhase(sf::Uint32, Player&, Player&);
private:
  Player		_player[2];
  Deck			_deck;
};

#endif
