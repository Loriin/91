#include <iostream>
#include <sstream>
#include "RPack.hh"

RPack::RPack(sf::RenderWindow *r) : _render(r)
{
  _textures.push_back(new sf::Texture);
  _textures[0]->loadFromFile("Ressources/card.png");
}

RPack::~RPack()
{
  for (std::size_t i = 0; i < _musics.size(); i++)
    delete (_musics[i]);
  for (std::size_t i = 0; i < _textures.size(); i++)
    delete (_textures[i]);
  for (std::size_t i = 0; i < _songs.size(); i++)
    delete (_songs[i]);
}

sf::Sprite *RPack::getSprite(std::size_t a) const
{
  if (a >= _textures.size())
    return (new sf::Sprite(*(_textures[0])));
  return (new sf::Sprite(*(_textures[a])));
}

sf::Texture *RPack::getTexture(std::size_t a) const
{
  if (a >= _textures.size())
    return (_textures[0]);
  return (_textures[a]);
}

sf::Music *RPack::getMusic(std::size_t a) const
{
  if (a >= _musics.size())
    return (0);
  return (_musics[a]);
}

sf::Sound *RPack::getSong(std::size_t a) const
{
  if (a >= _songs.size())
    return (_songs[0]);
  return (_songs[a]);
}
void RPack::load()
{
  sf::Texture texture;
  sf::Sprite sprite;
  sf::Font font;
  sf::Text txt;

  font.loadFromFile("Ressources/font.ttf");
  txt.setFont(font);
  txt.setString("Loading...");
  txt.setCharacterSize(60);
  txt.setPosition(350, 275);
  txt.setColor(sf::Color::Black);
  texture.loadFromFile("Ressources/load.png");
  sprite.setTexture(texture);
  _render->draw(sprite);
  _render->draw(txt);
  _render->display();
}
