
#ifndef INC_3DBODY_3DBODY_INCLUDE_EVENT_HANDLING_MOUSEEVENT_H_
#define INC_3DBODY_3DBODY_INCLUDE_EVENT_HANDLING_MOUSEEVENT_H_

#include <GLFW/glfw3.h>

namespace gf {

enum MOUSE_INPUT_CODE {
  LEFT   = 0,
  RIGHT  = 1,
  MIDDLE = 2,
  NONE   = 9
};

enum MOUSE_ACTION{
  PRESSED = GLFW_PRESS,
  RELEASED = GLFW_RELEASE,
  REPEAT = GLFW_REPEAT
};

class MouseInput {
 public:
  static MOUSE_INPUT_CODE getPressedButton(GLFWwindow *window) {
	if (glfwGetMouseButton(window, 0)==GLFW_PRESS)
	  return MOUSE_INPUT_CODE::LEFT;
	else if (glfwGetMouseButton(window, 1)==GLFW_PRESS)
	  return MOUSE_INPUT_CODE::RIGHT;
	else if (glfwGetMouseButton(window, 2)==GLFW_PRESS)
	  return MOUSE_INPUT_CODE::MIDDLE;
	return MOUSE_INPUT_CODE::NONE;

  }
};

extern void onMouseButtonCallback(GLFWwindow *window, int button, int action, int mods);

extern void onScrollCallback(GLFWwindow *window, double xoffset, double yoffset);

extern void onDropFileCallback(GLFWwindow *window, int count, const char **paths);

}

#endif //INC_3DBODY_3DBODY_INCLUDE_EVENT_HANDLING_MOUSEEVENT_H_
