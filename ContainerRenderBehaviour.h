#ifndef CONTAINERRENDERBEHAVIOUR_H__
#define CONTAINERRENDERBEHAVIOUR_H__

#include "IRenderBehaviour.h"
#include "DisplayObject.h"
#include <vector>

class ContainerRenderBehaviour : public IRenderBehaviour {
 public:
  ContainerRenderBehaviour(std::vector<DisplayObject*> const&);
  void onRender(IRenderer*, DisplayObject const&);
 private:
  std::vector<DisplayObject*> const& m_children;
};

#endif
