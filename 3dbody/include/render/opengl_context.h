#ifndef INC_3DBODY_OPENGL_CONTEXT_H
#define INC_3DBODY_OPENGL_CONTEXT_H

#include "render_base.h"

namespace gf
{
  class OpenGL_Context : public RenderContext
  {
  public:

    bool init(GFWindow* window) override;

    void pre_render() override;

    void post_render() override;

    void end() override;

    void setupWindowIcon(GLFWwindow* glWindow) override;
  };
}

#endif
