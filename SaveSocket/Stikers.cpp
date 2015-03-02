#include "Stikers.hh"
#include <iostream>

Stikers::Stikers(sf::RenderWindow *r, sf::Sprite *s, unsigned int x, unsigned int y,
		 unsigned int w, unsigned int h) : _render(r),
						   _look(s),
						   _x(x),
						   _y(y),
						   _w(w),
						   _h(h),
						   _click(false)
{
  if (_look)
    _look->setPosition(_x, _y);
  _font.loadFromFile("Ressources/pokefont.ttf");
  _txt.setFont(_font);
  _txt.setCharacterSize(20);
  _txt.setColor(sf::Color::Black);
}

Stikers::~Stikers()
{
  
}

bool Stikers::isClickable()
{
  return (_click);
}

void Stikers::onClick(unsigned int x, unsigned int y)
{
  if (!isClicked(x, y))
    return;
}

bool Stikers::isClicked(unsigned int x, unsigned int y)
{
  return (x >= _x && x <= _x + _w &&
	  y >= _y && y <= _y + _h);
}

void Stikers::drawStikers()
{
  if (_look)
    _render->draw(*_look);
  if (_bTxt)
    _render->draw(_txt);
}

void Stikers::setImage(sf::Texture const &a)
{
  if (_look)
    _look->setTexture(a);
}

void Stikers::setImage(sf::Sprite *a)
{
  if (_look)
    delete (_look);
  _look = a;
}

void Stikers::setPosition(int x, int y)
{
  _x = x;
  _y = y;
  if (_look)
    _look->setPosition(x, y);
}

sf::Sprite *Stikers::getLook()
{
  return (_look);
}

void Stikers::setTxt(std::string a)
{
  _txt.setString(a);
  _txt.setPosition(_x, _y + (_h / 2) - 10);
  _bTxt = true;
}

void Stikers::setBText(bool a)
{
  _bTxt = a;
}
