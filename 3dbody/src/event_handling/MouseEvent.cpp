#include "include/event_handling/MouseEvent.h"
#include "include/layout/BaseWindow.h"
#include "util/Log.h"

namespace gf {

MouseEventHandling *ThreeDBodyMouseEventHandling::instance_ = nullptr;

void onMouseButtonCallback(GLFWwindow *window, int button, int action, int mods) {
  ThreeDBodyMouseEventHandling::getInstance()->onMouseButtonCallback(window, button, action, mods);
}

void onMouseWheelCallback(GLFWwindow *window, double xoffset, double yoffset) {
  ThreeDBodyMouseEventHandling::getInstance()->onScrollCallback(window, xoffset, yoffset);
}

void onDropFileCallback(GLFWwindow *window, int count, const char **paths) {
  ThreeDBodyMouseEventHandling::getInstance()->onDropFileCallback(window, count, paths);
}

void ThreeDBodyMouseEventHandling::onMouseButtonCallback(GLFWwindow *window, int button, int action, int mods) {
  ///mouse left button used to pan models
  ///mouse right button used to rotate.
  ///mouse left button + ALT modifier used to scale whole model objects.
  ///to scale along certain direction, please use keyboard callback.
  glfwGetCursorPos(window, &x_, &y_);
  if (button==GLFW_MOUSE_BUTTON_LEFT) {
	if (MouseInput::getMouseModifier(mods)==MOUSE_MODIFIER::MOUSE_MOD_ALT
		&& MouseInput::getMouseAction(action)==MOUSE_ACTION::MOUSE_ACTION_PRESSED) {

	  //todo: implement scale functionality.
	  return;
	}
	if (MouseInput::getMouseAction(action)==MOUSE_ACTION::MOUSE_ACTION_PRESSED) {
	  auto pWindow = static_cast<BaseWindow *>(glfwGetWindowUserPointer(window));
	  pWindow->getSceneView()->getCamera()->onPanMovement(x_, y_);
	  glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
	}
	if (MouseInput::getMouseAction(action)==MOUSE_ACTION::MOUSE_ACTION_RELEASED) {
	  glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
	}
  } else if (button = GLFW_MOUSE_BUTTON_RIGHT) {
	if (MouseInput::getMouseAction(action)==MOUSE_ACTION::MOUSE_ACTION_PRESSED) {
	  auto pWindow = static_cast<BaseWindow *>(glfwGetWindowUserPointer(window));

	  //fixme: implement rotational functionality in camera class.
	  pWindow->getSceneView()->getCamera()->onRotateMovement(x_, y_);
	  glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
	}
	if (MouseInput::getMouseAction(action)==MOUSE_ACTION::MOUSE_ACTION_RELEASED) {
	  glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
	}
  }
}

void ThreeDBodyMouseEventHandling::onScrollCallback(GLFWwindow *window, double xoffset, double yoffset) {
  auto pWindow = static_cast<BaseWindow *>(glfwGetWindowUserPointer(window));
  pWindow->getSceneView()->getCamera()->onZoomMovement(yoffset);
}

void ThreeDBodyMouseEventHandling::onDropFileCallback(GLFWwindow *window, int count, const char **paths) {
  for (int i = 0; i < count; i++) {
	//TODO: here add drop file callback
  }
}

MouseEventHandling *ThreeDBodyMouseEventHandling::getInstance() {
  if (instance_==nullptr) {
	instance_ = new ThreeDBodyMouseEventHandling();
	instance_->x_ = 0;
	instance_->y_ = 0;
#ifdef GF_CUSTOM_CURSOR
	///implement your custom cursor setup function by setting images and x and y dimension.
	///then you can pass to getCreateCustomCursor function of GLFW.
	///to destroy your custom cursor use getStandardCursor(0).
	///@see GLFW/glfw3.h
#endif
  }
  return instance_;
}

}

