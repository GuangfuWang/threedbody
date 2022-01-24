

#ifndef INC_3DBODY_3DBODY_INCLUDE_LAYOUT_THREEDBODYWINDOW_H_
#define INC_3DBODY_3DBODY_INCLUDE_LAYOUT_THREEDBODYWINDOW_H_

#include "include/layout/MainWindows/BaseWindow.h"
#include "include/render/RenderVertexIndexBuffer/VertexIndexBufferBase.h"
#include "include/mesh/MeshData/VanillaMesh.h"
#include "include/shader/Shader.h"
#include "include/scene/SceneCamera.h"
#include "include/scene/SceneLight.h"

#include "include/render/RenderContext/UIContext.h"
#include "include/render/RenderContext/OpenGLContext.h"
#include "include/layout/ViewPort/SceneView.h"
#include "include/layout/ContentBroswer/ContentBroswer.h"
#include "include/layout/WidgetPanels/PropertyPanel.h"

namespace gf {

class ThreeDBodyWindow : public BaseWindow {
 public:

  ThreeDBodyWindow() :
	  mIsRunning(true), mWindow(nullptr), contentBrowserOpen(true) {
	mUICtx     = std::make_unique<UIContext>();
	mRenderCtx = std::make_unique<OpenGL_Context>();
  }

  ~ThreeDBodyWindow();

  bool init(int width, int height, const string &title);

  void render() override;

  void *getNativeWindow() override { return mWindow; }

  void setNativeWindow(void *window) {
	mWindow = (GLFWwindow *)window;
  }

  bool isRunning() { return mIsRunning; }

  void setRunningStatus(bool run) override {
	mIsRunning = run;
  }

  void setWidth(const int &w) override { mWidth = w; }

  void setHeight(const int &h) override { mHeight = h; }

  int getWidth() override { return mWidth; }

  int getHeight() override { return mHeight; }

  SceneView *getSceneView() override { return mSceneView.get(); }

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
