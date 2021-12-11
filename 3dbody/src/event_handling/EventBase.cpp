
#include "include/event_handling/EventBase.h"
#include "include/layout/BaseWindow.h"

void gf::onWindowSizeCallback(GLFWwindow *window, int width, int height) {
  auto pWindow = static_cast<BaseWindow *>(glfwGetWindowUserPointer(window));
  pWindow->onResize(width, height);
}


void gf::onWindowCloseCallback(GLFWwindow *window)  {
  BaseWindow *pWindow = static_cast<BaseWindow *>(glfwGetWindowUserPointer(window));
  pWindow->onClose();
}

