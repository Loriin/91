#include "Module.hh"
#include "Engine.hh"

Module::Module(Engine *engine, std::size_t bg, std::size_t music) : _engine(engine), _x(0), _y(0)
{
  _bg = _engine->getPack()->getSprite(bg);
  _loopSong = _engine->getPack()->getMusic(music);
}
Module::~Module()
{
  if (_bg)
    delete (_bg);
  if (_loopSong)
    delete (_loopSong);
  for (std::size_t i = 0; i < _stickers.size(); i++)
    delete (_stickers[i]);
}

void Module::drawModule()
{
  if (_bg)
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
  if (_loopSong)
    {
      _loopSong->setLoop(true);
      _loopSong->play();
    }
}

void Module::closeModule()
{
  if (_loopSong)
    _loopSong->stop();
}

void Module::setPosition(int x, int y)
{
  if (x < 0)
    x = 0;
  if (y < 0)
    y = 0;
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
