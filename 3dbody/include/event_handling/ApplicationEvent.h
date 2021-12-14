

#ifndef INC_3DBODY_3DBODY_INCLUDE_EVENT_HANDLING_APPLICATIONEVENT_H_
#define INC_3DBODY_3DBODY_INCLUDE_EVENT_HANDLING_APPLICATIONEVENT_H_

#include <climits>
#include <GLFW/glfw3.h>

namespace gf {

enum class APP_EVENT {
  APP_CLOSE = 0,
  APP_RESIZE,
  APP_NONE = INT_MAX
};

/**
 * @author Guangfu
 * @brief this is a pure virtual interface for app event.
 */
class AppEventHandling {
 public:
  virtual void onWindowSizeCallback(GLFWwindow *window, int width, int height) = 0;

  virtual void onWindowCloseCallback(GLFWwindow *window) = 0;

};

/**
 * @note please implement a singleton if you need custom app event handling.
 */
class ThreeDBodyAppEventHandling : public AppEventHandling {

 public:
  void onWindowSizeCallback(GLFWwindow *window, int width, int height) override;

  void onWindowCloseCallback(GLFWwindow *window) override;

  static AppEventHandling *getInstance();

 private:

  ThreeDBodyAppEventHandling() = default;

 private:

  static AppEventHandling *instance_;
};

extern void onWindowSizeCallback(GLFWwindow *window, int width, int height);

extern void onWindowCloseCallback(GLFWwindow *window);

}

#endif //INC_3DBODY_3DBODY_INCLUDE_EVENT_HANDLING_APPLICATIONEVENT_H_
