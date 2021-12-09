#ifndef INC_3DBODY_UI_CONTEXT_H
#define INC_3DBODY_UI_CONTEXT_H

#include "RenderBase.h"

namespace gf
{
  class UIContext : public RenderContext
  {

  public:

    bool init(BaseWindow* window) override;

    void pre_render() override;

    void post_render() override;

    void end() override;

    void setupWindowIcon(GLFWwindow* glWindow) override;

  };
}

#endif
