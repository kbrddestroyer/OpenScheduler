#include "CredentialsDao.hpp"

#include <format>


namespace Login {
    CredentialsDao::CredentialsDao(const sql::ResultSet *rs) :
        username(rs->getString("username")),
        passwd_sha256(rs->getString("passwd_sha256")),
        id(rs->getInt("id"))
    {
    }

    CredentialsDao::CredentialsDao(const uint32_t id, const std::string &username, const std::string &passwd_sha256) :
        id(id),
        username(username),
        passwd_sha256(passwd_sha256)
    {}

    const std::string CredentialsDao::getUpdateQuery() const {
        return std::format(
            "username=\"{}\", passwd_sha256=\"{}\"",
            username.c_str(), passwd_sha256.c_str()
        );
    }

} // Login