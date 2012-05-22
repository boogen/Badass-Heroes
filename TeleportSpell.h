#ifndef TELEPORTSPELL_H__
#define TELEPORTSPELL_H__

#include "Spell.h"

class TeleportSpell : public Spell {
 public:
  explicit TeleportSpell(Context const& c);
  void onEvent(const Event& e);
  void tick(float dt);
  void cast(std::pair<int, int> from, std::pair<int, int> to);
};

#endif
