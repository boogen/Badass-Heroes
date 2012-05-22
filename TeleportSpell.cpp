#include "TeleportSpell.h"
#include <cmath>
#include "SpellEvent.h"

TeleportSpell::TeleportSpell(Context const& c): Spell(c, "teleport") {
}

void TeleportSpell::onEvent(const Event& e) {
  if (e.event_type == EventType::MouseMoved) {
    int x = floor((e.mouse_data.x - m_parent->x()) / m_context.TILE_SIZE);
    int y = floor((e.mouse_data.y - m_parent->y()) / m_context.TILE_SIZE);

    setPosition(x * m_context.TILE_SIZE, y * m_context.TILE_SIZE);
  }
}

void TeleportSpell::tick(float dt) {
  
}

void TeleportSpell::cast(std::pair<int, int> from, std::pair<int, int> to) {
  dispatchEvent(new SpellEvent(SpellType::teleport, floor(m_x /m_context.TILE_SIZE), floor(m_y / m_context.TILE_SIZE)), this);
}

