#include "ConfigParser.hpp"
#include <regex>


namespace Config {
    ConfigValueParser::ConfigValueParser(const std::string &regexp) : regexp_(regexp) {}

    ConfigKVPair ConfigValueParser::parse(const std::string &raw) const {
        if (std::smatch match; std::regex_match(raw, match, regexp_) ) {
            return { match[1].str(), match[2].str() };
        }

        return {};
    }
} // Config