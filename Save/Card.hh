#ifndef CARD_HH_
#define CARD_HH_

#include <string>
#include "SpellBook.hh"
#include <SFML/Graphics.hpp>
#include "Stikers.hh"

class Engine;

class Card
{
public:
  static const	sf::Color ColorClan[5];

  typedef enum		e_clan
    {
      None = -1,
      Igvar = 0,
      Shadow,
      Krion,
      Starn,
      Zarron
    }			Clan;

public:
  Card(Engine*, Clan = None);
  ~Card();
  std::string		getClanName() const;
  std::string		getName() const;
  void			setPosition(std::size_t, std::size_t);
  void			drawCard();
  bool			clickOn(std::size_t, std::size_t);
  void			flip(bool);
protected:
  Engine		*_engine;
  sf::Sprite		*_picture;
  Stikers		*_backCard;
protected:
  std::string		_name;
  int			_unitValue;
  int			_groupeValue;
  Clan			_clan;
  sf::RectangleShape	_rectCard;
  std::size_t		_x;
  std::size_t		_y;
  bool			_front;
};

#endif
