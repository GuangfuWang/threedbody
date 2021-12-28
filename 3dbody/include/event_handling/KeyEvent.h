#ifndef INC_3DBODY_3DBODY_INCLUDE_EVENT_HANDLING_KEY_EVENT_H_
#define INC_3DBODY_3DBODY_INCLUDE_EVENT_HANDLING_KEY_EVENT_H_

#include <GLFW/glfw3.h>
#include "include/layout/MainWindows/BaseWindow.h"

namespace gf {

enum KEY_MAP {
  KEY_1 = GLFW_KEY_1,
  KEY_2 = GLFW_KEY_2,
  KEY_3 = GLFW_KEY_3,
  KEY_4 = GLFW_KEY_4,
  KEY_5 = GLFW_KEY_5,
  KEY_6 = GLFW_KEY_6,
  KEY_7 = GLFW_KEY_7,
  KEY_8 = GLFW_KEY_8,
  KEY_9 = GLFW_KEY_9,
  KEY_0 = GLFW_KEY_0,

  KEY_1_R = GLFW_KEY_KP_1,
  KEY_2_R = GLFW_KEY_KP_2,
  KEY_3_R = GLFW_KEY_KP_3,
  KEY_4_R = GLFW_KEY_KP_4,
  KEY_5_R = GLFW_KEY_KP_5,
  KEY_6_R = GLFW_KEY_KP_6,
  KEY_7_R = GLFW_KEY_KP_7,
  KEY_8_R = GLFW_KEY_KP_8,
  KEY_9_R = GLFW_KEY_KP_9,
  KEY_0_R = GLFW_KEY_KP_0,

  KEY_A = GLFW_KEY_A,
  KEY_B = GLFW_KEY_B,
  KEY_C = GLFW_KEY_C,
  KEY_D = GLFW_KEY_D,
  KEY_E = GLFW_KEY_E,
  KEY_F = GLFW_KEY_F,
  KEY_G = GLFW_KEY_G,
  KEY_H = GLFW_KEY_H,
  KEY_I = GLFW_KEY_I,
  KEY_J = GLFW_KEY_J,
  KEY_K = GLFW_KEY_K,
  KEY_L = GLFW_KEY_L,
  KEY_M = GLFW_KEY_M,
  KEY_N = GLFW_KEY_N,
  KEY_O = GLFW_KEY_O,
  KEY_P = GLFW_KEY_P,
  KEY_Q = GLFW_KEY_Q,
  KEY_R = GLFW_KEY_R,
  KEY_S = GLFW_KEY_S,
  KEY_T = GLFW_KEY_T,
  KEY_U = GLFW_KEY_U,
  KEY_V = GLFW_KEY_V,
  KEY_W = GLFW_KEY_W,
  KEY_X = GLFW_KEY_X,
  KEY_Y = GLFW_KEY_Y,
  KEY_Z = GLFW_KEY_Z,

  KEY_CTRL_LEFT   = GLFW_KEY_LEFT_CONTROL,
  KEY_CTRL_RIGHT  = GLFW_KEY_RIGHT_CONTROL,
  KEY_ALT_LEFT    = GLFW_KEY_LEFT_ALT,
  KEY_ALT_RIGHT   = GLFW_KEY_RIGHT_ALT,
  KEY_SHIFT_LEFT  = GLFW_KEY_LEFT_SHIFT,
  KEY_SHIFT_RIGHT = GLFW_KEY_RIGHT_SHIFT,

  KEY_ESC  = GLFW_KEY_ESCAPE,
  KEY_TAB  = GLFW_KEY_TAB,
  KEY_CAPS = GLFW_KEY_CAPS_LOCK,

  KEY_SPACE      = GLFW_KEY_SPACE,
  KEY_ADD        = GLFW_KEY_KP_ADD,
  KEY_MUL        = GLFW_KEY_KP_MULTIPLY,
  KEY_SUBTRACT   = GLFW_KEY_KP_SUBTRACT,
  KEY_DIV        = GLFW_KEY_KP_DIVIDE,
  KEY_ADD_R      = GLFW_KEY_KP_ADD,
  KEY_MUL_R      = GLFW_KEY_KP_MULTIPLY,
  KEY_SUBTRACT_R = GLFW_KEY_KP_SUBTRACT,
  KEY_DIV_R      = GLFW_KEY_KP_DIVIDE,
  KEY_EQUAL      = GLFW_KEY_EQUAL,

  KEY_UP    = GLFW_KEY_UP,
  KEY_DOWN  = GLFW_KEY_DOWN,
  KEY_LEFT  = GLFW_KEY_LEFT,
  KEY_RIGHT = GLFW_KEY_RIGHT,

