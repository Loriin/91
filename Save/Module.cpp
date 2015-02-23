#include "Module.hh"
#include "Engine.hh"

Module::Module(Engine *engine, unsigned int bg, unsigned int music) : _engine(engine), _x(0), _y(0)
{
  _bg = _engine->getSources()->getSprite(bg);
  _loopSong = _engine->getSources()->getMusic(music);
}

Module::~Module()
{
  delete (_bg);
  delete (_loopSong);
}

void Module::drawModule()
{
  _engine->getRender()->draw(*_bg);
}

void Module::eventModule()
{
  
}

void Module::updateModule()
{
  
}

void Module::openModule()
{
  _loopSong->setLoop(true);
  _loopSong->play();
}

void Module::closeModule()
{
  _loopSong->stop();
}

void Module::setPosition(int x, int y)
{
  _x = x;
  _y = y;
}

int Module::getX()
{
  return (_x);
}

int Module::getY()
{
  return (_y);
}
