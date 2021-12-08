

#ifndef INC_3DBODY_3DBODY_INCLUDE_LAYOUT_VIEW_WINDOW_H_
#define INC_3DBODY_3DBODY_INCLUDE_LAYOUT_VIEW_WINDOW_H_

#include "include/render/render_base.h"
#include "include/mesh/mesh.h"
#include "include/shader/shader.h"
#include "include/scene/scene_camera.h"
#include "include/scene/scene_light.h"
#include "include/scene/scene_view.h"

#include "include/render/ui_context.h"
#include "include/render/opengl_context.h"
#include "include/render/opengl_buffer_manager.h"
#include "include/layout/property_panel.h"


namespace gf {

class ViewWindow : public GFWindow {
 public:

  ViewWindow() :
      mIsRunning(true), mWindow(nullptr) {
    mUICtx = std::make_unique<UIContext>();
    mRenderCtx = std::make_unique<OpenGL_Context>();
  }

  ~ViewWindow();

  bool init(int width, int height, const std::string &title);

  void render();

  void handle_input();

  void *get_native_window() override { return mWindow; }

  void set_native_window(void *window) {
    mWindow = (GLFWwindow *) window;
  }

  void on_scroll(double delta) override;

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

};

}

#endif //INC_3DBODY_3DBODY_INCLUDE_LAYOUT_VIEW_WINDOW_H_
