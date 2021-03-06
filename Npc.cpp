#include "Npc.h"
#include "ContainerRenderBehaviour.h"
#include "ContainerSizeBehaviour.h"
#include "AnimatedSprite.h"
#include <iostream>
#include <cmath>
#include "Utils.h"

Npc::Npc(Context const& c, std::string image, int health, std::vector<std::vector<int> > const& map): Character(c, health, map),
												      m_minion(false) {
  DisplayObject* sprite = new AnimatedSprite(c, image);
  addChild(sprite);
  
  m_render_behaviour = new ContainerRenderBehaviour(m_children);
  m_size_behaviour = new ContainerSizeBehaviour(m_children);



  for (int i = 0; i < m_map.size(); ++i) {
    m_seen.push_back(std::vector<bool>());
    for (int j = 0; j < m_map.at(i).size(); ++j) {
      m_seen.at(i).push_back(true);
    }
  }

}

void Npc::animate(const std::string& dir, int count) {  
  for (int i = 0; i < m_children.size(); ++i) {
    AnimatedSprite* sprite = dynamic_cast<AnimatedSprite*>(m_children.at(i));
    if (sprite) {
      sprite->animate(dir, count);
    }
  }

}

void Npc::stop() {
  animate(Animations::idle);
  /*  for (int i = 0; i < m_sprites.size(); ++i) {
    dynamic_cast<AnimatedSprite*>(m_sprites.at(i))->stop();
    }*/
}

void Npc::setMinion(bool value) {
  m_minion = value;
}

void Npc::die() {  
  m_children.at(0)->addEventListener("animationfinish", this, static_cast<Listener>(&Npc::onDeath));
  animate(Animations::dead, 1);
}

void Npc::onDeath(GameEventPointer e, EventDispatcher* dispatcher) {
  dispatchEvent(new GameEvent(ET::dead), this);
}


void Npc::tick(float dt) {
  Character::tick(dt);

  for (int i = 0; i < m_children.size(); ++i) {
    m_children.at(i)->tick(dt);
  }

}

bool Npc::turn(std::vector<std::vector<float> > const& scents) {
  if (m_minion) {
    return false;
  }
  float max_scent = scents.at(row()).at(col());
  point pos = point(row(), col());
  for (int j = 0; j < 4; ++j) {
    if (scents.at(row() + Utils::directions[j].first).at(col() + Utils::directions[j].second) > max_scent) {
      max_scent = scents.at(row() + Utils::directions[j].first).at(col() + Utils::directions[j].second);
      pos = point(row() + Utils::directions[j].first, col() + Utils::directions[j].second);
    }
  }
  
  if (pos.first != row() || pos.second != col()) {
    onAction(Action(Action::WALK, point(pos.first, pos.second)));
    return true;
  }

  return false;
  
}
