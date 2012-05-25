#ifndef HUD_H__
#define HUD_H__

#include "DisplayObject.h"
#include "AnimatedSprite.h"
#include "Event.h"
#include "Figure.h"
#include "Sprite.h"

class Hud : public DisplayObject {
 public:
  Hud(Context const& c);
  void render();
  void onEvent(const Event& e);
  void setAvatar(Figure* avatar);
 private:
  Sprite* m_background;
  Figure* m_current_avatar;  
};

#endif
