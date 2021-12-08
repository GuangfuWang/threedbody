#include "pch.hpp"
#include "include/application/application.h"

int main(void)
{
  auto app = std::make_unique<Application>("3D Body");
  app->loop();

  return 0;
}
