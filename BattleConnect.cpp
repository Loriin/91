#include "BattleConnect.hh"
#include "Engine.hh"
#include "Field.hh"
#include "Well.hh"

#include <iostream>

BattleConnect::BattleConnect(Engine *engine, unsigned int bg,
		       unsigned int music) : Module(engine, bg, music),
					     _deck(engine),
					     _well(0),
					     _phase(BattleConnect::ServerPhase),
					     _th(&BattleConnect::listenSocket, this),
					     _connect(BattleConnect::Disconnected)
{
  _execute[0] = &BattleConnect::moveOpponent;
  _execute[1] = &BattleConnect::dropCard;
  _execute[2] = &BattleConnect::dropWell;
  _execute[3] = &BattleConnect::dropBoard;
  _execute[4] = &BattleConnect::putWell;
  _execute[5] = &BattleConnect::putBoard;



  _deck.check();
  _deck.setPosition(250, 730);

  //			Debut des rectangles;
  //
  _toto.push_back(new sf::RectangleShape(sf::Vector2f(560, 300)));
  _toto.push_back(new sf::RectangleShape(sf::Vector2f(560, 300)));
  _toto.push_back(new sf::RectangleShape(sf::Vector2f(560, 300)));
  _toto.push_back(new sf::RectangleShape(sf::Vector2f(560, 300)));
  _toto.push_back(new sf::RectangleShape(sf::Vector2f(560, 300)));
  _toto.push_back(new sf::RectangleShape(sf::Vector2f(560, 300)));
  //			.
  _toto.push_back(new sf::RectangleShape(sf::Vector2f(650, 300)));
  _toto.push_back(new sf::RectangleShape(sf::Vector2f(650, 300)));
  _toto.push_back(new sf::RectangleShape(sf::Vector2f(650, 300)));
  //			.
  _toto[0]->setFillColor(sf::Color::Red);
  _toto[1]->setFillColor(sf::Color::Red);
  //			.
  _toto[2]->setFillColor(sf::Color::Green);
  _toto[3]->setFillColor(sf::Color::Green);
  //			.
  _toto[4]->setFillColor(sf::Color::Yellow);
  _toto[5]->setFillColor(sf::Color::Yellow);
  //			.
  _toto[6]->setFillColor(sf::Color::Magenta);
  _toto[7]->setFillColor(sf::Color::Magenta);
  _toto[8]->setFillColor(sf::Color::Magenta);
  //			.
  _toto[0]->setPosition(635, 50);
  _toto[1]->setPosition(1335, 390);
  //			.
  _toto[2]->setPosition(25, 50);
  _toto[3]->setPosition(1335, 730);
  //			.
  _toto[4]->setPosition(25, 390);
  _toto[5]->setPosition(720, 730);
  //			.
  _toto[6]->setPosition(1245, 50);
  _toto[7]->setPosition(645, 390);
  _toto[8]->setPosition(25, 730);
  //			.
  //			Fin des rectangles;

  _fields[0] = new Field(_engine);
  _fields[1] = new Field(_engine);
  _fields[2] = new Field(_engine);

  _fieldsE[0] = new Field(_engine);
  _fieldsE[1] = new Field(_engine);
  _fieldsE[2] = new Field(_engine);

  _fields[0]->setPosition(1335, 390);
  _fields[1]->setPosition(1335, 730);
  _fields[2]->setPosition(720, 730);

  _fieldsE[0]->setPosition(635, 50);
  _fieldsE[1]->setPosition(25, 50);
  _fieldsE[2]->setPosition(25, 390);

  _well = new Well(_engine);
  _well->setPosition(645, 390);

  _font.loadFromFile("Ressources/prov.ttf");
  _ip = "";
  _txt.setCharacterSize(50);
  _txt.setFont(_font);
  _txt.setString("Veuillez entrez l'adresse Hote");
  _txt.setColor(sf::Color::Black);
  _txt.setPosition(870, 450);
}

BattleConnect::~BattleConnect()
{
  for (std::size_t i = 0; i < 9; i++)
    delete(_toto[i]);
  delete (_fields[0]);
  delete (_fields[1]);
  delete (_fields[2]);
  delete (_fieldsE[0]);
  delete (_fieldsE[1]);
  delete (_fieldsE[2]);
  delete (_well);
}

