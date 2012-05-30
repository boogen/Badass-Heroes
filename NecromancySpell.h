#ifndef NECROMANCYSPELL_H__
#define NECROMANCYSPELL_H__

#include "Spell.h"

class NecromancySpell : public Spell {
 public:
  explicit NecromancySpell(Context const& c);
  void onEvent(const Event& e);
  void tick(float dt);
  void cast(std::pair<int, int> from, std::pair<int, int> to);
};

#endif
