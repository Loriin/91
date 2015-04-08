#include "Engine.hh"
#include "../common/Randomer.hh"

int		main()
{
  Engine	engine;

  Randomer::iniRand();
  engine.start();
  return (0);
}
