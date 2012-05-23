#ifndef DRUNKSPELL_H__
#define DRUNKSPELL_H__

#include "Spell.h"

class DrunkSpell : public Spell {
 public:
  explicit DrunkSpell(Context const& c);
  void onEvent(const Event& e);
  void tick(float dt);
  void cast(std::pair<int, int> from, std::pair<int, int> to);
};

#endif
