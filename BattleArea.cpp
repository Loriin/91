#include "BattleArea.hh"
#include "Engine.hh"
#include "Field.hh"
#include "Well.hh"

#include <iostream>

BattleArea::BattleArea(Engine *engine, unsigned int bg,
		       unsigned int music) : Module(engine, bg, music),
					     _deck(engine),
					     _well(0),
					     _phase(BattleArea::ServerPhase)
{
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

  _fields[0]->setPosition(635, 50);
  _fields[1]->setPosition(25, 50);
  _fields[2]->setPosition(25, 390);

  _well = new Well(_engine);
  _well->setPosition(645, 390);
}

BattleArea::~BattleArea()
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

void BattleArea::drawModule()
{
  _engine->getRender()->draw(*_bg);
  for (unsigned int i = 0; i < 9; i++)
    _engine->getRender()->draw(*_toto[i]);
  _deck.drawDeck();
  for (std::size_t i = 0; i < 3; i++)
    _fields[i]->drawField(_fields[i]->hoverCard(_x, _y));
  _well->drawWell();
  _hand.setPosition(_x, _y);
  _hand.drawHand();
}

bool BattleArea::drawEvent()
{
  std::size_t	well;

  if (_engine->getEvent()->type == sf::Event::MouseButtonPressed)
    {
      if (_engine->getEvent()->mouseButton.button == sf::Mouse::Left)
	{
	  if (_deck.clickOn(_x, _y) && _hand.isEmpty())
	    {
	      _hand.takeCard(_deck.draw());
	      return (true);
	    }

	  for (std::size_t i = 0; i < 3; i++)
	    {
	      if (_fields[i]->hoverCard(_x, _y) != Field::IsOut && _hand.isEmpty() &&
		  !_fields[i]->isEmpty())
		{
		  _hand.takeCard(_fields[i]->drop());
		  return (true);
		}
	    }
	  if ((well = _well->hoverCard(_x, _y)) < Well::IsIn &&
	      !_well->isEmpty(well) && _hand.isEmpty())
	    {
	      _hand.takeCard(_well->popCard(well));
	      return (true);
	    }
	}
    }
  return (false);
}

bool BattleArea::mainEvent()
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
		  _fields[i]->addCard(_hand.giveCard());
		  return (true);
		}
	    }

	  if ((well = _well->hoverCard(_x, _y)) < Well::IsIn &&
	      !_well->isFull(well) && !_hand.isEmpty())
	    {
	      _well->addCard(_hand.giveCard(), well);
	      return (true);

	    }
	}
    }
  return (false);
}

void BattleArea::eventModule()
{
  if (_phase == BattleArea::EndPhase || _phase == BattleArea::ServerPhase)
    return;
  else if (_phase == BattleArea::DrawPhase && drawEvent())
    _phase = BattleArea::ServerPhase;
  else if (_phase == BattleArea::MainPhase && mainEvent())
    _phase = BattleArea::ServerPhase;
}

void BattleArea::updateModule()
{
  
}

void BattleArea::openModule()
{
  return;
  _loopSong->setLoop(true);
  _loopSong->play();
}

void BattleArea::closeModule()
{
  return;
  _loopSong->stop();
}
