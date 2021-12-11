
#ifndef INC_3DBODY_3DBODY_INCLUDE_EVENT_HANDLING_GAME_CONTROLLER_EVENT_H_
#define INC_3DBODY_3DBODY_INCLUDE_EVENT_HANDLING_GAME_CONTROLLER_EVENT_H_

#include <GLFW/glfw3.h>
#include "util/Log.h"

namespace gf {

enum JOYSTICK_INPUT {
  HAT_CENTERED   = 0,
  HAT_UP         = 1 << 0,
  HAT_RIGHT      = 1 << 1,
  HAT_DOWN       = 1 << 2,
  HAT_LEFT       = 1 << 3,
  HAT_RIGHT_UP   = (HAT_RIGHT | HAT_UP),
  HAT_RIGHT_DOWN = (HAT_RIGHT | HAT_DOWN),
  HAT_LEFT_UP    = (HAT_LEFT | HAT_UP),
  HAT_LEFT_DOWN  = (HAT_LEFT | HAT_DOWN),
};

extern void onJoystickCallback(int jid, int event);

}

#endif //INC_3DBODY_3DBODY_INCLUDE_EVENT_HANDLING_GAME_CONTROLLER_EVENT_H_
