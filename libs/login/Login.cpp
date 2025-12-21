#include "Login.hpp"

#include "utils/utility.h"
#include "CredentialsDao.hpp"

#include <vector>
#include <sstream>
#include <iomanip>

#include "table/QueryProcessor.hpp"

namespace Login {

    Login::Login(const Credentials &credentials)
        : credentials_(std::make_unique<Credentials>(credentials))
    {}

    void Login::doHashPassword(const std::string & raw_passwd, std::string & passwd_sha256) noexcept {
        if (update_digest(raw_passwd.c_str(), raw_passwd.length()) != HASH_SUCCESS)
            return;

        uint32_t data_size = get_md_size();

        std::vector<unsigned char> hashed(data_size);

        if (hash_passwd(hashed.data(), &data_size) != HASH_SUCCESS)
            return;

        std::stringstream ss;
        for (const unsigned char byte : hashed) {
            ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(byte);
        }
        passwd_sha256 = ss.str();
    }


    bool Login::tryLogin() const {
        std::string hashed_passwd;

        const auto dao = Database::QueryProcessor<CredentialsDao>::selectByPK<std::string>(
            "test_logins",
            "username",
            "\'" + this->credentials_->username + "\'"
            );

        doHashPassword(
            credentials_->raw_password,
            hashed_passwd
        );

        return dao->getHashedPasswd() == hashed_passwd;
    }

    bool Login::tryRegister() const {
        std::string hashed_passwd;
        doHashPassword(credentials_->raw_password, hashed_passwd);

        // TODO: Move database call somewhere else to maintain SOLID
        const CredentialsDao dao(
            credentials_->username, hashed_passwd
        );

        return Database::QueryProcessor<CredentialsDao>::insert("test_logins", dao);
    }

} // Login