#include "Hud.h"
#include <iostream>

Hud::Hud(Context const& c): DisplayObject(c),
			    m_current_avatar(NULL) {
  setBounds(new Rectangle(0, 0, m_context.screen_width, m_context.screen_height));
  m_background = new Sprite(m_context, "hud.png");
  addChild(m_background);
}

void Hud::setAvatar(Figure* figure) {
  if (m_current_avatar && m_current_avatar->parent()) {
    m_current_avatar->parent()->removeChild(m_current_avatar);
  }
  m_current_avatar = figure;
  m_current_avatar->setPosition(37, 53);
  addChild(m_current_avatar);
}

void Hud::render() {
  m_background->render();
  if (m_current_avatar != NULL) {
    m_current_avatar->render();
  }
}


void Hud::onEvent(const Event& e) {
  if (e.event_type == EventType::Resize) {
    setPosition(m_context.screen_width - 200, 0);
    setBounds(new Rectangle(0, 0, m_context.screen_width, m_context.screen_height));
  }
  
}
