#ifndef SPELLBOOK_HH_
#define SPELLBOOK_HH_

#include <string>

class SpellBook
{
public:
  typedef enum	e_spell
    {
      None = -1,
      Spell1 = 0,
      Spell2,
      Spell3
    }		Spell;
public:
  SpellBook();
  ~SpellBook();
};

#endif
