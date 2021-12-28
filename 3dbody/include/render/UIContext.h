#ifndef INC_3DBODY_UI_CONTEXT_H
#define INC_3DBODY_UI_CONTEXT_H

#include <imgui.h>
#include "include/render/RenderContext.h"
#include "include/layout/MainWindows/BaseWindow.h"

namespace gf {

enum UI_STYLE {
  DEFAULT = 0,
  DARK    = 1,
  CLASSIC = 2,
  LIGHT   = 3
};

class UIContext : public RenderContext {

 public:

  bool init(BaseWindow *window) override;

  void preRender() override;

  void postRender() override;

  void end() override;

  void setupWindowIcon(GLFWwindow *glWindow) override;

  void setStyle(const UI_STYLE &m_style = UI_STYLE::DEFAULT);

  void enableKeyboardControl(ImGuiIO &io);

  void enableDocking(ImGuiIO &io);

  void enableJoystickControl(ImGuiIO &io);

  void setupGLSLVersion(const char *glsl_ver = "#version 430");

 private:

  void loadFont(ImGuiIO &io);

 private:
  mutable char *glslVersion;
};
}

#endif
