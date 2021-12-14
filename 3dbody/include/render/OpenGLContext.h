#ifndef INC_3DBODY_OPENGL_CONTEXT_H
#define INC_3DBODY_OPENGL_CONTEXT_H

#include "include/render/RenderContext.h"
#include "include/layout/BaseWindow.h"
#include "include/event_handling/KeyEvent.h"
#include "include/event_handling/MouseEvent.h"
#include "include/event_handling/ApplicationEvent.h"

namespace gf {
class OpenGL_Context final : public RenderContext {
 public:

  bool init(BaseWindow *window) override;

  void preRender() override;

  void postRender() override;

  void end() override;

  void setupWindowIcon(GLFWwindow *glWindow) override;

};
}

#endif
