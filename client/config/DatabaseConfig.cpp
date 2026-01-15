#include "DatabaseConfig.hpp"


namespace OpenScheduler {
    void DatabaseConfig::onValuesObtained(const std::map<std::string, std::string> & result) {
        host_ = result.at("HOSTNAME");
        login_ = result.at("LOGIN");
        password_ = result.at("PASSWORD");
        schema_ = result.at("SCHEMA");
    }
}