#include "include/event_handling/MouseEvent.h"
#include "include/layout/BaseWindow.h"
#include "util/Log.h"

namespace gf {

MouseEventHandling *ThreeDBodyMouseEventHandling::instance_ = nullptr;

void onMouseButtonCallback(GLFWwindow *window, int button, int action, int mods) {
  ThreeDBodyMouseEventHandling::getInstance()->onMouseButtonCallback(window, button, action, mods);
}

void onScrollCallback(GLFWwindow *window, double xoffset, double yoffset) {
  ThreeDBodyMouseEventHandling::getInstance()->onScrollCallback(window, xoffset, yoffset);
}

void onDropFileCallback(GLFWwindow *window, int count, const char **paths) {
  ThreeDBodyMouseEventHandling::getInstance()->onDropFileCallback(window, count, paths);
}

void ThreeDBodyMouseEventHandling::onMouseButtonCallback(GLFWwindow *window, int button, int action, int mods) {
  if (button==GLFW_MOUSE_BUTTON_LEFT) {
	double x;
	double y;
	glfwGetCursorPos(window, &x, &y);
	if (MouseInput::getMouseAction(action)==MOUSE_ACTION::MOUSE_ACTION_PRESSED) {

	  double x, y;
	  glfwGetCursorPos(window, &x, &y);
	  auto pWindow = static_cast<BaseWindow *>(glfwGetWindowUserPointer(window));
//	  pWindow->getSceneView()->onMouseMove(x, y, MouseInput::getMouseButton(button));
	  GF_CORE_INFO("Mouse left button clicked!");

	}

  } else if (button = GLFW_MOUSE_BUTTON_RIGHT) {

  }
}

void ThreeDBodyMouseEventHandling::onScrollCallback(GLFWwindow *window, double xoffset, double yoffset) {
  auto pWindow = static_cast<BaseWindow *>(glfwGetWindowUserPointer(window));
//  pWindow->onScroll(yoffset);
}

void ThreeDBodyMouseEventHandling::onDropFileCallback(GLFWwindow *window, int count, const char **paths) {
  for (int i = 0; i < count; i++) {
	//TODO: here add drop file callback
  }
}

MouseEventHandling *ThreeDBodyMouseEventHandling::getInstance() {
  if (instance_==nullptr) {
	instance_ = new ThreeDBodyMouseEventHandling();
  }
  return instance_;
}

}

