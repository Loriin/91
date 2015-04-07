#ifndef TOOLS_HH_
#define TOOLS_HH_

#include <string>

#include "Module.hh"

class Engine;

class Tools : public Module
{
public:
Tools(Engine *, std::size_t = 0, std::size_t = 0);
~Tools();
  void drawModule();
  void eventModule();
  void updateModule();
  void closeModule();
  void openModule();
  void setPosition(int, int);
};

#endif
