
#ifndef INC_3DBODY_3DBODY_INCLUDE_APPLICATION_APPLICATION_H_
#define INC_3DBODY_3DBODY_INCLUDE_APPLICATION_APPLICATION_H_

#include <memory>
#include "include/layout/view_window.h"
#include "include/scene/scene_camera.h"

class Application
{

 public:
  Application(const std::string& app_name);

  static Application& Instance() { return *sInstance; }

  void loop();

 private:
  static Application* sInstance;

  std::unique_ptr<gf::ViewWindow> mWindow;
};


#endif //INC_3DBODY_3DBODY_INCLUDE_APPLICATION_APPLICATION_H_
