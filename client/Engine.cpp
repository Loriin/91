#include <iostream>
#include "Engine.hh"

Engine::Engine() : _render(sf::VideoMode::getDesktopMode(), "Tittle", sf::Style::Close),
		   _res(&_render),
		   _cModule(0), _th(&Engine::updater, this),
		   _focus(true)
{
  _modules[0] = new MainMenu(this, 0, 0);
  _modules[1] = new Tools(this, 0, 0);
  _modules[_cModule]->openModule();
  _th.launch();
}

Engine::~Engine()
{
  for (std::size_t i = 0; i < 2; i++)
    delete (_modules[i]);
}

void	Engine::event()
{
  while (_render.pollEvent(_event))
    {
      if (_event.type == sf::Event::LostFocus)
	{
	  _focus = false;
	  return;
	}
      if (_event.type == sf::Event::GainedFocus)
	_focus = true;
      if (!_focus)
	return;
      if (_event.type == sf::Event::Closed)
	_render.close();
      if (_event.type == sf::Event::MouseMoved)
	_modules[_cModule]->setPosition(_event.mouseMove.x, _event.mouseMove.y);
      _modules[_cModule]->eventModule();
    }
}
void	Engine::start()
{
  _render.setFramerateLimit(60);
  while (_render.isOpen())
    {
      event();
      _render.clear();
      _modules[_cModule]->drawModule();
      _render.display();
    }
}

void Engine::setModule(std::size_t a)
{
  _modules[_cModule]->closeModule();
  _modules[a]->openModule();
  _modules[a]->setPosition(_modules[_cModule]->getX(), _modules[_cModule]->getY());
  _cModule = a;
}

void Engine::updater()
{
  sf::sleep(sf::milliseconds(10));
  _modules[_cModule]->updateModule();
}

sf::RenderWindow *Engine::getRender()
{
  return (&_render);
}

sf::Event *Engine::getEvent()
{
  return (&_event);
}

RPack *Engine::getPack()
{
  return (&_res);
}

sf::VideoMode	Engine::getMode()
{
  std::vector<sf::VideoMode> modes = sf::VideoMode::getFullscreenModes();
  sf::VideoMode mode = modes[0];
  return (sf::VideoMode(mode.width, mode.height, mode.bitsPerPixel));
}

void		Engine::setFullScreen()
{
  _render.create(getMode(), "Tittle", sf::Style::Fullscreen);
}

void		Engine::setDesktop()
{
  _render.create(sf::VideoMode::getDesktopMode(), "Tittle", sf::Style::Close);
}
