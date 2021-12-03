
#ifndef INC_3DBODY_LOGGER_H
#define INC_3DBODY_LOGGER_H

#include <string>
#include <cstring>
#include <cstdarg>
#include <vector>
#include <fstream>

namespace gf {

    /**
     * this class is used to output log information.
     */

#define Logger(channel, level, ...) Log::Write(channel,level, __FILE__, __LINE__, __FUNCTION__, __VA_ARGS__)

#define G_INFO(...) Log::Write(Log::Level::INFO_, __FILE__, __LINE__, __FUNCTION__, __VA_ARGS__)
#define G_WARN(...) Log::Write(Log::Level::WARN_, __FILE__, __LINE__, __FUNCTION__, __VA_ARGS__)
#define G_ERROR(...) Log::Write(Log::Level::ERROR_, __FILE__, __LINE__, __FUNCTION__, __VA_ARGS__)
#define G_FATAL(...) Log::Write(Log::Level::FATAL_, __FILE__, __LINE__, __FUNCTION__, __VA_ARGS__)
#define G_DEBUG(...) Log::Write(Log::Level::DEBUG_, __FILE__, __LINE__, __FUNCTION__, __VA_ARGS__)

    class Log {
    public:
        enum class Channel {
            Console = 0,
            File = 1,
            Internet = 2
        };

        enum class Level {
            INFO_ = 0,
            WARN_ = 1,
            ERROR_ = 2,
            FATAL_ = 3,
            DEBUG_ = 4
        };

    private:
        static std::string output_file;
        static Channel c;

        static const std::string info_prefix;
        static const std::string warn_prefix;
        static const std::string error_prefix;
        static const std::string fatal_prefix;
        static const std::string debug_prefix;

        static std::string format(const char *msg, va_list args) {
            size_t size = 1024;
            std::vector<char> dynamicbuf(size);
            char *buf = &dynamicbuf[0];
            va_list argsTmp;
            while (1) {
                va_copy(argsTmp, args);
                int needed = vsnprintf(buf, size, msg, argsTmp);
                va_end(argsTmp);
                if (needed < (int) size - 1 && needed >= 0) {
                    return std::string(buf, (size_t) needed);
                }
                size = needed >= 0 ? needed + 2 : size * 2;
                dynamicbuf.resize(size);
                buf = &dynamicbuf[0];
            }
        }

    public:

        inline static void setChannel(Channel c_ = Channel::Console) {
            c = c_;
        }

        inline static bool Write(Level l, const char *file, int line, const char *function, const char *msg, ...) {
            if (strlen(msg) == 0) {
                return true;
            }
            char tt[1024];
            sprintf(tt, "At File: %s\n\t\t    Line: %i\n\t\t    Function: %s\n\t\t Massage: ",
                    file, line, function);
            std::string prefix_info(tt);
            if (c == Channel::Console) {
                if (l == Level::INFO_) {
                    va_list args;
                    va_start(args, msg);
                    std::string temp = info_prefix + prefix_info + format(msg, args);
                    temp += "\n";
                    va_end(args);
                    fprintf(stdout, temp.c_str());
                    fflush(stdout);
                    return true;
                } else if (l == Level::WARN_) {
                    va_list args;
                    va_start(args, msg);
                    std::string temp = warn_prefix + prefix_info + format(msg, args);
                    temp += "\n";
                    va_end(args);
                    fprintf(stdout, temp.c_str());
                    fflush(stdout);
                    return true;
                } else if (l == Level::ERROR_) {
                    va_list args;
                    va_start(args, msg);
                    std::string temp = error_prefix + prefix_info + format(msg, args);
                    temp += "\n";
                    va_end(args);
                    fprintf(stdout, temp.c_str());
                    fflush(stdout);
                    return true;
                } else if (l == Level::FATAL_) {
                    va_list args;
                    va_start(args, msg);
                    std::string temp = fatal_prefix + prefix_info + format(msg, args);
                    temp += "\n";
                    va_end(args);
                    fprintf(stdout, temp.c_str());
                    fflush(stdout);
                    return true;
                } else if (l == Level::DEBUG_) {
                    va_list args;
                    va_start(args, msg);
                    std::string temp = debug_prefix + prefix_info + format(msg, args);
                    temp += "\n";
                    va_end(args);
                    fprintf(stdout, temp.c_str());
                    fflush(stdout);
                    return true;
                } else {
                    fprintf(stderr, "\nUnknown output log level, available are: ");
                    fprintf(stderr, "\n\t1. Level::INFO\n\t2. Level::WARN\n\t3. Level::ERROR"
                                    "\n\t4. Level::FATAL\n\t5. Level::DEBUG");
                    return false;
                }
            } else if (c == Channel::File) {
                std::ofstream ifs(output_file, std::ios::out);
                if (!ifs.is_open()) {
                    return false;
                }
                va_list args;
                va_start(args, msg);
                std::string temp = "";
                if (l == Level::INFO_) {
                    temp = info_prefix;
                } else if (l == Level::WARN_) {
                    temp = warn_prefix;
                } else if (l == Level::ERROR_) {
                    temp = error_prefix;
                } else if (l == Level::FATAL_) {
                    temp = fatal_prefix;
                } else if (l == Level::DEBUG_) {
                    temp = debug_prefix;
                }
                temp += prefix_info + format(msg, args);
                temp += "\n";
                va_end(args);
                ifs << temp;
                ifs.close();

            } else if (c == Channel::Internet) {

            } else {
                fprintf(stderr, "\nUnknown output log channel, available are: ");
                fprintf(stderr, "\n\t1. Channel::Console\n\t2. Channel::File\n\t3. Channel::Internet");
                return false;
            }
            return true;
        }

        inline static bool setFilePath(const std::string &path) {
            if (!path.size()) {
                fprintf(stderr, "\nEmpty file path!");
                return false;
            }
            if (path[path.size() - 1] == '/') {
                std::string temp = __DATE__;
                std::string t = "";
                for (auto &e: temp) {
                    if (e != ' ') {
                        t += e;
                    }
                }
                fprintf(stderr, "\nLog file path ends with \'/\', file name set to default: %s", t.c_str());
                output_file = path + t + "log.txt";
                return true;
            }
            output_file = path;
            return true;
        }

    };


}


#endif //INC_3DBODY_LOGGER_H
