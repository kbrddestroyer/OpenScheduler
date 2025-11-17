#include "Login.hpp"

#include "utils/utility.h"

namespace Login {

    Login::Login(const Credentials &credentials)
        : credentials(std::make_unique<Credentials>(credentials))
    {}

    void Login::doHashPassword(const std::string & raw_passwd, std::string & passwd_sha256) noexcept {
    }


} // Login