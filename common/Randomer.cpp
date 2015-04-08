#include <iostream>

#include "Randomer.hh"

bool		Randomer::init = false;

std::size_t	Randomer::random(std::size_t limit)
{
  return (rand() % limit);
}

void		Randomer::iniRand()
{
  if (init)
    return;
  srand(static_cast<int>(time(0)));
  init = true;
}

