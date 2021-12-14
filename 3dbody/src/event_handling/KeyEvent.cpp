
#include "include/event_handling/KeyEvent.h"

namespace gf {

KeyEventHandling *ThreeDBodyKeyEventHandling::instance_ = nullptr;

void ThreeDBodyKeyEventHandling::onKeyCallBack(GLFWwindow *window, int key, int scancode, int action, int mods) {
  ///todo:implement key callback here.




}
KeyEventHandling *ThreeDBodyKeyEventHandling::getInstance() {
  if (instance_==nullptr) {
	instance_ = new ThreeDBodyKeyEventHandling();
  }
  return instance_;
}
void onKeyEventCallBack(GLFWwindow *window, int key, int scancode, int action, int mods) {
  KeyEventHandling *keyEventHandler = ThreeDBodyKeyEventHandling::getInstance();
  keyEventHandler->onKeyCallBack(window, key, scancode, action, mods);
}

}
