#ifndef STICKER_HH_
#define STICKER_HH_

#include <string>
#include <SFML/Graphics.hpp>

class Sticker
{
public:
  Sticker(sf::RenderWindow*, sf::Sprite*,
	  std::size_t = 0, std::size_t = 0, std::size_t = 0, std::size_t = 0);
  ~Sticker();
  bool			isClickable();
  void			onClick(std::size_t, std::size_t);
  bool			isClicked(std::size_t, std::size_t);
  void			drawSticker();
  void			setImage(sf::Texture const &a);
  void			setImage(sf::Sprite *a);
  void			setPosition(int, int);
  sf::Sprite		*getLook();
  void			setTxt(std::string);
  void			setBText(bool);
private:
  sf::RenderWindow	*_render;
  sf::Sprite		*_look;
  std::size_t		_x;
  std::size_t		_y;
  std::size_t		_w;
  std::size_t		_h;
  bool			_click;
  sf::Text		_txt;
  sf::Font		_font;
  bool			_bTxt;
};

#endif
