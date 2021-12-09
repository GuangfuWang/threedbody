#include "logger.h"

#include <spdlog/spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog/sinks/basic_file_sink.h>

namespace gf {
Ref<spdlog::logger> log::s_CoreLogger;
Ref<spdlog::logger> log::s_ClientLogger;

void log::Init()
{
  std::vector<spdlog::sink_ptr> logSinks;
  logSinks.emplace_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
  logSinks.emplace_back(std::make_shared<spdlog::sinks::basic_file_sink_mt>("three_d_body.log", true));

  logSinks[0]->set_pattern("%^[%T] %n: %v%$");
  logSinks[1]->set_pattern("[%T] [%l] %n: %v");

  s_CoreLogger = std::make_shared<spdlog::logger>("3D Body", begin(logSinks), end(logSinks));
  spdlog::register_logger(s_CoreLogger);
  s_CoreLogger->set_level(spdlog::level::trace);
  s_CoreLogger->flush_on(spdlog::level::trace);

  s_ClientLogger = std::make_shared<spdlog::logger>("3D Body", begin(logSinks), end(logSinks));
  spdlog::register_logger(s_ClientLogger);
  s_ClientLogger->set_level(spdlog::level::trace);
  s_ClientLogger->flush_on(spdlog::level::trace);
}
}
