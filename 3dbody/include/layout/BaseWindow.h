
#ifndef _VIEW_WINDOW_H_
#define _VIEW_WINDOW_H_

#include "def.h"

namespace gf {

class BaseWindow {
 public:

  virtual void *getNativeWindow() = 0;

  virtual void setNativeWindow(void *window) = 0;

  virtual void onScroll(double delta) = 0;

  virtual void onMouseButton(unsigned char code) = 0;

  virtual void onKey(int key, int scancode, int action, int mods) = 0;

  virtual void onResize(int width, int height) = 0;

  virtual void onClose() = 0;

  int    mWidth;
  int    mHeight;
  string mTitle;
};

}

#endif //_VIEW_WINDOW_H_
