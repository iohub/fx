#ifndef FXUTIL_H
#define FXUTIL_H

#include <stdint.h>
#include <fmt/core.h>

namespace fx {

class Logging {
public:
    enum class Level: uint8_t {
        ERROR, WARN, INFO, DEBUG
    };
    static void set_level(Level l);

    template <typename... T>
    static void info(fmt::format_string<T...> fmt, T&&... args) {
        if (level >= Level::INFO) fmt::print(fmt, args...);
    }
    template <typename... T>
    static void debug(fmt::format_string<T...> fmt, T&&... args) {
        if (level >= Level::DEBUG) fmt::print(fmt, args...);
    }
    template <typename... T>
    static void error(fmt::format_string<T...> fmt, T&&... args) {
        if (level >= Level::ERROR) fmt::print(fmt, args...);
    }

    static Level level;
};


}


#endif
