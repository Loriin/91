#ifndef FIELD_HH_
#define FIELD_HH_

#include <string>
#include <vector>
#include "Card.hh"
#include "Engine.hh"

class Field
{
public:

  typedef enum		eFieldState
    {
      IsIn = 7,
      IsOut = 8
    }			FieldState;

public:
  Field(Engine*);
  ~Field();
  void			addCard(Card*);
  bool			isFull();
  bool			isEmpty();
  Card			*drop(std::size_t = 0);
  void			setPosition(std::size_t, std::size_t);
  void			drawField(std::size_t = 7);
  std::size_t		hoverCard(std::size_t, std::size_t) const;
  void			organizedCard();
  int			getScore() const;
private:
  Engine		*_engine;
  Stikers		*_backField;
  std::vector<Card*>	_pile;
  std::size_t		_x;
  std::size_t		_y;
  int			_score;
};

#endif
