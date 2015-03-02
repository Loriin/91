#ifndef SERVER_HH_
#define SERVER_HH_

#include <string>
#include <SFML/Network.hpp>
#include "BattleConnect.hh"

class Server
{
public:

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
  Server(BattleConnect*);
  ~Server();
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
private:
  BattleConnect			*_module;
private:
  std::vector<sf::Packet>	_cmd;
  sf::TcpSocket			_socket;
  //sf::Thread			_th;
  Connect			_connect;
  std::string			_ip;
  void				(Server::*_execute[6])(sf::Packet&);
};

#endif
