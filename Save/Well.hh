#ifndef WELL_HH_
#define WELL_HH_

#include <string>
#include <list>
#include "Card.hh"
#include "Engine.hh"

class Well
{
public:

  typedef enum		eWellState
    {
      IsIn = 3,
      IsOut = 4
    }			WellState;

public:
  Well(Engine*);
  ~Well();
  void			setPosition(std::size_t, std::size_t);
  std::size_t		hoverCard(std::size_t, std::size_t);
  void			addCard(Card*, std::size_t);
  Card			*popCard(std::size_t);
  bool			isEmpty(std::size_t);
  bool			isFull(std::size_t);
  void			drawWell();
private:
  Engine		*_engine;
  Stikers		_backWell;
  std::size_t		_x;
  std::size_t		_y;
  sf::IntRect		_well[3];
  std::list<Card*>	_pile[3];
};

#endif
