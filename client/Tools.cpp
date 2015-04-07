#include "Tools.hh"
#include "Engine.hh"

Tools::Tools(Engine *engine, std::size_t bg, std::size_t music) : Module(engine, bg, music)
{

}

Tools::~Tools()
{

}

void Tools::drawModule()
{
  if (_bg)
    _engine->getRender()->draw(*_bg);
}

void Tools::eventModule()
{
  
}

void Tools::updateModule()
{
  
}

void Tools::openModule()
{
  if (_loopSong)
    {
      _loopSong->setLoop(true);
      _loopSong->play();
    }
}

void Tools::closeModule()
{
  if (_loopSong)
    _loopSong->stop();
}

void Tools::setPosition(int x, int y)
{
  if (x < 0)
    x = 0;
  if (y < 0)
    y = 0;
  _x = x;
  _y = y;
}
