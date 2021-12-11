
#include "include/event_handling/KeyEvent.h"

void gf::onKeyCallback(GLFWwindow *window, int key, int scancode, int action, int mods) {
  auto pWindow = static_cast<BaseWindow *>(glfwGetWindowUserPointer(window));
  pWindow->onKey(key, scancode, action, mods);
}

