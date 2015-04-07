#include "SocketGame.hh"
#include "Engine.hh"

SocketGame::SocketGame(Engine *engine, std::size_t bg, std::size_t music) : Module(engine, bg, music)
{

}

SocketGame::~SocketGame()
{

}

void SocketGame::drawModule()
{
  if (_bg)
    _engine->getRender()->draw(*_bg);
}

void SocketGame::eventModule()
{
  // recupération de l'event
  // envoie d'une commande au server
  // check des evenement de la pile server
}

void SocketGame::updateModule()
{
  // ecoute du server : mise des evenement sur la pile server
}

void SocketGame::openModule()
{
  if (_loopSong)
    {
      _loopSong->setLoop(true);
      _loopSong->play();
    }
}

void SocketGame::closeModule()
{
  if (_loopSong)
    _loopSong->stop();
}

void SocketGame::setPosition(int x, int y)
{
  if (x < 0)
    x = 0;
  if (y < 0)
    y = 0;
  _x = x;
  _y = y;
}
