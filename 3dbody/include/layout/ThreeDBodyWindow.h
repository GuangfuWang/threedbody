

#ifndef INC_3DBODY_3DBODY_INCLUDE_LAYOUT_THREEDBODYWINDOW_H_
#define INC_3DBODY_3DBODY_INCLUDE_LAYOUT_THREEDBODYWINDOW_H_

#include "include/render/RenderBase.h"
#include "include/mesh/Mesh.h"
#include "include/shader/Shader.h"
#include "include/scene/SceneCamera.h"
#include "include/scene/SceneLight.h"
#include "SceneView.h"

#include "include/render/UIContext.h"
#include "include/render/OpenGLContext.h"
#include "include/render/OpenGLBufferManager.h"
#include "include/layout/PropertyPanel.h"

namespace gf {

class ThreeDBodyWindow : public BaseWindow {
 public:

  ThreeDBodyWindow() :
	  mIsRunning(true), mWindow(nullptr) {
	mUICtx     = std::make_unique<UIContext>();
	mRenderCtx = std::make_unique<OpenGL_Context>();
  }

  ~ThreeDBodyWindow();

  bool init(int width, int height, const std::string &title);

  void render();

  void handle_input();

  void *get_native_window() override { return mWindow; }

  void set_native_window(void *window) {
	mWindow = (GLFWwindow *)window;
  }

  void on_scroll(double delta) override;


  void on_mouse_button(unsigned char code) override;

  void on_key(int key, int scancode, int action, int mods) override;

  void on_resize(int width, int height) override;

  void on_close() override;

  bool is_running() { return mIsRunning; }

 private:

  GLFWwindow *mWindow;

  // Render contexts
  std::unique_ptr<UIContext> mUICtx;

  std::unique_ptr<OpenGL_Context> mRenderCtx;

  // UI components
  std::unique_ptr<Property_Panel> mPropertyPanel;

  std::unique_ptr<SceneView> mSceneView;

  bool mIsRunning;

  float scene_property_width_ratio = 0.8f;
  float scene_property_height_ratio = 1.0f;

};

}

#endif //INC_3DBODY_3DBODY_INCLUDE_LAYOUT_THREEDBODYWINDOW_H_
