#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <memory>
#include <fstream>
#include <string>
#include <map>

#include "ConfigParser.hpp"


namespace Config {
    enum class ConfigReadResult {
        CONFIG_EMPTY,
        CONFIG_OK,
        CONFIG_FILE_NOT_FOUND,
        CONFIG_SYNTAX_ERROR
    };

    /**
     * Base class for every config object
     */
    class Config {
    public:
        // Restrict default config creation with no filename provided
        Config() = delete;
        explicit Config( std::string  /* filename */ );

        virtual ~Config();

        bool prepare();
        [[nodiscard]] bool ready() const { return stream_.is_open(); }
        bool parse();

        [[nodiscard]] const std::string& filename() { return filename_; }
        [[nodiscard]] ConfigReadResult result() const { return result_; }
    protected:
        virtual void onValuesObtained( const std::map<std::string, std::string> & /* result */ ) = 0;
    private:
        bool read(std::map<std::string, std::string> &);
    protected:
        std::ifstream stream_;

        std::string filename_;
        ConfigReadResult result_ = ConfigReadResult::CONFIG_EMPTY;
    };
} // Config

#endif //CONFIG_HPP
