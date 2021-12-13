
#ifndef INC_3DBODY_3DBODY_INCLUDE_EVENT_HANDLING_EVENTBASE_H_
#define INC_3DBODY_3DBODY_INCLUDE_EVENT_HANDLING_EVENTBASE_H_

#include "include/shader/Shader.h"

namespace gf {

enum class EVENT_SOURCE_TYPE {
  NONE = 0,
  KEYBOARD,
  MOUSE,
  JOYSTICK,
  TIME_INPUT,
  CLIPBOARD,
  PATH_DROP
};

enum class EVENT_ACTION {
  NONE = 0,
  PRESSED,
  RELEASE,
  HOVERED
};

class EventHandleBase {
 public:
  virtual void update(Shader *shader) = 0;
};


/**
 * @brief this class is used for dispatching all events.
 */
class EventDispatcher{

 public:

  void dispatch();


};


extern void onWindowSizeCallback(GLFWwindow *window, int width, int height);

extern void onWindowCloseCallback(GLFWwindow *window);

}

#endif //INC_3DBODY_3DBODY_INCLUDE_EVENT_HANDLING_EVENTBASE_H_
