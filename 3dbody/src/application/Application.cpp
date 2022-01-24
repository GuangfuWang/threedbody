
#include "include/application/Application.h"

namespace gf {
Application::Application(const std::string &app_name) {
  mWindow = createUniqueRef<gf::ThreeDBodyWindow>();
  mWindow->init(1440, 1080, app_name);

}

void Application::loop() {
  while (mWindow->isRunning()) {
	mWindow->render();
  }
}
}


