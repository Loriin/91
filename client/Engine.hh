#ifndef ENGINE_HH_
#define ENGINE_HH_

#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "RPack.hh"
#include "MainMenu.hh"
#include "Tools.hh"
#include "Game.hh"

class Engine
{
public:
  Engine();
  ~Engine();
  void			start();
  void			setModule(std::size_t);
  void			updater();
  sf::RenderWindow	*getRender();
  sf::Event		*getEvent();
  RPack			*getPack();
  sf::VideoMode		getMode();
  void			event();
  void			setFullScreen();
  void			setDesktop();
private:
  sf::RenderWindow	_render;
  sf::Event		_event;
  RPack			_res;
  Module		*_modules[5];
  std::size_t		_cModule;
  sf::Thread		_th;
  bool			_focus;
};

#endif
