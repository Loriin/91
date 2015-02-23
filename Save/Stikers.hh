#ifndef STIKERS_HH_
#define STIKERS_HH_

#include <string>
#include <SFML/Graphics.hpp>

class Stikers
{
public:
  Stikers(sf::RenderWindow*, sf::Sprite*, unsigned int = 0, unsigned int = 0, unsigned int = 0, unsigned int = 0);
  ~Stikers();
  bool isClickable();
  void onClick(unsigned int, unsigned int);
  bool isClicked(unsigned int, unsigned int);
  void drawStikers();
  void setImage(sf::Texture const &a);
  void setImage(sf::Sprite *a);
  void setPosition(int, int);
  sf::Sprite *getLook();
  void setTxt(std::string);
  void setBText(bool);
private:
  sf::RenderWindow *_render;
  sf::Sprite *_look;
  unsigned int _x;
  unsigned int _y;
  unsigned int _w;
  unsigned int _h;
  bool _click;
  sf::Text _txt;
  sf::Font _font;
  bool _bTxt;
};

#endif
