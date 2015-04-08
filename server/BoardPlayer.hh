#ifndef BOARDPLAYER_HH_
# define BOARDPLAYER_HH_

/*
**			INCLUDES
*/
//# include		"BoardGame.hh"

/*
**			FW DECLARATION
*/
class			Field;
class			Card;

/*
**			CLASS
*/
class			BoardPlayer
{
private:
  Field			_tab_fields[3];
  int			_score;
  Card			_hand;
  // [TODO] debufs

public:
  BoardPlayer(int nb_card_per_fields); // 7
  ~BoardPlayer();
};

#endif /* !BOARDPLAYER_HH_ */
