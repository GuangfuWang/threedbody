
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


/**
 * please note we did NOT implement a class what's soever, that is because we current will not use game controller.
 * maybe implement that in future as a feature.
 * @author Guangfu.
 * @param jid
 * @param event
 */
extern void onJoystickCallback(int jid, int event);

}

#endif //INC_3DBODY_3DBODY_INCLUDE_EVENT_HANDLING_GAME_CONTROLLER_EVENT_H_
