
#include "include/event_handling/EventBase.h"
#include "include/layout/BaseWindow.h"

void gf::on_window_size_callback(GLFWwindow *window, int width, int height) {
  auto pWindow = static_cast<BaseWindow *>(glfwGetWindowUserPointer(window));
  pWindow->on_resize(width, height);
}


void gf::on_window_close_callback(GLFWwindow *window)  {
  BaseWindow *pWindow = static_cast<BaseWindow *>(glfwGetWindowUserPointer(window));
  pWindow->on_close();
}