void BattleConnect::drawModule()
{
  _engine->getRender()->draw(*_bg);
  if (_connect == BattleConnect::Disconnected)
    {
      _engine->getRender()->draw(_txt);
      return;
    }
  for (unsigned int i = 0; i < 9; i++)
    _engine->getRender()->draw(*_toto[i]);
  _deck.drawDeck();
  for (std::size_t i = 0; i < 3; i++)
    {
      _fields[i]->drawField(_fields[i]->hoverCard(_x, _y));
      _fieldsE[i]->drawField(_fieldsE[i]->hoverCard(_x, _y));
    }
  _well->drawWell();
  _handE.drawHand();
  _hand.setPosition(_x, _y);
  _hand.drawHand();
}

void BattleConnect::textEvent()
{
  // Enter == 13
  // Back = 8

  char code;
  if (_engine->getEvent()->type == sf::Event::TextEntered && _ip.size() <= 30)
    {
      code = static_cast<char>(_engine->getEvent()->text.unicode);
      if (code == 8)
	_ip = "";
      else if (code == 13 && _socket.connect(sf::IpAddress(_ip), 55001) == sf::Socket::Done)
	{
	  _connect = BattleConnect::Wait;
	  _th.launch();
	  return;
	}
      else if (code == 13)
	_txt.setString("Erreur: Veuillez entrez l'adresse Hote");
      else
	_ip += code;
      _txt.setString(_ip);
    }
}

bool BattleConnect::drawEvent()
{
  std::size_t	well;

  if (_engine->getEvent()->type == sf::Event::MouseButtonPressed)
    {
      if (_engine->getEvent()->mouseButton.button == sf::Mouse::Left)
	{
	  if (_deck.clickOn(_x, _y) && _hand.isEmpty())
	    {
	      sendCommand(1);
	      std::cout << "Il doit piocher !" << std::endl;
	      //_hand.takeCard(_deck.draw());
	      return (true);
	    }

	  for (std::size_t i = 0; i < 3; i++)
	    {
	      if (_fields[i]->hoverCard(_x, _y) != Field::IsOut && _hand.isEmpty() &&
		  !_fields[i]->isEmpty())
		{
		  sendCommand(3, i, 0);
		  //_hand.takeCard(_fields[i]->drop());
		  return (true);
		}
	    }
	  if ((well = _well->hoverCard(_x, _y)) < Well::IsIn &&
	      !_well->isEmpty(well) && _hand.isEmpty())
	    {
	      sendCommand(2, well);
	      //_hand.takeCard(_well->popCard(well));
	      return (true);
	    }
	}
    }
  return (false);
}

bool BattleConnect::mainEvent()
{
  std::size_t	well;

  if (_engine->getEvent()->type == sf::Event::MouseButtonPressed)
    {
      if (_engine->getEvent()->mouseButton.button == sf::Mouse::Left)
	{
	  for (std::size_t i = 0; i < 3; i++)
	    {
	      if (_fields[i]->hoverCard(_x, _y) != Field::IsOut && !_hand.isEmpty() &&
		  !_fields[i]->isFull())
		{
		  sendCommand(5, i);
		  //_fields[i]->addCard(_hand.giveCard());
		  return (true);
		}
	    }

	  if ((well = _well->hoverCard(_x, _y)) < Well::IsIn &&
	      !_well->isFull(well) && !_hand.isEmpty())
	    {
	      sendCommand(4, well);
	      //_well->addCard(_hand.giveCard(), well);
	      return (true);

	    }
	}
    }
  return (false);
}

void BattleConnect::eventModule()
{
  if (_connect == BattleConnect::Disconnected)
    {
      textEvent();
      return;
    }
  if (_phase == BattleConnect::EndPhase || _phase == BattleConnect::ServerPhase)
    return;
  else if (_phase == BattleConnect::DrawPhase && drawEvent())
    _phase = BattleConnect::ServerPhase;
  else if (_phase == BattleConnect::MainPhase && mainEvent())
    _phase = BattleConnect::ServerPhase;
}

void BattleConnect::openModule()
{
  //	A faire lors de la saisi de l'adresse IP
  // _socket.connect("192.168.1.16", 55001);
  // _connect = BattleConnect::Start;
  // _th.launch();
  //	___________________

  return;
  _loopSong->setLoop(true);
  _loopSong->play();
}

void BattleConnect::closeModule()
{
  _socket.disconnect();
  return;
  _loopSong->stop();
}

void BattleConnect::sendCommand(std::size_t cmd, std::size_t p1, std::size_t p2)
{
  sf::Packet	packet;
  sf::Uint32	Ucmd = cmd;
  sf::Uint32	Up1 = p1;
  sf::Uint32	Up2 = p2;
 
  std::cout << "Ajout de la commande " << cmd << " dans la pile." << std::endl;
  packet << Ucmd << Up1 << Up2;
  _cmd.push_back(packet);
}

