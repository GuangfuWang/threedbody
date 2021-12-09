//
// Created by bigdata-wgf on 2021/12/8.
//

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

}

#endif //INC_3DBODY_3DBODY_INCLUDE_EVENT_HANDLING_EVENTBASE_H_