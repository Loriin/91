#include "Game.hh"
#include "Engine.hh"

Game::Game(Engine *engine, std::size_t bg, std::size_t music) : Module(engine, bg, music)
{

}

Game::~Game()
{

}

void Game::drawModule()
{
  if (_bg)
    _engine->getRender()->draw(*_bg);
}

void Game::eventModule()
{
  
}

void Game::updateModule()
{
  
}

void Game::openModule()
{
  if (_loopSong)
    {
      _loopSong->setLoop(true);
      _loopSong->play();
    }
}

void Game::closeModule()
{
  if (_loopSong)
    _loopSong->stop();
}

void Game::setPosition(int x, int y)
{
  if (x < 0)
    x = 0;
  if (y < 0)
    y = 0;
  _x = x;
  _y = y;
}
