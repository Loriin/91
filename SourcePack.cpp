#include <iostream>
#include <sstream>
#include "SourcePack.hh"

SourcePack::SourcePack(sf::RenderWindow *r) : _render(r)
{
  load();
  // ________________ 
  // _____ FOND _____
  // ________________

  _textures.push_back(new sf::Texture);
  //_textures[0]->loadFromFile("Ressources/sprite/bulbifond.png");
  _textures[0]->loadFromFile("Ressources/sprite/back.jpg");
  _sprites.push_back(new sf::Sprite(*_textures[0]));

  _textures.push_back(new sf::Texture);
  _textures[1]->loadFromFile("Ressources/pokemon/034.png");
  _sprites.push_back(new sf::Sprite(*_textures[1]));

  _textures.push_back(new sf::Texture);
  _textures[2]->loadFromFile("Ressources/pokemon/031.png");
  _sprites.push_back(new sf::Sprite(*_textures[2]));

  _textures.push_back(new sf::Texture);
  _textures[3]->loadFromFile("Ressources/pokemon/115.png");
  _sprites.push_back(new sf::Sprite(*_textures[3]));

  _textures.push_back(new sf::Texture);
  _textures[4]->loadFromFile("Ressources/pokemon/107.png");
  _sprites.push_back(new sf::Sprite(*_textures[4]));

  _textures.push_back(new sf::Texture);
  _textures[5]->loadFromFile("Ressources/pokemon/143.png");
  _sprites.push_back(new sf::Sprite(*_textures[5]));

  _textures.push_back(new sf::Texture);
  _textures[6]->loadFromFile("Ressources/pokemon/195.png");
  _sprites.push_back(new sf::Sprite(*_textures[6]));

  _textures.push_back(new sf::Texture);
  _textures[7]->loadFromFile("Ressources/pokemon/149.png");
  _sprites.push_back(new sf::Sprite(*_textures[7]));


  // ________________
  // ____ Musics ____
  // ________________

  _musics.push_back(new sf::Music);
  _musics[0]->openFromFile("Ressources/sound/loopsong.ogg");

  _musics.push_back(new sf::Music);
  _musics[1]->openFromFile("Ressources/sound/center.ogg");

  _musics.push_back(new sf::Music);
  _musics[2]->openFromFile("Ressources/sound/tour.ogg");

  _musics.push_back(new sf::Music);
  _musics[3]->openFromFile("Ressources/sound/palette.ogg");

  _musics.push_back(new sf::Music);
  _musics[4]->openFromFile("Ressources/sound/arena.ogg");

  // ________________
  // _____ SONG _____
  // ________________

  _buffers.push_back(sf::SoundBuffer());
  _buffers[0].loadFromFile("Ressources/sound/lvlup.ogg");
  _songs.push_back(new sf::Sound(_buffers[0]));

  _buffers.push_back(sf::SoundBuffer());
  _buffers[1].loadFromFile("Ressources/sound/pokeball.ogg");
  _songs.push_back(new sf::Sound(_buffers[1]));
  
  // ________________
  // ________________
  // ________________

}

SourcePack::~SourcePack()
{
  unsigned int i = 0;
  while (i < _sprites.size())
    delete (_sprites[i++]);
  i = 0;
  while (i < _textures.size())
    delete (_textures[i++]);
  i = 0;
  while (i < _musics.size())
    delete (_musics[i++]);
}

sf::Sprite *SourcePack::getSprite(unsigned int a) const
{
  if (a > _sprites.size())
    return (new sf::Sprite(*_sprites[0]));
  return (new sf::Sprite(*_sprites[a]));
}

sf::Texture *SourcePack::getTexture(unsigned int a) const
{
  if (a > _textures.size())
    return (_textures[0]);
  return (_textures[a]);
}

sf::Music *SourcePack::getMusic(unsigned int a) const
{
  if (a > _musics.size())
    return (_musics[0]);
  return (_musics[a]);
}

sf::Sound *SourcePack::getSong(unsigned int a) const
{
  if (a > _songs.size())
    return (_songs[0]);
  return (_songs[a]);
}
void SourcePack::load()
{
  sf::Texture texture;
  sf::Sprite sprite;
  sf::Font font;
  sf::Text txt;

  font.loadFromFile("Ressources/pokefont.ttf");
  txt.setFont(font);
  txt.setString("Loading...");
  txt.setCharacterSize(60);
  txt.setPosition(350, 275);
  txt.setColor(sf::Color::Black);
  texture.loadFromFile("Ressources/sprite/load.png");
  sprite.setTexture(texture);
  _render->draw(sprite);
  _render->draw(txt);
  _render->display();
}
