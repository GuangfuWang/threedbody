
#ifndef INC_3DBODY_3DBODY_INCLUDE_RENDER_RENDERCONTEXT_H_
#define INC_3DBODY_3DBODY_INCLUDE_RENDER_RENDERCONTEXT_H_

#include "include/render/VertexIndexBuffer.h"
#include "include/layout/MainWindows/BaseWindow.h"

namespace gf {

class RenderContext {

 public:

  RenderContext() : mWindow(nullptr) {}

  virtual bool init(BaseWindow *window) {
	mWindow = window;
	return true;
  }

  virtual void preRender() = 0;

  virtual void postRender() = 0;

  virtual void end() = 0;

  virtual void setupWindowIcon(GLFWwindow *glWindow) = 0;

 protected:
  BaseWindow *mWindow;
};

}

#endif //INC_3DBODY_3DBODY_INCLUDE_RENDER_RENDERCONTEXT_H_