  KEY_DOT           = GLFW_KEY_KP_DECIMAL,
  KEY_DOT_R         = GLFW_KEY_KP_DECIMAL,
  KEY_COMMA         = GLFW_KEY_COMMA,
  KEY_END           = GLFW_KEY_END,
  KEY_APOSTROPHE    = GLFW_KEY_APOSTROPHE,
  KEY_SLASH         = GLFW_KEY_SLASH,
  KEY_BACK_SLASH    = GLFW_KEY_BACKSLASH,
  KEY_BRACKET_LEFT  = GLFW_KEY_LEFT_BRACKET,
  KEY_BRACKET_RIGHT = GLFW_KEY_RIGHT_BRACKET,
  KEY_DELETE        = GLFW_KEY_DELETE,
  KEY_BACKSPACE     = GLFW_KEY_BACKSPACE,
  KEY_SEMICOLON     = GLFW_KEY_SEMICOLON,
  KEY_ENTER         = GLFW_KEY_ENTER,
  KEY_ENTER_R       = GLFW_KEY_KP_ENTER,

  KEY_F1  = GLFW_KEY_F1,
  KEY_F2  = GLFW_KEY_F2,
  KEY_F3  = GLFW_KEY_F3,
  KEY_F4  = GLFW_KEY_F4,
  KEY_F5  = GLFW_KEY_F5,
  KEY_F6  = GLFW_KEY_F6,
  KEY_F7  = GLFW_KEY_F7,
  KEY_F8  = GLFW_KEY_F8,
  KEY_F9  = GLFW_KEY_F9,
  KEY_F10 = GLFW_KEY_F10,
  KEY_F11 = GLFW_KEY_F11,
  KEY_F12 = GLFW_KEY_F12,

  KEY_NUM_LOCK     = GLFW_KEY_NUM_LOCK,
  KEY_GRAVE_ACCENT = GLFW_KEY_GRAVE_ACCENT

};

enum class KEY_ACTION {
  KEY_PRESSED  = GLFW_PRESS,
  KEY_RELEASED = GLFW_RELEASE,
  KEY_REPEAT   = GLFW_REPEAT,

  ///ERROR CODE.
  KEY_NONE = INT_MAX

};

enum class KEY_MODIFIER {
  KEY_MOD_CTRL  = GLFW_MOD_CONTROL,
  KEY_MOD_ALT   = GLFW_MOD_ALT,
  KEY_MOD_SHIFT = GLFW_MOD_SHIFT,

  ///Not used in current project actually.
  KEY_MOD_CAPS_LOCK = GLFW_MOD_CAPS_LOCK,
  KEY_MOD_SUPER     = GLFW_MOD_SUPER,
  KEY_MOD_NUM_LOCK  = GLFW_MOD_NUM_LOCK,

  ///error code.
  KEY_MOD_NONE = INT_MAX
};

class KeyInput {
 public:

  static KEY_ACTION getKeyAction(const int &action) {
	if (action==GLFW_PRESS)return KEY_ACTION::KEY_PRESSED;
	if (action==GLFW_RELEASE)return KEY_ACTION::KEY_RELEASED;
	if (action==GLFW_REPEAT) return KEY_ACTION::KEY_REPEAT;
	return KEY_ACTION::KEY_NONE;
  }

  static KEY_MODIFIER getKeyModifier(const int &mods) {
	if (mods==GLFW_MOD_CONTROL)return KEY_MODIFIER::KEY_MOD_CTRL;
	if (mods==GLFW_MOD_ALT)return KEY_MODIFIER::KEY_MOD_ALT;
	if (mods==GLFW_MOD_SHIFT)return KEY_MODIFIER::KEY_MOD_SHIFT;
	if (mods==GLFW_MOD_NUM_LOCK)return KEY_MODIFIER::KEY_MOD_NUM_LOCK;
	if (mods==GLFW_MOD_CAPS_LOCK)return KEY_MODIFIER::KEY_MOD_CAPS_LOCK;
	if (mods==GLFW_MOD_SUPER)return KEY_MODIFIER::KEY_MOD_SUPER;
	return KEY_MODIFIER::KEY_MOD_NONE;
  }

  static KEY_MAP getKeyMap(const int &key) {
	return (KEY_MAP)key;
  }

};

class KeyEventHandling {

 public:
  virtual void onKeyCallBack(GLFWwindow *window, int key, int scancode, int action, int mods) = 0;

};

/**
 * @note highly recommend you use singleton if you need implement your own key event handling system.
 */
class ThreeDBodyKeyEventHandling final : public KeyEventHandling {

 public:
  void onKeyCallBack(GLFWwindow *window, int key, int scancode, int action, int mods) override;
  static KeyEventHandling *getInstance();

 private:
  ThreeDBodyKeyEventHandling() = default;

 private:
  static KeyEventHandling *instance_;
};

extern void onKeyEventCallBack(GLFWwindow *window, int key, int scancode, int action, int mods);

}

#endif //INC_3DBODY_3DBODY_INCLUDE_EVENT_HANDLING_KEY_EVENT_H_
