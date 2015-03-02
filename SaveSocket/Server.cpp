#include "Server.hh"
#include <iostream>

Server::Server(BattleConnect *m) : _module(m)
{

  _execute[0] = &Server::moveOpponent;
  _execute[1] = &Server::dropCard;
  _execute[2] = &Server::dropWell;
  _execute[3] = &Server::dropBoard;
  _execute[4] = &Server::putWell;
  _execute[5] = &Server::putBoard;
}

Server::~Server()
{

}


void Server::sendCommand(std::size_t cmd, std::size_t p1, std::size_t p2)
{
  sf::Packet	packet;
  sf::Uint32	Ucmd = cmd;
  sf::Uint32	Up1 = p1;
  sf::Uint32	Up2 = p2;
 
  std::cout << "Ajout de la commande " << cmd << " dans la pile." << std::endl;
  packet << Ucmd << Up1 << Up2;
  _cmd.push_back(packet);
}

// void Server::updateModule()
// {
//   if ((_connect == Server::Start || _connect == Server::Run) &&
//       _phase == Server::MainPhase)
//     sendCommand(0, _x, _y);
//   std::size_t	max = _cmd.size();
//   if (max == 0)
//     return;
//   std::cout << "Entré dans l'update." << std::endl;

//   for (std::size_t i = 0; i < max; i++)
//     {
//       while (_socket.send(_cmd[0]) != sf::Socket::Done)
// 	std::cout << "retry de la commande !" << std::endl;
//       std::cout << "Commande envoyé !" << std::endl;
//       _cmd.erase(_cmd.begin());
//     }
// }

// bool Server::receiveSpecial(sf::Packet &p, sf::Uint32 pos)
// {
//   (void)p;
//   if (!(pos < 304 && pos >= 300))
//     return (false);
//   if (pos == 300)
//     _phase = Server::DrawPhase;
//   else if (pos == 301)
//     _phase = Server::MainPhase;
//   return (true);
// }

// void Server::listenSocket()
// {
//   sf::Packet	packet;
//   sf::Uint32	pos;

//   while (_connect == Server::Wait)
//     {
//       if (_socket.receive(packet) == sf::Socket::Done)
// 	{
// 	  packet >> pos;
// 	  if (receiveSpecial(packet, pos))
// 	    _connect = Server::Start;
// 	  packet.clear();
// 	}
//       else
// 	{
// 	  _connect = Server::Disconnected;
// 	  return;
// 	}
//       sf::sleep(sf::milliseconds(10));
//     }

//   while (_connect != Server::Stop && 
// 	 _connect != Server::Exit)
//     {
//       //std::cout << "Ecoute des commandes." << std::endl;
//       if (_socket.receive(packet) == sf::Socket::Done)
// 	{
// 	  packet >> pos;
// 	  //std::cout << "Reception de la commande " << pos << std::endl;
// 	  if (pos < 6)
// 	    (this->*_execute[pos])(packet);
// 	  else
// 	    receiveSpecial(packet, pos);
// 	  packet.clear();
// 	}
//       else
// 	{
// 	  _connect = Server::Disconnected;
// 	  _txt.setString("Vous avez été déconnecté du serveur...");
// 	  return;
// 	}
//       sf::sleep(sf::milliseconds(10));
//     }
//   _connect = Server::Stop;
// }

void Server::moveOpponent(sf::Packet &packet)
{
  sf::Uint32	x;
  sf::Uint32	y;
  bool		oppenent;

  packet >> oppenent;
  packet >> x;
  packet >> y;
  if (oppenent)
    _module->moveOpponent(x, y);
}

void Server::dropCard(sf::Packet &packet)
{
  bool		oppenent;
  sf::Uint32	type;
  sf::Uint32	clan;

  packet >> oppenent;
  packet >> type;
  packet >> clan;

  _module->dropCard(_module->getDeck().gType(type), _module->getDeck().gClan(clan), oppenent);  
  _module->setPhase(BattleConnect::ServerPhase);
}

void Server::dropWell(sf::Packet &packet)
{
  sf::Uint32	well;
  bool		oppenent;

  packet >> oppenent;
  packet >> well;
  _module->dropWell(well, oppenent);
  _module->setPhase(BattleConnect::ServerPhase);
}

void Server::dropBoard(sf::Packet &packet)
{
  sf::Uint32	board;
  sf::Uint32	pos;
  bool		oppenent;

  packet >> oppenent;
  packet >> board >> pos;
  _module->dropBoard(board, pos, oppenent);
  _module->setPhase(BattleConnect::ServerPhase);
}

void Server::putWell(sf::Packet &packet)
{
  sf::Uint32	well;
  bool		oppenent;

  packet >> oppenent;
  packet >> well;
  _module->putWell(well, oppenent);
  _module->setPhase(BattleConnect::ServerPhase);
}

void Server::putBoard(sf::Packet &packet)
{
  sf::Uint32	board;
  bool		oppenent;

  packet >> oppenent;
  packet >> board;
  _module->putBoard(board, oppenent);
  _module->setPhase(BattleConnect::ServerPhase);
}
