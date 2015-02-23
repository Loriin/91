#include <iostream>
#include "Engine.hh"

Engine::Engine() : _render(sf::VideoMode::getDesktopMode(), "Tittle"),
		   _res(&_render),
		   _cModule(0), _th(&Engine::updater, this),
		   _view(sf::FloatRect(0, 0, 1920, 1080)),
		   _rateX(1),
		   _rateY(1),
		   _boardX(0),
		   _boardY(0)
{
  //, sf::Style::Close
  //sf::VideoMode(1920, 1080)
  //_view.setViewport(sf::FloatRect(0, 0, 0.5f, 0.5f));
  sf::Vector2u	size = _render.getSize();
  resizeView(size.x, size.y);
  srand((int)time(NULL));
  _modules[0] = new BattleArea(this, 9, 2);
  _modules[_cModule]->openModule();
  _th.launch();
}

Engine::~Engine()
{

}

void			Engine::start()
{
  _render.setFramerateLimit(60);
  _render.setView(_view);
  while (_render.isOpen())
    {
      while (_render.pollEvent(_event))
	{
	  if (_event.type == sf::Event::Closed)
	    _render.close();
	  if (_event.type == sf::Event::MouseMoved)
	    {
	      _modules[_cModule]->setPosition(_event.mouseMove.x * _rateX - _boardX * _rateX,
					      _event.mouseMove.y * _rateY - _boardY * _rateY);
	    }
	  _modules[_cModule]->eventModule();
	  if (_event.type == sf::Event::Resized)
	    resizeView(_event.size.width, _event.size.height);
	}
      _render.clear();
      _modules[_cModule]->drawModule();
      _render.display();
    }
}

void			Engine::setModule(unsigned int a)
{
  _modules[_cModule]->closeModule();
  _modules[a]->openModule();
  _modules[a]->setPosition(_modules[_cModule]->getX(), _modules[_cModule]->getY());
  _cModule = a;
}

void			Engine::updater()
{
  sf::sleep(sf::milliseconds(10));
  _modules[_cModule]->updateModule();
}

sf::RenderWindow	*Engine::getRender()
{
  return (&_render);
}

sf::Event		*Engine::getEvent()
{
  return (&_event);
}

SourcePack		*Engine::getSources()
{
  return (&_res);
}

void			Engine::resizeView(float w, float h)
{
  float			rate;
  float			board;

  if (w / 16 >= h / 9)
    {
      rate = h / 9;
      board = ((w - (16 * rate)) / w);
      _boardX = (board / 2) * w;
      _boardY = 0;
      _view.setViewport(sf::FloatRect(board / 2, 0, 1 - board, 1));
    }
  else
    {
      rate = w / 16;
      board = ((h - (9 * rate)) / h);
      _boardX = 0;
      _boardY = (board / 2) * h;
      _view.setViewport(sf::FloatRect(0, board / 2, 1, 1 - board));
    }
  _render.setView(_view);
  _rateX = 1920 / (16 * rate);
  _rateY = 1080 / (9 * rate);
}
