#include "logger.h"

namespace gf {
#ifdef GF_WIN
    const std::string Log::info_prefix = "[INFO ]: ";
    const std::string Log::warn_prefix = "[WARN ]: ";
    const std::string Log::error_prefix = "[ERROR]: ";
    const std::string Log::fatal_prefix = "[FATAL]: ";
    const std::string Log::debug_prefix = "[DEBUG]: ";
    Log::Channel Log::c = Log::Channel::Console;
    std::string Log::output_file = "./logOutput/log.txt";
#elif defined(GF_LINUX)
    const std::string Log::info_prefix = "\033[0m[INFO ]: ";
    const std::string Log::warn_prefix = "\033[35m[WARN ]: ";
    const std::string Log::error_prefix = "\033[33m[ERROR]: ";
    const std::string Log::fatal_prefix = "\033[31m[FATAL]: ";
    const std::string Log::debug_prefix = "\033[0m[DEBUG]: ";
    Log::Channel Log::c = Log::Channel::Console;
    std::string Log::output_file = "./logOutput/log.txt";
#endif
}
