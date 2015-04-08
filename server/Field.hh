#ifndef FIELD_HH_
# define FIELD_HH_

/*
**			INCLUDES
*/
# include		"BoardGame.hh"

/*
**			CLASS
*/
class			Field
{
private:
  enum			ALIGNMENT
    {
      POSITIVE,
      NEUTRAL,
      NEGATIVE
    };
  Card			*_tab_card[];
  ALIGNMENT		_alignment;
  bool			_is_empty;
public:
  Field(int nb_card);
  ~Field();
};

#endif /* !FIELD_HH_ */
