
#ifndef INC_3DBODY_3DBODY_INCLUDE_EVENT_HANDLING_EVENTBASE_H_
#define INC_3DBODY_3DBODY_INCLUDE_EVENT_HANDLING_EVENTBASE_H_

#include "include/shader/Shader.h"

namespace gf {

#define EVENT_SOURCE(X) EVENT_SOURCE_TYPE::##X

enum class EVENT_SOURCE_TYPE {
  NONE = 0,
  KEYBOARD,
  MOUSE,
  JOYSTICK,
  TIME_INPUT,
  CLIPBOARD,
  PATH_DROP
};

class EventHandleInterface {
 public:

  virtual void update(Shader *shader) = 0;

};

}

#endif //INC_3DBODY_3DBODY_INCLUDE_EVENT_HANDLING_EVENTBASE_H_
