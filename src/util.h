#ifndef FXUTIL_H
#define FXUTIL_H

#include <stdint.h>
#include <fmt/core.h>
#include <functional>

namespace fx {

// format alias
template <typename... T>
std::string _f(fmt::format_string<T...> fmt, T&&... args) {
    return fmt::format(fmt, args...);
}

class Defer {
public:
    Defer(std::function<void()> &&init, std::function<void()> &&finish) :
        finish_(std::move(finish))
    {
        if (init) init();
    }

    ~Defer() {
        if (finish_) finish_();
    }

private:
    std::function<void()> finish_;
};

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
