#ifndef MAINMENU_HH_
#define MAINMENU_HH_

#include <string>

#include "Module.hh"

class Engine;

class MainMenu : public Module
{
public:
MainMenu(Engine *, std::size_t = 0, std::size_t = 0);
~MainMenu();
  void drawModule();
  void eventModule();
  void updateModule();
  void closeModule();
  void openModule();
  void setPosition(int, int);
};

#endif
