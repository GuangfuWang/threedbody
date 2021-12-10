#include "include/event_handling/MouseEvent.h"
#include "include/layout/BaseWindow.h"

void gf::on_mouse_button_callback(GLFWwindow *window, int button, int action, int mods) {
  if (button==GLFW_MOUSE_BUTTON_LEFT) {
	double x;
	double y;
	glfwGetCursorPos(window, &x, &y);
  }
}
void gf::on_scroll_callback(GLFWwindow *window, double xoffset, double yoffset) {
  auto pWindow = static_cast<BaseWindow *>(glfwGetWindowUserPointer(window));
  pWindow->on_scroll(yoffset);
}
void gf::on_drop_file_callback(GLFWwindow *window, int count, const char **paths) {
  for (int i = 0; i < count; i++) {
	//TODO: here add drop file callback
  }
}

