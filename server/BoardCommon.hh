#ifndef BOARDCOMMON_HH_
# define BOARDCOMMON_HH_

/*
**		INCLUDES
*/
# include	"BoardGame.hh"

/*
**		CLASS
*/
class		BoardCommon
{
private:
  Field		_tab_fields[4];
public:
  BoardCommon(int nb_card_max_per_field); // 5
  ~BoardCommon();
};

#endif /* !BOARDCOMMON_HH_ */
