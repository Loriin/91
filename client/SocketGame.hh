#ifndef GAME_HH_
#define GAME_HH_

#include <string>

#include "Module.hh"

class Engine;

class SocketGame : public Module
{
public:
SocketGame(Engine *, std::size_t = 0, std::size_t = 0);
~SocketGame();
  void drawModule();
  void eventModule();
  void updateModule();
  void closeModule();
  void openModule();
  void setPosition(int, int);
};

#endif
