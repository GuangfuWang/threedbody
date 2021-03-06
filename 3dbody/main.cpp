
#include "include/application/Application.h"
#include "util/Log.h"

int main() {
  gf::Log::init();
  auto app = std::make_unique<gf::Application>("3D Body");
  app->loop();

  GF_INFO("3D Body Process terminated...");

  return 0;
}
