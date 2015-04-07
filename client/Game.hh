#ifndef GAME_HH_
#define GAME_HH_

#include <string>

#include "Module.hh"

class Engine;

class Game : public Module
{
public:
Game(Engine *, std::size_t = 0, std::size_t = 0);
~Game();
  void drawModule();
  void eventModule();
  void updateModule();
  void closeModule();
  void openModule();
  void setPosition(int, int);
};

#endif
