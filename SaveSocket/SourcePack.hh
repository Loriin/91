#ifndef SOURCEPACK_HH_
#define SOURCEPACK_HH_

#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class SourcePack
{
public:
  SourcePack(sf::RenderWindow*);
  ~SourcePack();
  sf::Sprite *getSprite(unsigned int) const;
  sf::Texture *getTexture(unsigned int) const;
  sf::Music *getMusic(unsigned int a) const;
  sf::Sound *getSong(unsigned int a) const;
  void playSound(unsigned int);

  void load();
private:
  std::vector<sf::Sprite*> _sprites;
  std::vector<sf::Texture*> _textures;
  std::vector<sf::Music*> _musics;

  std::vector<sf::SoundBuffer> _buffers;
  std::vector<sf::Sound*> _songs;

  sf::RenderWindow *_render;
};

#endif
