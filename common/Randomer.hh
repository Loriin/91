#ifndef RANDOMER_HH_
#define RANDOMER_HH_

#include <string>
#include <cstdlib>
#include <ctime>

class Randomer
{
public:
  static std::size_t	random(std::size_t = 100);
  static void		iniRand();
  static bool		init;
};

#endif