void BattleConnect::updateModule()
{
  if ((_connect == BattleConnect::Start || _connect == BattleConnect::Run) &&
      _phase == BattleConnect::MainPhase)
    sendCommand(0, _x, _y);
  std::size_t	max = _cmd.size();
  if (max == 0)
    return;
  std::cout << "Entré dans l'update." << std::endl;

  for (std::size_t i = 0; i < max; i++)
    {
      _socket.send(_cmd[0]);
      std::cout << "Commande envoyé !" << std::endl;
      _cmd.erase(_cmd.begin());
    }
}

bool BattleConnect::receiveSpecial(sf::Packet &p, sf::Uint32 pos)
{
  (void)p;
  if (!(pos < 304 && pos >= 300))
    return (false);
  if (pos == 300)
    _phase = BattleConnect::DrawPhase;
  else if (pos == 301)
    _phase = BattleConnect::MainPhase;
  return (true);
}

void BattleConnect::listenSocket()
{
  sf::Packet	packet;
  sf::Uint32	pos;

  while (_connect == BattleConnect::Wait)
    {
      if (_socket.receive(packet) == sf::Socket::Done)
	{
	  packet >> pos;
	  if (receiveSpecial(packet, pos))
	    _connect = BattleConnect::Start;
	  packet.clear();
	}
      else
	{
	  _connect = BattleConnect::Disconnected;
	  return;
	}
      sf::sleep(sf::milliseconds(10));
    }

  while (_connect != BattleConnect::Stop && 
	 _connect != BattleConnect::Exit)
    {
      //std::cout << "Ecoute des commandes." << std::endl;
      if (_socket.receive(packet) == sf::Socket::Done)
	{
	  packet >> pos;
	  //std::cout << "Reception de la commande " << pos << std::endl;
	  if (pos < 6)
	    (this->*_execute[pos])(packet);
	  else
	    receiveSpecial(packet, pos);
	  packet.clear();
	}
      else
	{
	  _connect = BattleConnect::Disconnected;
	  _txt.setString("Vous avez été déconnecté du serveur...");
	  return;
	}
      sf::sleep(sf::milliseconds(10));
    }
  _connect = BattleConnect::Stop;
}

void BattleConnect::moveOpponent(sf::Packet &packet)
{
  sf::Uint32	x;
  sf::Uint32	y;
  bool		oppenent;

  packet >> oppenent;
  packet >> x;
  packet >> y;
  if (oppenent)
    _handE.setPosition(x, y);
}

void BattleConnect::dropCard(sf::Packet &packet)
{
  bool		oppenent;
  sf::Uint32	type;
  sf::Uint32	clan;

  packet >> oppenent;
  packet >> type;
  packet >> clan;

  if (oppenent)
    {
      std::cout << "L'ennemie pioche !" << std::endl;
      _handE.takeCard(_deck.makeCard(_deck.gType(type), _deck.gClan(clan)));
    }
  else
    _hand.takeCard(_deck.makeCard(_deck.gType(type), _deck.gClan(clan)));
  _phase = BattleConnect::ServerPhase;
}

void BattleConnect::dropWell(sf::Packet &packet)
{
  sf::Uint32	well;
  bool		oppenent;

  packet >> oppenent;
  packet >> well;
  if (oppenent)
    _handE.takeCard(_well->popCard(well));
  else
    _hand.takeCard(_well->popCard(well));
  _phase = BattleConnect::ServerPhase;
}

void BattleConnect::dropBoard(sf::Packet &packet)
{
  sf::Uint32	board;
  sf::Uint32	pos;
  bool		oppenent;

  packet >> oppenent;
  packet >> board >> pos;
  if (oppenent)
    _handE.takeCard(_fieldsE[board]->drop(pos));
  else
    _hand.takeCard(_fields[board]->drop(pos));
  _phase = BattleConnect::ServerPhase;
}

void BattleConnect::putWell(sf::Packet &packet)
{
  sf::Uint32	well;
  bool		oppenent;

  packet >> oppenent;
  packet >> well;
  if (oppenent)
    _well->addCard(_handE.giveCard(), well);
  else
    _well->addCard(_hand.giveCard(), well);
  _phase = BattleConnect::ServerPhase;
}

void BattleConnect::putBoard(sf::Packet &packet)
{
  sf::Uint32	board;
  bool		oppenent;

  packet >> oppenent;
  packet >> board;
  if (oppenent)
    _fieldsE[board]->addCard(_handE.giveCard());
  else
    _fields[board]->addCard(_hand.giveCard());
  _phase = BattleConnect::ServerPhase;
}
