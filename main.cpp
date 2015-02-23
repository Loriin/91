#include "Engine.hh"
#include "Deck.hh"

int	main()
{
  Engine e;

  Deck	d(&e);
  e.start();
  return (0);
}
