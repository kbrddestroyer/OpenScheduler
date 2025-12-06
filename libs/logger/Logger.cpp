#include "Logger.hpp"

#include <string_view>

namespace Logger {
    int _logger_streambuf::overflow(int_type val) {
        if (val != EOF)
            std::cout.put(val);

        return val;
    }


} // Logger