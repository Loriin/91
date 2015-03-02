#include "BattleConnect.hh"
#include "Engine.hh"
#include "Field.hh"
#include "Well.hh"
#include "Server.hh"

#include <iostream>

BattleConnect::BattleConnect(Engine *engine, unsigned int bg,
		       unsigned int music) : Module(engine, bg, music),
					     _deck(engine),
					     _well(0),
					     _phase(BattleConnect::ServerPhase),
					     //_connect(BattleConnect::Disconnected),
					     _server(0)
{
  _server = new Server(this);

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
  delete (_server);
}

void BattleConnect::drawModule()
{
  _engine->getRender()->draw(*_bg);
  if (!_server->isConnect())
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
  if (_engine->getEvent()->type != sf::Event::TextEntered || _ip.size() >= 30)
    return;

  code = static_cast<char>(_engine->getEvent()->text.unicode);
  if (code == 8)
    _ip = "";
  else if (code == 13 && _server->connect(_ip))
    _server->start();
  else if (code == 13)
    _txt.setString("Erreur: Veuillez entrez l'adresse Hote");
  else
    _ip += code;
  _txt.setString(_ip);
}

bool BattleConnect::drawEvent()
{
  std::size_t	well;

  if (_engine->getEvent()->type == sf::Event::MouseButtonPressed)
    {
      if (_engine->getEvent()->mouseButton.button == sf::Mouse::Left)
	{
	  if (_deck.clickOn(_x, _y) && _hand.isEmpty())
	    return (_server->sendCommand(1));
	  for (std::size_t i = 0; i < 3; i++)
	    if (_fields[i]->hoverCard(_x, _y) != Field::IsOut && _hand.isEmpty() &&
		!_fields[i]->isEmpty())
	      return (_server->sendCommand(3, i, 0));
	  if ((well = _well->hoverCard(_x, _y)) < Well::IsIn &&
	      !_well->isEmpty(well) && _hand.isEmpty())
	    return (_server->sendCommand(2, well));
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
	    if (_fields[i]->hoverCard(_x, _y) != Field::IsOut && !_hand.isEmpty() &&
		!_fields[i]->isFull())
	      return (_server->sendCommand(5, i));
	  
	  if ((well = _well->hoverCard(_x, _y)) < Well::IsIn &&
	      !_well->isFull(well) && !_hand.isEmpty())
	    return (_server->sendCommand(4, well));
	}
    }
  return (false);
}

void BattleConnect::eventModule()
{
  if (_phase == BattleConnect::DrawPhase ||
      _phase == BattleConnect::MainPhase)
    std::cout << "je suis dans la bonne phase..." << std::endl;
  else
    std::cout << "mauvaise phase" << std::endl;
  if (!_server->isConnect())
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
  return;
  _loopSong->setLoop(true);
  _loopSong->play();
}

void BattleConnect::closeModule()
{
  return;
  _loopSong->stop();
}

void BattleConnect::updateModule()
{
  _server->execute();
}

void BattleConnect::moveOpponent(std::size_t x, std::size_t y)
{
  _handE.setPosition(x, y);
}

void BattleConnect::dropCard(Card::CardType type, Card::Clan clan, bool op)
{
  if (op)
    _handE.takeCard(_deck.makeCard(type, clan));
  else
    _hand.takeCard(_deck.makeCard(type, clan));
}

void BattleConnect::dropWell(std::size_t pos, bool op)
{
  if (op)
    _handE.takeCard(_well->popCard(pos));
  else
    _hand.takeCard(_well->popCard(pos));
}

void BattleConnect::dropBoard(std::size_t pos, std::size_t num, bool op)
{
  if (op)
    _handE.takeCard(_fieldsE[pos]->drop(num));
  else
    _hand.takeCard(_fields[pos]->drop(num));
}

void BattleConnect::putWell(std::size_t pos, bool op)
{
  if (op)
    _well->addCard(_handE.giveCard(), pos);
  else
    _well->addCard(_hand.giveCard(), pos);
}

void BattleConnect::putBoard(std::size_t pos , bool op)
{
  if (op)
    _fieldsE[pos]->addCard(_handE.giveCard());
  else
    _fields[pos]->addCard(_hand.giveCard());
}

Deck &BattleConnect::getDeck()
{
  return (_deck);
}

void BattleConnect::setPhase(BattleConnect::BattlePhase p)
{
  _phase = p;
}

BattleConnect::BattlePhase BattleConnect::getPhase()
{
  return (_phase);
}

void BattleConnect::setPosition(int x, int y)
{
  _x = x;
  _y = y;
  if (_x < 0)
    _x = 0;
  if (_y < 0)
    _y = 0;
  _server->setPosition(static_cast<std::size_t>(1920 - x), static_cast<std::size_t>(1080 - y));
}
