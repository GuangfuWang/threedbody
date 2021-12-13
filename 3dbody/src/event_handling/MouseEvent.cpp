#include "include/event_handling/MouseEvent.h"
#include "include/layout/BaseWindow.h"
#include "util/Log.h"

void gf::onMouseButtonCallback(GLFWwindow *window, int button, int action, int mods) {
  if (button==GLFW_MOUSE_BUTTON_LEFT) {
	double x;
	double y;
	glfwGetCursorPos(window, &x, &y);
	if (action==MOUSE_ACTION::PRESSED)GF_CORE_INFO("Mouse left button clicked!");
  }
}
void gf::onScrollCallback(GLFWwindow *window, double xoffset, double yoffset) {
  auto pWindow = static_cast<BaseWindow *>(glfwGetWindowUserPointer(window));
  pWindow->onScroll(yoffset);
}
void gf::onDropFileCallback(GLFWwindow *window, int count, const char **paths) {
  for (int i = 0; i < count; i++) {
	//TODO: here add drop file callback
  }
}

