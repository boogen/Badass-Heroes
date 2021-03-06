#ifndef NPC_H__
#define NPC_H__

#include "Character.h"
#include <vector>
#include <deque>
#include <queue>
#include "Action.h"

class Npc : public Character {
 public:
  Npc(Context const& c, std::string image, int health, std::vector<std::vector<int> > const& map);
  virtual void animate(const std::string& dir, int count = -1);
  virtual void stop();
  void die();
  void tick(float dt);
  void setMinion(bool value);
  bool turn(std::vector<std::vector<float> > const& scents);
 private:
  void onDeath(GameEventPointer e, EventDispatcher* dispatcher);
 private:
  bool m_minion;
};

#endif
