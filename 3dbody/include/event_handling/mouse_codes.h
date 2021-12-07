//
// Created by bigdata-wgf on 2021/12/7.
//

#ifndef INC_3DBODY_3DBODY_INCLUDE_EVENT_HANDLING_MOUSE_CODES_H_
#define INC_3DBODY_3DBODY_INCLUDE_EVENT_HANDLING_MOUSE_CODES_H_

namespace gf {

enum MouseCode {
  // From glfw3.h
  Button0 = 0,
  Button1 = 1,
  Button2 = 2,
  Button3 = 3,
  Button4 = 4,
  Button5 = 5,
  Button6 = 6,
  Button7 = 7,

  ButtonLast = Button7,
  ButtonLeft = Button0,
  ButtonRight = Button1,
  ButtonMiddle = Button2
};
}

#endif //INC_3DBODY_3DBODY_INCLUDE_EVENT_HANDLING_MOUSE_CODES_H_
