#include "Config.hpp"
#include "ConfigParser.hpp"

#include <utility>

namespace Config {
    Config::Config( std::string  filename ) : filename_(std::move(filename)) {}

    Config::~Config() {
        if (stream_.is_open()) {
            stream_.close();
        }
    }

    bool Config::prepare() {
        stream_.open(filename_, std::ios_base::in);

        if ( !stream_.is_open() ) {
            result_ = ConfigReadResult::CONFIG_FILE_NOT_FOUND;
        }

        return stream_.is_open();
    }

    bool Config::parse() {
        if (std::map< std::string, std::string > parsed; read(parsed))
        {
            onValuesObtained(parsed);
            return true;
        }
        return false;
    }

    bool Config::read(std::map<std::string, std::string> &result) {
        // Assuming that result variable is already properly initialized
        if ( !this->ready() )
            return false;

        std::string line;
        ConfigValueParser parser(R"(^(\w+)\s+=\s+(.+?))");

        while ( std::getline( stream_, line ) ) {
            ConfigKVPair kvpair = parser.parse(line);
            result.insert( kvpair );
        }

        return true;
    }
} // Config