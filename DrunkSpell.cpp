#include "DrunkSpell.h"
#include <cmath>
#include "SpellEvent.h"

DrunkSpell::DrunkSpell(Context const& c): Spell(c, "select") {
}

void DrunkSpell::onEvent(const Event& e) {
  if (e.event_type == EventType::MouseMoved) {
    int x = floor((e.mouse_data.x - m_parent->x()) / m_context.TILE_SIZE);
    int y = floor((e.mouse_data.y - m_parent->y()) / m_context.TILE_SIZE);

    setPosition(x * m_context.TILE_SIZE, y * m_context.TILE_SIZE);
  }
}

void DrunkSpell::tick(float dt) {
  
}

void DrunkSpell::cast(std::pair<int, int> from, std::pair<int, int> to) {
  dispatchEvent(new SpellEvent(SpellType::drunk, floor(m_x /m_context.TILE_SIZE), floor(m_y / m_context.TILE_SIZE)), this);
}

