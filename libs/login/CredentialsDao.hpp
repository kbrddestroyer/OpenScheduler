#ifndef CREDENTIALSDAO_HPP
#define CREDENTIALSDAO_HPP

#include <string>
#include <database/Database.hpp>

#include "Login.hpp"


namespace Login {

/* INTERNAL */
class CredentialsDao final : public Database::DAOBase {
public:
    CredentialsDao() = delete;
    explicit CredentialsDao(const sql::ResultSet * /* rs */);
    explicit CredentialsDao(const std::string & /* username */, const std::string & /* passwd_sha256 */);

    [[nodiscard]] const std::string& getUsername() const { return username; }
    [[nodiscard]] const std::string& getHashedPasswd() const { return passwd_sha256; }
    [[nodiscard]] const std::string getUpdateQuery() const override;
protected:
    std::string username;
    std::string passwd_sha256;
};

} // Login

#endif //CREDENTIALSDAO_HPP
