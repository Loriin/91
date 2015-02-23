#include "Server.hh"

Server::Server()
{

}
Server::~Server()
{

}

void	Server::sendSocket(sf::TcpSocket &socket, sf::Packet &packet, bool oppenent)
{
  sf::Uint32	cmd;
  sf::Uint32	p1;
  sf::Uint32	p2;
  sf::Packet	sender;

  packet >> cmd >> p1 >> p2;
  std::cout << "Reception de la commande " << cmd << std::endl;
  sender << cmd << oppenent << p1 << p2;
  socket.send(sender);
}

void	Server::sendPhase(Server::Player &player, Server::Phase phase)
{
  sf::Uint32	cmd;
  sf::Packet	sender;

  cmd = phase;

  sender << cmd;
  player._socket.send(sender);
}

void	Server::deletePlayer(Server::Player &p)
{
  p._packet.clear();
  p._socket.disconnect();
  p._name = "";
  p._score = 0;
}

void	Server::sendReverse(Server::Player &me, Server::Player &him)
{
  sf::Uint32	cmd;
  sf::Uint32	p1;
  sf::Uint32	p2;
  sf::Packet	sender[2];
  Deck::Card	card;

  std::cout << "Reverse de la commande " << cmd << std::endl;
  me._socket.receive(me._packet);
  me._packet >> cmd >> p1 >> p2;
  if (cmd == 1)
    {
      card = _deck.popCard();
      if (card._type == Deck::None && card._clan == Deck::NoClan)
	{
	  sendPhase(me, Server::DrawPhase);
	  return;
	}
      p1 = card._type;
      p2 = card._clan;
      sender[0] << cmd << p1 << p2;
      sender[1] << cmd << p1 << p2;
    }
  else
    {
      sender[0] << cmd << p1 << p2;
      sender[1] << cmd << p1 << p2;
    }
  me._packet.clear();
  if (cmd != 0)
    sendSocket(me._socket, sender[0], false);
  sendSocket(him._socket, sender[1], true);
  changePhase(cmd, me, him);
}

void	Server::game()
{
  std::cout << "Ip adress : " << sf::IpAddress::getLocalAddress() << " ." << std::endl;

  sf::TcpListener	listener;
  sf::SocketSelector	selector;

  listener.listen(55001);

  while (listener.accept(_player[0]._socket) != sf::Socket::Done);
  selector.add(_player[0]._socket);
  while (listener.accept(_player[1]._socket) != sf::Socket::Done);
  selector.add(_player[1]._socket);

  sendPhase(_player[0], Server::DrawPhase);
  sendPhase(_player[1], Server::ServerPhase);

  while (_player[0]._score != 91 && _player[1]._score != 91)
    {
      if (selector.wait())
	{
	  std::cout << "Commande en ecoute..." << std::endl;
	  if (selector.isReady(_player[0]._socket))
	    sendReverse(_player[0], _player[1]);
	  else if (selector.isReady(_player[1]._socket))
	    sendReverse(_player[1], _player[0]);
	}
    }
  deletePlayer(_player[0]);
  deletePlayer(_player[1]);
}

void	Server::start()
{
  while (true)
    game();
}

void	Server::changePhase(sf::Uint32 cmd, Server::Player &me, Server::Player &him)
{
  switch (cmd)
    {
    case 1 :
      {
	sendPhase(me, Server::MainPhase);
	sendPhase(him, Server::EndPhase);
      }
      break;

    case 2 :
      {
	sendPhase(me, Server::MainPhase);
	sendPhase(him, Server::EndPhase);
      }
      break;

    case 3 :
      {
	sendPhase(me, Server::MainPhase);
	sendPhase(him, Server::EndPhase);
      }
      break;

    case 4 :
      {
	sendPhase(me, Server::EndPhase);
	sendPhase(him, Server::DrawPhase);
      }
      break;

    case 5 :
      {
	sendPhase(me, Server::EndPhase);
	sendPhase(him, Server::DrawPhase);
      }
      break;
    }
}
