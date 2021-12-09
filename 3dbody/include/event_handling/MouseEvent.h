//
// Created by bigdata-wgf on 2021/12/8.
//

#ifndef INC_3DBODY_3DBODY_INCLUDE_EVENT_HANDLING_MOUSEEVENT_H_
#define INC_3DBODY_3DBODY_INCLUDE_EVENT_HANDLING_MOUSEEVENT_H_

#include "GLFW/glfw3.h"

namespace gf {

enum class MOUSE_INPUT_CODE {
  LEFT   = 0,
  RIGHT  = 1,
  MIDDLE = 2,
  NONE   = 9
};

class MouseInput {
 public:
  static MOUSE_INPUT_CODE GetPressedButton(GLFWwindow *window) {
	if (glfwGetMouseButton(window, 0)==GLFW_PRESS)
	  return MOUSE_INPUT_CODE::LEFT;
	else if (glfwGetMouseButton(window, 1)==GLFW_PRESS)
	  return MOUSE_INPUT_CODE::RIGHT;
	else if (glfwGetMouseButton(window, 2)==GLFW_PRESS)
	  return MOUSE_INPUT_CODE::MIDDLE;
	return MOUSE_INPUT_CODE::NONE;

  }
};

}

#endif //INC_3DBODY_3DBODY_INCLUDE_EVENT_HANDLING_MOUSEEVENT_H_
