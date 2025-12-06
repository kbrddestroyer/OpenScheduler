#ifndef LOGGER_HPP
#define LOGGER_HPP

#include "Singleton.hpp"

#include <iostream>


namespace Logger {
    enum class Scope {
        INFO,
        WARNING,
        ERROR
    };

    class _logger_streambuf : public std::streambuf {
    public:
        _logger_streambuf() = default;

    private:
        int overflow(int_type) override;
    };

    class Logger : Utils::Singleton<Logger>, public std::ostream  {
    public:
        Logger() : std::ostream(&streambuf_) {}
    private:
        _logger_streambuf streambuf_;
    };

} // Logger

#endif //LOGGER_HPP
