
#ifndef CONFIGPARSER_HPP
#define CONFIGPARSER_HPP

#include <regex>


namespace Config {
    typedef std::pair<std::string, std::string> ConfigKVPair;

    /**
     * Parses config file by name
     */
    class ConfigValueParser {
    public:
        ConfigValueParser() = delete;
        explicit ConfigValueParser(const std::string &);

        [[nodiscard]] ConfigKVPair parse(const std::string &) const;
    private:
        std::regex regexp_;
    };

} // Config

#endif //CONFIGPARSER_HPP
