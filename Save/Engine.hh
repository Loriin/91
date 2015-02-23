#ifndef ENGINE_HH_
#define ENGINE_HH_

#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "SourcePack.hh"
#include "BattleArea.hh"

class Engine
{
public:
  Engine();
  ~Engine();
  void			start();
  void			setModule(unsigned int);
  void			updater();
  sf::RenderWindow	*getRender();
  sf::Event		*getEvent();
  SourcePack		*getSources();
  void			resizeView(float, float);
private:
  sf::RenderWindow	_render;
  sf::Event		_event;
  SourcePack		_res;
  Module		*_modules[5];
  unsigned int		_cModule;
  sf::Thread		_th;
  sf::View		_view;
  float			_rateX;
  float			_rateY;
  float			_boardX;
  float			_boardY;
};

#endif
