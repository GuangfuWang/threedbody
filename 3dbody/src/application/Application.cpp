
#include "include/application/Application.h"

namespace gf {
Application::Application(const std::string &app_name) {
  mWindow = std::make_unique<gf::ThreeDBodyWindow>();
  mWindow->init(1440, 1080, app_name);

}

void Application::loop() {
  while (mWindow->is_running()) {
    mWindow->render();
  }
}
}


