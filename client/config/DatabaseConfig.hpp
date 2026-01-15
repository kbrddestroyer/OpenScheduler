#ifndef DATABASECONFIG_HPP
#define DATABASECONFIG_HPP

#include <config/Config.hpp>

namespace OpenScheduler {
    class DatabaseConfig final : public Config::Config {
    public:
        DatabaseConfig() = delete;

        explicit DatabaseConfig(std::string basic_string)
            : Config(std::move(basic_string)) {
        }

        [[nodiscard]] const std::string &  HOST() const { return host_; }
        [[nodiscard]] const std::string &  LOGIN() const { return login_; }
        [[nodiscard]] const std::string &  PASSWORD() const { return password_; }
        [[nodiscard]] const std::string &  SCHEMA() const { return schema_; }
    protected:
        void onValuesObtained(const std::map<std::string, std::string> &) override;
    private:
        std::string host_;
        std::string login_;
        std::string password_;
        std::string schema_;
    };
}


#endif //DATABASECONFIG_HPP
