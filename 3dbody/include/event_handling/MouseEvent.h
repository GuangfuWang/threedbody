
#ifndef INC_3DBODY_3DBODY_INCLUDE_EVENT_HANDLING_MOUSEEVENT_H_
#define INC_3DBODY_3DBODY_INCLUDE_EVENT_HANDLING_MOUSEEVENT_H_

#include <GLFW/glfw3.h>
#include <climits>

namespace gf {

/**
 * @brief Mouse used to control mouse handling.
 */

enum class MOUSE_BUTTON {
  LEFT  = GLFW_MOUSE_BUTTON_LEFT,
  RIGHT = GLFW_MOUSE_BUTTON_RIGHT,

  ///Not used mouse buttons in current project.
  MIDDLE      = GLFW_MOUSE_BUTTON_MIDDLE,
  BUTTON_1    = GLFW_MOUSE_BUTTON_1,
  BUTTON_2    = GLFW_MOUSE_BUTTON_2,
  BUTTON_3    = GLFW_MOUSE_BUTTON_3,
  BUTTON_4    = GLFW_MOUSE_BUTTON_4,
  BUTTON_5    = GLFW_MOUSE_BUTTON_5,
  BUTTON_6    = GLFW_MOUSE_BUTTON_6,
  BUTTON_7    = GLFW_MOUSE_BUTTON_7,
  BUTTON_8    = GLFW_MOUSE_BUTTON_8,
  BUTTON_LAST = GLFW_MOUSE_BUTTON_LAST,

  ///error code.
  NONE = INT_MAX
};

enum class MOUSE_ACTION {
  MOUSE_ACTION_PRESSED  = GLFW_PRESS,
  MOUSE_ACTION_RELEASED = GLFW_RELEASE,
  MOUSE_ACTION_REPEAT   = GLFW_REPEAT,

  ///error code.
  MOUSE_ACTION_NONE = INT_MAX
};

enum class MOUSE_MODIFIER {
  MOUSE_MOD_CTRL  = GLFW_MOD_CONTROL,
  MOUSE_MOD_ALT   = GLFW_MOD_ALT,
  MOUSE_MOD_SHIFT = GLFW_MOD_SHIFT,

  ///Not used in current project actually.
  MOUSE_MOD_CAPS_LOCK = GLFW_MOD_CAPS_LOCK,
  MOUSE_MOD_SUPER     = GLFW_MOD_SUPER,
  MOUSE_MOD_NUM_LOCK  = GLFW_MOD_NUM_LOCK,

  ///error code
  MOUSE_MOD_NONE = INT_MAX
};

class MouseInput {
 public:

  static MOUSE_BUTTON getMouseButton(GLFWwindow *window) {

	if (glfwGetMouseButton(window, 0)==GLFW_PRESS)
	  return MOUSE_BUTTON::LEFT;
	else if (glfwGetMouseButton(window, 1)==GLFW_PRESS)
	  return MOUSE_BUTTON::RIGHT;

	//todo: if you need to use other mouse button, please implement here.
	return MOUSE_BUTTON::NONE;

  }

  static MOUSE_BUTTON getMouseButton(const int &button) {

	if (button==GLFW_MOUSE_BUTTON_RIGHT)return MOUSE_BUTTON::RIGHT;
	if (button==GLFW_MOUSE_BUTTON_LEFT)return MOUSE_BUTTON::LEFT;

	  //todo: if you need to use other mouse button, please implement here.
	else return MOUSE_BUTTON::NONE;
  }

  static MOUSE_ACTION getMouseAction(const int &action) {

	if (action==GLFW_PRESS) return MOUSE_ACTION::MOUSE_ACTION_PRESSED;
	if (action==GLFW_RELEASE) return MOUSE_ACTION::MOUSE_ACTION_RELEASED;
	if (action==GLFW_REPEAT) return MOUSE_ACTION::MOUSE_ACTION_REPEAT;

	///error code.
	return MOUSE_ACTION::MOUSE_ACTION_NONE;
  }

  static MOUSE_MODIFIER getMouseModifier(const int &mods) {

	if (mods==GLFW_MOD_CONTROL)return MOUSE_MODIFIER::MOUSE_MOD_CTRL;
	if (mods==GLFW_MOD_ALT)return MOUSE_MODIFIER::MOUSE_MOD_ALT;
	if (mods==GLFW_MOD_SHIFT)return MOUSE_MODIFIER::MOUSE_MOD_SHIFT;

	///error code.
	return MOUSE_MODIFIER::MOUSE_MOD_NONE;
  }

};

class MouseEventHandling {

 public:

  virtual void onMouseButtonCallback(GLFWwindow *window, int button, int action, int mods) = 0;

  virtual void onScrollCallback(GLFWwindow *window, double xoffset, double yoffset) = 0;

  virtual void onDropFileCallback(GLFWwindow *window, int count, const char **paths) = 0;

};

class ThreeDBodyMouseEventHandling : public MouseEventHandling {

 public:

  void onMouseButtonCallback(GLFWwindow *window, int button, int action, int mods) override;

  void onScrollCallback(GLFWwindow *window, double xoffset, double yoffset) override;

  void onDropFileCallback(GLFWwindow *window, int count, const char **paths) override;

  static MouseEventHandling *getInstance();

 private:
  ThreeDBodyMouseEventHandling() = default;

 private:
  static MouseEventHandling *instance_;

};

extern void onMouseButtonCallback(GLFWwindow *window, int button, int action, int mods);

extern void onScrollCallback(GLFWwindow *window, double xoffset, double yoffset);

extern void onDropFileCallback(GLFWwindow *window, int count, const char **paths);

}

#endif //INC_3DBODY_3DBODY_INCLUDE_EVENT_HANDLING_MOUSEEVENT_H_
