
#ifndef INC_3DBODY_LOGGER_H
#define INC_3DBODY_LOGGER_H

#define GLM_ENABLE_EXPERIMENTAL
#include "glm/gtx/string_cast.hpp"
#include <cassert>
// This ignores all warnings raised inside External headers
#pragma warning(push, 0)
#include <spdlog/spdlog/spdlog.h>
#include <spdlog/spdlog/fmt/ostr.h>
#pragma warning(pop)

#include "def.h"

namespace gf {

/**
 * this class is used to output Log information.
 * this is a thin wrapper of spdlog.
 */
class Log {
 public:
  static void init();

  static Ref<spdlog::logger> &getCoreLogger() { return s_CoreLogger; }
  static Ref<spdlog::logger> &getClientLogger() { return s_ClientLogger; }
 private:
  static Ref<spdlog::logger> s_CoreLogger;
  static Ref<spdlog::logger> s_ClientLogger;
};

template<typename OStream, glm::length_t L, typename T, glm::qualifier Q>
inline OStream &operator<<(OStream &os, const glm::vec<L, T, Q> &vector) {
  return os << glm::to_string(vector);
}

template<typename OStream, glm::length_t C, glm::length_t R, typename T, glm::qualifier Q>
inline OStream &operator<<(OStream &os, const glm::mat<C, R, T, Q> &matrix) {
  return os << glm::to_string(matrix);
}

template<typename OStream, typename T, glm::qualifier Q>
inline OStream &operator<<(OStream &os, glm::qua<T, Q> quaternion) {
  return os << glm::to_string(quaternion);
}

}

// Core Log macros
#define GF_CORE_TRACE(...)    gf::Log::getCoreLogger()->trace(__VA_ARGS__)
#define GF_CORE_INFO(...)     gf::Log::getCoreLogger()->info(__VA_ARGS__)
#define GF_CORE_WARN(...)     gf::Log::getCoreLogger()->warn(__VA_ARGS__)
#define GF_CORE_ERROR(...)    gf::Log::getCoreLogger()->error(__VA_ARGS__)
#define GF_CORE_CRITICAL(...) gf::Log::getCoreLogger()->critical(__VA_ARGS__)
#define GF_CORE_ASSERT(EXP,MSG) assert(((void)MSG, EXP))

// Client Log macros
#define GF_TRACE(...)         gf::Log::getClientLogger()->trace(__VA_ARGS__)
#define GF_INFO(...)          gf::Log::getClientLogger()->info(__VA_ARGS__)
#define GF_WARN(...)          gf::Log::getClientLogger()->warn(__VA_ARGS__)
#define GF_ERROR(...)         gf::Log::getClientLogger()->error(__VA_ARGS__)
#define GF_CRITICAL(...)      gf::Log::getClientLogger()->critical(__VA_ARGS__)

#endif //INC_3DBODY_LOGGER_H
