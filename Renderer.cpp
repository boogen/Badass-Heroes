#include "GL/gl.h"
#include "Renderer.h"
#include "IDrawable.h"
#include "TextureFactory.h"

Renderer::Renderer(float window_width, float window_height):m_window_width(window_width),
                                                        m_window_height(window_height) {
}

void Renderer::renderSprite(const IDrawable& drawable) {
    Texture t = m_texture_factory.getTexture(drawable.texture());
    glLoadIdentity();
    glTranslatef(drawable.x(), drawable.y(), 0.0f);
    glScalef(2 *t.width() / m_window_width, 2 *t.height() / m_window_height, 1.0f);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, t.get());
    glBegin(GL_TRIANGLES);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1.0f, 0.0f, 0.0f);

    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 0.0f);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);

    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 0.0f);

    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(0.0f, 1.0f, 0.0f);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);

    glEnd();
}