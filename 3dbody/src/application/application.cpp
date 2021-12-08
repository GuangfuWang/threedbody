#include "pch.hpp"
#include "include/application/application.h"
#include "include/layout/view_window.h"

Application::Application(const std::string& app_name)
{
  mWindow = std::make_unique<gf::ViewWindow>();
  mWindow->init(1080, 720, app_name);

}

void Application::loop()
{
  while (mWindow->is_running())
  {
    mWindow->render();
  }
}

