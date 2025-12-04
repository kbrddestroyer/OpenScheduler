#ifndef LOGIN_HPP
#define LOGIN_HPP

#include <string>
#include <memory>
#include "utils/utility.h"
#include "compile_utils.h"


namespace Login {
    struct Credentials {
        std::string username;
        std::string raw_password;
    };

    /**
     *  Defines class Login that should handle the login process from client side
     */
    class DECLSPEC_AUTO Login {
    public:
        Login() = delete;
        explicit Login(const Credentials &);

        static void doHashPassword(const std::string &, std::string &) noexcept;
        /*
         *  TODO: Whole login flow refactor when model is switched to client-server
         */
        [[nodiscard]] bool tryLogin(const std::string& /* db_passwd */) const;
        [[nodiscard]] bool tryRegister() const;
    private:
        const std::unique_ptr<Credentials> credentials_;
    };

} // Login

#endif //LOGIN_HPP
