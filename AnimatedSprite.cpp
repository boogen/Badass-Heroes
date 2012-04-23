#include "AnimatedSprite.h"
#include "TextureFactory.h"
#include "SpriteRenderBehaviour.h"
#include <iostream>
#include "AnimationParser.h"

AnimatedSprite::AnimatedSprite(Context const& c, std::string spritesheet): Sprite(c, spritesheet + ".png"),
									   m_frame_nr(0),
									   m_direction(Animations::up),
									   m_animate(false),
									   m_animation_speed(4) {


  AnimationParser parser;
  parser.parse(spritesheet + ".txt");

  m_frame->setSize(parser.frame_size, parser.frame_size);


  for (AnimationDescription::iterator it = parser.m_animations.begin(); it != parser.m_animations.end(); ++it) {
    std::vector<Frame*> frames;
    for (std::vector<std::pair<float, float> >::iterator jt = it->second.begin(); jt != it->second.end(); ++jt) {
      Frame* f = new Frame(spritesheet + ".png");
      f->setUV(jt->first, jt->second);
      f->setSize(parser.frame_size, parser.frame_size);
      setScale(m_context.TILE_SIZE / parser.frame_size);
      frames.push_back(f);
    }

    m_frames.insert(std::make_pair(it->first, frames));
  }

  
}

void AnimatedSprite::animate(std::string dir) {
  m_animate = true;
  if (dir != m_direction) {
    m_frame_nr = 0;
    m_direction = dir;
  }
}

void AnimatedSprite::stop() {
  m_animate = false;
  m_frame_nr = 0;
  m_direction = Animations::down;
}

void AnimatedSprite::render() {
  dynamic_cast<SpriteRenderBehaviour*>(m_render_behaviour)->setFrame(m_frames.at(m_direction).at((m_frame_nr / m_animation_speed) % m_frames.at(m_direction).size()));
  Sprite::render();
  if (m_animate) {
    m_frame_nr++;
  }
}

