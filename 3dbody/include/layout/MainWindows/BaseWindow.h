
#ifndef _VIEW_WINDOW_H_
#define _VIEW_WINDOW_H_

#include "def.h"
#include "include/layout/ViewPort/SceneView.h"

namespace gf {

class BaseWindow {
 public:

  virtual void *getNativeWindow() = 0;

  virtual void setNativeWindow(void *window) = 0;

  virtual SceneView *getSceneView() = 0;

  virtual void setRunningStatus(bool run) = 0;

  virtual void setWidth(const int &w) = 0;

  virtual void setHeight(const int &h) = 0;

  virtual void render() = 0;

  virtual int getWidth() = 0;

  virtual int getHeight() = 0;

  int    mWidth;
  int    mHeight;
  string mTitle;

};

}

#endif //_VIEW_WINDOW_H_
