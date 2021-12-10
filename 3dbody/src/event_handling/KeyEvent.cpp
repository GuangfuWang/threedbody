
#include "include/event_handling/KeyEvent.h"

void gf::on_key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {
  auto pWindow = static_cast<BaseWindow *>(glfwGetWindowUserPointer(window));
  pWindow->on_key(key, scancode, action, mods);
}

