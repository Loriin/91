#ifndef BOARDGAME_HH_
# define BOARDGAME_HH_

/*
**			INCLUDES			
*/
# include		"../common/Card.hh"
# include		"Field.hh"
# include		"BoardPlayer.hh"
# include		"BoardCommon.hh"

/*
**			CLASS
*/
class			BoardGame
{
private:
  BoardPlayer		_board_players[2];
  BoardCommon		_board_common;
public:
  BoardGame();
  ~BoardGame();
};

#endif /* !BOARDGAME_HH_ */
