#ifndef MODULE_HH_
#define MODULE_HH_

#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Stikers.hh"

class Engine;

class Module
{
public:
  Module(Engine *, unsigned int = 0, unsigned int = 0);
  virtual ~Module();
  virtual void drawModule();
  virtual void eventModule();
  virtual void updateModule();
  virtual void closeModule();
  virtual void openModule();
  virtual void setPosition(int, int);
  int getX();
  int getY();
protected:
  Engine		*_engine;
  sf::Sprite		*_bg;
  sf::Music		*_loopSong;
  std::vector<Stikers*> _stikers;
  int			_x;
  int			_y;
};

#endif
