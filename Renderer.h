#ifndef RENDERER_H__
#define RENDERER_H__

#include "IRenderer.h"
#include "TextureFactory.h"
#include "Types.h"
class IDrawable;
//class TextureFactory;

class Renderer: public IRenderer {
public:
    explicit Renderer();
    void beginFrame();
    void endFrame();
    void renderSprite(const IDrawable&);
    void renderSpriteAnimation(const IDrawable&, int frame, ANIM::Direction direction);
    void setSize(float, float);
    float getWindowWidth() const;
    float getWindowHeight() const;
private :
    TextureFactory m_texture_factory;
    float m_window_width;
    float m_window_height;
};


#endif
