
#ifndef INC_3DBODY_LOGGER_H
#define INC_3DBODY_LOGGER_H

#define GLM_ENABLE_EXPERIMENTAL
#include "glm/gtx/string_cast.hpp"

// This ignores all warnings raised inside External headers
#pragma warning(push, 0)
#include <spdlog/spdlog/spdlog.h>
#include <spdlog/spdlog/fmt/ostr.h>
#pragma warning(pop)

namespace gf {

template<typename T>
using Ref = std::shared_ptr<T>;
template<typename T, typename ... Args>
constexpr Ref<T> CreateRef(Args&& ... args)
{
  return std::make_shared<T>(std::forward<Args>(args)...);
}

/**
 * this class is used to output log information.
 * this is a thin wrapper of spdlog.
 */
class log {
 public:
  static void Init();

  static Ref<spdlog::logger> &GetCoreLogger() { return s_CoreLogger; }
  static Ref<spdlog::logger> &GetClientLogger() { return s_ClientLogger; }
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

// Core log macros
#define GF_CORE_TRACE(...)    gf::log::GetCoreLogger()->trace(__VA_ARGS__)
#define GF_CORE_INFO(...)     gf::log::GetCoreLogger()->info(__VA_ARGS__)
#define GF_CORE_WARN(...)     gf::log::GetCoreLogger()->warn(__VA_ARGS__)
#define GF_CORE_ERROR(...)    gf::log::GetCoreLogger()->error(__VA_ARGS__)
#define GF_CORE_CRITICAL(...) gf::log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define GF_TRACE(...)         gf::log::GetClientLogger()->trace(__VA_ARGS__)
#define GF_INFO(...)          gf::log::GetClientLogger()->info(__VA_ARGS__)
#define GF_WARN(...)          gf::log::GetClientLogger()->warn(__VA_ARGS__)
#define GF_ERROR(...)         gf::log::GetClientLogger()->error(__VA_ARGS__)
#define GF_CRITICAL(...)      gf::log::GetClientLogger()->critical(__VA_ARGS__)


#endif //INC_3DBODY_LOGGER_H
