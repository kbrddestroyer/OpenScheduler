#include "CredentialsDao.hpp"

#include <format>


namespace Login {
    CredentialsDao::CredentialsDao(const sql::ResultSet *rs) :
        username(rs->getString("username")),
        passwd_sha256(rs->getString("passwd_sha256")),
        role(rs->getInt("role"))
    {}

    CredentialsDao::CredentialsDao(const std::string &username, const std::string &passwd_sha256, uint8_t role) :
        username(username),
        passwd_sha256(passwd_sha256),
        role(role)
    {}

    const std::string CredentialsDao::getUpdateQuery() const {
        return std::format(
            "username=\"{}\", passwd_sha256=\"{}\", role={}",
            username.c_str(), passwd_sha256.c_str(), role
        );
    }

} // Login