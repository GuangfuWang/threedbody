

#ifndef INC_3DBODY_3DBODY_INCLUDE_LAYOUT_THREEDBODYWINDOW_H_
#define INC_3DBODY_3DBODY_INCLUDE_LAYOUT_THREEDBODYWINDOW_H_

#include "include/layout/BaseWindow.h"
#include "include/render/VertexIndexBuffer.h"
#include "include/mesh/Mesh.h"
#include "include/shader/Shader.h"
#include "include/scene/SceneCamera.h"
#include "include/scene/SceneLight.h"

#include "include/render/UIContext.h"
#include "include/render/OpenGLContext.h"
#include "include/layout/SceneView.h"
#include "include/layout/ContentBroswer.h"
#include "include/layout/PropertyPanel.h"

namespace gf {

class ThreeDBodyWindow : public BaseWindow {
 public:

  ThreeDBodyWindow() :
	  mIsRunning(true), mWindow(nullptr),contentBrowserOpen(true) {
	mUICtx     = std::make_unique<UIContext>();
	mRenderCtx = std::make_unique<OpenGL_Context>();
  }

  ~ThreeDBodyWindow();

  bool init(int width, int height, const string &title);

  void render();

  void handleInput();

  void *getNativeWindow() override { return mWindow; }

  void setNativeWindow(void *window) {
	mWindow = (GLFWwindow *)window;
  }

  void onScroll(double delta) override;

  void onMouseButton(unsigned char code) override;

  void onKey(int key, int scancode, int action, int mods) override;

  void onResize(int width, int height) override;

  void onClose() override;

  bool isRunning() { return mIsRunning; }

 private:

  GLFWwindow *mWindow;

  // Render contexts
  Ref_Unique<UIContext> mUICtx;

  Ref_Unique<OpenGL_Context> mRenderCtx;

  // UI components
  Ref_Unique<Property_Panel> mPropertyPanel;

  Ref_Unique<SceneView> mSceneView;

  Ref_Unique<ContentBrowser> mContentBrowser;

  bool mIsRunning;

  bool contentBrowserOpen;

};

}

#endif //INC_3DBODY_3DBODY_INCLUDE_LAYOUT_THREEDBODYWINDOW_H_
