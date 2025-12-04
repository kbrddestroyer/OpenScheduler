#ifndef LOGIN_HPP
#define LOGIN_HPP

#include <cstdint>
#include <string>

#if __linux__
#include <memory>
#endif

#include <memory>

#include "utils/utility.h"

namespace Login {
    struct Credentials {
        std::string username;
        std::string raw_password;
    };

    /**
     *  Defines class Login that should handle the login process from client side
     */
    class Login {
    public:
        Login() = delete;
        explicit Login(const Credentials &);
    private:
        static void doHashPassword(const std::string &, std::string &) noexcept;
    private:
        const std::unique_ptr<Credentials> credentials;
    };

} // Login

#endif //LOGIN_HPP
