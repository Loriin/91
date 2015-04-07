#include "Sticker.hh"
#include <iostream>

Sticker::Sticker(sf::RenderWindow *r, sf::Sprite *s, std::size_t x, std::size_t y,
		 std::size_t w, std::size_t h) : _render(r),
						   _look(s),
						   _x(x),
						   _y(y),
						   _w(w),
						   _h(h),
						   _click(false)
{
  _look->setPosition(_x, _y);
  _font.loadFromFile("Ressources/pokefont.ttf");
  _txt.setFont(_font);
  _txt.setCharacterSize(20);
  _txt.setColor(sf::Color::Black);
}

Sticker::~Sticker()
{
  if (_look)
    delete (_look);
}

bool Sticker::isClickable()
{
  return (_click);
}

void Sticker::onClick(std::size_t x, std::size_t y)
{
  if (!isClicked(x, y))
    return;
}

bool Sticker::isClicked(std::size_t x, std::size_t y)
{
  return (x >= _x && x <= _x + _w &&
	  y >= _y && y <= _y + _h);
}

void Sticker::drawSticker()
{
  _render->draw(*_look);
  if (_bTxt)
    _render->draw(_txt);
}

void Sticker::setImage(sf::Texture const &a)
{
  _look->setTexture(a);
}

void Sticker::setImage(sf::Sprite *a)
{
  if (_look)
    delete (_look);
  _look = a;
}

void Sticker::setPosition(int x, int y)
{
  _x = x;
  _y = y;
  _look->setPosition(x, y);
}

sf::Sprite *Sticker::getLook()
{
  return (_look);
}

void Sticker::setTxt(std::string a)
{
  _txt.setString(a);
  _txt.setPosition(_x, _y + (_h / 2) - 10);
  _bTxt = true;
}

void Sticker::setBText(bool a)
{
  _bTxt = a;
}
