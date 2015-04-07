#include "MainMenu.hh"
#include "Engine.hh"

MainMenu::MainMenu(Engine *engine, std::size_t bg, std::size_t music) : Module(engine, bg, music)
{

}

MainMenu::~MainMenu()
{

}

void MainMenu::drawModule()
{
  if (_bg)
    _engine->getRender()->draw(*_bg);
}

void MainMenu::eventModule()
{
  
}

void MainMenu::updateModule()
{
  
}

void MainMenu::openModule()
{
  if (_loopSong)
    {
      _loopSong->setLoop(true);
      _loopSong->play();
    }
}

void MainMenu::closeModule()
{
  if (_loopSong)
    _loopSong->stop();
}

void MainMenu::setPosition(int x, int y)
{
  if (x < 0)
    x = 0;
  if (y < 0)
    y = 0;
  _x = x;
  _y = y;
}
